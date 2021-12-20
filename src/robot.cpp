#include <RBE1001Lib.h>
//#include "IRdecoder.h"
#include "robot.h"
// a file to define functions initRobot for setup and those included in main loop to be included in main cpp file

Robot::Robot() : left_motor(MOTOR_LEFT_PWM, MOTOR_LEFT_DIR, MOTOR_LEFT_ENCA, MOTOR_LEFT_ENCB), right_motor(MOTOR_RIGHT_PWM, MOTOR_RIGHT_DIR, MOTOR_RIGHT_ENCA, MOTOR_RIGHT_ENCB)
{
}
//IRDecoder::IRDecoder(uint8_t pin) : irPin(pin) {}
void Robot::initRobot()
{

  // wheelmotor setup
  left_motor.attach();
  right_motor.attach();

  // servo stuff
  ESP32PWM::allocateTimer(1);
  lifter.attach(SERVO_PIN);
  servoPositionFeedback.attach(SERVO_FEEDBACK_SENSOR);

  // blue motor
  // pinMode(PWMA, OUTPUT);
  // pinMode(AIN2, OUTPUT);
  // pinMode(AIN1, OUTPUT);

  //ir detector stuff
  //decoder.init();

  //ultrasonic stuff
  ultrasonic.attach(SIDE_ULTRASONIC_TRIG, SIDE_ULTRASONIC_ECHO);
}
//functions for driving

// bring motors to 0
void Robot::wheelStop()
{
  left_motor.setSpeed(0);
  right_motor.setSpeed(0);
}

// wheelmotor 60deg/sec
void Robot::startDriving()
{
  left_motor.setSpeed(60);
  right_motor.setSpeed(60);
}
// void Robot::driveFor(){
//   left_motor.startMoveFor(500, 60);
//   right_motor.startMoveFor(500, 60);
//}

// turn around
void Robot::uTurn()
{
  left_motor.setSpeed(-30);
  right_motor.setSpeed(30);
  if (right_motor.getCurrentDegrees() - prevDegreesRight >= turn180)
  {
    wheelStop();
  }
}

// Fourbar up
// void Robot::blueMotorUp()
// {
//   digitalWrite(AIN1, HIGH);
//   digitalWrite(AIN2, LOW);
//   digitalWrite(PWMA, HIGH);
// }

// // Fourbar Down
// void Robot::blueMotorDown()
// {
//   digitalWrite(AIN1, LOW);
//   digitalWrite(AIN2, HIGH);
//   digitalWrite(PWMA, HIGH);
// }

// close gripper
void Robot::closeGripper()
{
  lifter.write(lower);
} 

// open gripper
void Robot::openGripper()
{
  lifter.write(raise);
}

// stop driving fourbar by writing pwma low
//void Robot::blueMotorStop() { digitalWrite(PWMA, LOW); }

// void Robot::getKeyCode(){
//   int16_t keyPress = decoder.getKeyCode();
//   if(keyPress >= 0) Serial.println("Key: " + String(keyPress)); 
//}
//ultrasonic get distance

// float Robot::ultrasonicGetDistance(){
  
//   if (distance = ultrasonic.getDistanceCM()>=5)
//   {
//     delay(1000);
//       return distance;
//   Serial.print(distance);
//   }
// }
