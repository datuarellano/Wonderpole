///////////////////////////////////////////////////////////////////////////
//// INPUTS : Mic and piezo ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void inputs()
{
  // TODO inputs
  // Electret Mic
  if (sw_3_1.read() == LOW && sw_3_1_state == false)
  {
    sw_3_1_state = true;
    mixer2.gain(2, (param1_val * ANALOG)); // mic
    mixer2.gain(3, 0.9);                   // piezo
  }
  else if (sw_3_1.read() == HIGH && sw_3_1_state == true)
  {
    sw_3_1_state = false;
    mixer2.gain(2, 0); // mic
    mixer2.gain(3, 0); // piezo
  }
  else
  {
    sw_3_1_state = false;
    mixer2.gain(2, 0); // mic
    mixer2.gain(3, 0); // piezo
  }
}