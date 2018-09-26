/*
 * Led_Flash
 * 依次点亮1~6号LED灯，依次熄灭6~1号LED灯，如此循环
 */

int delayTime = 200;
int ledPin;

void setup()
{
  for (ledPin = 1; ledPin < 7; ledPin++) //依次设置1~6个数字引脚为输出模式
  { 
    pinMode(ledPin, OUTPUT); //设置第ledPin个引脚为输出模式
  }
}
void loop()
{
  for (ledPin = 1; ledPin < 7; ledPin++) //每隔delayTime依次点亮1~6引脚相连的led灯
  {
    digitalWrite(ledPin, HIGH); //点亮ledPin引脚相连的led灯
    delay(delayTime);//延时delayTime
  }
  for (ledPin = 6; ledPin > 0; ledPin--) //每隔delayTime依次熄灭6~1引脚相连的led灯
  {
    digitalWrite(ledPin, LOW); //熄灭ledPin引脚相连的led灯
    delay(delayTime);//延时delayTime
  }
}
