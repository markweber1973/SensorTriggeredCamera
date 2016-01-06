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
 
void sigterm(int signum) { std::cout << "sigterm"; }
const int pin = 11;

typedef void function_t( void ) ;

//std::shared_ptr<SensorMonitor> mySensorMonitor;

void wPiTriggered(void) 
{ 
  std::cout << "wPiTriggered"; 
//  mySensorMonitor->sensorRequired.out.triggered();      
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
  std::string raspiString;
  
  std::ostringstream stringStream;
  stringStream << "raspistill -o /home/pi/stills/" << currentDateTime() << ".jpg";
  system(stringStream.str().c_str()); 
}

int main(int argc, char **argv)
{
  std::cout << "START" << std::endl;  
  
  dezyne::locator loc;
  dezyne::runtime rt;
  loc.set(rt); 
//  mySensorMonitor = std::make_shared<SensorMonitor>(loc);

  struct sigaction sigact; 
  memset(&sigact, 0, sizeof(struct sigaction));
  sigact.sa_handler = sigterm; 
  sigaction(SIGTERM, &sigact, NULL);
  
  wiringPiSetup();
  wiringPiISR(pin, INT_EDGE_RISING, wPiTriggered);

/*
  mySensorMonitor->sensorMonitorProvided.out.triggerDetected = []{
    std::cout << "sensorMonitorProvided.out.triggerDetected" << std::endl;
    TakePicture();
  };  

  mySensorMonitor->sensorRequired.in.enable = []{
    std::cout << "sensor enable" << std::endl;
  };  

  mySensorMonitor->sensorRequired.in.disable = []{
    std::cout << "sensor disable" << std::endl;
  };  
  
  mySensorMonitor->sensorMonitorProvided.in.enable();  

  getchar();

  mySensorMonitor->sensorMonitorProvided.in.disable();
  */
  std::cout << "END" << std::endl;    
	return 0;
}