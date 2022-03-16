#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32
import RPi.GPIO as GPIO
import time as time

MOTORE_DX = 19
MOTORE_SX = 26
MOTORE_PWM = 13

HOLD = 2
PAUSE = 0.5


def orario():
   GPIO.output(MOTORE_SX,False)
   GPIO.output(MOTORE_DX,True)
   


def antiorario():
   GPIO.output(MOTORE_DX,False)
   GPIO.output(MOTORE_SX,True)
   


# inizializzazione del nodo publisher del motore
rospy.init_node('motore_pub')
pub=rospy.Publisher('motor_value',Int32,queue_size = 10)
rate=rospy.Rate(1)
rate.sleep()

count = 0


if __name__ == '__main__':

   # definizione della funzione (IN/OUT) dei pin e del loro stato iniziale
   GPIO.setmode(GPIO.BCM)
   GPIO.setup(MOTORE_PWM, GPIO.OUT)
   GPIO.setup(MOTORE_DX, GPIO.OUT)
   GPIO.setup(MOTORE_SX, GPIO.OUT)

   pi_pwm = GPIO.PWM(MOTORE_PWM,100) #create PWM instance with frequency
   pi_pwm.start(0)                    #start PWM of required Duty Cycle 

   while not rospy.is_shutdown():
   
      orario()

      for duty in range(25,100,5):

         pi_pwm.ChangeDutyCycle(duty) #provide duty cycle in the range 0-100
         GPIO.output(MOTORE_PWM,True)
         pub.publish(duty)
         time.sleep(HOLD)
         GPIO.output(MOTORE_PWM,False)
         

      time.sleep(PAUSE)
    
      antiorario()

      for duty in range(100,25,-5):
         
         pi_pwm.ChangeDutyCycle(duty)
         GPIO.output(MOTORE_PWM,True)
         pub.publish(duty)
         time.sleep(HOLD)
         GPIO.output(MOTORE_PWM,False)


      time.sleep(PAUSE)

   pi_pwm.stop()
   GPIO.cleanup()






