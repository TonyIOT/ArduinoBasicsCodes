/*
   Random
   通过Random随机显示0到9的数字
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

int num;

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

  randomSeed(analogRead(0));
}

//根据索引显示数字
void showNum(int index)
{
  digitalWrite(pin_a, numTable[index][0]); //设置a 引脚的电平
  digitalWrite(pin_b, numTable[index][1]); //设置b 引脚的电平
  digitalWrite(pin_c, numTable[index][2]); //设置c 引脚的电平
  digitalWrite(pin_d, numTable[index][3]); //设置d 引脚的电平
  digitalWrite(pin_e, numTable[index][4]); //设置e 引脚的电平
  digitalWrite(pin_f, numTable[index][5]); //设置f 引脚的电平
  digitalWrite(pin_g, numTable[index][6]); //设置g 引脚的电平
  digitalWrite(pin_p, numTable[index][7]); //设置dp引脚的电平

}

void loop()
{
  num = random(10); //产生随机数
  showNum(num); //显示随机数
  delay(500);
}
