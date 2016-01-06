#ifndef DEZYNE_PUMP_HH
#define DEZYNE_PUMP_HH

#include "coroutine.hh"

#include <condition_variable>
#include <functional>
#include <future>
#include <list>
#include <map>
#include <mutex>
#include <queue>
#include <set>

namespace dezyne
{
  struct pump
  {
    std::function<void()> worker;
    std::list<coroutine> coroutines;
    std::list<coroutine> collateral_blocked;
    std::set<void*> skip_block;
    std::queue<std::function<void()>> queue;
    std::function<void()> next_event;

    struct deadline
    {
      size_t id;
      std::chrono::steady_clock::time_point t;
      deadline(size_t id, size_t ms)
      : id(id)
      , t(std::chrono::steady_clock::now() + std::chrono::milliseconds(ms))
      {}
      bool expired() const {return t <= std::chrono::steady_clock::now();}
      bool operator < (const deadline& d) const {return t < d.t || (t == d.t && id < d.id);}
    };

    std::map<deadline, std::function<void()>> timers;
    std::function<void()> switch_context;
    std::function<void()> exit;
    std::thread::id thread_id;
    bool running;
    std::condition_variable condition;
    std::mutex mutex;
    std::future<void> task;
    pump();
    ~pump();
    void operator()();

    void collateral_block();
    void collateral_release(std::list<coroutine>::iterator);

    void block(void*);
    void create_context();
    void release(void*);
    void operator()(const std::function<void()>&);
    void operator()(std::function<void()>&&);
    template <typename L, typename = typename std::enable_if<std::is_void<typename std::result_of<L()>::type>::value>::type>
    void and_wait(const L& l)
    {
      std::promise<void> p;
      this->operator()([&p,l]{l(); p.set_value();});
      p.get_future().get();
    }
    template <typename L, typename = typename std::enable_if<!std::is_void<typename std::result_of<L()>::type>::value>::type>
    auto and_wait(const L& l) -> decltype(l())
    {
      std::promise<decltype(l())> p;
      this->operator()([&p,l]{p.set_value(l());});
      return p.get_future().get();
    }
    void handle(size_t id, size_t ms, const std::function<void()>&);
    void remove(size_t id);
  };
}

#endif //DEZYNE_PUMP_HH
