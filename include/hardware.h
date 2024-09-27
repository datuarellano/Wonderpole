// Define Teensy IO pins
#define ENCODER_BTN 2
#define LED_R 3
#define LED_G 4
#define LED_B 5
#define TRIGGER 9
#define BTN_TOP 10
#define LED 13
#define RIBBON 14
#define ACCELMODE_1 28
#define ACCELMODE_2 29
#define SWITCH2_1 30
#define SWITCH2_2 31
#define SWITCH3_1 32
#define SWITCH3_2 33
#define VOLUME 24
#define PARAM1 25
#define PARAM2 26

// Analog smoothing
AnalogSmooth asmooth = AnalogSmooth(30);
AnalogSmooth asmooth2 = AnalogSmooth(30);
AnalogSmooth asmooth3 = AnalogSmooth(30);
AnalogSmooth asmooth4 = AnalogSmooth(50);

// constants for faster division
const float DIV4 = 0.25; // 1/4
const float DIV8 = 0.125; // 1/8
const float ANALOG = 0.0009775171065493646; // 1/1023

#include <rgbLED.h>


///////////////////////////////////////////////////////////////////////////
//// BUTTONS & SWITCHES ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Switch & button state variables
bool sw_2_1_state = false;
bool sw_2_2_state = false;
bool sw_3_1_state = false;
bool sw_3_2_state = false;
bool btn_top_state = false;

// Button & switch debounce
Bounce2::Button btn_top = Bounce2::Button();
Bounce2::Button btn_trigger = Bounce2::Button();
Bounce2::Button btn_encoder = Bounce2::Button();
Bounce2::Button sw_accelmode_1 = Bounce2::Button();
Bounce2::Button sw_accelmode_2 = Bounce2::Button();
Bounce2::Button sw_2_1 = Bounce2::Button();
Bounce2::Button sw_2_2 = Bounce2::Button();
Bounce2::Button sw_3_1 = Bounce2::Button();
Bounce2::Button sw_3_2 = Bounce2::Button();

void setupButtonsSwitches() {
  // Buttons setup
  btn_top.attach(BTN_TOP, INPUT_PULLUP);
  btn_top.interval(25);
  
  btn_trigger.attach(TRIGGER, INPUT_PULLUP);
  btn_trigger.interval(25);

  btn_encoder.attach(ENCODER_BTN, INPUT_PULLUP);
  btn_encoder.interval(25);

  // Switches Setup
  sw_accelmode_1.attach(ACCELMODE_1, INPUT_PULLUP);
  sw_accelmode_1.interval(15);
  
  sw_accelmode_2.attach(ACCELMODE_2, INPUT_PULLUP);
  sw_accelmode_2.interval(15);
  
  sw_2_1.attach(SWITCH2_1, INPUT_PULLUP);
  sw_2_1.interval(15);
  sw_2_2.attach(SWITCH2_2, INPUT_PULLUP);
  sw_2_2.interval(15);
  
  sw_3_1.attach(SWITCH3_1, INPUT_PULLUP);
  sw_3_1.interval(15);
  sw_3_2.attach(SWITCH3_2, INPUT_PULLUP);
  sw_3_2.interval(15);
}

void updateButtonsSwitches() {
  // Update buttons
  btn_top.update();
  btn_trigger.update();
  btn_encoder.update();
  sw_accelmode_1.update();
  sw_accelmode_2.update();
  sw_2_1.update();
  sw_2_2.update();
  sw_3_1.update();
  sw_3_2.update();
}

///////////////////////////////////////////////////////////////////////////
//// ENCODER //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
Encoder encoder(0,1); // B,A
int encoder_curr = 0;
int encoder_prev = 0;
int encoder_button_curr = 0;
int encoder_button_prev = 0;
int num_presets = 3;
int current_preset = 0;

int encoderRead() { 
  return encoder.read() * DIV4;
}

int encoderTurn() {
  encoder_curr = encoderRead();
  if (encoder_curr > encoder_prev) {
    return 1; // right
  }
  else if (encoder_curr < encoder_prev) {
    return -1; // left
  }
  return 0;
}

int encoderIncrement(int value, int increment) {
  encoder_curr = encoderRead();
  if (encoderTurn() == 1)
  {
    value = value + increment;
    encoder_curr = 0;
    encoder.write(0);
  }
  else if (encoderTurn() == -1)
  {
    value = value - increment;
    encoder_curr = 0;
    encoder.write(0);
  }
  return value;
}

void encoderLED() {
  // preset colours
  if (current_preset == 0) LED_purple();
  else if (current_preset == 1) LED_blue();
  else if (current_preset == 2) LED_orange();
}

void encoderCyclePresets() {
  if (btn_encoder.fell()) Serial.println("Encoder");
  current_preset = encoderIncrement(current_preset, 1);

  if (current_preset >= num_presets - 1) current_preset = num_presets - 1;
  else if (current_preset <= 0) current_preset = 0;

  encoderLED();
}

///////////////////////////////////////////////////////////////////////////
//// POTENTIOMETERS ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
float volume_val, param1_val, param2_val, rib_val;

void potsRead() {
  // TODO POTS
  volume_val = analogRead(VOLUME);
  param1_val = analogRead(PARAM1);
  param2_val = analogRead(PARAM2);
  volume_val = asmooth.smooth(volume_val);
  param1_val = asmooth2.smooth(param1_val);
  param2_val = asmooth3.smooth(param2_val);
}

void volume() {
  // TODO VOLUME
  volume_val = volume_val * ANALOG;
  mainAmp_LEFT.gain(volume_val);
  mainAmp_RIGHT.gain(volume_val);
  sgtl5000_1.volume(volume_val);
}


///////////////////////////////////////////////////////////////////////////
//// MPU6050 //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_accel;

void setupMPU6050() {
  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu_accel = mpu.getAccelerometerSensor();
}


///////////////////////////////////////////////////////////////////////////
//// SGTL5000 AUDIO BOARD /////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void setupSGTL5000Audio() {
  AudioMemory(64);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  sgtl5000_1.lineOutLevel(29); // 29 default
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.lineInLevel(5); // 5 default
  sgtl5000_1.audioPreProcessorEnable();
  sgtl5000_1.audioPostProcessorEnable();
  sgtl5000_1.enhanceBassEnable();
}