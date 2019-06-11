#include <Arduino.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=234.01138305664057,668.0113677978514
AudioAnalyzeRMS          rms1;           //xy=436.0056838989258,493.0965747833252
AudioAnalyzePeak         peak1;          //xy=438.0056953430176,458.09659337997437
AudioOutputTDM           tdm3;           //xy=452.00569915771484,666.0965728759766
AudioOutputTDM           tdm2;           //xy=1408.0113143920898,674.0113296508789
AudioConnection          patchCord1(tdm1, 0, tdm3, 0);
AudioConnection          patchCord2(tdm1, 0, peak1, 0);
AudioConnection          patchCord3(tdm1, 0, rms1, 0);
AudioConnection          patchCord4(tdm1, 2, tdm3, 2);
AudioConnection          patchCord5(tdm1, 4, tdm3, 4);
AudioConnection          patchCord6(tdm1, 6, tdm3, 6);
AudioConnection          patchCord7(tdm1, 8, tdm3, 8);
AudioConnection          patchCord8(tdm1, 10, tdm3, 10);
AudioControlCS42448      cs42448_1;      //xy=330.0056915283203,860.0965957641602
// GUItool: end automatically generated code



void setup() {
  Serial.begin(115200);

  Serial.println("Initializing the CS42448...");

  delay(500);

  cs42448_1.enable();
  cs42448_1.adcHighPassFilterDisable();

  Serial.println("...done");

}

void loop() {

  float peak = peak1.read();
  float rms = rms1.read();

  Serial.print("Peak: ");
  Serial.print(peak);
  Serial.print(" RMS: ");
  Serial.println(rms);

  delay(1000);

}