///////////////////////////////////////////////////////////////////////////
//// ACCELEROMETER ////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

bool acc_play = false;
bool acc_left = false;
bool acc_right = false;
bool acc_fore = false;
bool acc_back = false;

void accelerometerTest() {
  /* Get a new normalized sensor event */
  sensors_event_t accel;
  mpu_accel->getEvent(&accel);

  // I think we may need to constrain the values
  // since they can exceed > 10.0
  if (accel.acceleration.x > 10)
    accel.acceleration.x = 10;
  if (accel.acceleration.z > 10)
    accel.acceleration.z = 10;

  if (accel.acceleration.x < -1.6)
    Serial.println(accel.acceleration.x);
  else if (accel.acceleration.x > 1.6)
    Serial.println(accel.acceleration.x);
  
  if (accel.acceleration.z < -1.6)
    Serial.println(accel.acceleration.z);
  else if (accel.acceleration.z > 1.6)
    Serial.println(accel.acceleration.z);
}

void accelerometer()
{
  mixer2.gain(0, 0.8);

  /* Get a new normalized sensor event */
  sensors_event_t accel;
  mpu_accel->getEvent(&accel);

  // Accelerometer Mode Switch
  int acc_fade = 800;
  
  if (sw_accelmode_1.read() == LOW && acc_play == false)
  {
    acc_play = true;
    dc_accA.amplitude(0.9, acc_fade);
  }
  else if (sw_accelmode_1.read() == HIGH && acc_play == true)
  {
    acc_play = false;
    dc_accA.amplitude(0, acc_fade);
  }
  else
  {
    dc_accA.amplitude(0, acc_fade);
  }

  if (sw_accelmode_2.read() == LOW && acc_play == false)
  {
    acc_play = true;
    dc_accB.amplitude(0.9, acc_fade);
  }
  else if (sw_accelmode_2.read() == HIGH && acc_play == true)
  {
    acc_play = false;
    dc_accB.amplitude(0, acc_fade);
  }
  else
  {
    dc_accB.amplitude(0, acc_fade);
  }

  // ACCELEROMETER MODE 1: WIND RAIN SEA
  // LEFT
  tonesweep1.play(0.5, 500, 9000, 2);
  pink1.amplitude(0.8);

  // RIGHT
  tonesweep2.play(0.5, 300, 12000, 2);
  noise1.amplitude(0.8);

  // FORE
  tonesweep3.play(0.5, 300, 7000, 2);
  noise2.amplitude(0.8);
  LFO1.amplitude(0.8);

  // BACK
  tonesweep4.play(0.5, 500, 9000, 2);
  pink2.amplitude(0.9);
  string1.noteOn(5000, 1.0);
  bitcrusher1.bits(3);

  filter4.resonance(3);

  // ACCELEROMETER Mode 2: Drones & Chords
  if (current_preset == 0)
  {
    float amp = 0.8;
    waveform_0.begin(amp, notes[acc_note_0], WAVEFORM_SINE);
    waveform_1.begin(amp, notes[acc_note_1], WAVEFORM_SINE);
    waveform_2.begin(amp, notes[acc_note_2], WAVEFORM_SINE);
    waveform_3.begin(amp, notes[acc_note_3], WAVEFORM_SINE);
    waveform_4.begin(amp, notes[acc_note_4], WAVEFORM_SINE);
    waveform_5.begin(amp, notes[acc_note_5], WAVEFORM_SINE);
  }
  if (current_preset == 1)
  {
    float amp = 0.3;
    waveform_0.begin(amp, notes[acc_note_0] / 2, WAVEFORM_SAWTOOTH);
    waveform_1.begin(amp, notes[acc_note_1], WAVEFORM_SAWTOOTH);
    waveform_2.begin(amp, notes[acc_note_2], WAVEFORM_SAWTOOTH);
    waveform_3.begin(amp, notes[acc_note_3] / 2, WAVEFORM_SAWTOOTH);
    waveform_4.begin(amp, notes[acc_note_4], WAVEFORM_SAWTOOTH);
    waveform_5.begin(amp, notes[acc_note_5], WAVEFORM_SAWTOOTH);
  }
  if (current_preset == 2)
  {
    float amp = 0.6;
    waveform_0.begin(amp, notes[acc_note_0], WAVEFORM_ARBITRARY);
    waveform_0.arbitraryWaveform(AKWF_ebass_0001, 3000);
    waveform_1.begin(amp, notes[acc_note_1], WAVEFORM_ARBITRARY);
    waveform_1.arbitraryWaveform(AKWF_ebass_0001, 3000);
    waveform_2.begin(amp, notes[acc_note_2], WAVEFORM_ARBITRARY);
    waveform_2.arbitraryWaveform(AKWF_ebass_0001, 3000);
    waveform_3.begin(amp, notes[acc_note_3], WAVEFORM_ARBITRARY);
    waveform_3.arbitraryWaveform(AKWF_ebass_0001, 3000);
    waveform_4.begin(amp, notes[acc_note_4], WAVEFORM_ARBITRARY);
    waveform_4.arbitraryWaveform(AKWF_ebass_0001, 3000);
    waveform_5.begin(amp, notes[acc_note_5], WAVEFORM_ARBITRARY);
    waveform_5.arbitraryWaveform(AKWF_ebass_0001, 3000);
  }

  
  // Check direction of pole
  
  // Thresholds
  float acc_min_thresh = 1.6;
  float acc_max_thresh = 8.0;
  
  // LEFT
  if (accel.acceleration.x <= acc_min_thresh)
  {
    acc_left = true;
    acc_right = false;
  }
  // RIGHT
  else if (accel.acceleration.x >= acc_min_thresh)
  {
    acc_left = false;
    acc_right = true;
  }
  // FORE
  if (accel.acceleration.z <= acc_min_thresh)
  {
    acc_fore = true;
    acc_back = false;
  }
  // BACK
  else if (accel.acceleration.z >= acc_min_thresh)
  {
    acc_fore = false;
    acc_back = true;
  }

  // Open up filters and amp gains depending on direction of pole
  // X Axis LEFT
  if (acc_left == true)
  {
    filter1.frequency(-(map(accel.acceleration.x, -acc_max_thresh, -acc_min_thresh, -8000, 0)));
    filter1.resonance(-(map(accel.acceleration.x, -acc_max_thresh, -acc_min_thresh, -3, -1)));
    mixer_acc_sub1.gain(1, -(map(accel.acceleration.x, -acc_max_thresh, -acc_min_thresh, -1.0, 0.0)));
    mixer_acc_sub2.gain(1, 0);
  }
  // X Axis RIGHT
  else if (acc_right == true)
  {
    filter2.frequency(map(accel.acceleration.x, acc_min_thresh, acc_max_thresh, 0, 8000));
    mixer_acc_sub1.gain(1, 0);
    mixer_acc_sub2.gain(1, map(accel.acceleration.x, acc_min_thresh, acc_max_thresh, 0.0, 1.0));
  }
  // Z Axis FORWARD
  if (acc_fore == true)
  {
    filter3.frequency(-(map(accel.acceleration.z, -acc_min_thresh, -acc_max_thresh, 0, -8000)));
    LFO1.frequency(-(map(accel.acceleration.z, -acc_min_thresh, -acc_max_thresh, -acc_max_thresh, -0.25)));
    mixer_acc_sub3.gain(1, -(map(accel.acceleration.z, -acc_min_thresh, -acc_max_thresh, 0.0, -1.0)));
    mixer_acc_sub4.gain(1, 0);
  }
  // Z Axis BACK
  else if (acc_back == true)
  {
    filter4.frequency(map(accel.acceleration.z, acc_min_thresh, acc_max_thresh, 0, 8000));
    mixer_acc_sub3.gain(1, 0);
    mixer_acc_sub4.gain(1, map(accel.acceleration.z, acc_min_thresh, acc_max_thresh, 0.0, 1.0));
  }
  // "CENTER" Be quiet between -2 and +2
  if (accel.acceleration.x > -acc_min_thresh && accel.acceleration.x < acc_min_thresh)
  {
    filter1.frequency(0);
    filter2.frequency(0);
    mixer_acc_sub1.gain(1, 0);
    mixer_acc_sub2.gain(1, 0);
  }
  if (accel.acceleration.z > -acc_min_thresh && accel.acceleration.z < acc_min_thresh)
  {
    filter3.frequency(0);
    filter4.frequency(0);
    mixer_acc_sub3.gain(1, 0);
    mixer_acc_sub4.gain(1, 0);
  }

  // TODO write a better chord function
  // Change chords depending on direction of pole and current preset number
  if (current_preset == 0)
  {
    if (acc_left == true)
    {
      acc_note_0 = 0;
      acc_note_1 = 1;
      acc_note_2 = 2;
    }
    else if (acc_right == true)
    {
      acc_note_0 = 3;
      acc_note_1 = 4;
      acc_note_2 = 5;
    }
    if (acc_fore == true)
    {
      acc_note_3 = 6;
      acc_note_4 = 7;
      acc_note_5 = 8;
    }
    else if (acc_back == true)
    {
      acc_note_3 = 9;
      acc_note_4 = 10;
      acc_note_5 = 11;
    }
  }
  if (current_preset == 1)
  {
    if (acc_left == true)
    {
      acc_note_0 = 0;
      acc_note_1 = 3;
      acc_note_2 = 5;
    }
    else if (acc_right == true)
    {
      acc_note_0 = 2;
      acc_note_1 = 4;
      acc_note_2 = 8;
    }
    if (acc_fore == true)
    {
      acc_note_3 = 0;
      acc_note_4 = 10;
      acc_note_5 = 11;
    }
    else if (acc_back == true)
    {
      acc_note_3 = 0;
      acc_note_4 = 2;
      acc_note_5 = 4;
    }
  }
  if (current_preset == 2)
  {
    if (acc_left == true)
    {
      acc_note_0 = 0;
      acc_note_1 = 2;
      acc_note_2 = 4;
    }
    else if (acc_right == true)
    {
      acc_note_0 = 0;
      acc_note_1 = 3;
      acc_note_2 = 7;
    }
    if (acc_fore == true)
    {
      acc_note_3 = 9;
      acc_note_4 = 10;
      acc_note_5 = 11;
    }
    else if (acc_back == true)
    {
      acc_note_3 = 1;
      acc_note_4 = 3;
      acc_note_5 = 5;
    }
  }
}