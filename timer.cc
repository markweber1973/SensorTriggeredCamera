#include "timer.hh"

#include "locator.hh"
#include "runtime.hh"

#include "itimer_impl.hh"

#include <functional>
#include <memory>

using namespace dezyne;

timer::timer(const locator& l)
: dzn_meta{"","timer",0,{},{[this]{port.check_bindings();}}}
, dzn_rt(l.get<runtime>())
, dzn_locator(l)
, port{{{"port",this,&dzn_meta},{"",0,0}}}
{
  locator tmp(l.clone());
  tmp.set(port);
  auto pimpl = l.get<std::function<std::shared_ptr<itimer_impl>(const locator&)>>()(tmp);
  port.in.create = [=]{pimpl->create();};
  port.in.cancel = [=]{pimpl->cancel();};
  port.out.timeout = []{};
}
