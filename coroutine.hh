#ifndef DEZYNE_COROUTINE_HH
#define DEZYNE_COROUTINE_HH

#if HAVE_BOOST_COROUTINE
#include <boost/coroutine/all.hpp>
#else
#include "context.hh"
#endif

namespace dezyne
{
#if HAVE_BOOST_COROUTINE
  typedef boost::coroutines::symmetric_coroutine<void>::call_type context;
  typedef boost::coroutines::symmetric_coroutine<void>::yield_type yield;
#else
  typedef std::function<void(dezyne::context&)> yield;
#endif

  struct coroutine
  {
    static int g_id;
    int id;

    dezyne::context context;
    dezyne::yield yield;
    void* port;
    bool finished;
    bool released;
    bool skip_block;
    template <typename Worker>
    coroutine(Worker&& worker)
    : id(g_id++)
    , context([this, worker](dezyne::yield& yield){
        this->yield = std::move(yield);
        worker();
      })
    , port(nullptr)
    , finished(false)
    , released(false)
    , skip_block(false)
    {}
    ~coroutine()
    {
#ifdef DEBUG_RUNTIME
      std::cout << __FUNCTION__ << ": " << id << std::endl;
#endif
    }
    void yield_to(dezyne::coroutine& c)
    {
      this->yield(c.context);
    }
#if HAVE_BOOST_COROUTINE
    coroutine() : id(-1), context() {}
    void call(dezyne::coroutine&)
    {
      this->context();
    }
    void release(){}
#else // !HAVE_BOOST_COROUTINE
    coroutine() : id(-1), context(false) {}
    void call(dezyne::coroutine& c)
    {
      this->context.call(c.context);
    }
    void release()
    {
      this->context.release();
    }
#endif // HAVE_BOOST_COROUTINE
  };
}
#endif //DEZYNE_COROUTINE_HH
