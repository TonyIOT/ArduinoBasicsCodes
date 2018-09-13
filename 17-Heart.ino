/*
   Heart
   点阵屏心形跳动显示
*/
int leds[8] = {6, 11, 5, 9, 14, 4, 15, 2}; //点阵屏正极引脚
int gnds[8] = {10, 16, 17, 7, 3, 8, 12, 13}; //点阵屏负极引脚

//大“心型”的数据
int table1[8][8] =
{
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
};

//小“心型”的数据
int table2[8][8] =
{
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

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

//心形显示函数
void ledShow(int temp[8][8])
{
  for (int j = 0 ; j < 8; j++)
  {
    digitalWrite(gnds[j], LOW);
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(leds[i], temp[i][j]);
      delayMicroseconds(100);
    }
    digitalWrite(gnds[j], HIGH);
    ledclean();
  }
}

void loop() {

  for (int i = 0; i < 100; i++) //利用for循环达到刷新延时的效果
  {
    ledShow(table1);
  }
  for (int i = 0; i < 50; i++)//利用for循环达到刷新延时的效果
  {
    ledShow(table2);
  }

}

