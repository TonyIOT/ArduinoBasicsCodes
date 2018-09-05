/*
 * SevSegFour
 * 驱动四位数码管显示0到9999
 */
#include "SevSeg.h"

SevSeg sevseg;

byte numDigits = 4; //数码管位数
byte digitPins[] = {2, 3, 12, 13}; //数码管公共极连接Arduino的引脚
byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4}; //数码管a,b,c,d,e,f,g,dp对应引脚
byte hardwareConfig = COMMON_CATHODE ; // 共阴极数码管

int numToShow = 0;
int delaycount = 0;

void setup() {
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins); //初始化数码管
}

void loop() {

  delaycount++;
  if (delaycount  == 1000) { //通过变量自加来达到延时效果，如果使用delay函数则会打断数码管显示
    delaycount = 0;
    numToShow++;
  }

  if (numToShow > 9999)
  {
    numToShow = 0;
  }
  
  sevseg.setNumber(numToShow, -1); //设置要显示的数据，不显示小数点
  sevseg.refreshDisplay(); // 必须重复运行刷新数码管显示

}





