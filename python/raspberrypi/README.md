# DFRobot_ICM42688

- [中文版](./README_CN.md)

The ICM-42688-P is a 6-axis MEMS MotionTracking device that combines a 3-axis gyroscope and a 3-axis accelerometer. It has a configurable host interface that supports I3CSM, I2C and SPI serial communication, features a 2 kB FIFO and 2 programmable interrupts with ultra low-power wake-on-motion support to minimize system power consumption.

![产品实物图](../../resources/images/SEN0452.jpg)

## Product Link（https://www.dfrobot.com/）
    SKU：SEN0452

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


## Summary
* Get temperature, gyroscope and accelerometer data
* tap detection
* Wake on Motion
* significant Motion Detection

## Installation

To use this library, first download the library to Raspberry Pi, then open the routines folder. To execute one routine, demox.py, type python demox.py on the command line. To execute the get_gyro_accel_temp_data.py routine, for example, you need to type:

```
python get_gyro_accel_temp_data.py
```

## Methods

```python
 
  def begin(self):
    '''!
      @brief   Begin function, detect whether the sensor is normally connected
      @return Init result
      @retval ERR_OK         Init succeed
      @retval ERR_DATA_BUS   Bus data read error
      @retval ERR_IC_VERSION The read sensor ID is wrong
    '''

  def get_temperature(self):
    '''!
      @brief   @brief Get measured temperature
      @return Temperature value, unit: ℃
    '''

  def get_accel_x(self):
    '''!
      @brief Get X-axis accelerometer value
      @return X-axis accelerometer value, unit: mg
    '''

  def get_accel_y(self):
    '''!
      @brief Get Y-axis accelerometer value
      @return Y-axis accelerometer value, unit: mg
    '''

  def get_accel_z(self):
    '''!
      @brief Get Z-axis accelerometer value
      @return Z-axis accelerometer value, unit: mg
    '''

  def get_gyro_x(self):
    '''!
      @brief Get X-axis gyroscope value
      @return X-axis gyroscope value, unit: dps
    '''

  def get_gyro_y(self):
    '''!
      @brief Get Y-axis gyroscope value
      @return Y-axis gyroscope value, unit: dps
    '''

  def get_gyro_z(self):
    '''!
      @brief Get Z-axis gyroscope value
      @return Z-axis gyroscope value, unit: dps
    '''

  def tap_detection_init(self,accel_mode):
    '''!
      @brief Tap detection init
      @param accel_mode Accelerometer operating mode
      @n      0 for operating in low-power mode
      @n      1 for operating in low-noise mode
    '''

  def get_tap_information(self):
    '''!
       @brief Get tap information
    '''


  def number_of_tap(self):
    '''!
      @brief Get the number of tap: single-tap or double tap
      @return The number of tap
      @retval TAP_SINGLE   Single-tap
      @retval TAP_DOUBLE   Double tap
    '''

  def axis_of_tap(self):
    '''!
      @brief Get the axis on which the tap occurred: X-axis, Y-axis, or Z-axis
      @return Tap axis
      @retval X_AXIS   X-axis
      @retval Y_AXIS   Y-axis
      @retval Z_AXIS   Z-axis
    '''

  def wake_on_motion_init(self):
    '''!
      @brief Wake on motion init
    '''

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

  def set_wom_interrupt(self,axis):
    '''!
      @brief Enable wake on interrupt of axis
      @param axis  x/y/z axis
      @n       X_AXIS_WOM
      @n       Y_AXIS_WOM
      @n       Z_AXIS_WOM
    '''

  def enable_SMD_interrupt(self,mode):
    '''!
      @brief Set important motion detection mode and enable SMD interrupt
      @param mode  
      @n      0: disable SMD
      @n      2 : SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
      @n      3 : SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
    '''

  def read_interrupt_status(self,reg):
    '''!
      @brief Read interrupt information and clear interrupt
      @param reg Interrupt information register
      @n         ICM42688_INT_STATUS2    Obtain interrupt information of SMD_INT, WOM_X_INT, WOM_Y_INT and WOM_Z_INT and clear them
      @n         ICM42688_INT_STATUS3    Obtain interrupt information of STEP_DET_INT, STEP_CNT_OVF_INT, TILT_DET_INT, WAKE_INT and TAP_DET_INT and clear them
      @return Interrupt information, return 0 when no interrupt
    '''

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

  def start_FIFO_mode(self):
    '''!
      @brief Enable FIFO
    '''

  def get_FIFO_data(self):
    '''!
      @brief Read FIFO data, read temperature, gyroscope and accelerometer data and save them for parse.
    '''

  def stop_FIFO_mode(self):
    '''!
      @brief Disable FIFO
    '''

  def set_INT_mode(self,INT_pin,INT_mode,INT_polarity,INT_drive_circuit):
    '''!
      @brief Set interrupt mode
      @param INT_pin  Interrupt pin 
      @n       1  Use INT1 interrupt pin
      @n       2  Use INT2 interrupt pin
      @param INT_mode Set interrupt mode
      @n       1  Interrupt lock mode (remain polarity after interrupt trigger, and restore after clearing interrupt)
      @n       0  Pulse mode
      @param INT_polarity Level polarity output by interrupt
      @n       0  Interrupt pin polarity is LOW when producing interrupt
      @n       1  Interrupt pin polarity is HIGH when producing interrupt
      @param INT_drive_circuit  
      @n       0  Open drain
      @n       1  Push pull
    '''

  def start_temp_measure(self):
    '''!
      @brief Start thermometer
    '''

  def start_gyro_measure(self,mode):
    '''!
    ' @brief Start gyroscope
    ' @param mode Set gyroscope working mode
    ' @n          STANDBY_MODE_ONLY_GYRO 1  Set stanby mode, only support gyroscope
    ' @n          LN_MODE  3                Set low-noise mode
    '''

  def start_accel_measure(self,mode):
    '''!
      @brief Start accelerometer
      @param mode Set accelerometer working mode
      @n          LP_MODE_ONLY_ACCEL  2     Set low-power mode, only support accelerometer
      @n          LN_MODE  3                Set low-noise mode
    '''

  def stop_temp_measure(self):
    '''!
      @brief Stop temperature measurement
    '''

  def stop_gyro_measure(self):
    '''!
      @brief Stop gyroscope
    '''

  def stop_accel_measure(self):
    '''!
      @brief Stop accelerometer
    '''

```

## Compatibility

* RaspberryPi Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |           |            |    √     |         |
| RaspberryPi4 |     √     |            |          |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |


## History

- 2021/09/28 - Version 1.0.0 released.


## Credits

Written by yangfeng(feng.yang@dfrobot.com),2021,(Welcome to our [website](https://www.dfrobot.com/))
