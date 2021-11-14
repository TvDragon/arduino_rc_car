#include <AFMotor.h>

AF_DCMotor leftMotor(4);  // left motor is on motor 4
AF_DCMotor rightMotor(3); // right motor is on motor 3

char command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void moveForward()
{
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}

void moveBackwards()
{
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
}

void turnLeft()
{
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  leftMotor.run(BACKWARD);
  rightMotor.run(FORWARD);
}

void turnRight()
{
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  leftMotor.run(FORWARD);
  rightMotor.run(BACKWARD);
} 

void Stop()
{
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(0);
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    command = Serial.read();
    Stop();
    switch (command) {
      case 'F':  
        moveForward();
        break;
      case 'B':  
        moveBackwards();
        break;
      case 'L':  
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
    }
  }

}
