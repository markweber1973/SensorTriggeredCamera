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
#ifndef ITIMER_HH
#define ITIMER_HH

#include "meta.hh"

#include <cassert>
#include <map>




struct itimer
{

  struct
  {
    std::function<void ()> create;
    std::function<void ()> cancel;
  } in;

  struct
  {
    std::function<void ()> timeout;
  } out;

  dezyne::port::meta meta;
  inline itimer(dezyne::port::meta m) : meta(m) {}


  void check_bindings() const
  {
    if (! in.create) throw dezyne::binding_error(meta, "in.create");
    if (! in.cancel) throw dezyne::binding_error(meta, "in.cancel");

    if (! out.timeout) throw dezyne::binding_error(meta, "out.timeout");

  }
};

inline void connect (itimer& provided, itimer& required)
{
  provided.out = required.out;
  required.in = provided.in;
  provided.meta.requires = required.meta.requires;
  required.meta.provides = provided.meta.provides;
}





#endif // ITIMER_HH
