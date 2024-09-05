const int note_count = 12;
const int key_count = 13;
const int scale_count = 9;
int root_note_idx;
int scale_idx;
float freq;
int rib_octave, acc_octave;
int curr_note_seq = 0;
int prev_note_seq = 0;
int t = 2; // tone
int s = 1; // semitone
int acc_note_0, acc_note_1, acc_note_2, acc_note_3, acc_note_4, acc_note_5;

// Chrono timers
Chrono noteSequenceTimer;

// Lydian
// t, t, t, s, t, s, t
// t, t, t, s, t, s, t, t, t, t, s, t

// Major

// TODO
// Array of scales / interval formulaes
int interval_formulas[][note_count] = {

//                          |  
//    t, t, s,  t,  t,  t,  s,  t,  t,  s,  t,
//    2, 2, 1,  2,  2,  2,  1,  2,  2,  1,  2,
  {0, 2, 4, 5,  7,  9, 11, 12, 14, 16, 17, 19}, // Major (Ionian)

//                     |
//    t, t, t+s, t, t+s,  t,  t, t+s,  t, t+s,  t
  {0, 2, 4,  7,  9,  12, 14, 16,  19, 21,  24,  26}, // Major Pentatonic
  
//                     |                    |
//    t+s, t, t, t+s, t,  t+s,  t,  t, t+s, t,  t+s 
  {0, 3,   5, 7,  10, 12, 15,  17, 19, 22,  24,  27}, // Minor Pentatonic
  
  {0, 2, 4, 5,  7,  9, 10, 12, 14, 16}, // Mixolydian
  {0, 2, 4, 6,  7,  9, 11, 12, 14, 16}, // Lydian
  {0, 4, 5, 7, 10, 12, 16, 17, 19, 22}, // Indian
  {0, 2, 5, 7, 10, 12, 14, 17, 19, 22}, // Egyptian
  {0, 2, 4, 6, 11, 12, 14, 16, 18, 23}, // Prometheus
  {0, 2, 3, 5,  7,  9, 10, 12, 14, 15}, // Dorian
};

// Array of keys
//                           
int key_values[] = {48,49,50,51,52,53,54,55,56,57,58,59};

// Array of notes that gets updated
float notes[note_count] = {};

void updateTuning(int root_note, int scale)
{
  // Update array of notes
  for (int i = 0; i < note_count; i++) {
    notes[i] = note_frequency[key_values[root_note] + interval_formulas[scale][i]];
    // Serial.print(notes[i]);
    // Serial.print(" ");
  }
    // Serial.println(" ");
    // delay(100);
}


// TODO sequencer
void sequence(int n1, int n2, int n3)
{
  int tempoX = map(param2_val, 0, 1023, 50, 500);
  int off = 1 * tempoX;
  int on = 2 * tempoX;
  int seq[] = {n1, n2, n3};
  
  if (noteSequenceTimer.hasPassed(off))
  {
    // Serial.println("Note Off");
    waveform6_envelope.noteOff();
    waveform7_envelope.noteOff();
    waveform8_envelope.noteOff();
    digitalWrite(LED, LOW);
  }
  if (noteSequenceTimer.hasPassed(on))
  {
    // Serial.println("Note On");
    waveform6_envelope.noteOn();
    waveform7_envelope.noteOn();
    waveform8_envelope.noteOn();

    curr_note_seq = seq[random(0,3)];
    freq = notes[curr_note_seq];

    digitalWrite(LED, HIGH);
  }
  if (noteSequenceTimer.hasPassed(on + off))
  {
    noteSequenceTimer.restart();
  }
}

void ribbonMode(int rib_mode)
{
  // Mode 1 subdivides the ribbon
  
  // 12 segments
  // float seg[] = { 85, 170, 255, 340, 425, 510, 595, 680, 765, 850, 935 };
  
  // 14 segments
  float seg[] = { 146, 219, 292, 365, 438, 511, 584, 657, 730, 803, 876 };

  if (rib_mode == 1) 
  {
    if (rib_val < seg[0]) {
      freq = notes[0];
    }
    else if (rib_val >= seg[0] && rib_val < seg[1]) {
      freq = notes[1];
    }
    else if (rib_val >= seg[1] && rib_val < seg[2]) {
      freq = notes[2];
    }
    else if (rib_val >= seg[2] && rib_val < seg[3]) {
      freq = notes[3];
    }
    else if (rib_val >= seg[3] && rib_val < seg[4]) {
      freq = notes[4];
    }
    else if (rib_val >= seg[4] && rib_val < seg[5]) {
      freq = notes[5];
    }
    else if (rib_val >= seg[5] && rib_val < seg[6]) {
      freq = notes[6];
    }
    else if (rib_val >= seg[6] && rib_val < seg[7]) {
      freq = notes[7];
    }
    else if (rib_val >= seg[7] && rib_val < seg[8]) {
      freq = notes[8];
    }
    else if (rib_val >= seg[8] && rib_val < seg[9]) {
      freq = notes[9];
    }
    else if (rib_val >= seg[9] && rib_val < seg[10]) {
      freq = notes[10];
    }
    else {
      freq = notes[11];
    }
  }
  // Mode 0 is linear and has no subdivisions
  else if (rib_mode == 0) 
  {
    freq = map(rib_val, 100, 800, 20, 6000);
  }

  // Mode 2 is sequenced notes
  else if (rib_mode == 2)
  {
    if (rib_val < seg[4]) sequence(0,2,3);
    else if (rib_val >= seg[4] && rib_val < seg[8]) sequence(2,3,6);
    else sequence(0,9,11);
  }

  // Serial.println(rib_val);
}


// TODO ribbon notes off --- relocate in some other file
void rib_notesOff() {
  waveform6_envelope.noteOff();
  waveform7_envelope.noteOff();
  waveform8_envelope.noteOff();
}

void changeTuning() {
  if (current_preset == 0)
  {
    rib_octave = -12;
    updateTuning(9, 2); // 
    // updateTuning(9, 1); // A major pentatonic
    // updateTuning(0, 1); // c major pentatonic
  }
  if (current_preset == 1)
  {
    rib_octave = -12;
    updateTuning(5, 2); // F# minor pentatonic
  }
  if (current_preset == 2)
  {
    rib_octave = 0;
    updateTuning(9, 0); // A major
  }
}