#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(2, 3);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Started");

  // set the data rate for the SoftwareSerial port
  softwareSerial.begin(9600);
}

void loop() {
//  if (softwareSerial.available()) {
//    Serial.write(softwareSerial.read());
//    Serial.println(softwareSerial.read());
//  }
//  if (Serial.available()) {
//    softwareSerial.write(Serial.read());
//    Serial.println(Serial.read());
//  }
while(Serial.available() > 0) {
      char a = softwareSerial.read();
      Serial.write(a);
    }
}
