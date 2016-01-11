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
: dzn_meta{"","MotionTriggeredCameraSystem",0,{&cMTC.dzn_meta,&cIRLED.dzn_meta,&cPIRSensor.dzn_meta},{}}
, dzn_rt(dezyne_locator.get<dezyne::runtime>())
, cMTC(dezyne_locator)
, cIRLED(dezyne_locator)
, cPIRSensor(dezyne_locator)
, pIMotionTriggeredCam(cMTC.motionTriggeredCam)
, rICamera(cMTC.camera)
, rIInput(cPIRSensor.inputSignal)
, rIOutput(cIRLED.iOutput)
{
  cMTC.dzn_meta.parent = &dzn_meta;
  cMTC.dzn_meta.name = "cMTC";
  cIRLED.dzn_meta.parent = &dzn_meta;
  cIRLED.dzn_meta.name = "cIRLED";
  cPIRSensor.dzn_meta.parent = &dzn_meta;
  cPIRSensor.dzn_meta.name = "cPIRSensor";
  connect(cPIRSensor.pirSensor, cMTC.sensor);
  connect(cIRLED.irLed, cMTC.led);
}

void MotionTriggeredCameraSystem::check_bindings() const
{
  dezyne::check_bindings(&dzn_meta);
}
void MotionTriggeredCameraSystem::dump_tree(std::ostream& os) const
{
  dezyne::dump_tree(os, &dzn_meta);
}

