#define MQ135_PIN 34

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("📊 Starting Threshold Calibration...");
}

void loop() {
  int gasValue = analogRead(MQ135_PIN);
  Serial.print("Gas Reading: ");
  Serial.println(gasValue);
  delay(1000); // 1-second gap
}
