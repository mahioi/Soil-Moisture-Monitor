int sensorPin = A0;
int redLED = 8;
int yellowLED = 9;
int greenLED = 10;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  int moisture = analogRead(sensorPin);
  Serial.print("Soil Moisture Level: ");
  Serial.println(moisture);

  // Reset all LEDs
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  // Adjusted thresholds
  if (moisture > 450) {
    digitalWrite(redLED, HIGH);    // Too dry
  } else if (moisture >= 300) {
    digitalWrite(yellowLED, HIGH); // Moist
  } else {
    digitalWrite(greenLED, HIGH);  // Well watered
  }

  delay(1000);
}
