#ifndef PIRSENSOR_HH
#define PIRSENSOR_HH

#include <iostream>

#include "IPIRSensor.hh"
#include "IInput.hh"


namespace dezyne {
  struct locator;
  struct runtime;
}


struct PIRSensor
{
  dezyne::meta dzn_meta;
  dezyne::runtime& dzn_rt;
  dezyne::locator const& dzn_locator;
#ifndef ENUM_PIRSensor_State
#define ENUM_PIRSensor_State 1
  struct State
  {
    enum type
    {
      Disabled, Enabled
    };
  };
#endif // ENUM_PIRSensor_State
  State::type state;
  std::function<void ()> out_pirSensor;
  IPIRSensor pirSensor;
  IInput inputSignal;

  PIRSensor(const dezyne::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os=std::clog) const;

  private:
  void pirSensor_enable();
  void pirSensor_disable();
  void inputSignal_triggered();
};

#endif // PIRSENSOR_HH
