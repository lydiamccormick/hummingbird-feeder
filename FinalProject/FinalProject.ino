#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(60, 6);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int waterLevel = 0;
int waterPin = 0;

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);

void setup() {
Serial.begin(9600);
analogWrite(6, 100);
lcd.begin(16, 2);
strip.begin();
strip.clear();
strip.show();
}

void loop() {
lcd.setCursor(1,0);
writeLevel();
}

void writeLevel() {
waterLevel = analogRead(waterPin);
Serial.println(waterLevel);

if(waterLevel < 210) {
  lcd.print("Fill Level:");
  lcd.setCursor(1,1);
  lcd.print("Running Low");
  redFill();
  delay(100);
  strip.clear();
  lcd.clear();
}
else if (waterLevel > 250) {
  lcd.print("Fill Level:");
  lcd.setCursor(1,1);
  lcd.print("Looking Good");
  greenFill();
  delay(100);
  strip.clear();
  lcd.clear();
}
else {
  lcd.print("Fill Level:");
  lcd.setCursor(1,1);
  lcd.print("Almost Low");
  blueFill();
  delay(100);
  strip.clear();
  lcd.clear();

}

}

void greenFill() {
  strip.clear();
  strip.fill(green);
  strip.show();
}

void blueFill() {
  strip.clear();
  strip.fill(blue);
  strip.show();
}

void redFill() {
  strip.clear();
  strip.fill(red);
  strip.show();
}






