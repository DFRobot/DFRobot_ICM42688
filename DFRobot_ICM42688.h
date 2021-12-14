/*!
 * @file DFRobot_ICM42688.h
 * @brief Define the basic structure of DFRobot_ICM42688 class
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-05-13
 * @url  https://github.com/DFRobot/DFRobot_ICM42688
 */
#ifndef __DFRobot_ICM42688_H
#define __DFRobot_ICM42688_H

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

//Open this macro and you can see the details of the program
#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define DFRobot_ICM42688_I2C_L_ADDR 0x68 
#define DFRobot_ICM42688_I2C_H_ADDR 0x69
#define DFRobot_ICM42688_ID  0x47 

#define ICM42688_DEVICE_CONFIG          0x11
#define ICM42688_DRIVE_CONFIG           0x13

#define ICM42688_SIGNAL_PATH_RESET      0x4B

#define ICM42688_PWR_MGMT0              0x4E

#define ICM42688_INT_CONFIG             0x14
#define ICM42688_INT_STATUS             0x2D
#define ICM42688_INT_STATUS2            0x37
#define ICM42688_INT_STATUS3            0x38
#define ICM42688_INT_CONFIG0            0x63
#define ICM42688_INT_CONFIG1            0x64
#define ICM42688_INT_SOURCE0            0x65
#define ICM42688_INT_SOURCE1            0x66
#define ICM42688_INT_SOURCE3            0x68
#define ICM42688_INT_SOURCE4            0x69
#define ICM42688_INT_SOURCE6            0x4D
#define ICM42688_INT_SOURCE7            0x4E
#define ICM42688_INT_SOURCE8            0x4F
#define ICM42688_INT_SOURCE9            0x50
#define ICM42688_INT_SOURCE10           0x51

#define ICM42688_TEMP_DATA1             0x1D
#define ICM42688_TEMP_DATA0             0x1E
#define ICM42688_ACCEL_DATA_X1          0x1F
#define ICM42688_ACCEL_DATA_X0          0x20
#define ICM42688_ACCEL_DATA_Y1          0x21
#define ICM42688_ACCEL_DATA_Y0          0x22
#define ICM42688_ACCEL_DATA_Z1          0x23
#define ICM42688_ACCEL_DATA_Z0          0x24
#define ICM42688_GYRO_DATA_X1           0x25
#define ICM42688_GYRO_DATA_X0           0x26
#define ICM42688_GYRO_DATA_Y1           0x27
#define ICM42688_GYRO_DATA_Y0           0x28
#define ICM42688_GYRO_DATA_Z1           0x29
#define ICM42688_GYRO_DATA_Z0           0x30

#define ICM42688_TMST_FSYNCH            0x43
#define ICM42688_TMST_FSYNCL            0x44

#define ICM42688_GYRO_CONFIG_STATIC2    0x0B
#define ICM42688_GYRO_CONFIG_STATIC3    0x0C
#define ICM42688_GYRO_CONFIG_STATIC4    0x0D
#define ICM42688_GYRO_CONFIG_STATIC5    0x0E
#define ICM42688_GYRO_CONFIG_STATIC6    0x0F
#define ICM42688_GYRO_CONFIG_STATIC7    0x10
#define ICM42688_GYRO_CONFIG_STATIC8    0x11
#define ICM42688_GYRO_CONFIG_STATIC9    0x12
#define ICM42688_GYRO_CONFIG_STATIC10   0x13


    
#define ICM42688_GYRO_CONFIG0           0x4F
#define ICM42688_ACCEL_CONFIG0          0x50
#define ICM42688_GYRO_CONFIG1           0x51
#define ICM42688_GYRO_ACCEL_CONFIG0     0x52
#define ICM42688_ACCEL_CONFIG1          0x53
    
#define ICM42688_TMST_CONFIG            0x54
    

#define ICM42688_SMD_CONFIG             0x57

#define ICM42688_FIFO_CONFIG            0x16
#define ICM42688_FIFO_COUNTH            0x2E
#define ICM42688_FIFO_COUNTL            0x2F
#define ICM42688_FIFO_DATA              0x30
#define ICM42688_FIFO_CONFIG1           0x5F
#define ICM42688_FIFO_CONFIG2           0x60
#define ICM42688_FIFO_CONFIG3           0x61
#define ICM42688_FIFO_LOST_PKT0         0x6C
#define ICM42688_FIFO_LOST_PKT1         0x6D

#define ICM42688_FSYNC_CONFIG           0x62
    

    

#define ICM42688_SELF_TEST_CONFIG       0x70
#define ICM42688_WHO_AM_I               0x75
#define ICM42688_REG_BANK_SEL           0x76   
#define ICM42688_SENSOR_CONFIG0         0x03



#define ICM42688_XG_ST_DATA             0x5F
#define ICM42688_YG_ST_DATA             0x60
#define ICM42688_ZG_ST_DATA             0x61

#define ICM42688_TMSTVAL0               0x62
#define ICM42688_TMSTVAL1               0x63
#define ICM42688_TMSTVAL2               0x64

#define ICM42688_INTF_CONFIG0           0x4C
#define ICM42688_INTF_CONFIG1           0x4D
#define ICM42688_INTF_CONFIG4           0x7A
#define ICM42688_INTF_CONFIG5           0x7B
#define ICM42688_INTF_CONFIG6           0x7C

#define ICM42688_ACCEL_CONFIG_STATIC2   0x03
#define ICM42688_ACCEL_CONFIG_STATIC3   0x04
#define ICM42688_ACCEL_CONFIG_STATIC4   0x05

#define ICM42688_XA_ST_DATA             0x3B
#define ICM42688_YA_ST_DATA             0x3C
#define ICM42688_ZA_ST_DATA             0x3D

#define ICM42688_APEX_DATA0             0x31
#define ICM42688_APEX_DATA1             0x32
#define ICM42688_APEX_DATA2             0x33
#define ICM42688_APEX_DATA3             0x34
#define ICM42688_APEX_DATA4             0x35
#define ICM42688_APEX_DATA5             0x36
#define ICM42688_APEX_CONFIG0           0x56
#define ICM42688_APEX_CONFIG1           0x40 
#define ICM42688_APEX_CONFIG2           0x41
#define ICM42688_APEX_CONFIG3           0x42
#define ICM42688_APEX_CONFIG4           0x43
#define ICM42688_APEX_CONFIG5           0x44
#define ICM42688_APEX_CONFIG6           0x45
#define ICM42688_APEX_CONFIG7           0x46
#define ICM42688_APEX_CONFIG8           0x47
#define ICM42688_APEX_CONFIG9           0x48

#define ICM42688_ACCEL_WOM_X_THR        0x4A
#define ICM42688_ACCEL_WOM_Y_THR        0x4B
#define ICM42688_ACCEL_WOM_Z_THR        0x4C

#define ICM42688_OFFSET_USER0           0x77
#define ICM42688_OFFSET_USER1           0x78
#define ICM42688_OFFSET_USER2           0x79
#define ICM42688_OFFSET_USER3           0x7A
#define ICM42688_OFFSET_USER4           0x7B
#define ICM42688_OFFSET_USER5           0x7C
#define ICM42688_OFFSET_USER6           0x7D
#define ICM42688_OFFSET_USER7           0x7E
#define ICM42688_OFFSET_USER8           0x7F

#define ICM42688_STEP_DET_INT           1<<5
#define ICM42688_STEP_CNT_OVF_INT       1<<4
#define ICM42688_TILT_DET_INT           1<<3
#define ICM42688_WAKE_INT               1<<2
#define ICM42688_SLEEP_INT              1<<1
#define ICM42688_TAP_DET_INT            1

#define ICM42688_SMD_INT                1<<3
#define ICM42688_WOM_Z_INT              1<<2
#define ICM42688_WOM_Y_INT              1<<1
#define ICM42688_WOM_X_INT              1

#define ICM42688_STATUS_WALK 1
#define ICM42688_STATUS_RUN 2

class DFRobot_ICM42688
{
public:
  #define ERR_OK             0      ///< No error
  #define ERR_DATA_BUS      -1      ///< Data bus error
  #define ERR_IC_VERSION    -2      ///< The chip version not match
  
  #define GYRO     0
  #define ACCEL    1
  #define ALL      5



  #define TMST_DEFAULT_CONFIG_START  0x23
  #define TMST_VALUE_DIS             0<<4
  #define TMST_VALUE_EN              1<<4
  #define TMST_RES_EN_DIS            0<<3 
  #define TMST_RES_EN                1<<3
  #define TMST_FSYNC_EN              1<<1
  #define TMST_FSYNC_DIS             0<<1
  #define TMST_DELTA_EN              0<<2
  #define TMST_DELTA_DIS             1<<2
  #define TMST_EN                    1
  #define TMST_DIS                   0

  #define X_AXIS   0
  #define Y_AXIS   2
  #define Z_AXIS   4

  #define X_AXIS_WOM   1
  #define Y_AXIS_WOM   2
  #define Z_AXIS_WOM   4

  #define ODR_32KHZ         1
  #define ODR_16KHZ         2
  #define ODR_8KHZ          3
  #define ODR_4KHZ          4
  #define ODR_2KHZ          5
  #define ODR_1KHZ          6
  #define ODR_200HZ         7
  #define ODR_100HZ         8
  #define ODR_50HZ          9
  #define ODR_25KHZ         10
  #define ODR_12_5KHZ       11
  #define ODR_6_25KHZ       12
  #define ODR_3_125HZ       13
  #define ODR_1_5625HZ      14
  #define ODR_500HZ         15

  #define FSR_0             0
  #define FSR_1             1
  #define FSR_2             2
  #define FSR_3             3
  #define FSR_4             4
  #define FSR_5             5
  #define FSR_6             6
  #define FSR_7             7

  #define LP_MODE_ONLY_ACCEL  2
  #define LN_MODE  3
  #define STANDBY_MODE_ONLY_GYRO 1 
  #define OFF_MODE   0

  #define TAP_SINGLE 8
  #define TAP_DOUBLE 16
  /**
   * @struct sSignalPathReset_t
   * @brief  Register:SIGNAL_PATH_RESET
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- ---
   * @n        |    b7    |      b6      |         b5        |         b4         |          b3         |        b2       |       b1       |      b0    |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------
   * @n        | Reserved | DMP_INIT_EN  |  DMP_MEM_RESET_EN |      Reserved      |   ABORT_AND_RESET   |   TMST_STROBE   |   FIFO_FLUSH   |  Reserved  |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------
   * @n        DMP_INIT_EN: When this bit is set to 1, the DMP is enabled
   * @n        DMP_MEM_RESET_EN: When this bit is set to 1, the DMP memory is reset
   * @n        ABORT_AND_RESET : When this bit is set to 1, the signal path is reset by restarting the ODR counter and signal path controls
   * @n        TMST_STROBE : When this bit is set to 1, the time stamp counter is latched into the time stamp register. This is a write on clear bit.
   * @n        FIFO_FLUSH : When set to 1, FIFO will get flushed.
   */
  typedef struct {
    uint8_t   reserved0: 1; 
    uint8_t   FIFOFlush: 1; 
    uint8_t   TMSTStrobe: 1; 
    uint8_t   abortAndReset: 1; 
    uint8_t   reserved4:1; 
    uint8_t   DMPMemResetEn:1;
    uint8_t   DMPInitEn:1;
    uint8_t   reserved7:1;
  } __attribute__ ((packed)) sSignalPathReset_t;
  /**
   * @struct sAPEXConfig0_t
   * @brief  Register:APEX_Config0
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------
   * @n        |            b7          |        b6      |         b5         |         b4         |          b3        |        b2      |       b1        |      b0     |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |     DMP_POWER_SAVE     |   TAP_ENABLE   |     PED_ENABLE     |     TILT_ENABLE    |        R2W_EN      |    Reserved    |             DMP_ODR           |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        DMP_POWER_SAVE : 0: DMP power save mode not active
   * @n                         1: DMP power save mode active (default)
   * @n        TAP_ENABLE :0: Tap Detection not enabled (tap detection function)
   * @n                    1: Tap Detection enabled when accelerometer ODR is set to one of the ODR 
   * @n                    values supported by Tap Detection (200Hz, 500Hz, 1kHz)
   * @n        PED_ENABLE  0: Pedometer not enabled
   * @n                    1: Pedometer enabled (Pedometer)
   * @n        TILT_ENABLE 0: Tilt Detection not enabled (tilt)
   * @n                    1: Tilt Detection enabled
   * @n        R2W_EN 0: Raise to Wake/Sleep not enabled
   * @n               1: Raise to Wake/Sleep enabled
   * @n        DMP_ODR 00: 25Hz
   * @n                01: Reserved
   * @n                10: 50Hz
   * @n                11: Reserved
   */
  typedef struct {
    uint8_t   dmpODR: 2; 
    uint8_t   reserved: 1; 
    uint8_t   R2WEn: 1; 
    uint8_t   tiltEnable:1; 
    uint8_t   PEDEnable:1;
    uint8_t   tapEnable:1;
    uint8_t   DMPPowerSave:1;
  } __attribute__ ((packed)) sAPEXConfig0_t;

  /**
   * @struct sAccelConfig0_t
   * @brief  Register:Accel_Config0
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                           ACCEL_FS_SEL                        |      Reserved      |                                ACCEL_ODR                          |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        ACCEL_FS_SEL :Full scale select for accelerometer UI interface output
   * @n                      000: ±16g (default)
   * @n                      001: ±8g
   * @n                      010: ±4g
   * @n                      011: ±2g
   * @n                      100: Reserved
   * @n                      101: Reserved
   * @n                      110: Reserved
   * @n                      111: Reserved
   * @n        ACCEL_ODR :Accelerometer ODR selection for UI interface output
   * @n                   0000: Reserved
   * @n                   0001: 32kHz (LN mode)
   * @n                   0010: 16kHz (LN mode)
   * @n                   0011: 8kHz (LN mode)
   * @n                   0100: 4kHz (LN mode)
   * @n                   0101: 2kHz (LN mode)
   * @n                   0110: 1kHz (LN mode) (default)
   * @n                   0111: 200Hz (LP or LN mode) 
   * @n                   1000: 100Hz (LP or LN mode)
   * @n                   1001: 50Hz (LP or LN mode)
   * @n                   1010: 25Hz (LP or LN mode)
   * @n                   1011: 12.5Hz (LP or LN mode)
   * @n                   1100: 6.25Hz (LP mode)
   * @n                   1101: 3.125Hz (LP mode)
   * @n                   1110: 1.5625Hz (LP mode)
   * @n                   1111: 500Hz (LP or LN mode)
   */
  typedef struct {
    uint8_t   accelODR: 4; 
    uint8_t   reserved: 1; 
    uint8_t   accelFsSel: 3; 
  } __attribute__ ((packed)) sAccelConfig0_t;

  /**
   * @struct sGyroConfig0_t
   * @brief  Register:Gyro_Config0
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                            GYRO_FS_SEL                        |      Reserved      |                                 GYRO_ODR                          |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        GYRO_FS_SEL : Full scale select for gyroscope UI interface output
   * @n                      000: ±2000dps (default)
   * @n                      001: ±1000dps
   * @n                      010: ±500dps
   * @n                      011: ±250dps
   * @n                      100: ±125dps
   * @n                      101: ±62.5dps
   * @n                      110: ±31.25dps
   * @n                      111: ±15.625dps
   * @n        GYRO_ODR :Gyroscope ODR selection for UI interface output
   * @n                  0000: Reserved
   * @n                  0001: 32kHz
   * @n                  0010: 16kHz
   * @n                  0011: 8kHz
   * @n                  0100: 4kHz
   * @n                  0101: 2kHz
   * @n                  0110: 1kHz (default)
   * @n                  0111: 200Hz 
   * @n                  1000: 100Hz
   * @n                  1001: 50Hz
   * @n                  1010: 25Hz
   * @n                  1011: 12.5Hz
   * @n                  1100: Reserved
   * @n                  1101: Reserved
   * @n                  1110: Reserved
   * @n                  1111: 500Hz
   */
  typedef struct {
    uint8_t   gyroODR: 4; 
    uint8_t   reserved: 1; 
    uint8_t   gyroFsSel: 3; 
  } __attribute__ ((packed)) sGyroConfig0_t;

  /**
   * @struct sGyroConfig1_t
   * @brief  Register:Gyro_Config1
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                          TEMP_FILT_BW                         |     reserved       |            GYRO_UI_FILT_ORD         |      GYRO_DEC2_M2_ORD       |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        TEMP_FILT_BW : Set the bandwidth of the temperature signal DLPF
   * @n                      000: DLPF BW = 4000Hz; DLPF Latency = 0.125ms (default)
   * @n                      001: DLPF BW = 170Hz; DLPF Latency = 1ms
   * @n                      010: DLPF BW = 82Hz; DLPF Latency = 2ms
   * @n                      011: DLPF BW = 40Hz; DLPF Latency = 4ms
   * @n                      100: DLPF BW = 20Hz; DLPF Latency = 8ms
   * @n                      101: DLPF BW = 10Hz; DLPF Latency = 16ms
   * @n                      110: DLPF BW = 5Hz; DLPF Latency = 32ms
   * @n                      111: DLPF BW = 5Hz; DLPF Latency = 32ms
   * @n        GYRO_UI_FILT_ORD :Selects order of GYRO UI filter
   * @n                           00: 1st Order
   * @n                           01: 2nd Order
   * @n                           10: 3rd Order
   * @n                           11: Reserved
   * @n        GYRO_DEC2_M2_ORD :Selects order of GYRO DEC2_M2 Filter
   * @n                          00: Reserved
   * @n                          01: Reserved
   * @n                          10: 3rd Order
   * @n                          11: Reserved
   */
  typedef struct {
    uint8_t   gyroDec2M2ODR: 2; 
    uint8_t   gyroUIFiltODR: 2; 
    uint8_t   reserved: 1; 
    uint8_t   agyroFiltBW: 3; 
  } __attribute__ ((packed)) sGyroConfig1_t;

  /**
   * @struct sGyroConfig1_t
   * @brief  Register:Gyro_Config1
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                    Reserved              |      TEMP_DIS      |        IDLE        |                GYRO_MODE            |           ACCEL_MODE        |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        TEMP_DIS : 0: Temperature sensor is enabled (default)
   * @n                   1: Temperature sensor is disabled
   * @n        IDLE : 0: When the accelerometer and gyroscope are powered off, the chip will go to OFF state, since the RC oscillator will also be powered off
   * @n               1: RC oscillator is powered on even if the accelerometer and gyroscope are powered off
   * @n        GYRO_MODE :00: Turns gyroscope off (default)
   * @n                   01: Places gyroscope in Standby Mode
   * @n                   10: Reserved
   * @n                   11: Places gyroscope in Low Noise (LN) Mode
   * @n                   Gyroscope needs to be kept ON for a minimum of 45ms. When transitioning from OFF to any of the other modes, do not issue any register writes for 200µs
   * @n        ACCEL_MODE: 00: Turns accelerometer off (default)
   * @n                    01: Turns accelerometer off
   * @n                    10: Places accelerometer in Low Power (LP) Mode
   * @n                    11: Places accelerometer in Low Noise (LN) Mode                
   * @n                    When transitioning from OFF to any of the other modes, do not issue any register writes for 200µs
   */
  typedef struct {
    uint8_t   accelMode: 2; 
    uint8_t   gyroMode: 2; 
    uint8_t   idle: 1; 
    uint8_t   tempDis:1; 
    uint8_t   reserved:2;
  } __attribute__ ((packed)) sPWRMgmt0_t;

  /**
   * @struct sINTFConfig0_t
   * @brief  Register:INTF_Config0
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- ---------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3         |        b2       |       b1       |      b0    |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        | FIFO_HOLD_LAST_DATA_EN | FIFO_COUNT_REC  |  FIFO_COUNT_ENDIAN | SENSOR_DATA_ENDIAN |                   Reserved            |          UI_SIFS_CFG        |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        FIFO_HOLD_LAST_DATA_EN: Method for processing invalid data, 0: Registers do not receive invalid samples. Registers hold last valid sample until new one arrives
   * @n                                                           FIFO : 16-bit FIFO packet: Same as Sense Registers (Do not receive invalid samples. They hold the last valid sample. Repeated reading before new sample received will yield copies of the last valid sample)
   * @n                                                                  20-bit FIFO packet: Invalid samples are indicated with the value -524288
   * @n                                                        1: Not receive invalid samples. Registers hold last valid sample until new one arrives
   * @n        FIFO_COUNT_REC: 0: FIFO count is reported in bytes
   * @n                        1: FIFO count is reported in records
   * @n        FIFO_COUNT_ENDIAN : 0: FIFO count is reported in Little Endian format
   * @n                            1: FIFO count is reported in Big Endian format (default)
   * @n        SENSOR_DATA_ENDIAN : 0: Sensor data is reported in Little Endian format
   * @n                             1: Sensor data is reported in Big Endian format (default)
   * @n        UI_SIFS_CFG: 0x: Reserved
   * @n                     10: Disable SPI
   * @n                     11: Disable I2C
   */
  typedef struct {
    uint8_t   UISifsConfig: 2; 
    uint8_t   reserved:2;
    uint8_t   sensorDataEndian: 1; 
    uint8_t   FIFOCountEndian: 1; 
    uint8_t   FIFOCountRec:1; 
    uint8_t   FIFOInvalidSampleTreatment:1;
  } __attribute__ ((packed)) sINTFConfig0_t;


  /**
   * @struct sINTFConfig1_t
   * @brief  Register:INTF_Config1
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                                       Reserved                                     |  ACCEL_LP_CLK_SEL  |    RTC_MODE    |              CLKSEL         |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        ACCEL_LP_CLK_SEL : 0: Accelerometer LP mode uses Wake Up oscillator clock
   * @n                           1: Accelerometer LP mode uses RC oscillator clock
   * @n        RTC_MODE : 0: No input RTC clock is required
   * @n                   1: RTC clock input is required
   * @n        CLKSEL : 00: Always select internal RC oscillator
   * @n                 01: Select PLL when available, else select RC oscillator (default)
   * @n                 10: Reserved
   * @n                 11: Disable all clocks
   */
  typedef struct {
    uint8_t   clksel: 2; 
    uint8_t   rtcMode: 1; 
    uint8_t   accelLpClkSel: 1; 
    uint8_t   reserved:4;
  } __attribute__ ((packed)) sINTFConfig1_t;

  /**
   * @struct sAccelConfig1_t
   * @brief  Register:Accel_Config1
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                            Reserved                           |          ACCEL_UI_FILT_ORD              |         ACCEL_DEC2_M2_ORD       |  Reserved  |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        ACCEL_UI_FILT_ORD : Selects order of ACCEL UI filter
   * @n                            00: 1st Order
   * @n                            01: 2nd Order
   * @n                            10: 3rd Order
   * @n                            11: Reserved
   * @n        ACCEL_DEC2_M2_ORD : Order of Accelerometer DEC2_M2 filter
   * @n                            00: Reserved
   * @n                            01: Reserved
   * @n                            10: 3rd order
   * @n                            11: Reserved
   */
  typedef struct {
    uint8_t   reserved: 1; 
    uint8_t   accelDec2M2ORD: 2; 
    uint8_t   accelUIFiltORD: 2; 
    uint8_t   reserved2: 3;
  } __attribute__ ((packed)) sAccelConfig1_t;

  /**
   * @struct sGyroAccelConfig0_t
   * @brief  Register:Gyro_Accel_Config0
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- -------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |       b2       |       b1       |      b0    |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                                       ACCEL_UI_FILT_BW                             |                             GYRO_UI_FILT_BW                       |
   * @n        ----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        ACCEL_UI_FILT_BW : Bandwidth for Accel LPF
   * @n                           LN Mode:
   * @n                              0 BW=ODR/2
   * @n                              1 BW=max(400Hz, ODR)/4 (default)
   * @n                              2 BW=max(400Hz, ODR)/5
   * @n                              3 BW=max(400Hz, ODR)/8
   * @n                              4 BW=max(400Hz, ODR)/10
   * @n                              5 BW=max(400Hz, ODR)/16
   * @n                              6 BW=max(400Hz, ODR)/20
   * @n                              7 BW=max(400Hz, ODR)/40
   * @n                              8 to 13: Reserved
   * @n                              14 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 
   * @n                              runs at max(400Hz, ODR) 
   * @n                              15 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 
   * @n                              runs at max(200Hz, 8*ODR)
   * @n                            LP Mode:
   * @n                              0 Reserved
   * @n                              1 1x AVG filter (default)
   * @n                              2 to 5 Reserved
   * @n                              6 16x AVG filter
   * @n                              7 to 15 Reserved
   * @n        GYRO_UI_FILT_BW :Bandwidth for Gyro LPF
   * @n                           LN Mode:
   * @n                            0 BW=ODR/2
   * @n                            1 BW=max(400Hz, ODR)/4 (default)
   * @n                            2 BW=max(400Hz, ODR)/5
   * @n                            3 BW=max(400Hz, ODR)/8
   * @n                            4 BW=max(400Hz, ODR)/10
   * @n                            5 BW=max(400Hz, ODR)/16
   * @n                            6 BW=max(400Hz, ODR)/20
   * @n                            7 BW=max(400Hz, ODR)/40
   * @n                            8 to 13: Reserved
   * @n                            14 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 runs at max(400Hz, ODR) 
   * @n                            15 Low Latency option: Trivial decimation @ ODR of Dec2 filter output. Dec2 runs at max(200Hz, 8*ODR)
   */
  typedef struct {
    uint8_t   gyroUIFiltBW: 4; 
    uint8_t   accelUIFiltBW: 4; 
  } __attribute__ ((packed)) sGyroAccelConfig0_t;

  /**
   * @struct sAPEXConfig7_t
   * @brief  Register:APEX_Config7
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   * @n        |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                                                      TAP_MIN_JERK_THR                                                                       |             TAP_MAX_PEAK_TOL            |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        TAP_MIN_JERK_THR  Tap detection minimum jerk threshold, use default value 010001b
   * @n        TAP_MAX_PEAK_TOL  Point detection maximum peak tolerance, use default value 01b
   */
  typedef struct {
    uint8_t   tapMaxPeakTol: 2; 
    uint8_t   tapMinJerkThr: 6; 
  } __attribute__ ((packed)) sAPEXConfig7_t;

  /**
   * @struct sAPEXConfig8_t
   * @brief  Register:APEX_Config8
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   * @n        |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |        Reserved      |                   TAP_TMAX                    |                     TAP_TAVG                    |                           TAP_TMIN                           |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        TAP_TMAX  Tap measurement window (number of samples), use default value 01b
   * @n        TAP_TAVG  Tap energy measurement window (number of samples), use default value 01b
   * @n        TAP_TMIN  Single tap window (number of samples), use default value 011b
   */
  typedef struct {
    uint8_t   tapTmin: 3; 
    uint8_t   tapTavg: 2; 
    uint8_t   tapTmax: 2;
    uint8_t   reserved:1;
  } __attribute__ ((packed)) sAPEXConfig8_t;

  /**
   * @struct sAPEXConfig4_t
   * @brief  Register:APEX_Config4
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   * @n        |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |           TILT_WAIT_TIME_SEL                |                                 SLEEP_TIME_OUT                           |                              Reserved                        |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        TILT_WAIT_TIME_SEL  Config delay time after tilt is detected before interrupt is triggered
   * @n                            00: 0s
   * @n                            01: 2s
   * @n                            10: 4s (default)
   * @n                            11: 6s
   * @n        SLEEP_TIME_OUT  Configures the time for sleep detection, for Raise to Wake/Sleep
   * @n                        000: 1.28sec
   * @n                        001: 2.56sec
   * @n                        010: 3.84sec
   * @n                        011: 5.12sec
   * @n                        100: 6.40sec
   * @n                        101: 7.68sec
   * @n                        110: 8.96sec
   * @n                        111: 10.24sec
   */
  typedef struct {
    uint8_t   reserved: 3;
    uint8_t   sleepTimeOut: 3; 
    uint8_t   tiltWaitTimeSel: 2; 
  } __attribute__ ((packed)) sAPEXConfig4_t;

  /**
   * @struct sSMDConfig_t
   * @brief  Register:SMD_Config
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------
   * @n        |            b7        |        b6      |         b5         |         b4         |          b3        |        b2      |       b1        |      b0       |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                                    Reserved                                     |     WOM_INT_MODE   |    WOM_MODE    |             SMD_MODE            |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        WOM_INT_MODE : (Wake on motion) 0: Set WoM interrupt on the OR of all enabled accelerometer thresholds
   * @n                                 1: Set WoM interrupt on the AND of all enabled accelerometer threshold
   * @n        WOM_MODE 0: Initial sample is stored. Future samples are compared to initial sample
   * @n                 1: Compare current sample to previous sample
   * @n        SMD_MODE  00: SMD disabled (important motion detector)
   * @n                  01: Reserved
   * @n                  10: SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
   * @n                  11: SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
   */
  typedef struct {
    uint8_t   SMDMode: 2; 
    uint8_t   WOMMode: 1; 
    uint8_t   WOMIntMode: 1;
    uint8_t   reserved: 4;
  } __attribute__ ((packed)) sSMDConfig_t;


  /**
   * @struct sGyroConfigStatic9_t
   * @brief  Register:Gyro_Config_Static9
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   * @n        |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                  Reserved                   | GYRO_Z_NF_COSWZ_SEL[0] | GYRO_Y_NF_COSWZ_SEL[0] | GYRO_X_NF_COSWZ_SEL[0] | GYRO_Z_NF_COSWZ[8] | GYRO_Y_NF_COSWZ[8] | GYRO_X_NF_COSWZ[8] |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        GYRO_Z_NF_COSWZ_SEL[0] :Used for gyroscope Z-axis notch filter frequency selection
   * @n        GYRO_Y_NF_COSWZ_SEL[0] :Used for gyroscope Y-axis notch filter frequency selection
   * @n        GYRO_X_NF_COSWZ_SEL[0] :Used for gyroscope X-axis notch filter frequency selection
   * @n        GYRO_Z_NF_COSWZ[8] :Used for gyroscope Z-axis notch filter frequency selection
   * @n        GYRO_Y_NF_COSWZ[8] :Used for gyroscope Y-axis notch filter frequency selection
   * @n        GYRO_X_NF_COSWZ[8] :Used for gyroscope X-axis notch filter frequency selection
   */
  typedef struct {
    uint8_t   gyroNFCoswzX8: 1; 
    uint8_t   gyroNFCoswzY8: 1; 
    uint8_t   gyroNFCoswzZ8: 1;
    uint8_t   gyroNFCoswzSelX: 1;
    uint8_t   gyroNFCoswzSelY: 1;
    uint8_t   gyroNFCoswzSelZ: 1;
    uint8_t   reserved:2;
  } __attribute__ ((packed)) sGyroConfigStatic9_t;

  /**
   * @struct sGyroConfigStatic2_t
   * @brief  Register:Gyro_Config_Static2
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- ---------------------------------------
   * @n        |            b7        |           b6         |           b5          |         b4         |          b3       |         b2       |          b1         |        b0          |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                                                                     Reserved                                                    |     GYRO_AAF_DIS    |     GYRO_NF_DIS    |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        GYRO_AAF_DIS :0: Enable gyroscope anti-aliasing filter (default)
   * @n                      1: Disable gyroscope anti-aliasing filter
   * @n        GYRO_NF_DIS   0: Enable Notch Filter (default)
   * @n                      1: Disable Notch Filter
   */
  typedef struct {
    uint8_t   gyroNFDis: 1; 
    uint8_t   gyroAAFDis: 1; 
    uint8_t   reserved: 6;
  } __attribute__ ((packed)) sGyroConfigStatic2_t;

  /**
   * @struct sGyroConfigStatic5_t
   * @brief  Register:Gyro_Config_Static5
   * @n         -------------------------------------------------------------------------------------------------------------------------------------- ---------------------------------------
   * @n         |            b7        |           b6         |           b5          |         b4         |          b3       |         b2       |          b1         |        b0          |
   * @n         ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n         |                                     GYRO_AAF_BITSHIFT                                    |                            GYRO_AAF_DELTSQR[11:8]                               |
   * @n         ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n         GYRO_AAF_BITSHIFT :Controls bandwidth of the gyroscope anti-alias filter
   * @n         GYRO_AAF_DELTSQR[11:8]   Controls bandwidth of the gyroscope anti-alias filter
  */
  typedef struct {
    uint8_t   gyroAAFDeltsqr: 4; 
    uint8_t   gyroAAFBitshift: 4; 
  } __attribute__ ((packed)) sGyroConfigStatic5_t;

  /**
   * @struct sAccelConfigStatic2_t
   * @brief  Register:Accel_Config_Static2
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   * @n        |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |       Reserved       |                                                          ACCEL_AAF_DELT                                                                   |    ACCEL_AAF_DIS   |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        ACCEL_AAF_DELT  Controls bandwidth of the accelerometer anti-alias filter
   * @n        ACCEL_AAF_DIS   0: Enable accelerometer anti-aliasing filter (default)
   * @n                        1: Disable accelerometer anti-aliasing filter
   */
  typedef struct {
    uint8_t   accelAAFDis: 1; 
    uint8_t   accelAAFDelt: 6;
    uint8_t   reserved: 1; 
  } __attribute__ ((packed)) sAccelConfigStatic2_t;

  /**
   * @struct sAccelConfigStatic4_t
   * @brief  Register:Accel_Config_Static4
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------------------------------------
   * @n        |            b7        |           b6         |           b5           |           b4           |           b3           |          b2        |          b1        |        b0          |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                                  ACCEL_AAF_BITSHIFT                                           |                               ACCEL_AAF_DELTSQR[11:8]                                 |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        ACCEL_AAF_BITSHIFT  Controls bandwidth of the accelerometer anti-alias filter
   * @n        ACCEL_AAF_DELTSQR[11:8]  Controls bandwidth of the accelerometer anti-alias filter
   */
  typedef struct {
    uint8_t   accelAAFDeltsqr: 4; 
    uint8_t   accelAAFBitshift: 4; 
  } __attribute__ ((packed)) sAccelConfigStatic4_t;


  /**
   * @struct sFIFOConfig1_t
   * @brief  Register:FIFO_Config1
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- ---------------------------
   * @n        |            b7        |           b6           |          b5         |        b4         |          b3        |        b2      |      b1        |      b0       |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |       Reserved       | FIFO_RESUME_PARTIAL_RD |    FIFO_WM_GT_TH    |   FIFO_HIRES_EN   | FIFO_TMST_FSYNC_EN |  FIFO_TEMP_EN  |  FIFO_GYRO_EN  | FIFO_ACCEL_EN |
   * @n        ------------------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        FIFO_RESUME_PARTIAL_RD : 0: Partial FIFO read is disabled and the entire FIFO needs to be re-read
   * @n                                 1: FIFO read can be partial, and resume from last read point
   * @n        FIFO_WM_GT_TH Trigger FIFO watermark interrupt on every ODR (DMA write) if FIFO_COUNT ≥ FIFO_WM_TH
   * @n        FIFO_HIRES_EN : FIFO_HIRES_EN Enable 3 bytes of extended 20-bits accel, gyro data  +  1 byte of extended 16-bit temperature sensor data to be placed into the FIFO
   * @n        FIFO_TMST_FSYNC_EN: Must be set to 1 for all FIFO use cases when FSYNC is used.
   * @n        FIFO_TEMP_EN  Enable temperature sensor packets to go to FIFO
   * @n        FIFO_GYRO_EN  Enable gyroscope packets to go to FIFO
   * @n        FIFO_ACCEL_EN  Enable accelerometer packets to go to FIFO
   */
  typedef struct {
    uint8_t   FIFOAccelEn: 1; 
    uint8_t   FIFOGyroEn: 1; 
    uint8_t   FIFOTempEn: 1;
    uint8_t   FIFOTmstFsyncEn: 1;
    uint8_t   FIFOHiresEn: 1;
    uint8_t   FIFOWmGtTh: 1;
    uint8_t   FIFOResumeParialRd:1;
    uint8_t   reseved :1;
  } __attribute__ ((packed)) sFIFOConfig1_t;

  /**
   * @struct sTMSTConfig_t
   * @brief  Register:TMST_Config
   * @n        -------------------------------------------------------------------------------------------------------------------------------------- --------------------
   * @n        |            b7          |        b6       |         b5         |         b4         |          b3        |        b2       |       b1        |      b0   |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |                            Reserved                           |   TMST_TO_REGS_EN  |       TMST_RES     |  TMST_DELTA_EN  |  TMST_FSYNC_EN  |  TMST_EN  |
   * @n        -----------------------------------------------------------------------------------------------------------------------------------------------------------
   * @n        TMST_TO_REGS_EN : 0: TMST_VALUE[19:0] read always returns 0s
   * @n                          1: TMST_VALUE[19:0] read returns timestamp value
   * @n        TMST_RES : Time Stamp resolution: When set to 0 (default), time stamp resolution is 1 µs. When set to 1, resolution is 16µs
   * @n        TMST_DELTA_EN  Time Stamp delta enable: When set to 1, the time stamp field contains the measurement of time since the last occurrence of ODR.
   * @n        TMST_FSYNC_EN  Time Stamp register FSYNC enable (default). When set to 1, the contents of the Timestamp feature of FSYNC is enabled. The user also needs to select FIFO_TMST_FSYNC_EN in order to propagate the timestamp value to the FIFO.
   * @n        TMST_EN 0: Time Stamp register disable
   * @n                1: Time Stamp register enable (default)
   */
  typedef struct {
    uint8_t   TimeStampEn: 1; 
    uint8_t   TimeStampFSYNCEn: 1; 
    uint8_t   TimeStampDeltaEn: 1;
    uint8_t   TimeStampRes: 1;
    uint8_t   TimeStampToRegsEn: 1;
    uint8_t   reseved :3;
  } __attribute__ ((packed)) sTMSTConfig_t;

  /**
   * @struct sINTConfig_t
   * @brief  Register:INT_Config
   * @n        -------------------------------------------------------------------------------------------------------------------------------
   * @n        |    b7    |    b6    |       b5        |         b4         |       b3      |     b2    |         b1         |    b0         |
   * @n        -------------------------------------------------------------------------------------------------------------------------------
   * @n        |      reversed       |    INT2_MODE    | INT2_DRIVE_CIRCUIT | INT2_POLARITY | INT1_MODE | INT1_DRIVE_CIRCUIT | INT1_POLARITY |
   * @n        -------------------------------------------------------------------------------------------------------------------------------
   * @n        INT2_MODE:INT2 interrupt mode
   * @n                    0: Pulsed mode
   * @n                    1: Latched mode
   * @n        INT2_DRIVE_CIRCUIT:INT2 drive circuit
   * @n                           0: Open drain
   * @n                           1: Push pull
   * @n        INT2_POLARITY:INT2 interrupt polarity
   * @n                           0: Active low (default)
   * @n                           1: Active high
   * @n        INT1_MODE:INT1 interrupt mode
   * @n                    0: Pulsed mode
   * @n                    1: Latched mode
   * @n        INT1_DRIVE_CIRCUIT:INT1 drive circuit
   * @n                           0: Open drain
   * @n                           1: Push pull
   * @n        INT1_POLARITY:INT1 interrupt polarity
   * @n                           0: Active low (default)
   * @n                           1: Active high
   */
  typedef struct {
    uint8_t   INT1Polarity: 1;
    uint8_t   INT1DriveCirCuit: 1;
    uint8_t   INT1Mode: 1;
    uint8_t   INT2Polarity: 1;
    uint8_t   INT2DriveCirCuit: 1;
    uint8_t   INT2Mode :1;
    uint8_t   reversed :2;
  } __attribute__ ((packed)) sINTConfig_t;

  /**
   * @struct sINTSource_t
   * @brief  Register:INT_Source
   * @n        ---------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |    b7    |    b6    |            b5         |          b4         |        b3       |       b2        |         b1       |     b0         |
   * @n        ---------------------------------------------------------------------------------------------------------------------------------------------
   * @n        |      reversed       |    STEP_DET_INT_EN    | STEP_CNT_OFL_INT_EN | TILT_DET_INT_EN | WAKE_DET_INT_EN | SLEEP_DET_INT_EN | TAP_DET_INT_EN |
   * @n        ---------------------------------------------------------------------------------------------------------------------------------------------
   */
  typedef struct {
    uint8_t   tapDetIntEn: 1;
    uint8_t   sleepDetIntEn: 1;
    uint8_t   wakeDetIntEn: 1;
    uint8_t   tiltDetIntEn: 1;
    uint8_t   stepCntOflIntEn :1;
    uint8_t   stepDetIntEn :1;
    uint8_t   reserved:2;
  } __attribute__ ((packed)) sINTSource_t;

public:
  /**
   * @fn DFRobot_ICM42688
   * @brief Constructor
   */
  DFRobot_ICM42688();

  /**
   * @fn begin
   * @brief Init function
   * @return Init result
   * @retval ERR_OK         Init succeed
   * @retval ERR_DATA_BUS   Bus data read error
   * @retval ERR_IC_VERSION The read Sensor ID is wrong
   */
  int begin(void);

  /**
   * @fn getTemperature
   * @brief Get measured temperature
   * @return Temperature value, unit: ℃
   */
  float getTemperature(void);

  /**
   * @fn getAccelDataX
   * @brief Get X-axis accelerometer value
   * @return X-axis accelerometer value, unit: mg
   */
  float getAccelDataX(void);

  /**
   * @fn getAccelDataY
   * @brief Get Y-axis accelerometer value
   * @return Y-axis accelerometer value, unit: mg
   */
  float getAccelDataY(void);

  /**
   * @fn getAccelDataZ
   * @brief Get Z-axis accelerometer value
   * @return Z-axis accelerometer value, unit: mg
   */
  float getAccelDataZ(void);

  /**
   * @fn getGyroDataX
   * @brief Get X-axis gyroscope value
   * @return X-axis gyroscope value, unit: dps
   */
  float getGyroDataX(void);

  /**
   * @fn getGyroDataY
   * @brief Get Y-axis gyroscope value
   * @return Y-axis gyroscope value, unit: dps
   */
  float getGyroDataY(void);

  /**
   * @fn getGyroDataZ
   * @brief Get Z-axis gyroscope value
   * @return Z-axis gyroscope value, unit: dps
   */
  float getGyroDataZ(void);

  /**
   * @fn tapDetectionInit
   * @brief Tap detection init
   * @param accelMode Accelerometer operating mode
   * @n      0 for operating in low-power mode
   * @n      1 for operating in low-noise mode
   */
  void tapDetectionInit(uint8_t accelMode);

  /**
   * @fn getTapInformation
   * @brief Get tap information
   */
  void getTapInformation();

  /**
   * @fn numberOfTap
   * @brief Get the number of tap: single-tap or double tap
   * @return The number of tap
   * @retval TAP_SINGLE   Single-tap
   * @retval TAP_DOUBLE   Double tap
   */
  uint8_t numberOfTap();

  /**
   * @fn axisOfTap
   * @brief Get the axis on which the tap occurred: X-axis, Y-axis, or Z-axis
   * @return Tap axis
   * @retval X_AXIS   X-axis
   * @retval Y_AXIS   Y-axis
   * @retval Z_AXIS   Z-axis
   */
  uint8_t axisOfTap();

  /**
   * @fn wakeOnMotionInit
   * @brief Wake on motion init
   */
  void wakeOnMotionInit();

  /**
   * @fn setWOMTh
   * @brief Set wake on motion interrupt threshold of axis accelerometer
   * @param axis  x/y/z轴
   * @n       X_AXIS_WOM
   * @n       Y_AXIS_WOM
   * @n       Z_AXIS_WOM
   * @n       ALL
   * @param threshold  Range(0-255) [WoM thresholds are expressed in fixed “mg” independent of the selected Range [0g : 1g]; Resolution 1g/256=~3.9mg]
   */
  void setWOMTh(uint8_t axis,uint8_t threshold);

  /**
   * @fn setWOMInterrupt
   * @brief Enable wake on motion interrupt
   * @param axis  X-axis, Y-axis, or Z-axis
   * @n       X_AXIS_WOM
   * @n       Y_AXIS_WOM
   * @n       Z_AXIS_WOM
   */
  void setWOMInterrupt(uint8_t axis);

  /**
   * @fn enableSMDInterrupt
   * @brief Set important motion detection mode and enable SMD interrupt
   * @param mode  
   * @n      0: disable SMD
   * @n      2 : SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
   * @n      3 : SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
   */
  void enableSMDInterrupt(uint8_t mode);

  /**
   * @fn readInterruptStatus
   * @brief Read interrupt information and clear interrupt
   * @param reg Interrupt information register
   * @n      ICM42688_INT_STATUS2    Obtain interrupt information of SMD_INT, WOM_X_INT, WOM_Y_INT, WOM_Z_INT and clear them
   * @n      ICM42688_INT_STATUS3    Obtain interrupt information of STEP_DET_INT, STEP_CNT_OVF_INT, TILT_DET_INT, WAKE_INT, TAP_DET_INT and clear them
   * @return Interrupt information, return 0 when no interrupt.
   */
  uint8_t readInterruptStatus(uint8_t reg);

  /**
   * @fn setODRAndFSR
   * @brief Set ODR and Full-scale range of gyroscope or accelerometer.
   * @param who  GYRO/ACCEL/ALL
   * @n       GYRO: indicate only set gyroscope
   * @n       ACCEL: indicate only set accelerometer
   * @param ODR Output data rate
   * @n       ODR_32KHZ         Support: Gyro/Accel(LN mode)
   * @n       ODR_16KHZ         Support: Gyro/Accel(LN mode)
   * @n       ODR_8KHZ          Support: Gyro/Accel(LN mode)
   * @n       ODR_4KHZ          Support: Gyro/Accel(LN mode)
   * @n       ODR_2KHZ          Support: Gyro/Accel(LN mode)
   * @n       ODR_1KHZ          Support: Gyro/Accel(LN mode)
   * @n       ODR_200HZ         Support: Gyro/Accel(LP or LN mode)
   * @n       ODR_100HZ         Support: Gyro/Accel(LP or LN mode)
   * @n       ODR_50HZ          Support: Gyro/Accel(LP or LN mode)
   * @n       ODR_25KHZ         Support: Gyro/Accel(LP or LN mode)
   * @n       ODR_12_5KHZ       Support: Gyro/Accel(LP or LN mode)
   * @n       ODR_6_25KHZ       Support: Accel(LP mode)
   * @n       ODR_3_125HZ       Support: Accel(LP mode)
   * @n       ODR_1_5625HZ      Support: Accel(LP mode)
   * @n       ODR_500HZ         Support: Accel(LP or LN mode)
   * @param FSR Full-scale range
   * @n       FSR_0      Gyro:±2000dps   /   Accel: ±16g
   * @n       FSR_1      Gyro:±1000dps   /   Accel: ±8g
   * @n       FSR_2      Gyro:±500dps    /   Accel: ±4g
   * @n       FSR_3      Gyro:±250dps    /   Accel: ±2g
   * @n       FSR_4      Gyro:±125dps    /   Accel: not optional
   * @n       FSR_5      Gyro:±62.5dps   /   Accel: not optional
   * @n       FSR_6      Gyro:±31.25dps  /   Accel: not optional
   * @n       FSR_7      Gyro:±15.625dps /   Accel: not optional
   * @return Set result
   * @retval true   indicate the setting succeeds
   * @retval flase  indicate selected parameter is wrong
   */
  bool setODRAndFSR(uint8_t who,uint8_t ODR,uint8_t FSR);

  /**
   * @fn startFIFOMode
   * @brief Enable FIFO
   */
  void startFIFOMode();

  /**
   * @fn sotpFIFOMode
   * @brief Disable FIFO
   */
  void sotpFIFOMode();

  /**
   * @fn getFIFOData
   * @brief Read FIFO data, read temperature, gyroscope and accelerometer data and save them for parse.
   */
  void getFIFOData();

  /**
   * @fn setINTMode
   * @brief Set interrupt mode
   * @param INTPin  Interrupt pin 
   * @n       1  Use INT1 interrupt pin
   * @n       2  Use INT2 interrupt pin
   * @param INTmode Set interrupt mode
   * @n       1  Interrupt lock mode (polarity remains unchanged when interrupt triggered, and restore after clearing interrupt)
   * @n       0  Pulse mode
   * @param INTPolarity Level polarity output by interrupt
   * @n       0  Interrupt pin polarity is LOW when producing interrupt
   * @n       1  Interrupt pin polarity is HIGH when producing interrupt
   * @param INTDriveCircuit  
   * @n       0  Open drain
   * @n       1  Push pull
   */
  void setINTMode(uint8_t INTPin,uint8_t INTmode,uint8_t INTPolarity,uint8_t INTDriveCircuit);

  /**
   * @fn startGyroMeasure
   * @brief Start gyroscope
   * @param mode Set gyroscope working mode
   * @n       STANDBY_MODE_ONLY_GYRO 1  Set stanby mode, only support gyroscope
   * @n       LN_MODE  3                Set low-noise mode
   */
  void startGyroMeasure(uint8_t mode);

  /**
   * @fn startAccelMeasure
   * @brief Start accelerometer
   * @param mode Set accelerometer working mode
   * @n       LP_MODE_ONLY_ACCEL  2     Set low-power mode, only support accelerometer
   * @n       LN_MODE  3                Set low-noise mode
   */
  void startAccelMeasure(uint8_t mode);

  /**
   * @fn startTempMeasure
   * @brief Start thermometer
   */
  void startTempMeasure();

protected:
  
  /**
   * @fn setFIFODataMode
   * @brief Set FIFO data packet format
   */
  void setFIFODataMode();

  /**
   * @fn writeReg
   * @brief Write register function, design it as a virtual function, implemented by a derived class.
   * @param reg  Register address 8bits
   * @param pBuf Storage and buffer for data to be written
   * @param size Length of data to be written
   */
  virtual void writeReg(uint8_t reg, void* pBuf, size_t size) = 0;
  
  /**
   * @fn readReg
   * @brief Read register function, design it as a virtual function, implemented by a derived class.
   * @param reg  Register address 8bits
   * @param pBuf Read data storage and buffer
   * @param size Read data length
   * @return return the read length, returning 0 means length reading failed
   */
  virtual uint8_t readReg(uint8_t reg, void* pBuf, size_t size) = 0;

private:
  /**
   * @fn setGyroNotchFilterFHz
   * @brief Set gyroscope notch filter frequency
   * @param freq  1000HZ-3000HZ
   * @param axis  
   * @n       X_AXIS
   * @n       Y_AXIS
   * @n       Z_AXIS
   * @n       ALL
   */
  void setGyroNotchFilterFHz(double freq,uint8_t axis);

  /**
   * @fn setGyroNFbandwidth
   * @brief Set gyroscope notch filter bandwidth
   * @param freq  1000HZ-3000HZ
   * @param axis  
   * @n       X_AXIS
   * @n       Y_AXIS
   * @n       Z_AXIS
   * @n       ALL
   */
  void setGyroNFbandwidth(uint8_t bw);

  /**
   * @fn setGyroNotchFilter
   * @brief Switch of gyroscope notch filter
   * @param mode  
   * @n       true  Enable
   * @n       false Disable
   */
  void setGyroNotchFilter(bool mode);

  /**
   * @fn setAAFBandwidth
   * @brief Set AAF bandwidth of gyroscope or accelerometer
   * @param who  
   * @n       GYRO
   * @n       ACCEL
   * @n       ALL
   * @param BWIndex Bandwidth index
   * @n              uint16_t AAFHZ[63] = {42,84,126,170,213,258,303,348,394,441,488,536,585,634,684,734,785,837,890,943,
   * @n                                    997,1051,1107,1163,1220,1277,1336,1395,1454,1515,1577,1639,1702,1766,1830,1896,
   * @n                                    1962,2029,2097,2166,2235,2306,2377,2449,2522,2596,2671,2746,2823,2900,2978,3057,
   * @n                                    3137,3217,3299,3381,3464,3548,3633,3718,3805,3892,3979};
   */
  void setAAFBandwidth(uint8_t who,uint8_t BWIndex);

  /**
   * @fn setAAF
   * @brief Set AAF switch of gyroscope or accelerometer
   * @param who  
   * @n       GYRO
   * @n       ACCEL
   * @n       ALL
   * @param mode  
   * @n       true  Enable
   * @n       false Disable
   */
  void setAAF(uint8_t who,bool mode);

  /**
   * @fn setUIFilter
   * @brief Set UI filter of gyroscope or accelerometer
   * @param who  GYRO\ACCEL\ALL
   * @param filterOrder  (range:1-3) Selects order of UI filter
   * @param UIFilterIndex (range:0-15) Bandwidth for GYRO\ACCEL LPF
   * @return Set result
   * @retval true   indicate the setting succeed
   * @retval flase  indicate selected parameter is wrong
   */
  bool setUIFilter(uint8_t who,uint8_t filterOrder ,uint8_t UIFilterIndex);

private:
  uint8_t _r, _g, _b;
  uint8_t _mode;
  uint8_t _tapNum ;
  uint8_t _tapAxis;
  uint8_t _tapDir ;
  float _gyroRange;
  float _accelRange;
  bool FIFOMode;
  int16_t _accelX;
  int16_t _accelY;
  int16_t _accelZ;
  int16_t _gyroX;
  int16_t _gyroZ;
  int16_t _gyroY;
  int8_t _temp;
  int8_t _INTPin;

  sAccelConfig0_t accelConfig0;
  sPWRMgmt0_t PWRMgmt0;
  sINTFConfig1_t INTFConfig1;
  sAccelConfig1_t accelConfig1;
  sGyroAccelConfig0_t gyroAccelConfig0;
  sAPEXConfig7_t APEXConfig7;
  sAPEXConfig8_t APEXConfig8;
  sSMDConfig_t SMDConfig;
  sGyroConfig1_t  gyroConfig1;
  sFIFOConfig1_t FIFOConfig1;
  sINTConfig_t INTConfig;
  sGyroConfig0_t gyroConfig0;
  sAPEXConfig0_t APEXConfig0;
  sGyroConfigStatic9_t gyroConfigStatic9;
  sGyroConfigStatic2_t gyroConfigStatic2;
  sGyroConfigStatic5_t gyroConfigStatic5;
  sAccelConfigStatic2_t accelConfigStatic2;
  sAccelConfigStatic4_t accelConfigStatic4;
  sINTSource_t  INTSource;
};

class DFRobot_ICM42688_I2C:public DFRobot_ICM42688{
public:
  DFRobot_ICM42688_I2C(uint8_t i2cAddr,TwoWire *pWire=&Wire);
  /**
   * @fn begin
   * @brief Init function
   * @return Init result
   * @retval ERR_OK         Init succeed
   * @retval ERR_DATA_BUS   Bus data read error
   * @retval ERR_IC_VERSION The read sensor ID is wrong
   */
  int begin(void);
protected:
  /**
   * @fn writeReg
   * @brief Write register values through I2C bus
   * @param reg  Register address 8bits
   * @param pBuf Storage and buffer for data to be written
   * @param size Length of data to be written
   * @return Return the read length, returning 0 means length reading failed
   */
   virtual void writeReg(uint8_t reg, void* pBuf, size_t size);

  /**
   * @fn readReg
   * @brief Read register values through I2C bus
   * @param reg  Register address 8bits
   * @param pBuf Storage and buffer for data to be read
   * @param size Length of data to be read
   * @return Return the read length, returning 0 means length reading failed
   */
  virtual uint8_t readReg(uint8_t reg, void* pBuf, size_t size);

private:
  TwoWire *_pWire;
  uint8_t _deviceAddr;
};


class DFRobot_ICM42688_SPI:public DFRobot_ICM42688{
public:
  DFRobot_ICM42688_SPI(uint8_t csPin=5,SPIClass *spi=&SPI);
  /**
   * @fn begin
   * @brief Init function
   * @return Init result
   * @retval ERR_OK         Init succeed
   * @retval ERR_DATA_BUS   Bus data read error
   * @retval ERR_IC_VERSION The read sensor ID is wrong
   */
  int begin(void);
protected:

  /**
   * @fn writeReg
   * @brief Write register value through SPI bus
   * @param reg  Register address 8bits
   * @param pBuf Storage and buffer for data to be written
   * @param size Length of data to be written
   */
  virtual void writeReg(uint8_t reg, void* pBuf, size_t size);

  /**
   * @fn readReg
   * @brief Read register value through SPI bus
   * @param reg  Register address 8bits
   * @param pBuf Storage and buffer for data to be read
   * @param size Length of data to be read
   * @return Return the read length, returning 0 means length reading failed
   */
  virtual uint8_t readReg(uint8_t reg, void* pBuf, size_t size);

private:
  SPIClass *_pSpi;
  uint8_t _csPin;
};
#endif
