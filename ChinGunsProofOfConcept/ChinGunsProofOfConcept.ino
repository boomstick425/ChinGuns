#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

void setup() {
  // put your setup code here, to run once:
  
  AFMS.begin();
  
  run_motor(40, FORWARD);
    
  delay(10000);
  
  run_motor(0, FORWARD);  

}


void loop() {
  // put your main code here, to run repeatedly:
  
}


void run_motor(uint8_t motor_speed, uint8_t motor_direction){
  
  if(motor_speed >= 0 && motor_speed <= 255){
    
      myMotor->setSpeed(motor_speed); 

      switch(motor_direction){
        case FORWARD :
          myMotor->run(FORWARD);
          break;
        case BACKWARD :
          myMotor->run(BACKWARD);
          break;
        case BRAKE :
          myMotor->run(BRAKE);
          break;
        case RELEASE :
          myMotor->run(RELEASE);
          break;      
      }    
  
  }   
   
}

