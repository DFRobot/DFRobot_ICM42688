# -*- coding:utf-8 -*-
'''!
  @file wake_on_motion_det.py
  @brief Wake on Motion Detection
  @n Experimental phenomenon: detect motion wake-on event on each axis through interrupt
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @licence     The MIT License (MIT)
  @author      [yangfeng]<feng.yang@dfrobot.com>
  @version  V1.0
  @date  2021-05-13
  @url https://github.com/DFRobot/DFRobot_ICM42688
'''
import sys
sys.path.append("../") # set system path to top
import time
from DFRobot_ICM42688 import *
import RPi.GPIO as GPIO


#Use I2C for communication
'''
  #Device I2C address is decided by SDO, SDO pull up, address is 0x69, SDO pull down, address is 0x68 (SDO default internal pull up)
  #DFRobot_ICM42688_I2C_L_ADDR 0x68 
  #DFRobot_ICM42688_I2C_H_ADDR 0x69
'''
#ICM42688 = DFRobot_ICM42688_I2C(i2c_addr = DFRobot_ICM42688_I2C_H_ADDR)


#Use SPI for communication
RASPBERRY_PIN_CS =  27              #Chip selection pin when SPI is selected, BCM code mode, the code number is 27, corresponding to pin GPIO2
ICM42688 = DFRobot_ICM42688_SPI(RASPBERRY_PIN_CS)

global flag
flag =0

def int_callback(channel):
  global flag
  flag = 1

def setup():
  ret = ICM42688.begin()
  while(ret !=0):
    if(ret == -1):
      print("bus data access error")
    else:
      print("Chip versions do not match")
    time.sleep(1)
    ret = ICM42688.begin()

  print("ICM43688 begin success!!!")
  #Configure IO interface interrupt to be triggered by falling edge
  gpio_int = 26
  GPIO.setmode(GPIO.BCM)
  GPIO.setup(gpio_int, GPIO.IN)
  GPIO.add_event_detect(gpio_int, GPIO.FALLING, callback=int_callback)
  
  '''
    Set interrupt mode
    INT_pin  Interrupt pin : 1 represents using INT1 interrupt pin; 2 represents using INT2 interrupt pin
    INT_mode Set interrupt mode, 1 represents interrupt lock mode (polarity remain unchanged when interrupt triggered, and restore after clearing interrupt); 0 represents pulse mode
    INT_polarity Level polarity output by interrupt, 0 represents interrupt pin polarity is LOW when producing interrupt, 1 represents interrupt pin polarity is HIGH when producing interrupt
    INT_drive_circuit  0 represents Open drain  1 represents Push pull
    Note: Polarity output by sensor interrupt needs to be set in line with the config controller interrupt detection mode above
  '''
  ICM42688.set_INT_mode(INT_pin=1, INT_mode=0, INT_polarity=0, INT_drive_circuit=1)
  # Init motion wake on basic config, basic config of the WOM is same as SWD, directly use ICM42688.wake_on_motion_init()
  ICM42688.wake_on_motion_init()
  '''
    Set motion interrupt wake on threshold of axis accelerometer
    axis
          X_AXIS_WOM
          Y_AXIS_WOM
          Z_AXIS_WOM
          ALL
    threshold  Range(0-255) [WoM thresholds are expressed in fixed “mg” independent of the selected Range [0g : 1g]; Resolution 1g/256=~3.9mg]
   '''
  ICM42688.set_wom_thr(axis=ICM42688.ALL,threshold=98)
  '''
    Enable WOM interrupt of an axis
    axis
          X_AXIS_WOM
          Y_AXIS_WOM
          Z_AXIS_WOM
  '''
  ICM42688.set_wom_interrupt(axis = ICM42688.X_AXIS_WOM|ICM42688.Y_AXIS_WOM|ICM42688.Z_AXIS_WOM)

def loop():
  global flag
  if(flag == 1):
    flag = 0
    '''
       Read interrupt information and clear interrupt
       reg Interrupt information register
           ICM42688_INT_STATUS2    Obtain interrupt information of SMD_INT, WOM_X_INT, WOM_Y_INT and WOM_Z_INT and clear them
           ICM42688_INT_STATUS3    Obtain interrupt information of STEP_DET_INT, STEP_CNT_OVF_INT, TILT_DET_INT, WAKE_INT and TAP_DET_INT and clear them
       Interrupt information, return 0 when no interrupt 
    '''
    status= ICM42688.read_interrupt_status(reg= ICM42688_INT_STATUS2)
    if(status & ICM42688_WOM_X_INT):
      print("X_AXIS_WOM ")
    if(status & ICM42688_WOM_Y_INT):
      print("Y_AXIS_WOM ")
    if(status & ICM42688_WOM_Z_INT):
      print("Z_AXIS_WOM ")

if __name__ == "__main__":
  setup()
  while True:
    loop()
