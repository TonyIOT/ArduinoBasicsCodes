/*
 * LCD1602_bit4
 * LCD1602驱动显示Hello World
 */
 
int LCD1602_RS = 7;
int LCD1602_EN = 6;
int DB[4] = { 2, 3, 4, 5};

/*
 * LCD写命令
 */
void LCD_Command_Write(int command)
{
  int i, temp;
  digitalWrite( LCD1602_RS, LOW);
  digitalWrite( LCD1602_EN, LOW);

  temp = command & 0xf0;
  for (i = DB[0]; i <= 5; i++)
  {
    digitalWrite(i, temp & 0x80);
    temp <<= 1;
  }

  digitalWrite( LCD1602_EN, HIGH);
  delayMicroseconds(1);
  digitalWrite( LCD1602_EN, LOW);

  temp = (command & 0x0f) << 4;
  for (i = DB[0]; i <= 5; i++)
  {
    digitalWrite(i, temp & 0x80);
    temp <<= 1;
  }

  digitalWrite( LCD1602_EN, HIGH);
  delayMicroseconds(1);
  digitalWrite( LCD1602_EN, LOW);
}

/*
 * LCD写数据
 */
void LCD_Data_Write(int dat)
{
  int i = 0, temp;
  digitalWrite( LCD1602_RS, HIGH);
  digitalWrite( LCD1602_EN, LOW);

  temp = dat & 0xf0;
  for (i = DB[0]; i <= 5; i++)
  {
    digitalWrite(i, temp & 0x80);
    temp <<= 1;
  }

  digitalWrite( LCD1602_EN, HIGH);
  delayMicroseconds(1);
  digitalWrite( LCD1602_EN, LOW);

  temp = (dat & 0x0f) << 4;
  for (i = DB[0]; i <= 5; i++)
  {
    digitalWrite(i, temp & 0x80);
    temp <<= 1;
  }

  digitalWrite( LCD1602_EN, HIGH);
  delayMicroseconds(1);
  digitalWrite( LCD1602_EN, LOW);
}

/*
 * LCD设置光标位置
 */
void LCD_SET_XY( int x, int y )
{
  int address;
  if (y == 0)    address = 0x80 + x;
  else          address = 0xC0 + x;
  LCD_Command_Write(address);
}

/*
 * LCD写一个字符
 */
void LCD_Write_Char( int x, int y, int dat)
{
  LCD_SET_XY( x, y );
  LCD_Data_Write(dat);
}

/*
 * LCD写字符串
 */
void LCD_Write_String(int X, int Y, char *s)
{
  LCD_SET_XY( X, Y );    //设置地址
  while (*s)             //写字符串
  {
    LCD_Data_Write(*s);
    s ++;
  }
}

void setup (void)
{
  int i = 0;
  for (i = 2; i <= 7; i++)
  {
    pinMode(i, OUTPUT);
  }
  delay(100);
  LCD_Command_Write(0x28);//显示模式设置4线 2行 5x7
  delay(50);
  LCD_Command_Write(0x06);//显示光标移动设置
  delay(50);
  LCD_Command_Write(0x0c);//显示开及光标设置
  delay(50);
  LCD_Command_Write(0x80);//设置数据地址指针
  delay(50);
  LCD_Command_Write(0x01);//显示清屏
  delay(50);

}

void loop (void)
{
  LCD_Write_String(2, 0, "Hello World!");
  LCD_Write_String(6, 1, "--TonyCode");
}

