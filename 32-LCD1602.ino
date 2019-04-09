/*
 * LCD1602
 * 1602驱动库的使用
 */
 
#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(2, 0);
  lcd.print("Hello World!");
  
  lcd.setCursor(0, 1);
  lcd.print("Second: ");
  lcd.print(millis() / 1000);
}

