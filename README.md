# DFRobot_ICM42688

- [中文版](./README_CN.md)

The ICM-42688-P is a 6-axis MEMS MotionTracking device that combines a 3-axis gyroscope and a 3-axis accelerometer. It has a configurable host interface that supports I3CSM, I2C and SPI serial communication, features a 2 kB FIFO and 2 programmable interrupts with ultra low-power wake-on-motion support to minimize system power consumption.



![产品实物图](./resources/images/SEN0452.jpg)


## Product Link(https://www.dfrobot.com/)
    SKU：SEN0452

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

* Get temperature data, gyroscope data and accelerometer data.
* Tap detection
* Wake on Motion
* Significant Motion Detection

## Installation

There are two ways to use the library:
1. Open the Arduino IDE, search for "DFRobot_ICM42688" in Tools --> Manager Libraries on the status bar, and install the library.
2. First download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in that folder.

## Methods

```C++
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
   * @return Temperature unit: ℃
   */
  float getTemperature(void);

  /**
   * @fn getAccelDataX
   * @brief Get X-axis accelerometer value
   * @return X-axis accelerometer value unit: mg
   */
  float getAccelDataX(void);

  /**
   * @fn getAccelDataY
   * @brief Get Y-axis accelerometer value
   * @return Y-axis accelerometer value unit: mg
   */
  float getAccelDataY(void);

  /**
   * @fn getAccelDataZ
   * @brief Get Z-axis accelerometer value
   * @return Z-axis accelerometer value unit: mg
   */
  float getAccelDataZ(void);

  /**
   * @fn getGyroDataX
   * @brief Get X-axis gyroscope value
   * @return X-axis gyroscope value unit: dps
   */
  float getGyroDataX(void);

  /**
   * @fn getGyroDataY
   * @brief Get Y-axis gyroscope value
   * @return Y-axis gyroscope value unit: dps
   */
  float getGyroDataY(void);

  /**
   * @fn getGyroDataZ
   * @brief Get Z-axis gyroscope value
   * @return Z-axis gyroscope value unit: dps
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
   * @retval TAP_SINGLE   single-tap
   * @n      TAP_DOUBLE   double tap
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
   * @brief Set wake on motion interrupt threshold of an axis accelerometer
   * @param axis  x/y/z axis
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
   * @param axis  x/y/z axis
   * @n       X_AXIS_WOM
   * @n       Y_AXIS_WOM
   * @n       Z_AXIS_WOM
   */
  void setWOMInterrupt(uint8_t axis);

  /**
   * @fn enableSMDInterrupt
   * @brief Set essential motion detection mode and enable SMD interrupt
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
   * @return Interrupt information, return 0 when no interrupt
   */
  uint8_t readInterruptStatus(uint8_t reg);

  /**
   * @fn setODRAndFSR
   * @brief Set ODR and Full-scale range of gyroscope or accelerometer
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
   * @retval true   The setting succeeds
   * @retval flase  Selected parameter is wrong
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
   * @n       1  Interrupt lock mode (remain polarity after interrupt trigger, and restore after clearing interrupt)
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
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    |   Remarks  |
------------------ | :----------: | :----------: | :---------: | :---------:|
Arduino uno        |              |              |             | only support 3.3V |
FireBeetle esp32   |      √       |              |             |            |
FireBeetle esp8266 |      √       |              |             |            |
FireBeetle m0      |      √       |              |             |            |
Leonardo           |              |              |             | only support 3.3V |
Microbit           |      √       |              |             |            |
Arduino MEGA2560   |              |              |             | only support 3.3V |


## History

- 2021/09/28 - Version 1.0.0 released.


## Credits

Written by yangfeng(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))





