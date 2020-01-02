#include <Arduino.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioInputTDM            tdm2;           //xy=411,396
AudioOutputTDM           tdm1;           //xy=675,395
AudioConnection          patchCord1(tdm2, 0, tdm1, 0);
AudioConnection          patchCord2(tdm2, 2, tdm1, 2);
AudioConnection          patchCord3(tdm2, 4, tdm1, 4);
AudioConnection          patchCord4(tdm2, 6, tdm1, 6);
AudioConnection          patchCord5(tdm2, 8, tdm1, 8);
AudioConnection          patchCord6(tdm2, 10, tdm1, 10);
AudioConnection          patchCord7(tdm2, 12, tdm1, 12);
AudioConnection          patchCord8(tdm2, 14, tdm1, 14);
AudioControlCS42448      cs42448_1;      //xy=520,570
// GUItool: end automatically generated code


void setup()
{

  delay(1000);
  Serial.begin(115200);

  AudioMemory(64);

  Serial.println("Initializing the CS42448...");

  cs42448_1.enable();
  delay(1000);

  Serial.print("Attempting to read register 0x05: ");
  Serial.println("xxx");
  //Serial.println(cs42448_1.read(0x05), BIN);
  delay(1000);
  Serial.println("Attempting to disable the high pass filter");
  // cs42448_1.adcHighPassFilterDisable();
  delay(1000);
  Serial.print("Attempting to read register 0x05 again: ");
  //Serial.println(cs42448_1.read(0x05), BIN);
  delay(1000);
  cs42448_1.volume(1);
  cs42448_1.inputLevel(15.85);

  Serial.println("...done");
}

void loop()
{
  // Serial.println("Initializing the CS42448...");
  // delay(500);
}