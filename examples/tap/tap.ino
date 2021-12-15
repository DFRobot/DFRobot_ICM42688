/*!
 * @file tap.ino
 * @brief Tap detection
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version V1.0
 * @date 2021-05-13
 * @url  https://github.com/DFRobot/DFRobot_ICM42688
 */
#include <DFRobot_ICM42688.h>
//Device I2C address is decided by SDO, SDO pull up, address is 0x69, SDO pull down, address is 0x68 (SDO default internal pull up)
//DFRobot_ICM42688_I2C_L_ADDR 0x68 
//DFRobot_ICM42688_I2C_H_ADDR 0x69
//DFRobot_ICM42688_I2C ICM42688(/*i2cAddr = */ DFRobot_ICM42688_I2C_H_ADDR);
DFRobot_ICM42688_SPI ICM42688(/* csPin= */5);
uint8_t flag = 0;

void interEvent(){
  flag = 1;
}

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
  Serial.println("ICM42688 begin success!!!");
  #if defined(ESP32) || defined(ESP8266)
  //Use D6 pin as interrupt pin by default, or select other non-conflicting pins as external interrupt pin
  attachInterrupt(digitalPinToInterrupt(D9)/*Query the interrupt number of the D9 pin*/,interEvent,FALLING);
  #elif defined(ARDUINO_SAM_ZERO)
  //Use 5 pin as interrupt pin by default, or select other non-conflicting pins as external interrupt pin
  attachInterrupt(digitalPinToInterrupt(6)/*Query the interrupt number of the 5 pin*/,interEvent,FALLING);
  #else
  /*    The Correspondence Table of AVR Series Arduino Interrupt Pins And Terminal Numbers
   * ---------------------------------------------------------------------------------------
   * |                                        |  DigitalPin  | 2  | 3  |                   |
   * |    Uno, Nano, Mini, other 328-based    |--------------------------------------------|
   * |                                        | Interrupt No | 0  | 1  |                   |
   * |-------------------------------------------------------------------------------------|
   * |                                        |    Pin       | 2  | 3  | 21 | 20 | 19 | 18 |
   * |               Mega2560                 |--------------------------------------------|
   * |                                        | Interrupt No | 0  | 1  | 2  | 3  | 4  | 5  |
   * |-------------------------------------------------------------------------------------|
   * |                                        |    Pin       | 3  | 2  | 0  | 1  | 7  |    |
   * |    Leonardo, other 32u4-based          |--------------------------------------------|
   * |                                        | Interrupt No | 0  | 1  | 2  | 3  | 4  |    |
   * |--------------------------------------------------------------------------------------
   */
  /*                      The Correspondence Table of micro:bit Interrupt Pins And Terminal Numbers
   * ---------------------------------------------------------------------------------------------------------------------------------------------
   * |             micro:bit                       | DigitalPin |P0-P20 can be used as an external interrupt                                     |
   * |  (When using as an external interrupt,      |---------------------------------------------------------------------------------------------|
   * |no need to set it to input mode with pinMode)|Interrupt No|Interrupt number is a pin digital value, such as P0 interrupt number 0, P1 is 1 |
   * |-------------------------------------------------------------------------------------------------------------------------------------------|
   */
  attachInterrupt(/*Interrupt No*/0,interEvent,FALLING);//Enable the external interrupt 0, connect INT1/2 to the digital pin of the main control: 
     //UNO(2), Mega2560(2), Leonardo(3), microbit(P0).
  #endif
  /**
   * Set interrupt mode
   * INTPin  Interrupt pin : 1 represents using INT1 interrupt pin; 2 represents using INT2 interrupt pin
   * INTmode Set interrupt mode, 1 represents interrupt lock mode (polarity remain unchanged after interrupt trigger, and restore after clearing interrupt); 0 represents pulse mode
   * INTPolarity Level polarity output by interrupt, 0 represents interrupt pin polarity is LOW when producing interrupt, 1 represents interrupt pin polarity is HIGH when producing interrupt
   * INTDriveCircuit  0 represents Open drain  1 represents Push pull
   */
  ICM42688.setINTMode(/*INTPin=*/1, /*INTmode=*/0, /*INTPolarity=*/0, /*INTDriveCircuit=*/1);
  /**
   * Tap detection init
   * accelMode Accelerometer operating mode: 0 for operating in low-power mode, 1 for operating in low-noise mode
   */
  ICM42688.tapDetectionInit(/* accelMode= */1);
}
void loop() {
  uint8_t status;
  uint32_t tapNum;
  uint8_t tapAxis;
  if(flag == 1){
    flag =0;
    /**
     * Read Interrupt information and clear interrupt
     * reg Interrupt information register
     *     ICM42688_INT_STATUS2    Obtain interrupt information of ICM42688_SMD_INT, ICM42688_WOM_X_INT, ICM42688_WOM_Y_INT and ICM42688_WOM_Z_INT and clear them
     *     ICM42688_INT_STATUS3    Obtain interrupt information of ICM42688_TAP_DET_INT and clear it
     * Return interrupt information, return 0 when no interrupt
     */
    status= ICM42688.readInterruptStatus(/* reg= */ICM42688_INT_STATUS3);
    if(status & ICM42688_TAP_DET_INT){
      ICM42688.getTapInformation();  //Get tap information
      tapNum = ICM42688.numberOfTap();  //Get the number of tap: single-tap TAP_SINGLE or double tap TAP_DOUBLE
      tapAxis = ICM42688.axisOfTap();  //Get the axis on which tap occurred: X_AXIS, Y_AXIS or Z_AXIS
      if(tapAxis == X_AXIS){
        Serial.print("X axis: ");
      } else if(tapAxis == Y_AXIS){
        Serial.print("Y axis: ");
      } else if(tapAxis == Z_AXIS){
        Serial.print("Z axis: ");
      }
      if(tapNum == TAP_SINGLE){
        Serial.println("Single");
      } else if(tapNum == TAP_DOUBLE){
        Serial.println("Double");
      }
    }
  }
}
