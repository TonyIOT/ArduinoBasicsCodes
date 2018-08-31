/*
   NixieTube
   控制共阳极数码管显示数字0到9
*/

//设置控制各段的数字IO脚，具体几号引脚对应哪一段，来源为数码管官方引脚图。
int pin_a = 7;
int pin_b = 6;
int pin_c = 5;
int pin_d = 10;
int pin_e = 11;
int pin_f = 8;
int pin_g = 9;
int pin_p = 4;


//根据共阴极数码管段码表定义0~9显示的各段开关状态
int numTable[10][8] = {
  //1为点亮，0为关闭
  //a  b  c  d  e  f  g  dp
  {1, 1, 1, 1, 1, 1, 0, 0},     //0
  {0, 1, 1, 0, 0, 0, 0, 0},     //1
  {1, 1, 0, 1, 1, 0, 1, 0},     //2
  {1, 1, 1, 1, 0, 0, 1, 0},     //3
  {0, 1, 1, 0, 0, 1, 1, 0},     //4
  {1, 0, 1, 1, 0, 1, 1, 0},     //5
  {1, 0, 1, 1, 1, 1, 1, 0},     //6
  {1, 1, 1, 0, 0, 0, 0, 0},     //7
  {1, 1, 1, 1, 1, 1, 1, 0},     //8
  {1, 1, 1, 1, 0, 1, 1, 0},     //9
};


void setup()
{
  for (int i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT); //设置4～11引脚为输出模式
  }
}

void loop()
{
  for (int i = 0; i < 10; i++)//以此显示数字0到9
  {
    digitalWrite(pin_a, numTable[i][0]); //设置a 引脚的电平
    digitalWrite(pin_b, numTable[i][1]); //设置b 引脚的电平
    digitalWrite(pin_c, numTable[i][2]); //设置c 引脚的电平
    digitalWrite(pin_d, numTable[i][3]); //设置d 引脚的电平
    digitalWrite(pin_e, numTable[i][4]); //设置e 引脚的电平
    digitalWrite(pin_f, numTable[i][5]); //设置f 引脚的电平
    digitalWrite(pin_g, numTable[i][6]); //设置g 引脚的电平
    digitalWrite(pin_p, numTable[i][7]); //设置dp引脚的电平
    delay(200);
  }

}
