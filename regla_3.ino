#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
int s1, s2, m1, m2, num = 0, del=0;

void setup() {  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Coloque el sensor");
  lcd.setCursor(0,1);
  lcd.print("en 0cm");
  delay(3000);
  s1 = analogRead(A0);
  s2 = analogRead(A1);
  if (s1 > 15) {
    s1 = 1;
  }
  else {
    s1 = 0;
  }
  if (s2 > 15) {
    s2 = 1;
  }
  else {
    s2 = 0;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("REGLA DIGITAL");
  lcd.setCursor(0,2);
  lcd.print(num);
  lcd.setCursor(3,2);
  lcd.print("cm");
}
void loop() {
  // put your main code here, to run repeatedly:
  while (s1 == 0 && s2 == 0) {
    conteo();
    delay(del);
    if (analogRead(A0)>15 && analogRead(A1)<15) {
      num++;
      s1 = 1, s2 = 0;
    }
    else if (analogRead(A0)<15 && analogRead(A1)>15) {
      num--;
      s1 = 0, s2 = 1;
    }
  }
  while (s1 == 0 && s2 == 1) {
    conteo();
    delay(del);
    if (analogRead(A0)<15 && analogRead(A1)<15) {
      num++;
      s1 = 0, s2 = 0;
    }
    else if (analogRead(A0)>15 && analogRead(A1)>15) {
      num--;
      s1 = 1, s2 = 1;
      }
  } 
  while (s1 == 1 && s2 == 0) {
    conteo();
    delay(del);
    if (analogRead(A0)>15 && analogRead(A1)>15) {
      num++;
      s1 = 1, s2 = 1;
    }
    else if (analogRead(A0)<15 && analogRead(A1)<15) {
      num--;
      s1 = 0, s2 = 0;
    }
  } while (s1 == 1 && s2 == 1) {
    conteo();
    delay(del);
    if (analogRead(A0)<15 && analogRead(A1)>15) {
      num++;
      s1 = 0, s2 = 1;
    }
    else if (analogRead(A0)>15 && analogRead(A1)<15) {
      num--;
      s1 = 1, s2 = 0;
    }
  }
}
void conteo(){
  if (num<10 && num >=0){
    lcd.setCursor(0,2);
    lcd.print("0");
    lcd.setCursor(1,2);
    lcd.print(num);
  }
  else if (num>9){
    lcd.setCursor(0,2);
    lcd.print(num);
      }
      else if (num<0){
        num = 0;
      lcd.setCursor(1,2);
      lcd.print(num);  
      }
}
