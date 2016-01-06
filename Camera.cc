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
#include "Camera.hh"

#include "locator.hh"
#include "runtime.hh"


Camera::Camera(const dezyne::locator& dezyne_locator)
: dzn_meta{"","Camera",0,{},{[this]{camera.check_bindings();},[this]{timer.check_bindings();}}}
, dzn_rt(dezyne_locator.get<dezyne::runtime>())
, dzn_locator(dezyne_locator)
, state(State::Idle)
, camera{{{"camera",this,&dzn_meta},{"",0,0}}}
, timer{{{"",0,0},{"timer",this,&dzn_meta}}}
{
  dzn_rt.performs_flush(this) = true;
  camera.in.takePicture = [&] () { return dezyne::call_in(this, [&]{return camera_takePicture();}, this->camera.meta, "takePicture"); };
  camera.in.abort = [&] () { return dezyne::call_in(this, [&]{return camera_abort();}, this->camera.meta, "abort"); };
  timer.out.timeout = [&] () { return dezyne::call_out(this, [=]{return timer_timeout();}, this->timer.meta, "timeout"); };

}

void Camera::camera_takePicture()
{
  if (this->state == State::Idle)
  {
    {
      this->timer.in.create();
      this->state = State::Busy;
    }
  }
  else if (this->state == State::Busy)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
}

void Camera::camera_abort()
{
  if (this->state == State::Idle)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Busy)
  {
    {
      this->timer.in.cancel();
      this->state = State::Idle;
    }
  }
}

void Camera::timer_timeout()
{
  if (this->state == State::Idle)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Busy)
  {
    {
      this->camera.out.pictureReady();
      this->state = State::Idle;
    }
  }
}


void Camera::check_bindings() const
{
  dezyne::check_bindings(&dzn_meta);
}
void Camera::dump_tree(std::ostream& os) const
{
  dezyne::dump_tree(os, &dzn_meta);
}

