#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"

//FPS_GT511C1 fps(4, 5);
FPS_GT511C3 fps(10, 11);

void setup() {
  Serial.begin(9600); //set up Arduino's hardware serial UART
  Serial.println("Setup started!");
  delay(100);
  fps.UseSerialDebug = true; // so you can see the messages in the serial debug screen
  Serial.println("Debug true!");
  delay(1000);
  fps.Open(); //send serial command to initialize fps
  Serial.println("Opened scanner!");
  delay(1000);
  fps.SetLED(true);
  Serial.println("LED on!");
  Serial.println("Setup completed!");
}

void loop() {
  // FPS Blink LED Test
//  fps.SetLED(true); // turn on the LED inside the fps
//  delay(1000);
//  fps.SetLED(false);// turn off the LED inside the fps
//  delay(1000);
}
