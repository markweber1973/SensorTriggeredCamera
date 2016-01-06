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
#ifndef CAMERA_HH
#define CAMERA_HH

#include <iostream>

#include "ICamera.hh"
#include "itimer.hh"


namespace dezyne {
  struct locator;
  struct runtime;
}


struct Camera
{
  dezyne::meta dzn_meta;
  dezyne::runtime& dzn_rt;
  dezyne::locator const& dzn_locator;
#ifndef ENUM_Camera_State
#define ENUM_Camera_State 1
  struct State
  {
    enum type
    {
      Idle, Busy
    };
  };
#endif // ENUM_Camera_State
  State::type state;
  std::function<void ()> out_camera;
  ICamera camera;
  itimer timer;

  Camera(const dezyne::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os=std::clog) const;

  private:
  void camera_takePicture();
  void camera_abort();
  void timer_timeout();
};

#endif // CAMERA_HH
