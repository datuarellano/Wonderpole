///////////////////////////////////////////////////////////////////////////
//// TOP BUTTON TRIGGER ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void topbutton() {
  // TODO Top button trigger
  drum_amp.gain(5);
  drum.length(100);
  drum.secondMix(0.7);
  drum_pinknoise.amplitude(0.7);
  // drum_filter.frequency(400);
  // drum_filter.resonance(5.0);
  // drum_bitcrusher.bits(7);

  if (btn_top.read() == LOW && btn_top_state == false)
  {
    drum.frequency(random(40,50));
    // drum.frequency(map(rib_val, 0, 1023, 20, 80));
    btn_top_state = true;
    drum_noise_dc.amplitude(0.05,5);
    drum.noteOn();
    LED_white();
  }
  else if (btn_top.read() == HIGH && btn_top_state == true)
  {
    btn_top_state = false;
    drum_noise_dc.amplitude(0,20);
  }
}