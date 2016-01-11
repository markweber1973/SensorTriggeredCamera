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
#ifndef IIRLED_HH
#define IIRLED_HH

#include "meta.hh"

#include <cassert>
#include <map>




struct IIRLED
{

  struct
  {
    std::function<void ()> SwitchOn;
    std::function<void ()> SwitchOff;
  } in;

  struct
  {
  } out;

  dezyne::port::meta meta;
  inline IIRLED(dezyne::port::meta m) : meta(m) {}


  void check_bindings() const
  {
    if (! in.SwitchOn) throw dezyne::binding_error(meta, "in.SwitchOn");
    if (! in.SwitchOff) throw dezyne::binding_error(meta, "in.SwitchOff");


  }
};

inline void connect (IIRLED& provided, IIRLED& required)
{
  provided.out = required.out;
  required.in = provided.in;
  provided.meta.requires = required.meta.requires;
  required.meta.provides = provided.meta.provides;
}





#endif // IIRLED_HH
