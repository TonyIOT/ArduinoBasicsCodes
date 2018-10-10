/*
 * IRrecvDemo
 * 红外控制，接收红外命令控制板载LED灯亮灭
 */

#include <IRremote.h>

int RECV_PIN = 11;
int LED_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value == 0xFFA25D) //开灯的值
    {
      digitalWrite(LED_PIN, LOW);
    } else if (results.value == 0xFF629D) //关灯的值
    {
      digitalWrite(LED_PIN, HIGH);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}







