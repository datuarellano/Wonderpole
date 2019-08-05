#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dc1;            //xy=1556.222297668457,906.444450378418
AudioSynthNoisePink      pink1;          //xy=1561,1171
AudioSynthToneSweep      tonesweep1;     //xy=1570,1222
AudioSynthWaveform       waveform1;      //xy=1683.9999618530273,966.4443988800049
AudioSynthWaveformSine   sine1;          //xy=1699.5556182861328,853.1110897064209
AudioEffectMultiply      multiply3;      //xy=1715,1187
AudioEffectMultiply      multiply2;      //xy=1839.111083984375,945.1111450195312
AudioSynthSimpleDrum     drum1;          //xy=1855,1348
AudioFilterStateVariable filter1;        //xy=1857,1194
AudioEffectMultiply      multiply1;      //xy=1872.888888888889,875.333350499471
AudioEffectFreeverb      freeverb1;      //xy=1966,1111
AudioFilterStateVariable filter2;        //xy=1987,942
AudioSynthWaveformSineModulated sine_fm1;       //xy=1987,1028
AudioMixer4              mixer2;         //xy=2077,1181
AudioMixer4              mixer1;         //xy=2231.000244140625,935.4444580078125
AudioAmplifier           mainAmp;           //xy=2366.0000534057617,935.0000038146973
AudioOutputI2S           i2s1;           //xy=2511.5000534057617,935.0000038146973
AudioConnection          patchCord1(dc1, 0, multiply1, 1);
AudioConnection          patchCord2(dc1, 0, multiply2, 0);
AudioConnection          patchCord3(pink1, 0, multiply3, 0);
AudioConnection          patchCord4(tonesweep1, 0, multiply3, 1);
AudioConnection          patchCord5(waveform1, 0, multiply2, 1);
AudioConnection          patchCord6(sine1, 0, multiply1, 0);
AudioConnection          patchCord7(multiply3, 0, filter1, 0);
AudioConnection          patchCord8(multiply2, 0, filter2, 0);
AudioConnection          patchCord9(multiply2, sine_fm1);
AudioConnection          patchCord10(drum1, 0, mixer2, 2);
AudioConnection          patchCord11(filter1, 0, freeverb1, 0);
AudioConnection          patchCord12(filter1, 0, mixer2, 0);
AudioConnection          patchCord13(multiply1, 0, mixer1, 0);
AudioConnection          patchCord14(freeverb1, 0, mixer2, 1);
AudioConnection          patchCord15(filter2, 0, mixer1, 1);
AudioConnection          patchCord16(sine_fm1, 0, mixer1, 2);
AudioConnection          patchCord17(mixer2, 0, mixer1, 3);
AudioConnection          patchCord18(mixer1, mainAmp);
AudioConnection          patchCord19(mainAmp, 0, i2s1, 0);
AudioConnection          patchCord20(mainAmp, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2403.5000915527344,858.5000162124634
// GUItool: end automatically generated code
