/*
 * Matrix
 * 点阵屏显示驱动
 */
int leds[8] = {6, 11, 5, 9, 14, 4, 15, 2}; //点阵屏正极引脚
int gnds[8] = {10, 16, 17, 7, 3, 8, 12, 13}; //点阵屏负极引脚


void setup() {
  for (int i = 0; i < 8; i++)
  {
    pinMode(leds[i], OUTPUT);
    pinMode(gnds[i], OUTPUT);
    digitalWrite(gnds[i], HIGH); //负极引脚拉高，熄灭所有LED
  }
}

void ledopen()
{
  for (int i = 0; i < 8; i++)//将点阵屏正极拉高，负极拉低，开启显示
  {
    digitalWrite(leds[i], HIGH);
    digitalWrite(gnds[i], LOW);
  }
}

void ledclean()
{
  for (int i = 0; i < 8; i++)//将点阵屏正极ladies，负极拉高，关断显示
  {
    digitalWrite(leds[i], LOW); 
    digitalWrite(gnds[i], HIGH);
  }
}

//逐列扫描
void ledCol()
{
  for (int i = 0 ; i < 8; i++)
  {
    digitalWrite(gnds[i], LOW); 
    for (int j = 0; j < 8; j++)
    {
      digitalWrite(leds[j], HIGH);
      delay(40);
    }
    digitalWrite(gnds[i], HIGH);
    ledclean();
  }
}

//逐行扫描
void ledRow()
{
  for (int i = 0 ; i < 8; i++)
  {
    digitalWrite(leds[i], HIGH);
    for (int j = 0; j < 8; j++)
    {
      digitalWrite(gnds[j], LOW);
      delay(40);
    }
    digitalWrite(leds[i], LOW);
    ledclean();
  }
}

void loop() {

  ledopen(); //全部打开
  delay(500);
  ledclean(); //全部关闭
  delay(500);
  ledCol(); //列扫描
  ledRow(); //行扫描

}












