#include "PIN_OUT.h"
#include "Set_Orientation.h"

#define MIN 0 // min value of speed
#define MAX 1 // max value of speed

/*
 * writes the value in all the four pwm pins
 */
void write_pwm(int pwm_value){

  digitalWrite(PWM_F_R,pwm_value);
  digitalWrite(PWM_F_L,pwm_value);
  digitalWrite(PWM_B_L,pwm_value);
  digitalWrite(PWM_B_R,pwm_value);
  
}


/*
 * activates the orientation mode forwaard and calls the function to write the pwm values
 * LEONARDO GOES FORWARD
 */
void go_forward_man(int v){
  int pwm_value;
  turn_off_orientation_mode();
  forward_mode();
  pwm_value = map(v,MIN,MAX,0,255); // the MAP function returns the value in proportion of 
  //the range given in the beginning projected in the secon range
  write_pwm(pwm_value);
  
}


/*
 * activates the orientation mode backward and calls the function to write the pwm values
 * LEONARDO GOES BACKWARD
 */
void go_backward_man(int v){
  int pwm_value;
  turn_off_orientation_mode();
  backward_mode();
  pwm_value = map(v,MIN,MAX,0,255); // the MAP function returns the value in proportion of 
  //the range given in the beginning projected in the secon range
  write_pwm(pwm_value);
  
}


/*
 * activates the orientation mode turn right and calls the function to write the pwm values
 * LEONARDO TURNS RIGHT
 */
void turn_right_man(int v){
  int pwm_value;
  turn_off_orientation_mode();
  turn_right_mode();
  pwm_value = map(v,MIN,MAX,0,255); // the MAP function returns the value in proportion of 
  //the range given in the beginning projected in the secon range
  write_pwm(pwm_value);
  
}


/*
 * activates the orientation mode turn left and calls the function to write the pwm values
 * LEONARDO TURNS LEFT
 */
void turn_left_man(int v){
  int pwm_value;
  turn_off_orientation_mode();
  turn_left_mode();
  pwm_value = map(v,MIN,MAX,0,255); // the MAP function returns the value in proportion of 
  //the range given in the beginning projected in the secon range
  write_pwm(pwm_value);
  
}
