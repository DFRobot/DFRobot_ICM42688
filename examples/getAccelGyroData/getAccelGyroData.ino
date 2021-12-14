/*!
 * @file getAccelGyroData.ino
 * @brief Get temperature, gyroscope and accelerometer data
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-05-13
 * @url  https://github.com/DFRobot/DFRobot_ICM42688
 */
#include <DFRobot_ICM42688.h>
//Device I2C address is decided by SDO, SDO pull up, address is 0x69, SDO pull down, address is 0x68 (SDO default to internal pull-up)
//DFRobot_ICM42688_I2C_L_ADDR 0x68 
//DFRobot_ICM42688_I2C_H_ADDR 0x69
//DFRobot_ICM42688_I2C ICM42688(/*i2cAddr = */ DFRobot_ICM42688_I2C_H_ADDR);
DFRobot_ICM42688_SPI ICM42688(/* csPin= */5);

void setup() {
  int ret;
  Serial.begin(9600);
  while((ret =ICM42688.begin()) !=0){
    if(ret == -1){
      Serial.println("bus data access error");
    } else 
      Serial.println("Chip versions do not match");
    delay(1000);
  }
  Serial.println("ICM43688 begin success!!!");
  /**
   * Set ODR and Full-scale range of gyroscope or accelerometer
   * who  GYRO/ACCEL/ALL
   *      GYRO: indicate only set gyroscope
   *      ACCEL: indicate only set accelerometer
   * ODR  Output data rate
   *      ODR_32KHZ         Support: Gyro/Accel(LN mode)
   *      ODR_16KHZ         Support: Gyro/Accel(LN mode)
   *      ODR_8KHZ          Support: Gyro/Accel(LN mode)
   *      ODR_4KHZ          Support: Gyro/Accel(LN mode)
   *      ODR_2KHZ          Support: Gyro/Accel(LN mode)
   *      ODR_1KHZ          Support: Gyro/Accel(LN mode)
   *      ODR_200HZ         Support: Gyro/Accel(LP or LN mode)
   *      ODR_100HZ         Support: Gyro/Accel(LP or LN mode)
   *      ODR_50HZ          Support: Gyro/Accel(LP or LN mode)
   *      ODR_25KHZ         Support: Gyro/Accel(LP or LN mode)
   *      ODR_12_5KHZ       Support: Gyro/Accel(LP or LN mode)
   *      ODR_6_25KHZ       Support: Accel(LP mode)
   *      ODR_3_125HZ       Support: Accel(LP mode)
   *      ODR_1_5625HZ      Support: Accel(LP mode)
   *      ODR_500HZ         Support: Accel(LP or LN mode)
   * FSR  Full-scale range
   *      FSR_0      Gyro:±2000dps   /   Accel: ±16g
   *      FSR_1      Gyro:±1000dps   /   Accel: ±8g
   *      FSR_2      Gyro:±500dps    /   Accel: ±4g
   *      FSR_3      Gyro:±250dps    /   Accel: ±2g
   *      FSR_4      Gyro:±125dps    /   Accel: not optional
   *      FSR_5      Gyro:±62.5dps   /   Accel: not optional
   *      FSR_6      Gyro:±31.25dps  /   Accel: not optional
   *      FSR_7      Gyro:±15.625dps /   Accel: not optional
   *  true indicate the setting succeeds; flase indicate selected parameter is wrong
   */
  ICM42688.setODRAndFSR(/* who= */GYRO,/* ODR= */ODR_1KHZ, /* FSR = */FSR_0);
  ICM42688.setODRAndFSR(/* who= */ACCEL,/* ODR= */ODR_500HZ, /* FSR = */FSR_0);
  /**
   * Set gyroscope and accelerometer working mode
   * mode 
   *      OFF_MODE   0              Disable
   *      STANDBY_MODE_ONLY_GYRO 1  Set stanby mode, only support gyroscope
   *      LP_MODE_ONLY_ACCEL  2     Set low-power mode, only support accelerometer
   *      LN_MODE  3                Set low-noise mode
   */
  ICM42688.startTempMeasure();
  ICM42688.startGyroMeasure(/* mode= */LN_MODE);
  ICM42688.startAccelMeasure(/* mode= */LN_MODE);
}

void loop() {
  float accelDataX,accelDataY,accelDataZ,gyroDataX,gyroDataY,gyroDataZ,tempData;
  tempData= ICM42688.getTemperature();
  accelDataX = ICM42688.getAccelDataX();
  accelDataY= ICM42688.getAccelDataY();
  accelDataZ= ICM42688.getAccelDataZ();
  gyroDataX= ICM42688.getGyroDataX();
  gyroDataY= ICM42688.getGyroDataY();
  gyroDataZ= ICM42688.getGyroDataZ();
  Serial.print("Temperature: ");
  Serial.print(tempData);
  Serial.println(" C");

  Serial.print("Accel_X: ");
  Serial.print(accelDataX);
  Serial.print(" mg   Accel_Y:");
  Serial.print(accelDataY);
  Serial.print(" mg   Accel_Z: ");
  Serial.print(accelDataZ);
  Serial.println(" mg");

  Serial.print("Gyro_X: ");
  Serial.print(gyroDataX);
  Serial.print(" dps   Gyro_Y: ");
  Serial.print(gyroDataY);
  Serial.print(" dps   Gyro_Z: ");
  Serial.print(gyroDataZ);
  Serial.println(" dps");
  delay(1000);
}
