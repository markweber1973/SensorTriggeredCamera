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
#ifndef IRLED_HH
#define IRLED_HH

#include <iostream>

#include "IIRLED.hh"
#include "IOutput.hh"


namespace dezyne {
  struct locator;
  struct runtime;
}


struct IRLED
{
  dezyne::meta dzn_meta;
  dezyne::runtime& dzn_rt;
  dezyne::locator const& dzn_locator;
#ifndef ENUM_IRLED_State
#define ENUM_IRLED_State 1
  struct State
  {
    enum type
    {
      On, Off
    };
  };
#endif // ENUM_IRLED_State
  State::type state;
  std::function<void ()> out_irLed;
  IIRLED irLed;
  IOutput iOutput;

  IRLED(const dezyne::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os=std::clog) const;

  private:
  void irLed_SwitchOn();
  void irLed_SwitchOff();
};

#endif // IRLED_HH
