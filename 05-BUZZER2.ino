/*
   BUZZER2
   使用无源蜂鸣器播放《葫芦娃》
*/

//对应音符和频率值
#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

//整首曲子的音符部分
int tune[] =
{
  NOTE_DH1, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_D0,
  NOTE_DH1, NOTE_D6, NOTE_D5, NOTE_DH1, NOTE_D6, NOTE_D0, NOTE_D6,
  NOTE_D6, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_D0, NOTE_D6,
  NOTE_DH1, NOTE_D6, NOTE_D5, NOTE_DH1, NOTE_D6, NOTE_D0,

  NOTE_D1, NOTE_D1, NOTE_D3,
  NOTE_D1, NOTE_D1, NOTE_D3, NOTE_D0,
  NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D5, NOTE_D6,
  NOTE_D5, NOTE_D1, NOTE_D3, NOTE_D0,
  NOTE_DH1, NOTE_D6, NOTE_D6, NOTE_D5, NOTE_D6,
  NOTE_D5, NOTE_D1, NOTE_D2, NOTE_D0,
  NOTE_D7, NOTE_D7, NOTE_D5, NOTE_D3,
  NOTE_D5,
  NOTE_DH1, NOTE_D0, NOTE_D6, NOTE_D6, NOTE_D5, NOTE_D5, NOTE_D6, NOTE_D6,
  NOTE_D0, NOTE_D5, NOTE_D1, NOTE_D3, NOTE_D0,
  NOTE_DH1, NOTE_D0, NOTE_D6, NOTE_D6, NOTE_D5, NOTE_D5, NOTE_D6, NOTE_D6,
  NOTE_D0, NOTE_D5, NOTE_D1, NOTE_D2, NOTE_D0,
  NOTE_D3, NOTE_D3, NOTE_D1, NOTE_DL6,
  NOTE_D1,
  NOTE_D3, NOTE_D5, NOTE_D6, NOTE_D6,
  NOTE_D3, NOTE_D5, NOTE_D6, NOTE_D6,
  NOTE_DH1, NOTE_D0, NOTE_D7, NOTE_D5,
  NOTE_D6,
};

//曲子的节拍，即音符持续时间
float duration[] =
{
  1, 1, 0.5, 0.5, 1,
  0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5,
  0.5, 1, 0.5, 1, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 1, 1,

  1, 1, 1 + 1,
  0.5, 1, 1 + 0.5, 1,
  1, 1, 0.5, 0.5, 1,
  0.5, 1, 1 + 0.5, 1,
  0.5, 0.5, 0.5, 0.5, 1 + 1,
  0.5, 1, 1 + 0.5, 1,
  1 + 1, 0.5, 0.5, 1,
  1 + 1 + 1 + 1,
  0.5, 0.5, 0.5 + 0.25, 0.25, 0.5 + 0.25, 0.25, 0.5 + 0.25, 0.25,
  0.5, 1, 0.5, 1, 1,
  0.5, 0.5, 0.5 + 0.25, 0.25, 0.5 + 0.25, 0.25, 0.5 + 0.25, 0.25,
  0.5, 1, 0.5, 1, 1,
  1 + 1, 0.5, 0.5, 1,
  1 + 1 + 1 + 1,
  0.5, 1, 0.5, 1 + 1,
  0.5, 1, 0.5, 1 + 1,
  1 + 1, 0.5, 0.5, 1,
  1 + 1 + 1 + 1
};

int length;//定义一个变量用来表示共有多少个音符
int tonePin = 8; //蜂鸣器的pin

void setup()
{
  pinMode(tonePin, OUTPUT); //设置蜂鸣器的pin为输出模式
  length = sizeof(tune) / sizeof(tune[0]); //这里用了一个sizeof函数，查出数组里有多少个音符
}

void loop()
{
  for (int x = 0; x < length; x++) //循环音符的次数
  {
    tone(tonePin, tune[x]); //依次播放tune数组元素，即每个音符
    delay(400 * duration[x]); //每个音符持续的时间，即节拍duration，400是调整时间的越大，曲子速度越慢，越小曲子速度越快
    noTone(tonePin);//停止当前音符，进入下一音符
  }
  delay(5000);//等待5秒后，循环重新开始
}

