#include <Arduino.h>
#include <RBE1001Lib.h>

enum State
{
    IDLE,
    ACTIVE,
    LINING,
    TURNING,
    SEARCHING
};

class Robot
{
public:
    Robot();
    //initial state for robot
    //State robotState = IDLE;

    //driving stuff
    

    //ultrasonic stuff
    bool searching = false;

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
    //const int PWMA = 5;
    //const int AIN1 = 19;
    //const int AIN2 = 23;

    //ir stuff
    //IRDecoder decoder;
    //const uint8_t IR_DETECTOR_PIN = 15;

    //ultrasonic stuff
    Rangefinder ultrasonic;
    float distance;
    bool roadBlock = false;
    bool prevReading = false;
    int targetWheelAngle = 0;
    int prevWheelAngle = 0;
    bool found = false;
    int prevDistance = 70;
    int currentDistance = 70;
    bool firstTime = true;
    int maxReading = 70;
    bool once = true;

    void initRobot();
    void wheelStop();
    void startDriving();
    void uTurn();
    void blueMotorDown();
    void blueMotorUp();
    void blueMotorStop();
    void openGripper();
    void closeGripper();
    void driveFor();
    void startMoveFor();
    float ultrasonicGetDistance();
    void getKeyCode();
    // void(turn)
};