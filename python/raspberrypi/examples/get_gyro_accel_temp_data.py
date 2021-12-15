# -*- coding:utf-8 -*-
'''! 
  @file get_gyro_accel_temp_data.py
  @brief Get temperature, gyroscope and accelerometer data
  @n Experimental phenomenon: get data once every second
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      [yangfeng]<feng.yang@dfrobot.com>
  @version  V1.0
  @date  2021-05-13
  @url https://github.com/DFRobot/DFRobot_ICM42688
'''
import sys
sys.path.append("../") # set system path to top
import time
from DFRobot_ICM42688 import *
#Use I2C for communication
'''
  #Device I2C address is decided by SDO, SDO pull up, address is 0x69, SDO pull down, address is 0x68 (SDO default to internal pull up)
  #DFRobot_ICM42688_I2C_L_ADDR 0x68 
  #DFRobot_ICM42688_I2C_H_ADDR 0x69
'''
#ICM42688 = DFRobot_ICM42688_I2C(i2c_addr = DFRobot_ICM42688_I2C_H_ADDR)


#Use SPI for communication
RASPBERRY_PIN_CS =  27              #Chip selection pin when SPI is selected, BCM code mode, the code number is 27, corresponding to pin GPIO2
ICM42688 = DFRobot_ICM42688_SPI(RASPBERRY_PIN_CS)

def setup():
  ret = ICM42688.begin()
  while(ret !=0):
    if(ret == -1):
      print("bus data access error")
    else:
      print("Chip versions do not match")
    time.sleep(1)
    ret = ICM42688.begin()

  print("ICM42688 begin success!!!")
  '''
    Set ODR and Full-scale range of gyroscope or accelerometer
    who  GYRO/ACCEL/ALL
         GYRO: indicate only set gyroscope
         ACCEL: indicate only set accelerometer
    ODR Output data rate
        ODR_32KHZ         Support: Gyro/Accel(LN mode)
        ODR_16KHZ         Support: Gyro/Accel(LN mode)
        ODR_8KHZ          Support: Gyro/Accel(LN mode)
        ODR_4KHZ          Support: Gyro/Accel(LN mode)
        ODR_2KHZ          Support: Gyro/Accel(LN mode)
        ODR_1KHZ          Support: Gyro/Accel(LN mode)
        ODR_200HZ         Support: Gyro/Accel(LP or LN mode)
        ODR_100HZ         Support: Gyro/Accel(LP or LN mode)
        ODR_50HZ          Support: Gyro/Accel(LP or LN mode)
        ODR_25KHZ         Support: Gyro/Accel(LP or LN mode)
        ODR_12_5KHZ       Support: Gyro/Accel(LP or LN mode)
        ODR_6_25KHZ       Support: Accel(LP mode)
        ODR_3_125HZ       Support: Accel(LP mode)
        ODR_1_5625HZ      Support: Accel(LP mode)
        ODR_500HZ         Support: Accel(LP or LN mode)
    FSR Full-scale range
        FSR_0      Gyro:±2000dps   /   Accel: ±16g
        FSR_1      Gyro:±1000dps   /   Accel: ±8g
        FSR_2      Gyro:±500dps    /   Accel: ±4g
        FSR_3      Gyro:±250dps    /   Accel: ±2g
        FSR_4      Gyro:±125dps    /   Accel: not optional
        FSR_5      Gyro:±62.5dps   /   Accel: not optional
        FSR_6      Gyro:±31.25dps  /   Accel: not optional
        FSR_7      Gyro:±15.625dps /   Accel: not optional
    Return True indicate the setting succeed, Flase indicate selected parameter is wrong
  '''
  while(ICM42688.set_ODR_and_FSR(ICM42688.GYRO,ICM42688.ODR_1KHZ,ICM42688.FSR_0)==False):
    print("Incorrect parameter passed in")
  while(ICM42688.set_ODR_and_FSR(ICM42688.ACCEL,ICM42688.ODR_1KHZ,ICM42688.FSR_0) == False):
    print("Incorrect parameter passed in")

  '''
    Set gyroscope and accelerometer working mode and start measurement
    mode 
         OFF_MODE   0              Disable
         STANDBY_MODE_ONLY_GYRO 1  Set stanby mode, only support gyroscope
         LP_MODE_ONLY_ACCEL  2     Set low-power mode, only support accelerometer
         LN_MODE  3                Set low-noise mode
    NOte: The accelerometer needs to be set to work in a mode compatible with the ODR. The gyroscope does not have low power mode.
  '''
  ICM42688.start_gyro_measure(mode =ICM42688.LN_MODE)
  ICM42688.start_accel_measure(mode = ICM42688.LN_MODE)
  #Start temperature measurement
  ICM42688.start_temp_measure()

def loop():
  '''
    Get temperature, accelerometer and gyroscope data
    Two methods of data acquisition:
    Obtain all measurement data at one time, which can effectively shorten communication time
    Single measurement data acquisition, only get the data you need
  '''
  measure_data = ICM42688.get_all_measure_data()
  print("===========================================")
  print("Temperature: = %f C"%(measure_data[0]))
  print("Accel_X: = %f mg"%(measure_data[1]))
  print("Accel_Y: = %f mg"%(measure_data[2]))
  print("Accel_Z: = %f mg"%(measure_data[3]))
  print("Gyro_X: = %f dps"%(measure_data[4]))
  print("Gyro_Y: = %f dps"%(measure_data[5]))
  print("Gyro_Z: = %f dps"%(measure_data[6]))
  time.sleep(1)

  temp_data= ICM42688.get_temperature()
  accel_data_x = ICM42688.get_accel_x()
  accel_data_y= ICM42688.get_accel_y()
  accel_data_z= ICM42688.get_accel_z()
  gyro_data_x= ICM42688.get_gyro_x()
  gyro_data_y= ICM42688.get_gyro_y()
  gyro_data_z= ICM42688.get_gyro_z()
  print("===========================================")
  print("Temperature: = %f C"%(temp_data))
  print("Accel_X: = %f mg"%(accel_data_x))
  print("Accel_Y: = %f mg"%(accel_data_y))
  print("Accel_Z: = %f mg"%(accel_data_z))
  print("Gyro_X: = %f dps"%(gyro_data_x))
  print("Gyro_Y: = %f dps"%(gyro_data_y))
  print("Gyro_Z: = %f dps"%(gyro_data_z))
  time.sleep(1)

if __name__ == "__main__":
  setup()
  while True:
    loop()
