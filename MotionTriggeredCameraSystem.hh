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
#ifndef MOTIONTRIGGEREDCAMERASYSTEM_HH
#define MOTIONTRIGGEREDCAMERASYSTEM_HH

#include <iostream>

#include "MotionTriggeredCam.hh"
#include "IRLED.hh"
#include "PIRSensor.hh"


#include "IMotionTriggeredCam.hh"
#include "IInput.hh"
#include "IOutput.hh"
#include "ICamera.hh"


namespace dezyne
{
  struct locator;
}


struct MotionTriggeredCameraSystem
{
  dezyne::meta dzn_meta;
  dezyne::runtime& dzn_rt;
  MotionTriggeredCam cMTC;
  IRLED cIRLED;
  PIRSensor cPIRSensor;

  IMotionTriggeredCam& pIMotionTriggeredCam;
  ICamera& rICamera;
  IInput& rIInput;
  IOutput& rIOutput;

  MotionTriggeredCameraSystem(const dezyne::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os=std::clog) const;
};

#endif // MOTIONTRIGGEREDCAMERASYSTEM_HH
