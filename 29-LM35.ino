/*
 * LM35
 * 模拟温度传感器LM35测试
 */
int potPin = A0;
float temperature = 0;
long value = 0;


void setup() {
  Serial.begin(9600); //设置串口波特率9600
}

void loop() {
  value = analogRead(potPin); //读取模拟输入

  //电压与摄氏度转换：
  //0.00488125=5/1024，0~5V对应模拟口读数1~1024，每10毫伏对应1℃
  temperature = (value * 0.0048828125 * 100);
  
  Serial.print("Temper =  ");
  Serial.print(temperature);
  Serial.println("℃");
  delay(500);

}
