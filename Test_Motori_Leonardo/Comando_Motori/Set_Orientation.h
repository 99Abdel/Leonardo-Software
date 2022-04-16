#include "PIN_OUT.h"


/*
 * this function turns on the h bridges to enable you to do all the other
 * things
 */
void turn_on_bridges(){
  digitalWrite(STANDBY_R, HIGH);
  digitalWrite(STANDBY_L, HIGH);
}


/*
 * this function turns off the h bridges so you will not be able to 
 * send signals from microcontroller
 */
void turn_off_bridges(){
  digitalWrite(STANDBY_R, LOW);
  digitalWrite(STANDBY_L, LOW);
}


/*
 * this function turns off the modality of the orientation of all the pins
 * remembeer to call this function before calling a setup modality.
 */
void turn_off_orientation_mode(){

  digitalWrite(CLKW_F_R,LOW);
  digitalWrite(CLKW_B_R,LOW);
  digitalWrite(CLKW_F_L,LOW);
  digitalWrite(CLKW_B_L,LOW);
  
  digitalWrite(ACLKW_F_R,LOW);
  digitalWrite(ACLKW_B_R,LOW);
  digitalWrite(ACLKW_F_L,LOW);
  digitalWrite(ACLKW_B_L,LOW);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the clokwise for the left motors and the anticlkwise for the right 
 * engines they have opposite rotation in order to perform a forward move
 */
void forward_mode(){

  digitalWrite(ACLKW_F_R,HIGH);
  digitalWrite(ACLKW_B_R,HIGH);
  
  digitalWrite(CLKW_F_L,HIGH);
  digitalWrite(CLKW_B_L,HIGH);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the anticlokwise for the left motors and the clkwise for the right 
 * engines, they have opposite rotation in order to perform a backward move
 */
void backward_mode(){

  digitalWrite(CLKW_F_R,HIGH);
  digitalWrite(CLKW_B_R,HIGH);
  
  digitalWrite(ACLKW_F_L,HIGH);
  digitalWrite(ACLKW_B_L,HIGH);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the clokwise for the left motors and the clkwise for the right 
 * engines, so they have the same rotation in order to performe a right turn
 */
void turn_right_mode(){

  digitalWrite(CLKW_F_R,HIGH);
  digitalWrite(CLKW_B_R,HIGH);
  digitalWrite(CLKW_F_L,HIGH);
  digitalWrite(CLKW_B_L,HIGH);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the anticlokwise for the left motors and the anticlokwise for the right 
 * engines, so they have the same rotation in order to performe a left turn
 */
void turn_left_mode(){

  digitalWrite(ACLKW_F_R,HIGH);
  digitalWrite(ACLKW_B_R,HIGH);
  digitalWrite(ACLKW_F_L,HIGH);
  digitalWrite(ACLKW_B_L,HIGH);
  
}
