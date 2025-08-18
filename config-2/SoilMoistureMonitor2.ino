#include <LiquidCrystal.h>

// --- Pin setup ---
const int sensorPin = A0;
const int redLED    = 8;
const int yellowLED = 9;
const int greenLED  = 10;

// LCD wiring: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// --- Thresholds (adjust after calibration) ---
int DRY   = 450;   // too dry
int MOIST = 300;   // borderline

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Soil Monitor 🌱");
  delay(2000);
  lcd.clear();
}

void loop() {
  int moisture = analogRead(sensorPin);

  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  // Show moisture on LCD
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture);
  lcd.print("   "); // clear extra chars

  // Reset LEDs
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  // Check moisture level
  if (moisture > DRY) {
    digitalWrite(redLED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: DRY    ");
  } else if (moisture >= MOIST) {
    digitalWrite(yellowLED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: Moist  ");
  } else {
    digitalWrite(greenLED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: Good   ");
  }

  delay(1000);
}
