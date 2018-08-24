/*
   AutoLed
   通过光敏电阻检测环境光，进而控制LED灯亮度
*/

int ledPin = 10;

int sensorValue = 0; //保存读到的传感器模拟值
int ledValue = 0;  //保存LED灯占空比

void setup()
{
  pinMode(ledPin, OUTPUT);     //数字口要选择带~号的具有pwm功能的输出口
}

void loop()
{
  sensorValue = analogRead(A0);     //读取A0模拟口的数值
  ledValue = map(sensorValue, 400, 800, 0, 200); //将400到800之间的数据映射成0到200之间的数据
  analogWrite(ledPin, ledValue);   //PWM控制LED灯亮度
  delay(100);
}
