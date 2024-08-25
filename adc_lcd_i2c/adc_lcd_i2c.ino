#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int adc10, adc8, adc2, x;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte numPins = 8;
byte pins[] = {2, 3, 4, 5, 6, 7,8,9};
byte num;

void adc2puerto2() {
  num = map(adc2, 0, 3, 0, 3);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc2puerto4() {
  num = map(adc2, 0, 3, 0, 15);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc2puerto8() {
  num = map(adc2, 0, 3, 0, 255);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc8puerto2() {
  num = map(adc8, 0, 255, 0, 3);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc8puerto4() {
  num = map(adc8, 0, 255, 0, 15);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc8puerto8() {
  num = map(adc8, 0, 255, 0, 255);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc10puerto2() {
  num = map(adc10, 0, 1023, 0, 3);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc10puerto4() {
  num = map(adc10, 0, 1023, 0, 15);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void adc10puerto8() {
  num = map(adc10, 0, 1023, 0, 255);
  for (byte i = 0; i < numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}
void resolucion10() {
  lcd.setCursor(0, 0);
  lcd.print("V");
  lcd.setCursor(2, 0);
  lcd.print(adc10 * 5.0 / 1024);
  lcd.setCursor(7, 0);
  lcd.print("T");
  lcd.setCursor(9, 0);
  lcd.print(adc10 * 5.0 / 1024 * 100);
}
void resolucion8() {
  lcd.setCursor(0, 0);
  lcd.print("V");
  lcd.setCursor(2, 0);
  lcd.print(adc8 * 5.0 / 256);
  lcd.setCursor(7, 0);
  lcd.print("T");
  lcd.setCursor(9, 0);
  lcd.print(adc8 * 5.0 / 256 * 100);
}
void resolucion2() {
  lcd.setCursor(0, 0);
  lcd.print("V");
  lcd.setCursor(2, 0);
  lcd.print(adc2 * 5.0 / 4);
  lcd.setCursor(7, 0);
  lcd.print("T");
  lcd.setCursor(9, 0);
  lcd.print(adc2 * 5.0 / 4 * 100);
}

void setup()
{
  // initialize the LCD
  Serial.begin(9600);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
  lcd.clear();  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  adc10 = analogRead(A0);
  adc8 = map(adc10, 0, 1023, 0, 255);
  adc2 = map(adc10, 0, 1023, 0, 3);
  resolucion8();
  adc8puerto8();
  delay(1000);
}
