void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Started");
  Serial.println("NODE MCU BOARD!");
  Serial.write("Started");
  Serial.write("NODE MCU BOARD!");
}

void loop() {
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("WOW!");
    Serial.write("WOW!");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}
