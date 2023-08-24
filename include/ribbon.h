///////////////////////////////////////////////////////////////////////////
//// RIBBON ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

bool rib_play = false;

void ribbon() {
  // TODO Ribbon controller
  rib_val = analogRead(RIBBON);
  rib_val = asmooth4.smooth(rib_val);
  rib_val = map(rib_val, 5, 1010, 0, 1023);
  // Serial.println(rib_val);

  float waveform6_amp = 0.8;
  float waveform7_amp = 0.7;
  float waveform8_amp = 0.7;

  // Ribbon mode switch
  if (sw_2_1.read() == LOW)
    ribbonMode(1);
  else if (sw_2_2.read() == LOW)
    ribbonMode(0);
  else if (sw_2_1.read() == HIGH && sw_2_2.read() == HIGH)
    ribbonMode(2);

  if (sw_2_1.fell())
    rib_notesOff();
  else if (sw_2_2.fell())
    rib_notesOff();
  else if (sw_2_1.rose() || sw_2_2.rose())
    rib_notesOff();

  // Ribbon sound design presets
  if (current_preset == 0)
  {
    // Oscillator 1
    waveform_6.begin(waveform6_amp, freq * 2, WAVEFORM_SINE);
    // waveform_6.arbitraryWaveform(AKWF_eguitar_0001, 3000);
    waveform6_envelope.attack(map(param1_val, 0, 1023, 0, 2000));
    waveform6_envelope.decay(500);
    waveform6_envelope.sustain(0.6);
    waveform6_envelope.release(500);
    waveform6_filter.frequency(900);
    waveform6_filter.resonance(5);
    // Oscillator 2
    waveform_7.begin(waveform7_amp, freq * 3, WAVEFORM_SINE);
    waveform7_envelope.attack(map(param1_val, 0, 1023, 700, 2000));
    waveform7_envelope.decay(500);
    waveform7_envelope.sustain(0.8);
    waveform7_envelope.release(2000);
    // Oscillator 3
    waveform_8.begin(waveform8_amp, freq * 0.5, WAVEFORM_SINE);
    waveform8_envelope.attack(map(param1_val, 0, 1023, 0, 2000));
    waveform8_envelope.decay(500);
    waveform8_envelope.sustain(0.8);
    waveform8_envelope.release(2000);
    }
    if (current_preset == 1)
    {
      // Oscillator 1
      waveform_6.begin(waveform6_amp * 0.5, freq, WAVEFORM_ARBITRARY);
      waveform_6.arbitraryWaveform(AKWF_eguitar_0001, 3000);
      waveform6_envelope.attack(param1_val);
      waveform6_envelope.decay(500);
      waveform6_envelope.sustain(0.1);
      waveform6_envelope.release(300);
      waveform6_filter.frequency(900);
      waveform6_filter.resonance(5);
      // Oscillator 2
      waveform_7.begin(waveform7_amp * 0.5, freq * 2, WAVEFORM_SAWTOOTH);
      waveform7_envelope.attack(500);
      waveform7_envelope.decay(500);
      waveform7_envelope.sustain(1.0);
      waveform7_envelope.release(100);
      // Oscillator 3
      waveform_8.begin(waveform8_amp * 0.5, freq * 0.5, WAVEFORM_SAMPLE_HOLD);
      waveform8_envelope.attack(map(param1_val, 0, 1023, 0, 2000));
      waveform8_envelope.decay(500);
      waveform8_envelope.sustain(0.8);
      waveform8_envelope.release(2000);
    }
    if (current_preset == 2)
    {
      // Oscillator 1
      waveform_6.begin(waveform6_amp, freq, WAVEFORM_ARBITRARY);
      waveform_6.arbitraryWaveform(AKWF_epiano_0001, 3000);
      // waveform_6.arbitraryWaveform(AKWF_flute_0001, 3000);
      // waveform_6.arbitraryWaveform(AKWF_hvoice_0001, 3000);
      waveform6_envelope.attack(map(param1_val, 0, 1023, 0, 2000));
      waveform6_envelope.decay(500);
      waveform6_envelope.sustain(1.0);
      waveform6_envelope.release(300);
      waveform6_filter.frequency(2000);
      waveform6_filter.resonance(1);
      // Oscillator 2
      waveform_7.begin(waveform7_amp * 0.7, freq * 2, WAVEFORM_SAWTOOTH);
      waveform7_envelope.attack(map(param1_val, 0, 1023, 0, 2000));
      waveform7_envelope.decay(500);
      waveform7_envelope.sustain(0.6);
      waveform7_envelope.release(2000);
      // Oscillator 3
      waveform_8.begin(waveform8_amp * 0.6, freq * 0.5, WAVEFORM_TRIANGLE);
      waveform8_envelope.attack(map(param1_val, 0, 1023, 0, 2000));
      waveform8_envelope.decay(500);
      waveform8_envelope.sustain(0.6);
      waveform8_envelope.release(1000);
    }

    // TODO Ribbon Trigger Button
    if (btn_trigger.read() == LOW && rib_play == false)
    {
      rib_play = true;
      waveform6_envelope.noteOn();
      waveform7_envelope.noteOn();
      digitalWrite(LED, LOW);
    }
    if (btn_trigger.read() == HIGH && rib_play == true)
    {
      rib_play = false;
      waveform6_envelope.noteOff();
      waveform7_envelope.noteOff();
      digitalWrite(LED, HIGH);
    }
    if (btn_trigger.read() == LOW) LED_red();
}