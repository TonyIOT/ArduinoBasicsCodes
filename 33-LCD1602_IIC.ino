/*
 * LCD1602 IIC驱动
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  //配置LCD地址及行列

void setup()
{
  lcd.init(); //初始化LCD
  lcd.backlight(); //打开背光
}

void loop()
{
  lcd.setCursor(2,0);//设置显示位置
  lcd.print("LCD1602 IIC");//显示字符数据
  lcd.setCursor(0,1);//设置显示位置
  lcd.print("JUST USE TWO IO");//显示字符数据
}
