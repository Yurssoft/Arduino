void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Started");

  // set the data rate for the SoftwareSerial port
  delay(100);
    Serial.write("Complete");
}

void loop() {

delay(1000);

const byte open[] = {0x55, 0xAA, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01};
Serial.write(open, sizeof(open));

while(Serial.available() > 0) {
      char a = Serial.read();
      Serial.write(a);
    }
    
delay(1000);

const byte ledOn[] = {0x55, 0xAA, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x12, 0x00, 0x13, 0x01};
Serial.write(ledOn, sizeof(ledOn));

while(Serial.available() > 0) {
      char a = Serial.read();
      Serial.write(a);
    }    
}
