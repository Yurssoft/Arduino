void setup() {
  Serial.begin(115200);
Serial.write("Setup complete!");    
}

// the loop function runs over and over again forever
void loop() {
const byte miBufferON[] = {0xA0, 0x01, 0x01, 0xA2};
Serial.write(miBufferON, sizeof(miBufferON));
  delay(2500);  

const byte miBufferOFF[] = {0xA0, 0x01, 0x00, 0xA1};
Serial.write(miBufferOFF, sizeof(miBufferOFF));
  delay(2500);  
Serial.write("Relays on off!");    
}
