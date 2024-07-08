#include <NewPing.h>

// Define ultrasonic sensor pins
const int trigPinFront = 2;
const int echoPinFront = 3;
const int trigPinLeft = 4;
const int echoPinLeft = 8;
const int trigPinRight = 11;
const int echoPinRight = 7;

// Define motor control pins
const int leftMotorForward = 9;  // Changed to 9 for PWM support
const int leftMotorBackward = 10; // Changed to 10 for PWM support
const int rightMotorForward = 6;  // Changed to 6 for PWM support
const int rightMotorBackward = 5; // Changed to 5 for PWM support

// Define ultrasonic sensor objects
NewPing frontSensor(trigPinFront, echoPinFront, 300);  // Max distance: 300 cm
NewPing leftSensor(trigPinLeft, echoPinLeft, 300);
NewPing rightSensor(trigPinRight, echoPinRight, 300);

void setup() {
  // Initialize motors
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read distances from sensors
  int frontDistance = readDistance(frontSensor);
  int leftDistance = readDistance(leftSensor);
  int rightDistance = readDistance(rightSensor);

  // Print sensor values for debugging
  Serial.print("Front: ");
  Serial.print(frontDistance);
  Serial.print("  Left: ");
  Serial.print(leftDistance);
  Serial.print("  Right: ");
  Serial.println(rightDistance);

  // Make decisions based on sensor values
  if (frontDistance > 20) {
    moveForward();
    // Move right if left<6
    if(leftDistance<7)
    {
        turnRight();
    }
    else if(rightDistance<7){
      turnLeft();
    }
    // Move forward if the front is clear
  } 
  else {
    stopMotors();
    delay(180);
    // Make a 90-degree turn based on the left and right sensor values
    if (leftDistance > rightDistance) {
      // Turn left
      turnLeft();
    } 
    else {
      // Turn right
      turnRight();
    }
  }
}

// Function to read distance from an ultrasonic sensor
int readDistance(NewPing& sensor) {
  delay(50);  // Delay for stability
  return sensor.ping_cm();
}

// Function to move the robot forward with speed control
void moveForward() {
  analogWrite(leftMotorForward, 50);  // Adjust speed as needed
  digitalWrite(leftMotorBackward, LOW);
  analogWrite(rightMotorForward, 54); // Adjust speed as needed
  digitalWrite(rightMotorBackward, LOW);
}

// Function to turn the robot left (90 degrees) with speed control
void turnLeft() {
  digitalWrite(leftMotorForward, LOW);
  analogWrite(leftMotorBackward, 50);  // Adjust speed as needed
  analogWrite(rightMotorForward, 45);  // Adjust speed as needed
  digitalWrite(rightMotorBackward, LOW);

  delay(180);  // Initial delay for starting the turn

  // Run the left turn for an additional duration to complete a 90-degree turn
  delay(180);
  stopMotors();
}

// Function to turn the robot right (90 degrees) with speed control
void turnRight() {
  analogWrite(leftMotorForward, 45);  // Adjust speed as needed
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  analogWrite(rightMotorBackward, 50);  // Adjust speed as needed

  delay(180);  // Initial delay for starting the turn

  // Run the right turn for an additional duration to complete a 90-degree turn
  delay(180);
  stopMotors();
}

// Function to stop the motors
void stopMotors() {
  analogWrite(leftMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(rightMotorBackward, 0);
}
