#ifndef TIMER_HH
#define TIMER_HH

#include <iostream>

#include "itimer.hh"


namespace dezyne {
  struct locator;
  struct runtime;
}


struct timer
{
  dezyne::meta dzn_meta;
  dezyne::runtime& dzn_rt;
  dezyne::locator const& dzn_locator;
  std::function<void ()> out_port;
  itimer port;

  timer(const dezyne::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os=std::clog) const;

  private:
  void port_create();
  void port_cancel();
};

#endif // TIMER_HH
