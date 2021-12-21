/*Daniel Perno RBE2001 Final Project

A program to open gripper, drive forward, sense pickup station, raise blue motor, close gripper, turn 180, drive forward,
detect intersection, turn right, lower blue motor, open gripper*/

#include <Arduino.h>
#include <RBE1001Lib.h>
#include <IRdecoder.h>
#include <RemoteConstants.h>
#include "robot.h"

//instantiate the Robot class with the object robot
Robot robot;

//start everything with initRobot from robot class
void setup() {
  Serial.begin(115200);
  robot.initRobot();
}

//main loop
void loop(){
  robot.mainStateMachine();
  //robot.openGripper();
  //delay(1000);
  //robot.wheelStop();
  //delay(2000);
  //robot.ultrasonicGetDistance();
  //robot.startDriving();
  //delay(4000);
  //robot.getKeyCode();
  //robot.wheelStop();
  //delay(2000);
  //robot.uTurn();
  //delay(1000);
  //robot.blueMotorUp();
  //delay(1000);
  //robot.closeGripper();     
  //delay(1000);
  //robot.startDriving();
  //delay(2000);
  //robot.driveFor();

  //robot.blueMotorStop();
  //delay(1000);
  //robot.wheelStop();
  //delay(2000);
  //robot.blueMotorDown();
  //delay(1000);

  //robot.blueMotorStop();
  //delay(2000);

  //robot.lifter.write(90);
}