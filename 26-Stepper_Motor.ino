/*
 * Stepper_Motor
 * 步进电机驱动，实现正反转
 */
void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void clockwise(int num)
{
  for (int count = 0; count < num; count++)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, HIGH);
      delay(3);
      digitalWrite(i, LOW);
    }
  }
}

void anticlockwise(int num)
{
  for (int count = 0; count < num; count++)
  {
    for (int i = 5; i > 1; i--)
    {
      digitalWrite(i, HIGH);
      delay(3);
      digitalWrite(i, LOW);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  clockwise(512);
  delay(10);
  anticlockwise(512);
}
