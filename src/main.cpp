/*Daniel Perno RBE2001 Final Project*/

#include <Arduino.h>
#include <IRdecoder.h>
#include <RBE1001Lib.h>
#include "robot.h"

Robot robot;

//start everything
void setup() {
  Serial.begin(115200);
  robot.initRobot();
}

//main loop
void loop(){

  //robot.wheelStop();
  //delay(2000);

  //robot.startDriving();
  //delay(2000);

  //robot.wheelStop();
  //delay(2000);

  //robot.openGripper();
  //delay(1000);
  robot.startDriving();
  //robot.uTurn();
  delay(1000);
  //robot.blueMotorUp();
  //delay(1000);
  //robot.closeGripper();
  //delay(1000);
  //robot.startDriving();
  //delay(2000);

  robot.blueMotorStop();
  delay(1000);
  robot.wheelStop();
  delay(2000);
  //robot.blueMotorDown();
  //delay(1000);

  //robot.blueMotorStop();
  //delay(2000);

  //robot.lifter.write(90);
}