// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "PIRSensor.hh"

#include "locator.hh"
#include "runtime.hh"


PIRSensor::PIRSensor(const dezyne::locator& dezyne_locator)
: dzn_meta{"","PIRSensor",0,{},{[this]{pirSensor.check_bindings();},[this]{inputSignal.check_bindings();}}}
, dzn_rt(dezyne_locator.get<dezyne::runtime>())
, dzn_locator(dezyne_locator)
, state(State::Disabled)
, pirSensor{{{"pirSensor",this,&dzn_meta},{"",0,0}}}
, inputSignal{{{"",0,0},{"inputSignal",this,&dzn_meta}}}
{
  dzn_rt.performs_flush(this) = true;
  pirSensor.in.enable = [&] () { return dezyne::call_in(this, [&]{return pirSensor_enable();}, this->pirSensor.meta, "enable"); };
  pirSensor.in.disable = [&] () { return dezyne::call_in(this, [&]{return pirSensor_disable();}, this->pirSensor.meta, "disable"); };
  inputSignal.out.triggered = [&] () { return dezyne::call_out(this, [=]{return inputSignal_triggered();}, this->inputSignal.meta, "triggered"); };

}

void PIRSensor::pirSensor_enable()
{
  if (this->state == State::Disabled)
  {
    this->state = State::Enabled;
  }
  else if (this->state == State::Enabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
}

void PIRSensor::pirSensor_disable()
{
  if (this->state == State::Disabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Enabled)
  {
    this->state = State::Disabled;
  }
}

void PIRSensor::inputSignal_triggered()
{
  if (this->state == State::Disabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Enabled)
  {
    this->pirSensor.out.triggered();
  }
}


void PIRSensor::check_bindings() const
{
  dezyne::check_bindings(&dzn_meta);
}
void PIRSensor::dump_tree(std::ostream& os) const
{
  dezyne::dump_tree(os, &dzn_meta);
}

