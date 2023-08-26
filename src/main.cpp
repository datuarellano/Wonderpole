#include <Arduino.h>
#include <AudioDesign.h>
#include <AnalogSmooth.h>
#include <Bounce2.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Encoder.h>
#include <Chrono.h>

#include <hardware.h>
#include <arbitrary_waveforms.h>
#include <NoteFrequencies.h>
#include <tuning-timing.h>
#include <ribbon.h>
#include <accelerometer.h>
#include <inputs.h>
#include <topbutton.h>
#include <mixers.h>

void setup() {
  Serial.begin(115200);
  setupMPU6050();
  setupButtonsSwitches();

  // LEDs
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(LED_R, OUTPUT);
  
  pinMode(RIBBON, INPUT_PULLDOWN);

  setupSGTL5000Audio();
}



void loop() {
  updateButtonsSwitches();
  potsRead();
  volume();
  encoderCyclePresets();
  mainMix();
  changeTuning();

  //// RIBBON ///////////////////////////////////////////////////////////////
  ribbon();

  //// ACCELEROMETER ////////////////////////////////////////////////////////
  accelerometer();
  // accelerometerTest();

  //// INPUTS ///////////////////////////////////////////////////////////////
  inputs();
  
  //// TOP BUTTON TRIGGER ///////////////////////////////////////////////////
  topbutton(); 


}