#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <RTClib.h>

// LCD setup (address 0x27 or 0x3F usually works, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Temperature sensor setup
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// RTC setup
RTC_DS3231 rtc;

void setup() {
  // Initialize serial and components
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  sensors.begin();
  if (!rtc.begin()) {
    lcd.print("RTC Not Found");
    while (1); // Halt
  }

  if (rtc.lostPower()) {
    // Set time to compilation time if RTC lost power
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  DateTime now = rtc.now();

  lcd.clear();
  
  // First row: Temp and time
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(tempC, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  lcd.setCursor(9, 0);
  if (now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());

  // Second row: Date
  lcd.setCursor(0, 1);
  if (now.day() < 10) lcd.print("0");
  lcd.print(now.day());
  lcd.print("/");
  if (now.month() < 10) lcd.print("0");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  delay(1000); // Update every second
}