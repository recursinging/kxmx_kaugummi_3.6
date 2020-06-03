#include <Arduino.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=411,219
AudioSynthWaveformSine   sine2;          //xy=411,252
AudioInputTDM            tdm2;           //xy=411,396
AudioSynthWaveformSine   sine4;          //xy=411,575
AudioSynthWaveformSine   sine3;          //xy=413,537
AudioOutputTDM           tdm1;           //xy=675,395
AudioConnection          patchCord1(sine1, 0, tdm1, 0);
AudioConnection          patchCord2(sine2, 0, tdm1, 2);
AudioConnection          patchCord3(tdm2, 4, tdm1, 4);
AudioConnection          patchCord4(tdm2, 6, tdm1, 6);
AudioConnection          patchCord5(tdm2, 8, tdm1, 8);
AudioConnection          patchCord6(tdm2, 10, tdm1, 10);
AudioConnection          patchCord7(sine4, 0, tdm1, 14);
AudioConnection          patchCord8(sine3, 0, tdm1, 12);
AudioControlCS42448      cs42448_1;      //xy=518,634
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

  sine1.frequency(1000);
  sine1.amplitude(1);
  
  sine2.frequency(2000);
  sine2.amplitude(1);
  
  sine3.frequency(4000);
  sine3.amplitude(1);
  
  sine4.frequency(4000);
  sine4.amplitude(1);
  
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("...done");
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}