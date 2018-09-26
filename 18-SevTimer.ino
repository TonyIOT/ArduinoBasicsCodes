/*
   SevTimer
   使用定时器驱动四位数码管实现数字时钟显示
*/
#include "TimerOne.h"
#include "SevSeg.h"

SevSeg sevseg;

int Fen = 0;
int Miao = 0;

byte numDigits = 4; //数码管位数
byte digitPins[] = {2, 3, 12, 13}; //数码管公共极连接Arduino的引脚
byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4}; //数码管a,b,c,d,e,f,g,dp对应引脚
byte hardwareConfig = COMMON_CATHODE ; // 共阴极数码管

void setup() {
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins); //初始化数码管

  Timer1.initialize(1000000);//初始化定时器为1s
  Timer1.attachInterrupt( timerIsr );//设置中断回调函数
}

void loop() {
  sevseg.setNumber(Fen * 100 + Miao, -1); //设置要显示的数据，不显示小数点
  sevseg.refreshDisplay(); // 必须重复运行刷新数码管显示
}

void timerIsr()//定时器中断处理函数
{
  Miao++;
  if (Miao > 59)
  {
    Miao = 0;
    Fen++;
    if (Fen > 59)
      Fen = 0;
  }
}

