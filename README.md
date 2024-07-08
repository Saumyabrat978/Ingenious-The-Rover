## Ingenious: The Rover

Automated path finding and obstacle avoiding rover

## Description

The project is based on the BFS algorithm and utilizes ultrasonic sensors to sense the nearby obstacles.
Here we have used Arduino IDE and library Newping to import ulrasonic functions.The model responds to minimum distance for every direction and control the RPM of the motor.
The rover manages the tilt ,RPM and direction of movement finally reaching to the destination

## Getting Started
Install Arduino IDE and you are good to go
### Dependencies

* Arduino IDE 2.1 or more ,Newping library.
*  Windows 10

### Installing

* Extract the code from the file and execute in IDE 

### Executing program

* Make output to the Arduino board
* after execution of the code and download Newping.h

```
#include <NewPing.h>
NewPing frontSensor(trigPinFront, echoPinFront, 300);  // Max distance: 300 cm
NewPing leftSensor(trigPinLeft, echoPinLeft, 300);
NewPing rightSensor(trigPinRight, echoPinRight, 300);
void setup()
void loop() 
```



## Authors






## Acknowledgments

Inspiration, code snippets, etc.
* [arduino](https://www.arduino.cc)
* [Circuit Digest](https://circuitdigest.com/microcontroller-projects/build-your-own-mars-rover-robot-using-arduino)
