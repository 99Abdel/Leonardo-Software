#!/usr/bin/env python

import RPi.GPIO as GPIO
import time as time


class Motors(object):
   """This class must be instantiated in order to help the user to guide simultaneousli 4 engines at a time
   there are many functions tha can help to move correctly Leonardo"""

   MOTORE_DX1 = 1
   MOTORE_SX1 = 2
   MOTORE_PWM1 = 3

   MOTORE_DX2 = 4
   MOTORE_SX2 = 5
   MOTORE_PWM2 = 6

   MOTORE_DX3 = 7
   MOTORE_SX3 = 8
   MOTORE_PWM3 = 9

   MOTORE_DX4 = 10
   MOTORE_SX4 = 11
   MOTORE_PWM4 = 12

   RADIUS = 0.04

   
   def __init__(self):
      """definizione della funzione (OUT) dei pin e del loro stato iniziale"""
      GPIO.setmode(GPIO.BCM)

      GPIO.setup(MOTORE_PWM1, GPIO.OUT)
      GPIO.setup(MOTORE_DX1, GPIO.OUT)
      GPIO.setup(MOTORE_SX1, GPIO.OUT)

      GPIO.setup(MOTORE_PWM2, GPIO.OUT)
      GPIO.setup(MOTORE_DX2, GPIO.OUT)
      GPIO.setup(MOTORE_SX2, GPIO.OUT)

      GPIO.setup(MOTORE_PWM3, GPIO.OUT)
      GPIO.setup(MOTORE_DX3, GPIO.OUT)
      GPIO.setup(MOTORE_SX3, GPIO.OUT)

      GPIO.setup(MOTORE_PWM4, GPIO.OUT)
      GPIO.setup(MOTORE_DX4, GPIO.OUT)
      GPIO.setup(MOTORE_SX4, GPIO.OUT)

      self.pi_pwm1 = GPIO.PWM(MOTORE_PWM1,100) #create PWM instance with frequency
      self.pi_pwm2 = GPIO.PWM(MOTORE_PWM2,100)
      self.pi_pwm3 = GPIO.PWM(MOTORE_PWM3,100)
      self.pi_pwm4 = GPIO.PWM(MOTORE_PWM4,100)

      self.pi_pwm1.start(0)                    #start PWM of required Duty Cycle 
      self.pi_pwm2.start(0) 
      self.pi_pwm3.start(0) 
      self.pi_pwm4.start(0) 


   def turn_off_forward_config(self):
      """turns off all the engines configuration: forward"""
      GPIO.output(self.MOTORE_SX1,False)
      GPIO.output(self.MOTORE_SX2,False)
      GPIO.output(self.MOTORE_SX3,False)
      GPIO.output(self.MOTORE_SX4,False)


   def turn_off_backward_config(self):
      """turns off all the engines configuration: backward"""
      GPIO.output(self.MOTORE_DX1,False)
      GPIO.output(self.MOTORE_DX2,False)
      GPIO.output(self.MOTORE_DX3,False)
      GPIO.output(self.MOTORE_DX4,False)


   def turn_on_forward_config(self):
      """turns on all the engines configuration: forward"""
      GPIO.output(self.MOTORE_SX1,True)
      GPIO.output(self.MOTORE_SX2,True)
      GPIO.output(self.MOTORE_SX3,True)
      GPIO.output(self.MOTORE_SX4,True)


   def turn_on_backward_config(self):
       """turns on all the engines configuration: backward"""
      GPIO.output(self.MOTORE_DX1,True)
      GPIO.output(self.MOTORE_DX2,True)
      GPIO.output(self.MOTORE_DX3,True)
      GPIO.output(self.MOTORE_DX4,True)


   def right_config(self):
      """engine 1-3 will turn right, engine 2-4 will turn left"""
      GPIO.output(self.MOTORE_DX1,True)
      GPIO.output(self.MOTORE_DX3,True)

      GPIO.output(self.MOTORE_SX2,True)
      GPIO.output(self.MOTORE_SX4,True)


   def left_config(self):
      """engine 1-3 will turn left, engine 2-4 will turn right"""
      GPIO.output(self.MOTORE_SX1,True)
      GPIO.output(self.MOTORE_SX3,True)

      GPIO.output(self.MOTORE_DX2,True)
      GPIO.output(self.MOTORE_DX4,True)


   def turn_off_config(self):
      """turns off all the engines configurations: bakward and forward"""
      self.turn_off_forward_config()
      self.turn_off_backward_config()
      

   def forward_config(self):
      """turns on the forward engines configuration and before it turns off the bakward config"""
      self.turn_off_backward_config()
      self.turn_on_forward_config()
   

   def backward_config(self):
      """turns on the bakward engines configuration and before it turns off the forward config"""
      self.turn_off_forward()
      self.turn_on_backward()


   def engines_inensity(self,duty):
      """ sets the frequency of rotation of the PWM moduler of each engine"""
      self.pi_pwm1.ChangeDutyCycle(duty)
      self.pi_pwm2.ChangeDutyCycle(duty)
      self.pi_pwm3.ChangeDutyCycle(duty)
      self.pi_pwm4.ChangeDutyCycle(duty)      


   def calculate_duty(self,v):
      w = v/RADIUS;
      f = w/(2*3.14)
      return f


   def go_forward(self,v,t):
      duty = self.calculate_duty(v)
      engines_inensity(duty)
      self.forward_config()
      time.sleep(t)
      self.turn_off_config()
      


   def go_backward(self,v,t):
      duty = self.calculate_duty(v)
      engines_inensity(duty)
      self.backward_config()
      time.sleep(t)
      self.turn_off_config()
      


   def turn_right(self,v,t):
      duty = self.calculate_duty(v)
      engines_inensity(duty)
      self.right_config()
      time.sleep(t)
      self.turn_off_config()
      


   def turn_right(self,v,t):
      duty = self.calculate_duty(v)
      engines_inensity(duty)
      self.left_config()
      time.sleep(t)
      self.turn_off_config()
      


   def stop_pwm(self):
      self.pi_pwm1.stop()
      self.pi_pwm2.stop()
      self.pi_pwm3.stop()
      self.pi_pwm4.stop()
   

   def kill_IO(self):
      GPIO.cleanup()










