#include "PIN_OUT.h"
#include "Manual_Mode.h"

#define DELAY 100
#define MIN 0 // min value of speed
#define MAX 1 // max value of speed

int pwm_value;

void setup() {

   Serial.begin(9600); // BEGINNING COMUNICATION RATE: 9600 bit/s
  
  /*
   * ALL OF THIS PINS ARE DIGITAL
   */
  // FOR SERIAL COMUNICATION
   pinMode(TX,INPUT);
   pinMode(RX,OUTPUT);
   
  // H BRIDGE PIN 
   pinMode(STANDBY_R,OUTPUT);
   pinMode(STANDBY_L,OUTPUT);
   
  // ALL THE PINS TO MOVE THE ENGINS ARE IN OUTPUT MODE

  // SET OF PINS FOR PWM TO SET SPEED FROM
   pinMode(PWM_F_R,OUTPUT);
   pinMode(PWM_F_L,OUTPUT);
   pinMode(PWM_B_R,OUTPUT);
   pinMode(PWM_B_L,OUTPUT);
  
  //THIS IS A SET TO INDICATE AND ENABLE THE ENGINES DIRECTION OF ROTATION
   pinMode(CLKW_F_R,OUTPUT);
   pinMode(ACLKW_F_R,OUTPUT);
   pinMode(CLKW_F_L,OUTPUT);
   pinMode(ACLKW_F_L,OUTPUT);
   pinMode(CLKW_B_R,OUTPUT);
   pinMode(ACLKW_B_R,OUTPUT);
   pinMode(CLKW_B_L,OUTPUT);
   pinMode(ACLKW_B_L,OUTPUT);
  
  
   /*
   * ALL OF THIS PINS ARE ANALOG
   */
}


void loop() {
  
  go_forward_man(0.5);

}
