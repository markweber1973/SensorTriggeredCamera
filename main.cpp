#include <stdio.h>

#include <iostream>
#include "runtime.hh"
#include "locator.hh"
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

#include "MotionTriggeredCameraSystem.hh"
#include "IPIRSensor.hh"
#include "IIRLED.hh"
#include "IOutput.hh"
 
void sigterm(int signum) { std::cout << "sigterm"; }

typedef void function_t( void ) ;

std::shared_ptr<MotionTriggeredCameraSystem> motionTriggeredCameraSystem;

void wPiTriggered(void) 
{ 
  std::cout << "wPiTriggered"; 
  motionTriggeredCameraSystem->cPIRSensor.inputSignal.out.triggered();
}


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void TakePicture()
{
  std::cout << "Start TakePicture" << std::endl;  
  
  std::string raspiString;
  
  std::ostringstream stringStream;
  stringStream << "raspistill -o /home/pi/stills/" << currentDateTime() << ".jpg";
  system(stringStream.str().c_str()); 
  std::cout << "End TakePicture" << std::endl;    
}

void wPiWriteOutput(int pin, int value)
{
  std::cout << "Start wPiWriteOutput pin: " << pin << " value: " << value << std::endl;    
  digitalWrite(pin, value);
  std::cout << "End wPiWriteOutput" << std::endl;    
}

int main(int argc, char **argv)
{
  std::cout << "START" << std::endl;  
  
  dezyne::locator loc;
  dezyne::runtime rt;
  loc.set(rt); 
  motionTriggeredCameraSystem = std::make_shared<MotionTriggeredCameraSystem>(loc);

  struct sigaction sigact; 
  memset(&sigact, 0, sizeof(struct sigaction));
  sigact.sa_handler = sigterm; 
  sigaction(SIGTERM, &sigact, NULL);
  
  wiringPiSetup();
  wiringPiISR(11, INT_EDGE_RISING, wPiTriggered);
  pinMode(10, 1); 

  motionTriggeredCameraSystem->cMTC.camera.in.takePicture = []{
    TakePicture();
    motionTriggeredCameraSystem->cMTC.camera.out.pictureReady();
  };  
  
  motionTriggeredCameraSystem->rIOutput.in.write = [=](int pin, int value){
    wPiWriteOutput(pin,value);
  };

  motionTriggeredCameraSystem->cMTC.motionTriggeredCam.in.enable();
  getchar();
  motionTriggeredCameraSystem->cMTC.motionTriggeredCam.in.disable();  
  
  std::cout << "END" << std::endl;    
	return 0;
}