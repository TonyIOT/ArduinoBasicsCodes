/*
   Relay
   继电器控制，通过串口控制继电器开关LED灯
*/
int incomedate = 0;
int relayPin = 13; //继电器引脚

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600); //设置串口波特率9600
}

void loop() {

  if (Serial.available() > 0)//串口接收到数据
  {
    incomedate = Serial.read();//获取串口接收到的数据
    if (incomedate == 'H')
    {
      digitalWrite(relayPin, HIGH);
      Serial.println("LED OPEN!");
    } else if (incomedate == 'L')
    {
      digitalWrite(relayPin, LOW);
      Serial.println("LED CLOSE!");
    }
  }

}
