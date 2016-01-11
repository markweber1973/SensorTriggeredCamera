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
#include "MotionTriggeredCam.hh"

#include "locator.hh"
#include "runtime.hh"


MotionTriggeredCam::MotionTriggeredCam(const dezyne::locator& dezyne_locator)
: dzn_meta{"","MotionTriggeredCam",0,{},{[this]{motionTriggeredCam.check_bindings();},[this]{camera.check_bindings();},[this]{sensor.check_bindings();},[this]{led.check_bindings();}}}
, dzn_rt(dezyne_locator.get<dezyne::runtime>())
, dzn_locator(dezyne_locator)
, state(State::Disabled)
, motionTriggeredCam{{{"motionTriggeredCam",this,&dzn_meta},{"",0,0}}}
, camera{{{"",0,0},{"camera",this,&dzn_meta}}}
, sensor{{{"",0,0},{"sensor",this,&dzn_meta}}}
, led{{{"",0,0},{"led",this,&dzn_meta}}}
{
  dzn_rt.performs_flush(this) = true;
  motionTriggeredCam.in.enable = [&] () { return dezyne::call_in(this, [&]{return motionTriggeredCam_enable();}, this->motionTriggeredCam.meta, "enable"); };
  motionTriggeredCam.in.disable = [&] () { return dezyne::call_in(this, [&]{return motionTriggeredCam_disable();}, this->motionTriggeredCam.meta, "disable"); };
  camera.out.pictureReady = [&] () { return dezyne::call_out(this, [=]{return camera_pictureReady();}, this->camera.meta, "pictureReady"); };
  sensor.out.triggered = [&] () { return dezyne::call_out(this, [=]{return sensor_triggered();}, this->sensor.meta, "triggered"); };

}

void MotionTriggeredCam::motionTriggeredCam_enable()
{
  if (this->state == State::Disabled)
  {
    {
      this->sensor.in.enable();
      this->state = State::Enabled;
    }
  }
  else if (this->state == State::Enabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Busy)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
}

void MotionTriggeredCam::motionTriggeredCam_disable()
{
  if (this->state == State::Disabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Enabled)
  {
    {
      this->sensor.in.disable();
      this->state = State::Disabled;
    }
  }
  else if (this->state == State::Busy)
  {
    {
      this->led.in.SwitchOff();
      this->sensor.in.disable();
      this->camera.in.abort();
      this->state = State::Disabled;
    }
  }
}

void MotionTriggeredCam::camera_pictureReady()
{
  if (this->state == State::Disabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Enabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Busy)
  {
    {
      this->led.in.SwitchOff();
      this->state = State::Enabled;
    }
  }
}

void MotionTriggeredCam::sensor_triggered()
{
  if (this->state == State::Disabled)
  {
    dzn_locator.get<dezyne::illegal_handler>().illegal();
  }
  else if (this->state == State::Enabled)
  {
    {
      this->led.in.SwitchOn();
      this->camera.in.takePicture();
      this->state = State::Busy;
    }
  }
  else if (this->state == State::Busy)
  {
    this->state = State::Busy;
  }
}


void MotionTriggeredCam::check_bindings() const
{
  dezyne::check_bindings(&dzn_meta);
}
void MotionTriggeredCam::dump_tree(std::ostream& os) const
{
  dezyne::dump_tree(os, &dzn_meta);
}

