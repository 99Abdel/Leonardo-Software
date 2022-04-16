/*
 * PIN ATMEGA 1284P
 */

/*
 * Tutti i pin sono definiti con il numero dell'atmega non con il numero ordinaro
 * di pin quindi serve usare la libreria con il numero come la GPIO di rapberry.
 * accanto ho messo il numero ordinato di pin
 */
  
#define TX 0 //INPUT SERIAL 1
#define RX 1 //OUTPUT SERIAL 2

#define SONAR1 8  // RIGHT SONAR 24
#define SONAR2 9  // CENTRAL SONAR 25
#define SONAR3 10 // LEFT SONAR 26

// PINS TO ACTIVATE THE H BRIDGE
#define STANDBY_R 2 // RIGHT H BRIDGE PIN OF ACTIVATION
#define STANDBY_L 5 // LEFT H BRIDGE PIN OF ACTIVATION

// ALL THE PINS STRUCTURE FOR THE MOVEMENT MODE FOR DC MOTORS

#define PWM_F_R 3  // PWM FRONT RIGHT MOTOR
#define PWM_F_L 4  // PWM FRONT LEFT MOTOR
#define PWM_B_R 6  // PWM BACK RIGHT MOTOR
#define PWM_B_L 7  // PWM BACK LEFT MOTOR


#define CLKW_F_R  16 // CLOKWISE PIN FRONT RIGHT MOTOR
#define ACLKW_F_R 17 // ANTICLOKWISE PIN FRONT RIGHT MOTOR

#define CLKW_F_L  18 // CLOCKWISE PIN FRONT LEFT MOTOR
#define ACLKW_F_L 19 // ANTICLOCKWISE PIN FRONT LEFT MOTOR

#define CLKW_B_R  20 // CLOKWISE PIN BACK RIGHT MOTOR
#define ACLKW_B_R 21 // ANTICLOKWISE PIN BACK RIGHT MOTOR

#define CLKW_B_L  22 // CLOCKWISE PIN BACK LEFT MOTOR
#define ACLKW_B_L 23 // ANTICLOCKWISE PIN BACK LEFT MOTOR



// ALL THE PINS STRUCTURE FOR THE MOVEMENT MODE FOR STEPPER MOTORS

#define PWM_F 12  // PWM FRONT UPLIFT MOTOR
#define PWM_C 13  // PWM CENTRE UPLIFT MOTOR
#define PWM_B 14  // PWM BACK UPLIFT MOTOR
#define PWM_CG 15 // PWM BARICENTRIC MOTOR
