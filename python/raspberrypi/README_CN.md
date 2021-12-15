# DFRobot_ICM42688

- [English Version](./README.md)

ICM-42688-P是一款6轴MEMS运动跟踪设备，它结合了一个3轴陀螺仪和一个3轴加速度计。它有一个可配置的主机接口，支持I3CSM, I2C和SPI串行通信，具有2 kB的FIFO和2个可编程中断，超低功率动态尾流支持，以最大限度地减少系统功耗。

![产品实物图](../../resources/images/SEN0452.jpg)


## 产品链接(https://www.dfrobot.com.cn/)
    SKU：SEN0452

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

要使用这个库，首先将库下载到Raspberry Pi，然后打开例程文件夹。要执行一个例程demox.py，请在命令行中输入python demox.py。例如，要执行get_gyro_accel_temp_data.py例程，你需要输入:
```
python get_gyro_accel_temp_data.py
```

## 方法

```python

  def begin(self):
    '''!
      @brief   开始函数，探测传感器是否正常连接
      @return 初始化结果
      @retval ERR_OK         初始化成功
      @retval ERR_DATA_BUS   总线数据访问错误
      @retval ERR_IC_VERSION 读取的传感器ID有误
    '''

  def get_all_measure_data(self):
    '''!
      @brief Obtain all measurement data
      @n     Get measured temperature
      @n     Get accelerometer value on X-axis
      @n     Get accelerometer value on Y-axis
      @n     Get accelerometer value on Z-axis
      @n     Get gyroscope value on X-axis
      @n     Get gyroscope value on Y-axis
      @n     Get gyroscope value on Z-axis
      @return a value list, content is as follows:
      @n      Temperature value, unit: ℃
      @n      X-axis accelerometer value, unit: mg
      @n      Y-axis accelerometer value, unit: mg
      @n      Z-axis accelerometer value, unit: mg
      @n      X-axis gyroscope value, unit: dps
      @n      Y-axis gyroscope value, unit: dps
      @n      Z-axis gyroscope value, unit: dps
    '''

  def get_temperature(self):
    '''!
      @brief   @brief 获取测量温度值
      @return 温度值 单位：℃
    '''

  def get_accel_x(self):
    '''!
      @brief 获取X轴加速计值
      @return X轴加速计值 单位：mg
    '''

  def get_accel_y(self):
    '''!
      @brief 获取Y轴加速计值
      @return Y轴加速计值 单位：mg
    '''

  def get_accel_z(self):
    '''!
      @brief 获取Z轴加速计值
      @return Z轴加速计值 单位：mg
    '''

  def get_gyro_x(self):
    '''!
      @brief 获取X轴陀螺仪值
      @return X轴陀螺仪值 单位：dps
    '''

  def get_gyro_y(self):
    '''!
      @brief 获取Y轴陀螺仪值
      @return Y轴陀螺仪值 单位：dps
    '''

  def get_gyro_z(self):
    '''!
      @brief 获取Z轴陀螺仪值
      @return Z轴陀螺仪值 单位：dps
    '''

  def tap_detection_init(self,accel_mode):
    '''!
      @brief 敲击事件初始化
      @param accel_mode 加速计工作模式
      @n      0 代表工作在低功耗模式
      @n      1 代表工作在低噪声模式
    '''

  def get_tap_information(self):
    '''!
       @brief 获取敲击信息
    '''


  def number_of_tap(self):
    '''!
      @brief 获取敲击次数，分别是：单击、双击
      @return 敲击次数
      @retval TAP_SINGLE   单击
      @retval TAP_DOUBLE   双击
    '''

  def axis_of_tap(self):
    '''!
      @brief 获取敲击轴，分别是：X\Y\Z轴
      @return 敲击轴
      @retval X_AXIS   X轴
      @retval Y_AXIS   Y轴
      @retval Z_AXIS   Z轴
    '''

  def wake_on_motion_init(self):
    '''!
      @brief 初始化移动唤醒
    '''

  def set_wom_thr(self,axis,threshold):
    '''!
      @brief 设置某轴加速度计的运动中断唤醒的阈值
      @param axis x/y/z轴
      @n       X_AXIS_WOM
      @n       Y_AXIS_WOM
      @n       Z_AXIS_WOM
      @n       ALL
      @param threshold  Range(0-255) [WoM thresholds are expressed in fixed “mg” independent of the selected Range [0g : 1g]; Resolution 1g/256=~3.9mg]
    '''

  def set_wom_interrupt(self,axis):
    '''!
      @brief 使能某轴的唤醒中断
      @param axis  x/y/z轴
      @n       X_AXIS_WOM
      @n       Y_AXIS_WOM
      @n       Z_AXIS_WOM
    '''

  def enable_SMD_interrupt(self,mode):
    '''!
      @brief 设置重要运动检测模式并且开启SMD中断
      @param mode  
      @n      0: disable SMD
      @n      2 : SMD short (1 sec wait) An SMD event is detected when two WOM are detected 1 sec apart
      @n      3 : SMD long (3 sec wait) An SMD event is detected when two WOM are detected 3 sec apart
    '''

  def read_interrupt_status(self,reg):
    '''!
      @brief 读取中断信息，并清除中断
      @param reg 中断信息寄存器
      @n         ICM42688_INT_STATUS2    可以获取SMD_INT、WOM_X_INT、WOM_Y_INT、WOM_Z_INT中断信息并且清除
      @n         ICM42688_INT_STATUS3    可以获取STEP_DET_INT、STEP_CNT_OVF_INT、TILT_DET_INT、WAKE_INT、TAP_DET_INT中断信息并且清除
      @return 中断信息，无中断时返回0。
    '''

  def set_ODR_and_FSR(self,who,ODR,FSR):
    '''!
      @brief 设置陀螺仪或者加速计的ODR和 Full-scale range
      @param who  GYRO/ACCEL/ALL
      @n       GYRO:代表只设置陀螺仪
      @n       ACCEL:代表只设置加速计
      @param ODR 输出数据速率
      @n       ODR_32KHZ         支持：Gyro/Accel(LN mode)
      @n       ODR_16KHZ         支持：Gyro/Accel(LN mode)
      @n       ODR_8KHZ          支持：Gyro/Accel(LN mode)
      @n       ODR_4KHZ          支持：Gyro/Accel(LN mode)
      @n       ODR_2KHZ          支持：Gyro/Accel(LN mode)
      @n       ODR_1KHZ          支持：Gyro/Accel(LN mode)
      @n       ODR_200HZ         支持：Gyro/Accel(LP or LN mode)
      @n       ODR_100HZ         支持：Gyro/Accel(LP or LN mode)
      @n       ODR_50HZ          支持：Gyro/Accel(LP or LN mode)
      @n       ODR_25KHZ         支持：Gyro/Accel(LP or LN mode)
      @n       ODR_12_5KHZ       支持：Gyro/Accel(LP or LN mode)
      @n       ODR_6_25KHZ       支持：Accel(LP mode)
      @n       ODR_3_125HZ       支持：Accel(LP mode)
      @n       ODR_1_5625HZ      支持：Accel(LP mode)
      @n       ODR_500HZ         支持：Accel(LP or LN mode)
      @param FSR Full-scale range
      @n       FSR_0      Gyro:±2000dps   /   Accel: ±16g
      @n       FSR_1      Gyro:±1000dps   /   Accel: ±8g
      @n       FSR_2      Gyro:±500dps    /   Accel: ±4g
      @n       FSR_3      Gyro:±250dps    /   Accel: ±2g
      @n       FSR_4      Gyro:±125dps    /   Accel: 不可选
      @n       FSR_5      Gyro:±62.5dps   /   Accel: 不可选
      @n       FSR_6      Gyro:±31.25dps  /   Accel: 不可选
      @n       FSR_7      Gyro:±15.625dps /   Accel: 不可选
      @return 设置结果
      @retval True   设置设置成功
      @retval False  选择的参数有误
    '''

  def start_FIFO_mode(self):
    '''!
      @brief 启用FIFO
    '''

  def get_FIFO_data(self):
    '''!
      @brief 读取FIFO数据，分别读出温度数据、陀螺仪数据、加速计数据并保存等待解析
    '''

  def stop_FIFO_mode(self):
    '''!
      @brief 关闭停用FIFO
    '''

  def set_INT_mode(self,INT_pin,INT_mode,INT_polarity,INT_drive_circuit):
    '''!
      @brief 设置中断模式
      @param INT_pin  中断引脚 
      @n       1  使用INT1中断引脚
      @n       2  使用INT2中断引脚
      @param INT_mode 设置中断模式
      @n       1  中断锁定模式（即中断触发后会保持极性，清除中断后恢复）
      @n       0  脉冲模式
      @param INT_polarity 中断输出的电平极性
      @n       0  产生中断时中断引脚极性为LOW
      @n       1  产生中断时中断引脚极性为HIGH
      @param INT_drive_circuit  
      @n       0  Open drain
      @n       1  Push pull
    '''

  def start_temp_measure(self):
    '''!
      @brief 启动温度计
    '''

  def start_gyro_measure(self,mode):
    '''!
    ' @brief 启动陀螺仪
    ' @param mode 设置陀螺仪的工作模式
    ' @n          STANDBY_MODE_ONLY_GYRO 1  设置为备用模式，仅支持陀螺仪
    ' @n          LN_MODE  3                设置为低噪声模式
    '''

  def start_accel_measure(self,mode):
    '''!
      @brief 启动加速计
      @param mode 设置加速计的工作模式
      @n          LP_MODE_ONLY_ACCEL  2     设置为低功耗模式，仅支持加速计
      @n          LN_MODE  3                设置为低噪声模式
    '''

  def stop_temp_measure(self):
    '''!
      @brief 关闭温度测量
    '''

  def stop_gyro_measure(self):
    '''!
      @brief 关闭陀螺仪
    '''

  def stop_accel_measure(self):
    '''!
      @brief 关闭加速计
    '''

```


## 兼容性

* RaspberryPi 版本

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |           |            |    √     |         |
| RaspberryPi4 |     √     |            |          |         |

* Python 版本

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |


## 历史

- 2019/06/25 - 1.0.0 版本


## 创作者

Written by yangfeng(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))

