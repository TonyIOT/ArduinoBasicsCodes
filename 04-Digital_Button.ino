/*
 * Digital_Button
 * 通过按键控制LED灯亮灭
 */

int buttonPin = 2;     // 按键的管脚定义
int ledPin =  9;      // LED灯管脚定义

int buttonState = 0;         // 存储按键状态值

void setup() {
  pinMode(ledPin, OUTPUT);  //设置LED管脚输出模式
  pinMode(buttonPin, INPUT_PULLUP); //设置按键管脚上拉输入模式
}

void loop() {

  buttonState = digitalRead(buttonPin); //读取按键返回状态值
 
  if (buttonState == LOW) { // 若按键被按下
    delay(80); //等待跳过按键抖动的不稳定过程
    if (buttonState == LOW) // 若按键被按下
    {      
      digitalWrite(ledPin, HIGH); // 点亮LED灯
    }
  }
  else {   
    digitalWrite(ledPin, LOW); // 熄灭LED灯
  }

}
