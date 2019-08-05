#include <Arduino.h>
#include <AudioDesign.h>
#include <AnalogSmooth.h>

AnalogSmooth asTouch = AnalogSmooth();
AnalogSmooth asPitch = AnalogSmooth();
AnalogSmooth asAccelX = AnalogSmooth(15);
AnalogSmooth asAccelZ = AnalogSmooth(15);
AnalogSmooth asVolume = AnalogSmooth();
AnalogSmooth asFreqHigh = AnalogSmooth();
AnalogSmooth asFreqLow = AnalogSmooth();
AnalogSmooth asOsc2mix = AnalogSmooth();

const int touchSwitchPin = 30;
const int wiperPin = 31;
const int volumePin = 32;
const int tuneHighPin = 33;
const int tuneLowPin = 34;
const int osc2mixPin = 35;
const int osc2waveformPin = 36;

const int touchSens = 4000;

int pitch;
float volume;
int freqHigh;
int freqLow;
float osc2mix;
int osc2waveform;

// MP6050 Gyro-Accelerometer
const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
int16_t accel_x, accel_y, accel_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data

char tmp_str[7]; // temporary variable used in convert function
char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
};
// MP6050 Gyro-Accelerometer END



void setup() {
  Serial.begin(9600);

  // Let's go gyro!
  Wire1.begin();
  Wire1.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire1.write(0x6B); // PWR_MGMT_1 register
  Wire1.write(0); // set to zero (wakes up the MPU-6050)
  Wire1.endTransmission(true);

  // Audio
  AudioMemory(64);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  sgtl5000_1.lineOutLevel(29);
  freeverb1.roomsize(0.9);
  freeverb1.damping(0.8);
  mixer2.gain(0, 0.7);
  mixer2.gain(1, 0.7);
}



void loop() {

  // TUNING
  // Read analog pin of Pot 1 then smoothen readings
  freqHigh = analogRead(tuneHighPin);
  freqHigh = asFreqHigh.smooth(freqHigh);
  freqHigh = map(freqHigh, 0, 1023, 261, 2637);
  // Read analog pin of Pot 2 then smoothen readings
  freqLow = analogRead(tuneLowPin);
  freqLow = asFreqLow.smooth(freqLow);
  freqLow = map(freqLow, 0, 1023, 33, 131);

  // Serial.print(freqHigh);
  // Serial.print(" -- ");
  // Serial.println(freqLow);

  // PITCH
  // Read analog pin of wiper then smoothen readings
  pitch = analogRead(wiperPin);
  pitch = asPitch.smooth(pitch);
  // Map the readings
  pitch = map(pitch, 0, 1023, freqLow, freqHigh);
  // Serial.println(pitch);

  // CAPACITIVE SWITCH
  float touchSwitch = touchRead(touchSwitchPin);
  // Serial.print(touchSwitch);
  // Serial.print(" -- ");
  float touchSwitchSmooth = asTouch.smooth(touchSwitch);
  // Serial.println(touchSwitchSmooth);

  // VOLUME CONTROL
  // Read analog pin of volume then smoothen readings
  volume = analogRead(volumePin);
  volume = asVolume.smooth(volume);
  // Map to 0.0-1.0
  volume = volume/1023;
  // Serial.println(volume);

  // Apply volume value to main amp gain
  mainAmp.gain(volume);

  // OSCILLATOR 2 MIX
  // Read analog pin of Pot 3 then smoothen readings
  osc2mix = analogRead(osc2mixPin);
  osc2mix = asOsc2mix.smooth(osc2mix);
  osc2mix = osc2mix/1023;

  // OSCILLATOR WAVEFORM CHOOSER
  osc2waveform = analogRead(osc2waveformPin);
  osc2waveform = map(osc2waveform, 0, 1023, 1, 5);
  // Serial.println(osc2waveform);
  if (osc2waveform == 1) {waveform1.begin(WAVEFORM_SINE);}
  else if (osc2waveform == 2) {waveform1.begin(WAVEFORM_TRIANGLE);}
  else if (osc2waveform == 3) {waveform1.begin(WAVEFORM_SQUARE);}
  else if (osc2waveform == 4) {waveform1.begin(WAVEFORM_SAWTOOTH);}
  else if (osc2waveform == 5) {waveform1.begin(WAVEFORM_PULSE);}

  if (touchSwitchSmooth > touchSens) {
    if (touchSwitchSmooth <= touchSens) {
      sine1.amplitude(0);
      waveform1.amplitude(0);
      dc1.amplitude(0, 0);  
    }
    if (touchSwitchSmooth > touchSens) {
      sine1.frequency(pitch);
      sine1.amplitude(0.8);
      waveform1.amplitude(osc2mix);
      waveform1.frequency(pitch - 5);
      filter2.frequency(1000);
      dc1.amplitude(0.9, 0);
    }
  } else {
    sine1.frequency(freqLow);
    waveform1.frequency(freqLow);
    dc1.amplitude(0, 0);
  }


  // Gyro
  Wire1.beginTransmission(MPU_ADDR);
  Wire1.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire1.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire1.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  // "Wire1.read()<<8 | Wire1.read();" means two registers are read and stored in the same variable
  accel_x = Wire1.read()<<8 | Wire1.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accel_y = Wire1.read()<<8 | Wire1.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accel_z = Wire1.read()<<8 | Wire1.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  
  gyro_x = Wire1.read()<<8 | Wire1.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire1.read()<<8 | Wire1.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire1.read()<<8 | Wire1.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)
  
  // print out data
  // Serial.print("aX = "); Serial.print(convert_int16_to_str(accel_x));
  // Serial.print(" | aY = "); Serial.print(convert_int16_to_str(accel_y));
  // Serial.print(" | aZ = "); Serial.print(convert_int16_to_str(accel_z));
  // Serial.print(" | gX = "); Serial.print(convert_int16_to_str(gyro_x));
  // Serial.print(" | gY = "); Serial.print(convert_int16_to_str(gyro_y));
  // Serial.print(" | gZ = "); Serial.print(convert_int16_to_str(gyro_z));
  // Serial.println();

  // WIND RAIN SEA
  accel_x = asAccelX.smooth(accel_x);
  float rain_freq = -(constrain(accel_x, -6000, -100));
  float rain_amp = rain_freq / 6000;
  tonesweep1.play(0.5, 500, 9000, 2);
  pink1.amplitude(0.8);
  filter1.frequency(rain_freq);
  mixer1.gain(3, rain_amp);

  // LOWER OCTAVE
  // HIGHER OCTAVE
  accel_z = asAccelZ.smooth(accel_z);
  float octaves = constrain(accel_z, -6000, 6000);
  float octavesMix = octaves/6000;
  Serial.println(accel_z);
  if (octaves > 1500) {
    sine_fm1.frequency(pitch/3);
    sine_fm1.amplitude(octavesMix);
    mixer1.gain(2, octavesMix - 0.3);
  } else if (octaves < -2500) {
    sine_fm1.frequency(pitch*4);
    sine_fm1.amplitude(-octavesMix);
    mixer1.gain(2, -octavesMix - 0.3);
  } else {
    sine_fm1.amplitude(0);
  }



  // RATTLE
  // float rattle = constrain(accel_x, 100, 6000);
  // Serial.println(rattle);
  // if (rattle > 100) {
  //   if (rattle > 100) {
  //     drum1.frequency(300);
  //     drum1.length(20);
  //     drum1.noteOn();
  //   }    
  // }


  delay(5); // delay in between reads for stability
}