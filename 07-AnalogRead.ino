/*
   AnalogRead
   通过电位器改变LED灯亮度
*/

int ledPin = 10;

int readValue = 0; //保存读到的模拟值
int ledValue = 0;  //保存LED灯占空比

void setup()
{
  pinMode(ledPin, OUTPUT);     //数字口要选择带~号的具有pwm功能的输出口
}

void loop()
{
  readValue = analogRead(A0);     //读取A0模拟口的数值（0-5V 对应 0-1204取值）
  ledValue = map(readValue, 0, 1024, 0, 255); //将0到1024之间的数据映射成0到255之间的数据
  analogWrite(ledPin, ledValue);   //PWM最大取值255
}
