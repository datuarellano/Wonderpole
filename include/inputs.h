///////////////////////////////////////////////////////////////////////////
//// INPUTS : Mic and piezo ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void inputs()
{
  // TODO inputs
  float gain = param1_val * ANALOG;

  if (sw_3_1.read() == HIGH && sw_3_2.read() == HIGH)
  {
    mixer2.gain(2, 0);
    mixer2.gain(3, 0);
  }
  else if (sw_3_2.read() == LOW)
  {
    mixer2.gain(2, 0);
    mixer2.gain(3, gain);
  }
  else {
    mixer2.gain(2, gain);
    mixer2.gain(3, gain);
  }
}