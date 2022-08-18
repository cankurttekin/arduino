#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27 ,20,4);

String currentlyPlaying;

void setup() {
  lcd.begin();
  Serial.begin(9600);
  Serial.setTimeout(0);
}


void loop() {
  if(Serial.available()){
    lcd.clear();
    currentlyPlaying = Serial.readString();
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(currentlyPlaying);
  delay(1100);
  for (int counter = 0; counter < 16; counter++) {
    lcd.scrollDisplayLeft();
    delay(320);
  }
}
