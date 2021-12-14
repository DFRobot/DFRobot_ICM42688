# DFRobot_ICM42688

- [English Version](./README.md)

ICM-42688-P是一款6轴MEMS运动跟踪设备，它结合了一个3轴陀螺仪和一个3轴加速度计。它有一个可配置的主机接口，支持I3CSM, I2C和SPI串行通信，具有2 kB的FIFO和2个可编程中断，超低功率动态尾流支持，以最大限度地减少系统功耗。

![产品实物图](./resources/images/SEN0352.jpg)


## 产品链接(https://www.dfrobot.com.cn/)
    SKU：SEN0352

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [创作者](#创作者)


## 概述

* 获取温度数据、陀螺仪数据、加速计数据
* 敲击检测
* 移动唤醒
* 重要的运动检测


## 库安装

这里提供两种使用本库的方法：
1. 打开Arduino IDE,在状态栏中的Tools--->Manager Libraries 搜索"DFRobot_ICM42688"并安装本库.
2. 首先下载库文件,将其粘贴到\Arduino\libraries目录中,然后打开examples文件夹并在该文件夹中运行演示.


## 方法

```C++
  /**
   * @fn begin
   * @brief 初始化函数
   * @return 初始化结果
   * @retval ERR_OK         初始化成功
   * @retval ERR_DATA_BUS   总线数据访问错误
   * @retval ERR_IC_VERSION 读取的传感器ID有误
   */
  int begin(void);

  /**
   * @fn getTemperature
   * @brief 获取测量温度值
   * @return 温度值 单位：℃
   */
  float getTemperature(void);

  /**
   * @fn getAccelDataX
   * @brief 获取X轴加速计值
   * @return X轴加速计值 单位：mg
   */
  float getAccelDataX(void);

  /**
   * @fn getAccelDataY
   * @brief 获取Y轴加速计值
   * @return Y轴加速计值 单位：mg
   */
  float getAccelDataY(void);

  /**
   * @fn getAccelDataZ
   * @brief 获取Z轴加速计值
   * @return Z轴加速计值 单位：mg
   */
  float getAccelDataZ(void);

  /**
   * @fn getGyroDataX
   * @brief 获取X轴陀螺仪值
   * @return X轴陀螺仪值 单位：dps
   */
  float getGyroDataX(void);

  /**
   * @fn getGyroDataY
   * @brief 获取Y轴陀螺仪值
   * @return Y轴陀螺仪值 单位：dps
   */
  float getGyroDataY(void);

  /**
   * @fn getGyroDataZ
   * @brief 获取Z轴陀螺仪值
   * @return Z轴陀螺仪值 单位：dps
   */
  float getGyroDataZ(void);

  /**
   * @fn tapDetectionInit
   * @brief 敲击事件初始化
   * @param accelMode 加速计工作模式
   * @n      0 代表工作在低功耗模式
   * @n      1 代表工作在低噪声模式
   */
  void tapDetectionInit(uint8_t accelMode);

  /**
   * @fn getTapInformation
   * @brief 获取敲击信息
   */
  void getTapInformation();

  /**
   * @fn numberOfTap
   * @brief 获取敲击次数，分别是：单击、双击
   * @return 敲击次数
   * @retval TAP_SINGLE   单击
   * @retval TAP_DOUBLE   双击
   */
  uint8_t numberOfTap();

  /**
   * @fn axisOfTap
   * @brief 获取敲击轴，分别是：X\Y\Z轴
   * @return 敲击轴
   * @retval X_AXIS   X轴
   * @retval Y_AXIS   Y轴
   * @retval Z_AXIS   Z轴
   */
  uint8_t axisOfTap();

  /**
   * @fn wakeOnMotionInit
   * @brief 初始化移动唤醒
   */
  void wakeOnMotionInit();

  /**
   * @fn setWOMTh
   * @brief 设置某轴加速度计的运动中断唤醒的阈值
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
   * @brief 使能运动唤醒中断
   * @param axis  x/y/z轴
   * @n       X_AXIS_WOM
   * @n       Y_AXIS_WOM
   * @n       Z_AXIS_WOM
   */
  void setWOMInterrupt(uint8_t axis);

  /**
   * @fn enableSMDInterrupt
   * @brief 设置重要运动检测模式并且开启SMD中断
   * @param mode  
   * @n      0: disable SMD
   * @n      2 : SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
   * @n      3 : SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
   */
  void enableSMDInterrupt(uint8_t mode);

  /**
   * @fn readInterruptStatus
   * @brief 读取中断信息，并清除中断
   * @param reg 中断信息寄存器
   * @n      ICM42688_INT_STATUS2    可以获取SMD_INT、WOM_X_INT、WOM_Y_INT、WOM_Z_INT中断信息并且清除
   * @n      ICM42688_INT_STATUS3    可以获取STEP_DET_INT、STEP_CNT_OVF_INT、TILT_DET_INT、WAKE_INT、TAP_DET_INT中断信息并且清除
   * @return 中断信息，无中断时返回0。
   */
  uint8_t readInterruptStatus(uint8_t reg);

  /**
   * @fn setODRAndFSR
   * @brief 设置陀螺仪或者加速计的ODR和 Full-scale range
   * @param who  GYRO/ACCEL/ALL
   * @n       GYRO:代表只设置陀螺仪
   * @n       ACCEL:代表只设置加速计
   * @param ODR 输出数据速率
   * @n       ODR_32KHZ         支持：Gyro/Accel(LN mode)
   * @n       ODR_16KHZ         支持：Gyro/Accel(LN mode)
   * @n       ODR_8KHZ          支持：Gyro/Accel(LN mode)
   * @n       ODR_4KHZ          支持：Gyro/Accel(LN mode)
   * @n       ODR_2KHZ          支持：Gyro/Accel(LN mode)
   * @n       ODR_1KHZ          支持：Gyro/Accel(LN mode)
   * @n       ODR_200HZ         支持：Gyro/Accel(LP or LN mode)
   * @n       ODR_100HZ         支持：Gyro/Accel(LP or LN mode)
   * @n       ODR_50HZ          支持：Gyro/Accel(LP or LN mode)
   * @n       ODR_25KHZ         支持：Gyro/Accel(LP or LN mode)
   * @n       ODR_12_5KHZ       支持：Gyro/Accel(LP or LN mode)
   * @n       ODR_6_25KHZ       支持：Accel(LP mode)
   * @n       ODR_3_125HZ       支持：Accel(LP mode)
   * @n       ODR_1_5625HZ      支持：Accel(LP mode)
   * @n       ODR_500HZ         支持：Accel(LP or LN mode)
   * @param FSR Full-scale range
   * @n       FSR_0      Gyro:±2000dps   /   Accel: ±16g
   * @n       FSR_1      Gyro:±1000dps   /   Accel: ±8g
   * @n       FSR_2      Gyro:±500dps    /   Accel: ±4g
   * @n       FSR_3      Gyro:±250dps    /   Accel: ±2g
   * @n       FSR_4      Gyro:±125dps    /   Accel: 不可选
   * @n       FSR_5      Gyro:±62.5dps   /   Accel: 不可选
   * @n       FSR_6      Gyro:±31.25dps  /   Accel: 不可选
   * @n       FSR_7      Gyro:±15.625dps /   Accel: 不可选
   * @return 设置结果
   * @retval true   设置设置成功
   * @retval flase  选择的参数有误
   */
  bool setODRAndFSR(uint8_t who,uint8_t ODR,uint8_t FSR);

  /**
   * @fn startFIFOMode
   * @brief 启用FIFO
   */
  void startFIFOMode();

  /**
   * @fn sotpFIFOMode
   * @brief 关闭停用FIFO
   */
  void sotpFIFOMode();

  /**
   * @fn getFIFOData
   * @brief 读取FIFO数据，分别读出温度数据、陀螺仪数据、加速计数据并保存等待解析
   */
  void getFIFOData();

  /**
   * @fn setINTMode
   * @brief 设置中断模式
   * @param INTPin  中断引脚 
   * @n       1  使用INT1中断引脚
   * @n       2  使用INT2中断引脚
   * @param INTmode 设置中断模式
   * @n       1  中断锁定模式（即中断触发后会保持极性，清除中断后恢复）
   * @n       0  脉冲模式
   * @param INTPolarity 中断输出的电平极性
   * @n       0  产生中断时中断引脚极性为LOW
   * @n       1  产生中断时中断引脚极性为HIGH
   * @param INTDriveCircuit  
   * @n       0  Open drain
   * @n       1  Push pull
   */
  void setINTMode(uint8_t INTPin,uint8_t INTmode,uint8_t INTPolarity,uint8_t INTDriveCircuit);

  /**
   * @fn startGyroMeasure
   * @brief 启动陀螺仪
   * @param mode 设置陀螺仪的工作模式
   * @n       STANDBY_MODE_ONLY_GYRO 1  设置为备用模式，仅支持陀螺仪
   * @n       LN_MODE  3                设置为低噪声模式
   */
  void startGyroMeasure(uint8_t mode);

  /**
   * @fn startAccelMeasure
   * @brief 启动加速计
   * @param mode 设置加速计的工作模式
   * @n       LP_MODE_ONLY_ACCEL  2     设置为低功耗模式，仅支持加速计
   * @n       LN_MODE  3                设置为低噪声模式
   */
  void startAccelMeasure(uint8_t mode);

  /**
   * @fn startTempMeasure
   * @brief 启动温度计
   */
  void startTempMeasure();
```


## 兼容性

主控               |  正常运行    |   运行失败    |   未测试    | 备注
------------------ | :----------: | :----------: | :---------: | :---------:|
Arduino uno        |              |              |             | 只支持3.3V |
FireBeetle esp32   |      √       |              |             |            |
FireBeetle esp8266 |      √       |              |             |            |
FireBeetle m0      |      √       |              |             |            |
Leonardo           |              |              |             | 只支持3.3V |
Microbit           |      √       |              |             |            |
Arduino MEGA2560   |              |              |             | 只支持3.3V |


## 历史

- 2019/06/25 - 1.0.0 版本

## 创作者

Written by yangfeng(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))

