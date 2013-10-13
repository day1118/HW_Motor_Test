/*
  Hockey Warrior - Encoder Test
  Tests the Encoder Sensors & prints the results. Can also run the motors.
 */
 
  #include "config.h"
  #include <Servo.h> 

  #define MOTOR_L_ENABLE_ON
  #define MOTOR_R_ENABLE_ON
  #define MOTOR_B_ENABLE_ON

  #define MOTOR_L_SPEED     180
  #define MOTOR_R_SPEED     180
  #define MOTOR_B_SPEED     200

  #define MOTOR_L_FORWARDS    true
  #define MOTOR_R_FORWARDS    true
  #define MOTOR_B_FORWARDS    true 
 
Servo servoF;  // create servo object to control a servo 
Servo servoB;
Servo servoK;

int servoFPos;
int servoBPos;
int servoKPos;

int servoState = 0;
int delayTime = 1000;


void setup() {
	// Set IR pins as outputs
  
  #ifdef MOTOR_L_ENABLE_ON
    pinMode(MOTOR_L_A_PIN, OUTPUT);
    pinMode(MOTOR_L_B_PIN, OUTPUT);  
    pinMode(MOTOR_L_ENABLE_PIN, OUTPUT);

    digitalWrite(MOTOR_L_A_PIN, MOTOR_L_FORWARDS);
    digitalWrite(MOTOR_L_B_PIN, !MOTOR_L_FORWARDS);
    analogWrite(MOTOR_L_ENABLE_PIN, MOTOR_L_SPEED);
  #endif

#ifdef MOTOR_R_ENABLE_ON
    pinMode(MOTOR_R_A_PIN, OUTPUT);
    pinMode(MOTOR_R_B_PIN, OUTPUT);  
    pinMode(MOTOR_R_ENABLE_PIN, OUTPUT);

    digitalWrite(MOTOR_R_A_PIN, MOTOR_R_FORWARDS);
    digitalWrite(MOTOR_R_B_PIN, !MOTOR_R_FORWARDS);
    analogWrite(MOTOR_R_ENABLE_PIN, MOTOR_R_SPEED);
  #endif

  #ifdef MOTOR_B_ENABLE_ON
    pinMode(MOTOR_B_A_PIN, OUTPUT);
    pinMode(MOTOR_B_B_PIN, OUTPUT);  
    pinMode(MOTOR_B_ENABLE_PIN, OUTPUT);

    digitalWrite(MOTOR_B_A_PIN, MOTOR_B_FORWARDS);
    digitalWrite(MOTOR_B_B_PIN, !MOTOR_B_FORWARDS);
    analogWrite(MOTOR_B_ENABLE_PIN, MOTOR_B_SPEED);
  #endif

  servoF.attach(SERVO_FRONT_PIN, SERVO_FRONT_MIN_PWM, SERVO_FRONT_MAX_PWM);  // attaches the servo on pin 9 to the servo object 
  servoB.attach(SERVO_BACK_PIN, SERVO_BACK_MIN_PWM, SERVO_BACK_MAX_PWM);
  servoK.attach(SERVO_KICK_PIN, SERVO_KICK_MIN_PWM, SERVO_KICK_MAX_PWM);


  Serial.begin(115200);      // open the serial port at 9600 bps:

  DEBUG_PRINT("Starting...");
}

void loop() {
  PLOT("servoState", servoState);

   switch(servoState)
   {
     case 0:
      servoFPos = SERVO_FRONT_UP;
      servoBPos = SERVO_BACK_UP;
      servoKPos = SERVO_KICK_UP;
      break;
     case 1:
      servoFPos = SERVO_FRONT_UP;
      servoBPos = SERVO_BACK_UP;
      servoKPos = SERVO_KICK_DOWN;
      break;
     case 2:
      servoFPos = SERVO_FRONT_UP;
      servoBPos = SERVO_BACK_UP;
      servoKPos = SERVO_KICK_UP;
      break;
     case 3:
      servoFPos = SERVO_FRONT_DOWN;
      servoBPos = SERVO_BACK_UP;
      servoKPos = SERVO_KICK_UP;
      break;
     case 4:
      servoFPos = SERVO_FRONT_UP;
      servoBPos = SERVO_BACK_UP;
      servoKPos = SERVO_KICK_UP;
      break;
     case 5:
      servoFPos = SERVO_FRONT_UP;
      servoBPos = SERVO_BACK_DOWN;
      servoKPos = SERVO_KICK_UP;
      break;
   }

    servoF.write(servoFPos);
    servoB.write(servoBPos);
    servoK.write(servoKPos);

   PLOT("servoFPos", servoFPos);
   PLOT("servoBPos", servoBPos);
   PLOT("servoKPos", servoKPos);

   servoState++;
   if(servoState > 5)
     servoState = 0;

    delay(delayTime);
}
