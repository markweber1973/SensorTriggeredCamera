#ifndef ITIMER_IMPL_HH
#define ITIMER_IMPL_HH

struct itimer_impl
{
  void virtual create() = 0;
  void virtual cancel() = 0;
};


#endif
