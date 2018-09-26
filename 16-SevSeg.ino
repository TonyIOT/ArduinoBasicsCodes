/*
 * SevSeg
 * 使用数码管库驱动数码管，根据A0模拟输入显示对应数字
 */
 
#include "SevSeg.h"

SevSeg sevseg;

byte numDigits = 1; //数码管位数
byte digitPins[] = {3, 2, 2, 2}; //数码管公共极连接Arduino的引脚
byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4}; //数码管a,b,c,d,e,f,g,dp对应引脚
byte hardwareConfig = COMMON_CATHODE ; // 共阴极数码管

int readValue = 0; //保存读到的模拟值
int showValue = 0; //需要显示的数据

void setup() {
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins); //初始化数码管
}

void loop() {
  readValue = analogRead(A0); //读取A0模拟口的数值（0-5V 对应0-1023取值）
  showValue = map(readValue, 0, 1023, 0, 9); //将0-1023之间的数据映射成0到9之间的数据
  sevseg.setNumber(showValue, 1); //数码管显示
  sevseg.refreshDisplay(); // 必须重复运行刷新数码管显示
}

