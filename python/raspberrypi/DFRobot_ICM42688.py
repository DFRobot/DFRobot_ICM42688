# -*- coding:utf-8 -*-
'''!
  @file DFRobot_ICM42688.py
  @brief Define basic structure of DFRobot_ICM42688 class, the implementation of basic method.
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      [yangfeng]<feng.yang@dfrobot.com>
  @version  V1.0
  @date  2021-6-9
  @url https://github.com/DFRobot/DFRobot_ICM42688
'''

import sys
import smbus
import logging
import numpy as np
from ctypes import *
import spidev
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

logger = logging.getLogger()
logger.setLevel(logging.INFO)  #Display all the print information
#logger.setLevel(logging.FATAL)#Use this option if you don't want to display too many prints but only printing errors
ph = logging.StreamHandler()
formatter = logging.Formatter("%(asctime)s - [%(filename)s %(funcName)s]:%(lineno)d - %(levelname)s: %(message)s")
ph.setFormatter(formatter) 
logger.addHandler(ph)

DFRobot_ICM42688_I2C_L_ADDR     =0x68 
DFRobot_ICM42688_I2C_H_ADDR     =0x69
DFRobot_ICM42688_ID             =0x47 
ICM42688_DEVICE_CONFIG          =0x11
ICM42688_DRIVE_CONFIG           =0x13
ICM42688_SIGNAL_PATH_RESET      =0x4B
ICM42688_PWR_MGMT0              =0x4E
ICM42688_INT_CONFIG             =0x14
ICM42688_INT_STATUS             =0x2D
ICM42688_INT_STATUS2            =0x37
ICM42688_INT_STATUS3            =0x38
ICM42688_INT_CONFIG0            =0x63
ICM42688_INT_CONFIG1            =0x64
ICM42688_INT_SOURCE0            =0x65
ICM42688_INT_SOURCE1            =0x66
ICM42688_INT_SOURCE3            =0x68
ICM42688_INT_SOURCE4            =0x69
ICM42688_INT_SOURCE6            =0x4D
ICM42688_INT_SOURCE7            =0x4E
ICM42688_INT_SOURCE8            =0x4F
ICM42688_INT_SOURCE9            =0x50
ICM42688_INT_SOURCE10           =0x51
ICM42688_TEMP_DATA1             =0x1D
ICM42688_TEMP_DATA0             =0x1E
ICM42688_ACCEL_DATA_X1          =0x1F
ICM42688_ACCEL_DATA_X0          =0x20
ICM42688_ACCEL_DATA_Y1          =0x21
ICM42688_ACCEL_DATA_Y0          =0x22
ICM42688_ACCEL_DATA_Z1          =0x23
ICM42688_ACCEL_DATA_Z0          =0x24
ICM42688_GYRO_DATA_X1           =0x25
ICM42688_GYRO_DATA_X0           =0x26
ICM42688_GYRO_DATA_Y1           =0x27
ICM42688_GYRO_DATA_Y0           =0x28
ICM42688_GYRO_DATA_Z1           =0x29
ICM42688_GYRO_DATA_Z0           =0x30
ICM42688_TMST_FSYNCH            =0x43
ICM42688_TMST_FSYNCL            =0x44
ICM42688_GYRO_CONFIG_STATIC2    =0x0B
ICM42688_GYRO_CONFIG_STATIC3    =0x0C
ICM42688_GYRO_CONFIG_STATIC4    =0x0D
ICM42688_GYRO_CONFIG_STATIC5    =0x0E
ICM42688_GYRO_CONFIG_STATIC6    =0x0F
ICM42688_GYRO_CONFIG_STATIC7    =0x10
ICM42688_GYRO_CONFIG_STATIC8    =0x11
ICM42688_GYRO_CONFIG_STATIC9    =0x12
ICM42688_GYRO_CONFIG_STATIC10   =0x13
ICM42688_GYRO_CONFIG0           =0x4F
ICM42688_ACCEL_CONFIG0          =0x50
ICM42688_GYRO_CONFIG1           =0x51
ICM42688_GYRO_ACCEL_CONFIG0     =0x52
ICM42688_ACCEL_CONFIG1          =0x53
ICM42688_TMST_CONFIG            =0x54
ICM42688_SMD_CONFIG             =0x57
ICM42688_FIFO_CONFIG            =0x16
ICM42688_FIFO_COUNTH            =0x2E
ICM42688_FIFO_COUNTL            =0x2F
ICM42688_FIFO_DATA              =0x30
ICM42688_FIFO_CONFIG1           =0x5F
ICM42688_FIFO_CONFIG2           =0x60
ICM42688_FIFO_CONFIG3           =0x61
ICM42688_FIFO_LOST_PKT0         =0x6C
ICM42688_FIFO_LOST_PKT1         =0x6D
ICM42688_FSYNC_CONFIG           =0x62
ICM42688_SELF_TEST_CONFIG       =0x70
ICM42688_WHO_AM_I               =0x75
ICM42688_REG_BANK_SEL           =0x76 
ICM42688_SENSOR_CONFIG0         =0x03
ICM42688_XG_ST_DATA             =0x5F
ICM42688_YG_ST_DATA             =0x60
ICM42688_ZG_ST_DATA             =0x61
ICM42688_TMSTVAL0               =0x62
ICM42688_TMSTVAL1               =0x63
ICM42688_TMSTVAL2               =0x64
ICM42688_INTF_CONFIG0           =0x4C
ICM42688_INTF_CONFIG1           =0x4D
ICM42688_INTF_CONFIG4           =0x7A
ICM42688_INTF_CONFIG5           =0x7B
ICM42688_INTF_CONFIG6           =0x7C
ICM42688_ACCEL_CONFIG_STATIC2   =0x03
ICM42688_ACCEL_CONFIG_STATIC3   =0x04
ICM42688_ACCEL_CONFIG_STATIC4   =0x05
ICM42688_XA_ST_DATA             =0x3B
ICM42688_YA_ST_DATA             =0x3C
ICM42688_ZA_ST_DATA             =0x3D
ICM42688_APEX_DATA0             =0x31
ICM42688_APEX_DATA1             =0x32
ICM42688_APEX_DATA2             =0x33
ICM42688_APEX_DATA3             =0x34
ICM42688_APEX_DATA4             =0x35
ICM42688_APEX_DATA5             =0x36
ICM42688_APEX_CONFIG0           =0x56
ICM42688_APEX_CONFIG1           =0x40
ICM42688_APEX_CONFIG2           =0x41
ICM42688_APEX_CONFIG3           =0x42
ICM42688_APEX_CONFIG4           =0x43
ICM42688_APEX_CONFIG5           =0x44
ICM42688_APEX_CONFIG6           =0x45
ICM42688_APEX_CONFIG7           =0x46
ICM42688_APEX_CONFIG8           =0x47
ICM42688_APEX_CONFIG9           =0x48
ICM42688_ACCEL_WOM_X_THR        =0x4A
ICM42688_ACCEL_WOM_Y_THR        =0x4B
ICM42688_ACCEL_WOM_Z_THR        =0x4C
ICM42688_OFFSET_USER0           =0x77
ICM42688_OFFSET_USER1           =0x78
ICM42688_OFFSET_USER2           =0x79
ICM42688_OFFSET_USER3           =0x7A
ICM42688_OFFSET_USER4           =0x7B
ICM42688_OFFSET_USER5           =0x7C
ICM42688_OFFSET_USER6           =0x7D
ICM42688_OFFSET_USER7           =0x7E
ICM42688_OFFSET_USER8           =0x7F
ICM42688_STEP_DET_INT           =1<<5
ICM42688_STEP_CNT_OVF_INT       =1<<4
ICM42688_TILT_DET_INT           =1<<3
ICM42688_WAKE_INT               =1<<2
ICM42688_SLEEP_INT              =1<<1
ICM42688_TAP_DET_INT            =1
ICM42688_SMD_INT                =1<<3
ICM42688_WOM_Z_INT              =1<<2
ICM42688_WOM_Y_INT              =1<<1
ICM42688_WOM_X_INT              =1
ICM42688_STATUS_WALK            =1
ICM42688_STATUS_RUN             =2


class DFRobot_ICM42688(object):


  ERR_OK         =    0      #No error
  ERR_DATA_BUS   =   -1      #Data bus error
  ERR_IC_VERSION =   -2      #The chip version not match

  GYRO    = 0
  ACCEL   = 1
  ALL     = 5

  TMST_DEFAULT_CONFIG_START = 0x23
  TMST_VALUE_DIS            = 0<<4
  TMST_VALUE_EN             = 1<<4
  TMST_RES_EN_DIS           = 0<<3
  TMST_RES_EN               = 1<<3
  TMST_FSYNC_EN             = 1<<1
  TMST_FSYNC_DIS            = 0<<1
  TMST_DELTA_EN             = 0<<2
  TMST_DELTA_DIS            = 1<<2
  TMST_EN                   = 1
  TMST_DIS                  = 0

  X_AXIS  = 0
  Y_AXIS  = 2
  Z_AXIS  = 4

  X_AXIS_WOM  = 1
  Y_AXIS_WOM  = 2
  Z_AXIS_WOM  = 4

  ODR_32KHZ        = 1
  ODR_16KHZ        = 2
  ODR_8KHZ         = 3
  ODR_4KHZ         = 4
  ODR_2KHZ         = 5
  ODR_1KHZ         = 6
  ODR_200HZ        = 7
  ODR_100HZ        = 8
  ODR_50HZ         = 9
  ODR_25KHZ        = 10
  ODR_12_5KHZ      = 11
  ODR_6_25KHZ      = 12
  ODR_3_125HZ      = 13
  ODR_1_5625HZ     = 14
  ODR_500HZ        = 15

  FSR_0            = 0
  FSR_1            = 1
  FSR_2            = 2
  FSR_3            = 3
  FSR_4            = 4
  FSR_5            = 5
  FSR_6            = 6
  FSR_7            = 7

  LP_MODE_ONLY_ACCEL = 2
  LN_MODE  = 3
  STANDBY_MODE_ONLY_GYRO = 1 
  OFF_MODE   = 0

  TAP_SINGLE = 8
  TAP_DOUBLE = 16

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   # |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                           ACCEL_FS_SEL                        |      Reserved      |                                ACCEL_ODR                          |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # ACCEL_FS_SEL :Full scale select for accelerometer UI interface output
   #               000: ±16g (default)
   #               001: ±8g
   #               010: ±4g
   #               011: ±2g
   #               100: Reserved
   #               101: Reserved
   #               110: Reserved
   #               111: Reserved
   # ACCEL_ODR :Accelerometer ODR selection for UI interface output
   #            0000: Reserved
   #            0001: 32kHz (LN mode)
   #            0010: 16kHz (LN mode)
   #            0011: 8kHz (LN mode)
   #            0100: 4kHz (LN mode)
   #            0101: 2kHz (LN mode)
   #            0110: 1kHz (LN mode) (default)
   #            0111: 200Hz (LP or LN mode) 
   #            1000: 100Hz (LP or LN mode)
   #            1001: 50Hz (LP or LN mode)
   #            1010: 25Hz (LP or LN mode)
   #            1011: 12.5Hz (LP or LN mode)
   #            1100: 6.25Hz (LP mode)
   #            1101: 3.125Hz (LP mode)
   #            1110: 1.5625Hz (LP mode)
   #            1111: 500Hz (LP or LN mode)
  '''
  class Accel_config0(Structure):
    _pack_ = 1
    _fields_=[('accel_ODR',c_ubyte,4),
            ('reserved',c_ubyte,1),  
            ('accel_fs_sel',c_ubyte,3)]
    def __init__(self, accel_ODR=6, reserved=0, accel_fs_sel=0):
      self.accel_ODR = accel_ODR
      self.reserved = reserved
      self.accel_fs_sel = accel_fs_sel

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   # |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                    Reserved              |      TEMP_DIS      |        IDLE        |                GYRO_MODE            |           ACCEL_MODE        |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # TEMP_DIS : 0: Temperature sensor is enabled (default)
   #            1: Temperature sensor is disabled
   # IDLE : 0: When the accelerometer and gyroscope are powered off, the chip will enter closure status, because the oscillator power is also cut off
   #        1: RC oscillator will not be powered down even if the accelerometer and gyroscope are powered off
   # GYRO_MODE :00: Turns gyroscope off (default)
   #            01: Places gyroscope in Standby Mode
   #            10: Reserved
   #            11: Places gyroscope in Low Noise (LN) Mode
   #            Enable gyroscope for more than 45ms. When OFF status is switched to other statuses, don't write to any register in 200us.
   # ACCEL_MODE: 00: Turns accelerometer off (default)
   #             01: Turns accelerometer off
   #             10: Places accelerometer in Low Power (LP) Mode
   #             11: Places accelerometer in Low Noise (LN) Mode                
   #             When OFF status is switched to other statuses, don't write to any register in 200us.
  '''
  class Pwrmgmt0(Structure):
    _pack_ = 1
    _fields_=[('accel_mode',c_ubyte,2),
            ('gyro_mode',c_ubyte,2),  
            ('idle',c_ubyte,1),
            ('temp_dis',c_ubyte,1),
            ('reserved',c_ubyte,2)]
    def __init__(self, accel_mode=0, gyro_mode=0, idle=0,temp_dis =0,reserved = 0):
      self.accel_mode = accel_mode
      self.gyro_mode = gyro_mode
      self.idle = idle
      self.temp_dis = temp_dis
      self.reserved = reserved

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   # |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                                       Reserved                                     |  ACCEL_LP_CLK_SEL  |    RTC_MODE    |              CLKSEL         |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # ACCEL_LP_CLK_SEL : 0: Accelerometer LP mode uses Wake Up oscillator clock
   #                    1: Accelerometer LP mode uses RC oscillator clock
   # RTC_MODE : 0: No input RTC clock is required
   #            1: RTC clock input is required
   # CLKSEL : 00: Always select internal RC oscillator
   #          01: Select PLL when available, else select RC oscillator (default)
   #          10: Reserved
   #          11: Disable all clocks
  '''
  class INTF_Config1(Structure):
    _pack_ = 1
    _fields_=[('clksel',c_ubyte,2),
            ('rtc_Mode',c_ubyte,1),  
            ('accel_lp_clk_sel',c_ubyte,1),
            ('reserved',c_ubyte,4)]
    def __init__(self, clksel=1, rtc_Mode=0, accel_lp_clk_sel=0,reserved =9):
      self.clksel = clksel
      self.rtc_Mode = rtc_Mode
      self.accel_lp_clk_sel = accel_lp_clk_sel
      self.reserved = reserved

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   # |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                            Reserved                           |          ACCEL_UI_FILT_ORD              |         ACCEL_DEC2_M2_ORD       |  Reserved  |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # ACCEL_UI_FILT_ORD : Selects order of ACCEL UI filter
   #                     00: 1st Order
   #                     01: 2nd Order
   #                     10: 3rd Order
   #                     11: Reserved
   # ACCEL_DEC2_M2_ORD : Order of Accelerometer DEC2_M2 filter
   #                     00: Reserved
   #                     01: Reserved
   #                     10: 3rd order
   #                     11: Reserved
  '''
  class Accel_config1(Structure):
    _pack_ = 1
    _fields_=[('reserved',c_ubyte,1),
            ('accel_dec2_m2_ORD',c_ubyte,2),  
            ('accel_ui_filt_ORD',c_ubyte,2),
            ('reserved2',c_ubyte,3)]
    def __init__(self, reserved=1, accel_dec2_m2_ORD=2, accel_ui_filt_ORD=1,reserved2 =0):
      self.reserved = reserved
      self.accel_dec2_m2_ORD = accel_dec2_m2_ORD
      self.accel_ui_filt_ORD = accel_ui_filt_ORD
      self.reserved2 = reserved2

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # 
   # -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   # |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                                       ACCEL_UI_FILT_BW                             |                             GYRO_UI_FILT_BW                       |
   # ----------------------------------------------------------------------------------------------------------------------------------------------------------
   # ACCEL_UI_FILT_BW : Bandwidth for Accel LPF
   #                    LN Mode:
   #                       0 BW=ODR/2
   #                       1 BW=max(400Hz, ODR)/4 (default)
   #                       2 BW=max(400Hz, ODR)/5
   #                       3 BW=max(400Hz, ODR)/8
   #                       4 BW=max(400Hz, ODR)/10
   #                       5 BW=max(400Hz, ODR)/16
   #                       6 BW=max(400Hz, ODR)/20
   #                       7 BW=max(400Hz, ODR)/40
   #                       8 to 13: Reserved
   #                       14 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 
   #                       runs at max(400Hz, ODR) 
   #                       15 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 
   #                       runs at max(200Hz, 8*ODR)
   #                     LP Mode:
   #                       0 Reserved
   #                       1 1x AVG filter (default)
   #                       2 to 5 Reserved
   #                       6 16x AVG filter
   #                       7 to 15 Reserved
   # GYRO_UI_FILT_BW :Bandwidth for Gyro LPF
   #                    LN Mode:
   #                     0 BW=ODR/2
   #                     1 BW=max(400Hz, ODR)/4 (default)
   #                     2 BW=max(400Hz, ODR)/5
   #                     3 BW=max(400Hz, ODR)/8
   #                     4 BW=max(400Hz, ODR)/10
   #                     5 BW=max(400Hz, ODR)/16
   #                     6 BW=max(400Hz, ODR)/20
   #                     7 BW=max(400Hz, ODR)/40
   #                     8 to 13: Reserved
   #                     14 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 runs at max(400Hz, ODR) 
   #                     15 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 runs at max(200Hz, 8*ODR)
  '''
  class Gyro_Accel_Config0(Structure):
    _pack_ = 1
    _fields_=[('gyro_ui_filt_BW',c_ubyte,4),
            ('accel_ui_filt_BW',c_ubyte,4)]
    def __init__(self, gyro_ui_filt_BW=1, accel_ui_filt_BW=1):
      self.gyro_ui_filt_BW = gyro_ui_filt_BW
      self.accel_ui_filt_BW = accel_ui_filt_BW

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   # |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   # -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   # |        Reserved      |                   TAP_TMAX                    |                     TAP_TAVG                    |                           TAP_TMIN                           |
   # -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   # TAP_TMAX  Tap measurement window (number of samples) Use default value 01b
   # TAP_TAVG  Tap energy measurement window (number of samples) Use default value 01b
   # TAP_TMIN  Single tap window (number of samples) Use default value 011b
  '''
  class APEX_Config8(Structure):
    _pack_ = 1
    _fields_=[('tap_tmin',c_ubyte,3),
            ('tap_tavg',c_ubyte,2),
            ('tap_tmax',c_ubyte,2),
            ('reserved',c_ubyte,1)]
    def __init__(self, tap_tmin=3, tap_tavg=1, tap_tmax=1, reserved=0):
      self.tap_tmin = tap_tmin
      self.tap_tavg = tap_tavg
      self.tap_tmax = tap_tmax
      self.reserved = reserved

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   # |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   # -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                                                      TAP_MIN_JERK_THR                                                                       |             TAP_MAX_PEAK_TOL            |
   # -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   # TAP_MIN_JERK_THR  Tap Detection minimum jerk threshold. Use default value 010001b
   # TAP_MAX_PEAK_TOL  Tap Detection maximum peak tolerance. Use default value 01b
  '''
  class APEX_Config7(Structure):
    _pack_ = 1
    _fields_=[('tap_max_peak_tol',c_ubyte,2),
            ('tap_min_jerk_thr',c_ubyte,6)]
    def __init__(self, tap_max_peak_tol=1, tap_min_jerk_thr=17):
      self.tap_max_peak_tol = tap_max_peak_tol
      self.tap_min_jerk_thr = tap_min_jerk_thr

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # 
   # 
   # ---------------------------------------------------------------------------------------------------------------------------------------------
   # |    b7    |    b6    |            b5         |          b4         |        b3       |       b2        |         b1       |     b0         |
   # ---------------------------------------------------------------------------------------------------------------------------------------------
   # |      reversed       |    STEP_DET_INT_EN    | STEP_CNT_OFL_INT_EN | TILT_DET_INT_EN | WAKE_DET_INT_EN | SLEEP_DET_INT_EN | TAP_DET_INT_EN |
   # ---------------------------------------------------------------------------------------------------------------------------------------------
  '''
  class INTSource(Structure):
    _pack_ = 1
    _fields_=[('tap_det_int_en',c_ubyte,1),
            ('sleep_det_int_en',c_ubyte,1),  
            ('wake_det_int_en',c_ubyte,1),
            ('tilt_det_int_en',c_ubyte,1),
            ('step_cnt_ofl_int_en',c_ubyte,1),
            ('step_det_int_en',c_ubyte,1),
            ('reserved',c_ubyte,2)]
    def __init__(self, tap_det_int_en=0, sleep_det_int_en=0, wake_det_int_en=0,tilt_det_int_en =0,step_cnt_ofl_int_en = 0,step_det_int_en = 0):
      self.tap_det_int_en = tap_det_int_en
      self.sleep_det_int_en = sleep_det_int_en
      self.wake_det_int_en = wake_det_int_en
      self.tilt_det_int_en = tilt_det_int_en
      self.step_cnt_ofl_int_en = step_cnt_ofl_int_en
      self.step_det_int_en = step_det_int_en
      self.reserved = 0

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # 
   # 
   # ---------------------------------------------------------------------------------------------------------------------------------------------
   # |    b7    |    b6    |            b5         |          b4         |        b3       |       b2        |         b1       |     b0         |
   # ---------------------------------------------------------------------------------------------------------------------------------------------
   # |      reversed       |    STEP_DET_INT_EN    | STEP_CNT_OFL_INT_EN | TILT_DET_INT_EN | WAKE_DET_INT_EN | SLEEP_DET_INT_EN | TAP_DET_INT_EN |
   # ---------------------------------------------------------------------------------------------------------------------------------------------
  '''
  class APEX_Config0(Structure):
    _pack_ = 1
    _fields_=[('dmp_ODR',c_ubyte,2),
            ('reserved',c_ubyte,1),  
            ('R2W_en',c_ubyte,1),
            ('tilt_enable',c_ubyte,1),
            ('PED_enable',c_ubyte,1),
            ('tap_enable',c_ubyte,1),
            ('DMP_power_save',c_ubyte,1)]
    def __init__(self):
      self.dmp_ODR = 0
      self.R2W_en = 0
      self.tilt_enable = 0
      self.PED_enable = 0
      self.tap_enable = 0
      self.DMP_power_save = 1
      self.reserved = 0

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
   # -------------------------------------------------------------------------------------------------------------------------------------- --------------------
   # |            b7        |        b6      |         b5         |         b4         |          b3        |        b2      |       b1        |      b0       |
   # -----------------------------------------------------------------------------------------------------------------------------------------------------------
   # |                                    Reserved                                     |     WOM_INT_MODE   |    WOM_MODE    |             SMD_MODE            |
   # -----------------------------------------------------------------------------------------------------------------------------------------------------------
   # WOM_INT_MODE : (Wake on motion) 0: Set WoM interrupt on the OR of all enabled accelerometer thresholds
   #                          1: Set WoM interrupt on the AND of all enabled accelerometer threshold
   # WOM_MODE 0: Initial sample is stored. Future samples are compared to initial sample.
   #          1: Compare current sample with previous sample
   # SMD_MODE  00: SMD disabled (important motion detector)
   #           01: Reserved
   #           10: SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
   #           11: SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
  '''
  class SMD_Config(Structure):
    _pack_ = 1
    _fields_=[('SMD_mode',c_ubyte,2),
            ('WOM_mode',c_ubyte,1),  
            ('WOM_int_mode',c_ubyte,1),
            ('reserved',c_ubyte,4)]
    def __init__(self):
      self.SMD_mode = 0
      self.WOM_mode = 0
      self.WOM_int_mode = 0
      self.reserved = 0

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))
  # Configure sensor ODR and full-scale range
  class ODR_FSR(Structure):
    _pack_ = 1
    _fields_=[('ODR',c_ubyte,4),
            ('reserved',c_ubyte,1),  
            ('fs_sel',c_ubyte,3)]
    def __init__(self):
      self.ODR = 6
      self.fs_sel = 0
      self.reserved = 0

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))

  '''
  # -------------------------------------------------------------------------------------------------------------------------------
  # |    b7    |    b6    |       b5        |         b4         |       b3      |     b2    |         b1         |    b0         |
  # -------------------------------------------------------------------------------------------------------------------------------
  # |      reversed       |    INT2_MODE    | INT2_DRIVE_CIRCUIT | INT2_POLARITY | INT1_MODE | INT1_DRIVE_CIRCUIT | INT1_POLARITY |
  # -------------------------------------------------------------------------------------------------------------------------------  #  INT2_MODE:INT2 interrupt mode
  #             0: Pulsed mode
  #             1: Latched mode
  # INT2_DRIVE_CIRCUIT:INT2 drive circuit
  #                    0: Open drain
  #                    1: Push pull
  # INT2_POLARITY:INT2 interrupt polarity
  #                    0: Active low (default)
  #                    1: Active high
  # INT1_MODE:INT1 interrupt mode
  #             0: Pulsed mode
  #             1: Latched mode
  # INT1_DRIVE_CIRCUIT:INT1 drive circuit
  #                    0: Open drain
  #                    1: Push pull
  # INT1_POLARITY:INT1 interrupt polarity
  #                    0: Active low (default)
  #                    1: Active high
  '''
  class INT_Config(Structure):
    _pack_ = 1
    _fields_=[('INT1_polarity',c_ubyte,1),
            ('INT1_drive_circuit',c_ubyte,1),  
            ('INT1_mode',c_ubyte,1),
            ('INT1_polarity',c_ubyte,1),
            ('INT2_drive_circuit',c_ubyte,1),  
            ('INT2_mode',c_ubyte,1),
            ('reversed',c_ubyte,2)]
    def __init__(self):
      self.INT1_polarity = 0
      self.INT1_drive_circuit = 0
      self.INT1_mode = 0
      self.INT2_polarity = 0
      self.INT2_drive_circuit = 0
      self.INT2_mode = 0
      self.reversed = 0

    def set_list(self, data):
      buf = (c_ubyte * len(data))()
      for i in range(len(data)):
        buf[i] = data[i]
      memmove(addressof(self), addressof(buf), len(data))

    def get_list(self):
      return list(bytearray(string_at(addressof(self),sizeof(self))))


  def __init__(self):
    self.__gyro_range         = 4000/65535.0
    self.__accel_range        = 0.488
    self.FIFO_mode            = False
    self._Pwrmgmt0            = self.Pwrmgmt0()
    self._INT_Config          = self.INT_Config()
    self._Accel_config0       = self.Accel_config0()
    self._INTF_Config1        = self.INTF_Config1()
    self._Accel_config1       = self.Accel_config1()
    self._Gyro_Accel_Config0  = self.Gyro_Accel_Config0()
    self._APEX_Config8        = self.APEX_Config8()
    self._APEX_Config7        = self.APEX_Config7()
    self._INTSource           = self.INTSource()
    self._APEX_Config0        = self.APEX_Config0()
    self._SMD_Config          = self.SMD_Config()
    self._ODR_FSR             = self.ODR_FSR()
    self._INT_pin = 0

  def begin(self):
    '''!
      @brief   Begin function, detect whether the sensor is normally connected
      @return Init result
      @retval ERR_OK         Init succeed
      @retval ERR_DATA_BUS   Bus data access error
      @retval ERR_IC_VERSION The read sensor ID is wrong
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL,[self.bank])
    id = self.read_reg(ICM42688_WHO_AM_I)
    if id == None :
      logger.warning("ERR_DATA_BUS")
      return self.ERR_DATA_BUS

    logger.info("id=%d"%(id))

    if id != DFRobot_ICM42688_ID:
      return self.ERR_IC_VERSION
    reset = 1
    self.write_reg(ICM42688_DEVICE_CONFIG, [reset])
    time.sleep(0.001)
    return self.ERR_OK

  def get_temperature(self):
    '''!
      @brief   @brief Get measured temperature
      @return Temperature value, unit: ℃
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__temp/2.07 + 25
    else:
      data1 = self.read_reg(ICM42688_TEMP_DATA1)
      data2 = self.read_reg(ICM42688_TEMP_DATA0)
      value = (np.int16((data1)*256 + data2))/132.48 + 25
    return value

  def get_accel_x(self):
    '''!
      @brief Get accelerometer value on X-axis
      @return X-axis accelerometer value, unit: mg
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__accel_x
    else:
      data1 = self.read_reg(ICM42688_ACCEL_DATA_X1)
      data2 = self.read_reg(ICM42688_ACCEL_DATA_X0)
      value = np.int16((data1)*256 + data2)

    return value*self.__accel_range

  def get_accel_y(self):
    '''!
      @brief Get accelerometer value on Y-axis
      @return Y-axis accelerometer value, unit: mg
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__accel_y
    else:
      data1 = self.read_reg(ICM42688_ACCEL_DATA_Y1)
      data2 = self.read_reg(ICM42688_ACCEL_DATA_Y0)
      value = np.int16((data1)*256 + data2)
    return value*self.__accel_range

  def get_accel_z(self):
    '''!
      @brief Get accelerometer value on Z-axis
      @return Z-axis accelerometer value, unit: mg
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__accel_z
    else:
      data1 = self.read_reg(ICM42688_ACCEL_DATA_Z1)
      data2 = self.read_reg(ICM42688_ACCEL_DATA_Z0)
      value = np.int16((data1)*256 + data2)
    return value*self.__accel_range

  def get_gyro_x(self):
    '''!
      @brief Get gyroscope value on X-axis
      @return X-axis gyroscope value, unit: dps
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__gyro_x
    else:
      data1 = self.read_reg(ICM42688_GYRO_DATA_X1)
      data2 = self.read_reg(ICM42688_GYRO_DATA_X1)
      value = np.int16((data1)*256 + data2)
    return value*self.__gyro_range

  def get_gyro_y(self):
    '''!
      @brief Get gyroscope value on Y-axis
      @return Y-axis gyroscope value, unit: dps
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__gyro_y
    else:
      data1 = self.read_reg(ICM42688_GYRO_DATA_Y1)
      data2 = self.read_reg(ICM42688_GYRO_DATA_Y1)
      value = np.int16((data1)*256 + data2)
    return value*self.__gyro_range

  def get_gyro_z(self):
    '''!
      @brief Get gyroscope value on Z-axis
      @return Z-axis gyroscope value, unit: dps
    '''
    value = 0.0
    if(self.FIFO_mode):
      value = self.__gyro_z
    else:
      data1 = self.read_reg(ICM42688_GYRO_DATA_Z1)
      data2 = self.read_reg(ICM42688_GYRO_DATA_Z1)
      value = np.int16((data1)*256 + data2)
    return value*self.__gyro_range

  def tap_detection_init(self,accel_mode):
    '''!
      @brief Tap detection init
      @param accel_mode Accelerometer operating mode
      @n      0 represent operating in low-power mode
      @n      1 represent operating in low-noise mode
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    if(accel_mode == 0):
      self._Accel_config0.accel_ODR = 15
      self.write_reg(ICM42688_ACCEL_CONFIG0, self._Accel_config0.get_list())
      self._Pwrmgmt0.accel_mode = 2
      self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())
      time.sleep(0.001)
      self._INTF_Config1.accel_lp_clk_sel = 0
      self.write_reg(ICM42688_PWR_MGMT0, self._INTF_Config1.get_list())
      self._Accel_config1.accel_ui_filt_ORD = 2
      self.write_reg(ICM42688_ACCEL_CONFIG1, self._Accel_config1.get_list())
      self._Gyro_Accel_Config0.accel_ui_filt_BW = 0
      self.write_reg(ICM42688_GYRO_ACCEL_CONFIG0, self._Gyro_Accel_Config0.get_list())
    elif(accel_mode == 1):
      self._Accel_config0.accel_ODR = 6
      self.write_reg(ICM42688_ACCEL_CONFIG0, self._Accel_config0.get_list())
      self._Pwrmgmt0.accel_mode = 3
      self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())
      time.sleep(0.001)
      self._Accel_config1.accel_ui_filt_ORD = 2
      self.write_reg(ICM42688_ACCEL_CONFIG1, self._Accel_config1.get_list())
      self._Gyro_Accel_Config0.accel_ui_filt_BW = 0
      self.write_reg(ICM42688_GYRO_ACCEL_CONFIG0, self._Gyro_Accel_Config0.get_list())
    else:
      logger.warning("accel_mode invalid !")
      return
    time.sleep(0.001)
    self.bank = 4
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._APEX_Config8.tap_tmin =3
    self._APEX_Config8.tap_tavg =3
    self._APEX_Config8.tap_tmax =2
    self.write_reg(ICM42688_APEX_CONFIG8, self._APEX_Config8.get_list())
    self._APEX_Config7.tap_max_peak_tol = 1
    self._APEX_Config7.tap_min_jerk_thr = 17
    self.write_reg(ICM42688_APEX_CONFIG7, self._APEX_Config7.get_list())
    time.sleep(0.001)
    self._INTSource.tap_det_int_en = 1
    if(self._INT_pin == 1):
      self.write_reg(ICM42688_INT_SOURCE6, self._INTSource.get_list())
    elif(self._INT_pin == 2):
      self.write_reg(ICM42688_INT_SOURCE7, self._INTSource.get_list())
    time.sleep(0.05)
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._APEX_Config0.tap_enable = 1
    self.write_reg(ICM42688_APEX_CONFIG0, self._APEX_Config0.get_list())

  def get_tap_information(self):
    '''!
       @brief Get tap information
    '''
    data = self.read_reg(ICM42688_APEX_DATA4)
    self._tap_num = data & 0x18
    self._tap_axis = data & 0x06
    self._tap_dir = data & 0x01
  

  def number_of_tap(self):
    '''!
      @brief Get the number of tap: single-tap or double tap
      @return The number of tap
      @retval TAP_SINGLE   Single-tap
      @retval TAP_DOUBLE   Double tap
    '''
    return self._tap_num

  def axis_of_tap(self):
    '''!
      @brief Get the axis on which tap occurred: X-axis, Y-axis, or Z-axis
      @return Tap axis
      @retval X_AXIS   X-axis
      @retval Y_AXIS   Y-axis
      @retval Z_AXIS   Z-axis
    '''
    return self._tap_axis

  def wake_on_motion_init(self):
    '''!
      @brief Init wake on motion
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Accel_config0.accel_ODR = 9
    self.write_reg(ICM42688_ACCEL_CONFIG0, self._Accel_config0.get_list())
    self._Pwrmgmt0.accel_mode = 2
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())
    time.sleep(0.001)
    self._INTF_Config1.accel_lp_clk_sel = 0
    self.write_reg(ICM42688_INTF_CONFIG1, self._INTF_Config1.get_list())
    time.sleep(0.001)

  def set_wom_thr(self,axis,threshold):
    '''!
      @brief Set motion interrupt wake on threshold of axis accelerometer
      @param axis x/y/z axis
      @n       X_AXIS_WOM
      @n       Y_AXIS_WOM
      @n       Z_AXIS_WOM
      @n       ALL
      @param threshold  Range(0-255) [WoM thresholds are expressed in fixed “mg” independent of the selected Range [0g : 1g]; Resolution 1g/256=~3.9mg]
    '''
    self.bank = 4
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    if(axis == self.X_AXIS):
      self.write_reg(ICM42688_ACCEL_WOM_X_THR, [threshold])
    elif(axis == self.Y_AXIS):
      self.write_reg(ICM42688_ACCEL_WOM_Y_THR, [threshold])
    elif(axis == self.Z_AXIS):
      self.write_reg(ICM42688_ACCEL_WOM_Z_THR, [threshold])
    elif(axis == self.ALL):
      self.write_reg(ICM42688_ACCEL_WOM_X_THR, [threshold])
      self.write_reg(ICM42688_ACCEL_WOM_Y_THR, [threshold])
      self.write_reg(ICM42688_ACCEL_WOM_Z_THR, [threshold])
    time.sleep(0.001)
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])

  def set_wom_interrupt(self,axis):
    '''!
      @brief Enable wake on interrupt of an axis
      @param axis  x/y/z axis
      @n       X_AXIS_WOM
      @n       Y_AXIS_WOM
      @n       Z_AXIS_WOM
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    if(self._INT_pin == 1):
      self.write_reg(ICM42688_INT_SOURCE1, [axis])
    elif(self._INT_pin == 2):
      self.write_reg(ICM42688_INT_SOURCE4, [axis])
    time.sleep(0.050)
    self._SMD_Config.SMD_mode = 1
    self._SMD_Config.WOM_mode = 1
    self._SMD_Config.WOM_int_mode = 0
    self.write_reg(ICM42688_SMD_CONFIG, self._SMD_Config.get_list())

  def enable_SMD_interrupt(self,mode):
    '''!
      @brief Set important motion detection mode and enable SMD interrupt
      @param mode  
      @n      0: disable SMD
      @n      2 : SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
      @n      3 : SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    INT = 1<<3
    if(self._INT_pin == 1):
      self.write_reg(ICM42688_INT_SOURCE1, [INT])
    elif(self._INT_pin == 2):
      self.write_reg(ICM42688_INT_SOURCE4, [INT])
    time.sleep(0.050)
    self._SMD_Config.SMD_mode = mode
    self._SMD_Config.WOM_mode = 1
    self._SMD_Config.WOM_int_mode = 0
    self.write_reg(ICM42688_SMD_CONFIG, self._SMD_Config.get_list())


  def read_interrupt_status(self,reg):
    '''!
      @brief Read interrupt information and clear interrupt
      @param reg Interrupt information register
      @n         ICM42688_INT_STATUS2    Obtain interrupt information of SMD_INT, WOM_X_INT, WOM_Y_INT and WOM_Z_INT and clear them
      @n         ICM42688_INT_STATUS3    Obtain interrupt information of STEP_DET_INT, STEP_CNT_OVF_INT, TILT_DET_INT, WAKE_INT and TAP_DET_INT and clear them
      @return Interrupt information, return 0 when no interrupt
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    return self.read_reg(reg)

  def set_ODR_and_FSR(self,who,ODR,FSR):
    '''!
      @brief Set ODR and Full-scale range of gyroscope or accelerometer
      @param who  GYRO/ACCEL/ALL
      @n       GYRO: indicate only set gyroscope
      @n       ACCEL: indicate only set accelerometer
      @param ODR Output data rate
      @n       ODR_32KHZ         Support: Gyro/Accel(LN mode)
      @n       ODR_16KHZ         Support: Gyro/Accel(LN mode)
      @n       ODR_8KHZ          Support: Gyro/Accel(LN mode)
      @n       ODR_4KHZ          Support: Gyro/Accel(LN mode)
      @n       ODR_2KHZ          Support: Gyro/Accel(LN mode)
      @n       ODR_1KHZ          Support: Gyro/Accel(LN mode)
      @n       ODR_200HZ         Support: Gyro/Accel(LP or LN mode)
      @n       ODR_100HZ         Support: Gyro/Accel(LP or LN mode)
      @n       ODR_50HZ          Support: Gyro/Accel(LP or LN mode)
      @n       ODR_25KHZ         Support: Gyro/Accel(LP or LN mode)
      @n       ODR_12_5KHZ       Support: Gyro/Accel(LP or LN mode)
      @n       ODR_6_25KHZ       Support: Accel(LP mode)
      @n       ODR_3_125HZ       Support: Accel(LP mode)
      @n       ODR_1_5625HZ      Support: Accel(LP mode)
      @n       ODR_500HZ         Support: Accel(LP or LN mode)
      @param FSR Full-scale range
      @n       FSR_0      Gyro:±2000dps   /   Accel: ±16g
      @n       FSR_1      Gyro:±1000dps   /   Accel: ±8g
      @n       FSR_2      Gyro:±500dps    /   Accel: ±4g
      @n       FSR_3      Gyro:±250dps    /   Accel: ±2g
      @n       FSR_4      Gyro:±125dps    /   Accel: not optional
      @n       FSR_5      Gyro:±62.5dps   /   Accel: not optional
      @n       FSR_6      Gyro:±31.25dps  /   Accel: not optional
      @n       FSR_7      Gyro:±15.625dps /   Accel: not optional
      @return Set result
      @retval True   indicate the setting succeed
      @retval False  indicate selected parameter is wrong
    '''
    ret = True
    _ODR_FSR = self.ODR_FSR()
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    if(who == self.GYRO):
      if(ODR > self.ODR_12_5KHZ or FSR > self.FSR_7):
        ret = False
      else:
        _ODR_FSR.ODR = ODR
        _ODR_FSR.fs_sel = FSR
        self.write_reg(ICM42688_GYRO_CONFIG0, _ODR_FSR.get_list())
        if(FSR == self.FSR_0):
          self.__gyroRange = 4000/65535.0
        elif(FSR == self.FSR_1):
          self.__gyroRange =  2000/65535.0
        elif(FSR == self.FSR_2):
          self.__gyroRange =  1000/65535.0
        elif(FSR == self.FSR_3):
          self.__gyroRange =  500/65535.0
        elif(FSR == self.FSR_4):
          self.__gyroRange =  250/65535.0
        elif(FSR == self.FSR_5):
          self.__gyroRange =  125/65535.0
        elif(FSR == self.FSR_6):
          self.__gyroRange =  62.5/65535.0
        elif(FSR == self.FSR_7):
          self.__gyroRange =  31.25/65535.0
    elif(who == self.ACCEL):
      if(ODR > self.ODR_500HZ or FSR > self.FSR_3):
        ret = False
      else:
        _ODR_FSR.ODR = ODR
        _ODR_FSR.fs_sel = FSR
        self.write_reg(ICM42688_ACCEL_CONFIG0, _ODR_FSR.get_list())
        if(FSR == self.FSR_0):
          self.__gyroRange = 0.488
        elif(FSR == self.FSR_1):
          self.__gyroRange = 0.244
        elif(FSR == self.FSR_2):
          self.__gyroRange = 0.122
        elif(FSR == self.FSR_3):
          self.__gyroRange = 0.061
    return ret

  def _set_FIFO_data_mode(self):
    '''!
      @brief Set FIFO data packet format
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    mode = 7
    self.write_reg(ICM42688_FIFO_CONFIG1, [mode])

  def start_FIFO_mode(self):
    '''!
      @brief Enable FIFO
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    FIFO_mode = True
    self._set_FIFO_data_mode()
    start = 1<<6
    self.write_reg(ICM42688_FIFO_CONFIG, [start])
    

  def get_FIFO_data(self):
    '''!
      @brief Read FIFO data, read temperature, gyroscope and accelerometer data and save them for parsing.
    '''
    data=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    for i in range(0,16):
      data[i] = self.read_reg(ICM42688_FIFO_DATA)
    self.__accel_x = np.int16((data[1])*256 + data[2])
    self.__accel_y = np.int16((data[3])*256 + data[4])
    self.__accel_z = np.int16((data[5])*256 + data[6])
    self.__gyro_x = np.int16((data[7])*256 + data[8])
    self.__gyro_y = np.int16((data[9])*256 + data[10])
    self.__gyro_z = np.int16((data[11])*256 + data[12])
    self.__temp = np.int8(data[13])


  def stop_FIFO_mode(self):
    '''!
      @brief Disable FIFO
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    start = 1<<7
    self.write_reg(ICM42688_FIFO_CONFIG, [start])


  def set_INT_mode(self,INT_pin,INT_mode,INT_polarity,INT_drive_circuit):
    '''!
      @brief Set interrupt mode
      @param INT_pin  Interrupt pin 
      @n       1  Use INT1 interrupt pin
      @n       2  Use INT2 interrupt pin
      @param INT_mode Set interrupt mode
      @n       1  Interrupt lock mode (polarity remain unchanged when interrupt triggered, and restore after clearing interrupt)
      @n       0  Pulse mode
      @param INT_polarity Level polarity output by interrupt
      @n       0  Interrupt pin polarity is LOW when producing interrupt
      @n       1  Interrupt pin polarity is HIGH when producing interrupt
      @param INT_drive_circuit  
      @n       0  Open drain
      @n       1  Push pull
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    if(INT_pin == 1):
      self._INT_pin = 1
      self._INT_Config.INT1_polarity = INT_polarity
      self._INT_Config.INT1_drive_circuit =INT_drive_circuit
      self._INT_Config.INT1_mode = INT_mode
    elif(INT_pin == 2):
      self._INT_pin = 2
      self._INT_Config.INT2_polarity = INT_polarity
      self._INT_Config.INT2_drive_circuit =INT_drive_circuit
      self._INT_Config.INT2_mode = INT_mode
    self.write_reg(ICM42688_INT_CONFIG, self._INT_Config.get_list())

  def start_temp_measure(self):
    '''!
      @brief Start thermometer
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Pwrmgmt0.tempDis = 0
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())

  def start_gyro_measure(self,mode):
    '''!
    ' @brief Start gyroscope
    ' @param mode Set gyroscope working mode
    ' @n          STANDBY_MODE_ONLY_GYRO 1  Set stanby mode, only support gyroscope
    ' @n          LN_MODE  3                Set low-noise mode
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Pwrmgmt0.gyro_mode = mode
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())
  

  def start_accel_measure(self,mode):
    '''!
      @brief Start accelerometer
      @param mode Set accelerometer working mode
      @n          LP_MODE_ONLY_ACCEL  2     Set low-power mode, only support accelerometer
      @n          LN_MODE  3                Set low-noise mode
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Pwrmgmt0.accel_mode = mode
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())

  def stop_temp_measure(self):
    '''!
      @brief Stop temperature measurement
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Pwrmgmt0.tempDis = 1
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())


  def stop_gyro_measure(self):
    '''!
      @brief Stop gyroscope
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Pwrmgmt0.gyro_mode = 0
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())
    time.sleep(0.001)


  def stop_accel_measure(self):
    '''!
      @brief Stop accelerometer
    '''
    self.bank = 0
    self.write_reg(ICM42688_REG_BANK_SEL, [self.bank])
    self._Pwrmgmt0.accel_mode = 0
    self.write_reg(ICM42688_PWR_MGMT0, self._Pwrmgmt0.get_list())
    time.sleep(0.001)


class DFRobot_ICM42688_I2C(DFRobot_ICM42688):
  def __init__(self, i2c_addr = DFRobot_ICM42688_I2C_H_ADDR,bus = 1):
    self.i2cbus=smbus.SMBus(bus)
    self.i2c_addr = i2c_addr
    super(DFRobot_ICM42688_I2C,self).__init__()


  def begin(self):
    ''' !
      @brief   Begin function, detect whether the sensor is normally connected
      @retval ERR_OK         Init succeed
      @retval ERR_DATA_BUS   Bus data read error
      @retval ERR_IC_VERSION The read sensor ID is wrong
    '''
    return super(DFRobot_ICM42688_I2C,self).begin()


  def write_reg(self, reg, value):
    '''!
      @brief   Write data to register
      @param reg Register address
      @param value Data to be written, list format
    '''
    self.i2cbus.write_i2c_block_data(self.i2c_addr, reg, value)
  

  def read_reg(self, reg):
    '''!
      @brief   Read data from register
      @param reg Register address
      @return The read data, list format
    '''
    self.i2cbus.write_byte(self.i2c_addr,reg)
    rslt = self.i2cbus.read_byte(self.i2c_addr)
    return rslt

class DFRobot_ICM42688_SPI(DFRobot_ICM42688): 
  def __init__(self ,cs, bus = 0, dev = 0,speed = 10000000):
    super(DFRobot_ICM42688_SPI, self).__init__()
    self.__cs = cs
    GPIO.setup(self.__cs, GPIO.OUT)
    GPIO.output(self.__cs, GPIO.LOW)
    self.__spi = spidev.SpiDev()
    self.__spi.open(bus, dev)
    self.__spi.no_cs = True
    self.__spi.max_speed_hz = speed

  def begin(self):
    '''!
      @brief   Begin function, detect whether the sensor is normally connected
      @retval ERR_OK         Init succeed
      @n      ERR_DATA_BUS   Bus data access error
      @n      ERR_IC_VERSION The read sensor ID is wrong
    '''
    return super(DFRobot_ICM42688_SPI,self).begin()

  def write_reg(self, reg, data):
    '''!
      @brief writes data to a register
      @param reg register address
      @param data Data to be written 
    '''
    GPIO.output(self.__cs, GPIO.LOW)
    self.__spi.writebytes([reg,data[0]])
    GPIO.output(self.__cs, GPIO.HIGH)

  def read_reg(self, reg):
    '''!
      @brief read the data from the register
      @param reg register address
      @return read data
    '''
    GPIO.output(self.__cs, GPIO.LOW)
    self.__spi.writebytes([reg | 0x80])
    data = self.__spi.readbytes(1)
    GPIO.output(self.__cs, GPIO.HIGH)
    return  data[0]
