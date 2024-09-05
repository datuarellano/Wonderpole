///////////////////////////////////////////////////////////////////////////
//// INPUTS : Mic and piezo ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void inputs()
{
  // TODO inputs
  // float gain = param1_val * ANALOG;
  float gainA = rib_val * ANALOG  * 25;
  float gainB = param1_val * ANALOG * 2;

  if (sw_3_1.read() == HIGH && sw_3_2.read() == HIGH)
  {
    mixer2.gain(2, 0);
    mixer2.gain(3, 0);
  }
  else if (sw_3_2.read() == LOW)
  {
    mixer2.gain(2, 0);
    mixer2.gain(3, gainB);
  }
  else {
    mixer2.gain(2, gainA);
    mixer2.gain(3, gainB);
  }
}