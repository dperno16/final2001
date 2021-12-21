#include <Arduino.h>
#include <RBE1001Lib.h>

enum ROBOT_STATE
{
    ROBOT_IDLE,
    ROBOT_ACTIVE,
    ROBOT_LINING,
    ROBOT_TURNING,
    ROBOT_SEARCHING,
    ROBOT_FEASTING,
    UTURN,
    BACKUP,
    RIGHTTURN
};
enum DESTINATION_STATE
{
    PICKUP,
    MIDDLE,
    DROPOFF
};
class Robot
{
public:
    Robot();
    //initial state for robot
    ROBOT_STATE robotState = ROBOT_IDLE;
    DESTINATION_STATE destinationState = PICKUP;

    //driving stuff
    bool returning = false;
    float wheelCircumference = 7 * 3.14;
    float wheelBaseCircumference = 14.7 * 3.14;
    float revolutionsFor360 = wheelBaseCircumference / wheelCircumference;
    float turn90 = revolutionsFor360 * 0.225 * 360;
    float turn180 = revolutionsFor360 * .475 * 360;
    int prevDegreesLeft = 0;
    int prevDegreesRight = 0;
    int setUp = 1;
    bool backedUp = false;

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
    const int PWMA = 5;
    const int AIN1 = 21;
    const int AIN2 = 23;

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

    void mainStateMachine();
    
};