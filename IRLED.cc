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
#include "IRLED.hh"

#include "locator.hh"
#include "runtime.hh"


IRLED::IRLED(const dezyne::locator& dezyne_locator)
: dzn_meta{"","IRLED",0,{},{[this]{irLed.check_bindings();},[this]{iOutput.check_bindings();}}}
, dzn_rt(dezyne_locator.get<dezyne::runtime>())
, dzn_locator(dezyne_locator)
, state(State::Off)
, irLed{{{"irLed",this,&dzn_meta},{"",0,0}}}
, iOutput{{{"",0,0},{"iOutput",this,&dzn_meta}}}
{
  dzn_rt.performs_flush(this) = true;
  irLed.in.SwitchOn = [&] () { return dezyne::call_in(this, [&]{return irLed_SwitchOn();}, this->irLed.meta, "SwitchOn"); };
  irLed.in.SwitchOff = [&] () { return dezyne::call_in(this, [&]{return irLed_SwitchOff();}, this->irLed.meta, "SwitchOff"); };

}

void IRLED::irLed_SwitchOn()
{
  if (this->state == State::Off)
  {
    {
      this->iOutput.in.write(10, 1);
      this->state = State::On;
    }
  }
  else if (this->state == State::On)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
}

void IRLED::irLed_SwitchOff()
{
  if (this->state == State::Off)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::On)
  {
    {
      this->iOutput.in.write(10, 0);
      this->state = State::Off;
    }
  }
}


void IRLED::check_bindings() const
{
  dezyne::check_bindings(&dzn_meta);
}
void IRLED::dump_tree(std::ostream& os) const
{
  dezyne::dump_tree(os, &dzn_meta);
}

