/*
  Hockey Warrior - Encoder Test
  Tests the Encoder Sensors & prints the results. Can also run the motors.
 */
 
  #include "config.h"

  #define MOTOR_L_ENABLE_ON
  #define MOTOR_R_ENABLE_ON
  #define MOTOR_B_ENABLE_ON

  #define MOTOR_L_SPEED     180
  #define MOTOR_R_SPEED     180
  #define MOTOR_B_SPEED     200

  #define MOTOR_L_FORWARDS    true
  #define MOTOR_R_FORWARDS    true
  #define MOTOR_B_FORWARDS    true 

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

  Serial.begin(115200);      // open the serial port at 9600 bps:

  DEBUG_PRINT("Starting...");
}

void loop() {
	delay(1);
}
