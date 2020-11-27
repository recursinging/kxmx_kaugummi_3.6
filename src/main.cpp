#include <Arduino.h>
#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSineHires
    sine_hires1;  // xy=411.25001525878906,787.0000228881836
AudioSynthWaveformSineHires
    sine_hires2;      // xy=412.50001525878906,827.0000247955322
AudioInputTDM tdm1;   // xy=420.01137924194336,642.0113143920898
AudioOutputTDM tdm2;  // xy=670.0113372802734,641.0112609863281
AudioConnection patchCord1(sine_hires1, 0, tdm2, 12);
AudioConnection patchCord2(sine_hires2, 0, tdm2, 14);
AudioConnection patchCord3(tdm1, 0, tdm2, 0);
AudioConnection patchCord4(tdm1, 2, tdm2, 2);
AudioConnection patchCord5(tdm1, 4, tdm2, 4);
AudioConnection patchCord6(tdm1, 6, tdm2, 6);
AudioConnection patchCord7(tdm1, 8, tdm2, 8);
AudioConnection patchCord8(tdm1, 10, tdm2, 10);
AudioControlCS42448 cs42448_1;  // xy=534.0056762695312,872.346607208252
// GUItool: end automatically generated code

void setup() {
  AudioMemory(64);
  pinMode(LED_BUILTIN, OUTPUT);
  
  delay(500);
  Serial.begin(115200);
  Serial.println("Initializing the CS42448...");

  // Enable the codec
  cs42448_1.enable();
  delay(100);

  Serial.print("Here are the default settings of register 0x05: ");
  Serial.println(cs42448_1.read(0x05), BIN);
  delay(100);
  
  Serial.println("Set the ADC to differential mode...");
  cs42448_1.adcDifferentialMode();
  
  Serial.println("Freeze the high pass filter...");
  cs42448_1.adcHighPassFilterFreeze();
  delay(100);
  
  Serial.print("Here are the updated settings of register 0x05: ");
  Serial.println(cs42448_1.read(0x05), BIN);
  delay(100);
  
  // Set the codec output and input levels
  cs42448_1.volume(1);
  cs42448_1.inputLevel(15.85);

  // These two sine waves are for verifying the output of channels 7 and 8 respectively
  sine_hires1.frequency(1000);
  sine_hires1.amplitude(1);

  sine_hires2.frequency(10000);
  sine_hires2.amplitude(1);

  Serial.println("...done");
}

void loop() {
  // Just blink to indicate when the codec is initialized...
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}