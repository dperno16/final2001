#include <Arduino.h>
#include <RBE1001Lib.h>

enum ROBOT_STATE
{
    ROBOT_IDLE,
    ROBOT_ACTIVE,
    ROBOT_LINING,
    ROBOT_TURNING,
    ROBOT_SEARCHING
};

class Robot
{
public:
    Robot();

    ROBOT_STATE robotState = ROBOT_IDLE;
    bool returning = false;
    float wheelCircumference = 7 * 3.14;
    float wheelBaseCircumference = 14.7 * 3.14;
    float revolutionsFor360 = wheelBaseCircumference / wheelCircumference;
    float turn90 = revolutionsFor360 * 0.225 * 360;
    float turn180 = revolutionsFor360 * .475 * 360;
    int prevDegreesLeft = 0;
    int prevDegreesRight = 0;
    int setUp = 1;

    // motor stuff
    Motor left_motor;
    Motor right_motor;

    unsigned long lastTime = 0;
    const unsigned long LINE_FOLLOWING_INTERVAL = 5;
    int baseSpeed = 200; // base speed of 90 degrees/sec

    // Servo Stuff
    Servo lifter;
    ESP32AnalogRead servoPositionFeedback;
    uint16_t lower = 0;
    uint16_t raise = 90;

    // blue motor
    const int PWMA = 5;
    const int AIN1 = 19;
    const int AIN2 = 23;

    void initRobot();
    void wheelStop();
    void startDriving();
    void uTurn();
    void blueMotorDown();
    void blueMotorUp();
    void blueMotorStop();
    void openGripper();
    void closeGripper();
    // void(turn)
};