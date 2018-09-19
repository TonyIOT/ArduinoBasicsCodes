/*
   Shift
   74HC595扩展IO，串行驱动8路LED灯
*/
int latchPin = 10;//锁存引脚
int clockPin = 9; //时钟引脚
int dataPin = 8; //数据引脚

void setup ()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); //让三个脚都是输出状态
}
void loop()
{
  for (int data = 0; data < 255; data++)
  {
    digitalWrite(latchPin, LOW); //将ST_CP口上加低电平让芯片准备好接收数据
    shiftOut(dataPin, clockPin, LSBFIRST, data);
    digitalWrite(latchPin, HIGH); //将ST_CP这个针脚恢复到高电平
    delay(1000); //暂停1秒钟观看显示效果
  }
}






