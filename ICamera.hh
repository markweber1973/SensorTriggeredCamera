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
#ifndef ICAMERA_HH
#define ICAMERA_HH

#include "meta.hh"

#include <cassert>
#include <map>




struct ICamera
{

  struct
  {
    std::function<void ()> takePicture;
    std::function<void ()> abort;
  } in;

  struct
  {
    std::function<void ()> pictureReady;
  } out;

  dezyne::port::meta meta;
  inline ICamera(dezyne::port::meta m) : meta(m) {}


  void check_bindings() const
  {
    if (! in.takePicture) throw dezyne::binding_error(meta, "in.takePicture");
    if (! in.abort) throw dezyne::binding_error(meta, "in.abort");

    if (! out.pictureReady) throw dezyne::binding_error(meta, "out.pictureReady");

  }
};

inline void connect (ICamera& provided, ICamera& required)
{
  provided.out = required.out;
  required.in = provided.in;
  provided.meta.requires = required.meta.requires;
  required.meta.provides = provided.meta.provides;
}





#endif // ICAMERA_HH
