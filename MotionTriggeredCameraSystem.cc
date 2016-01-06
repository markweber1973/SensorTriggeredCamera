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
#include "MotionTriggeredCameraSystem.hh"

#include "runtime.hh"


MotionTriggeredCameraSystem::MotionTriggeredCameraSystem(const dezyne::locator& dezyne_locator)
: dzn_meta{"","MotionTriggeredCameraSystem",0,{&mtc.dzn_meta,&cam.dzn_meta,&sens.dzn_meta,&tim.dzn_meta},{}}
, dzn_rt(dezyne_locator.get<dezyne::runtime>())
, mtc(dezyne_locator)
, cam(dezyne_locator)
, sens(dezyne_locator)
, tim(dezyne_locator)
, theMotionCam(mtc.motionTriggeredCam)
, input(sens.inputSignal)
, output(sens.outputSignal)
{
  mtc.dzn_meta.parent = &dzn_meta;
  mtc.dzn_meta.name = "mtc";
  cam.dzn_meta.parent = &dzn_meta;
  cam.dzn_meta.name = "cam";
  sens.dzn_meta.parent = &dzn_meta;
  sens.dzn_meta.name = "sens";
  tim.dzn_meta.parent = &dzn_meta;
  tim.dzn_meta.name = "tim";
  connect(cam.camera, mtc.camera);
  connect(sens.pirSensor, mtc.sensor);
  connect(tim.port, cam.timer);
}

void MotionTriggeredCameraSystem::check_bindings() const
{
  dezyne::check_bindings(&dzn_meta);
}
void MotionTriggeredCameraSystem::dump_tree(std::ostream& os) const
{
  dezyne::dump_tree(os, &dzn_meta);
}

