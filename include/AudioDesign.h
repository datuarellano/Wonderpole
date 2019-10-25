#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dc1;            //xy=1158.333251953125,1046.6666259765625
AudioSynthNoisePink      pink1;          //xy=1157.777660369873,1310.555513381958
AudioSynthToneSweep      tonesweep1;     //xy=1166.777660369873,1361.555513381958
AudioSynthToneSweep      tonesweep2;     //xy=1171.1111450195312,1560.0000762939453
AudioSynthNoiseWhite     noise1;         //xy=1185.5555801391602,1506.6665906906128
AudioSynthWaveform       waveform1;      //xy=1285.333251953125,1106.6666259765625
AudioSynthWaveformSine   sine1;          //xy=1301.333251953125,993.6666259765625
AudioEffectMultiply      multiply3;      //xy=1311.777660369873,1326.555513381958
AudioSynthKarplusStrong  string1;        //xy=1327.777847290039,1578.8889541625977
AudioEffectMultiply      multiply4;      //xy=1337.7777099609375,1513.3333530426025
AudioEffectMultiply      multiply2;      //xy=1441.333251953125,1085.6666259765625
AudioFilterStateVariable filter1;        //xy=1453.777660369873,1333.555513381958
AudioEffectMultiply      multiply1;      //xy=1474.333251953125,1015.6666259765625
AudioMixer4              mixer3;         //xy=1476.6666666666667,1565.5555555555554
AudioEffectFreeverb      freeverb1;      //xy=1568.333251953125,1251.6666259765625
AudioFilterStateVariable filter2;        //xy=1589.333251953125,1082.6666259765625
AudioSynthWaveformSineModulated sine_fm1;       //xy=1589.333251953125,1168.6666259765625
AudioFilterStateVariable filter3;        //xy=1601.1110877990723,1514.4444637298584
AudioMixer4              mixer2;         //xy=1679.333251953125,1321.6666259765625
AudioMixer4              mixer1;         //xy=1833.333251953125,1075.6666259765625
AudioAmplifier           mainAmp;        //xy=1968.333251953125,1075.6666259765625
AudioOutputI2S           i2s1;           //xy=2113.333251953125,1075.6666259765625
AudioConnection          patchCord1(dc1, 0, multiply1, 1);
AudioConnection          patchCord2(dc1, 0, multiply2, 0);
AudioConnection          patchCord3(pink1, 0, multiply3, 0);
AudioConnection          patchCord4(tonesweep1, 0, multiply3, 1);
AudioConnection          patchCord5(tonesweep2, 0, multiply4, 1);
AudioConnection          patchCord6(noise1, 0, multiply4, 0);
AudioConnection          patchCord7(waveform1, 0, multiply2, 1);
AudioConnection          patchCord8(sine1, 0, multiply1, 0);
AudioConnection          patchCord9(multiply3, 0, filter1, 0);
AudioConnection          patchCord10(string1, 0, mixer3, 1);
AudioConnection          patchCord11(multiply4, 0, mixer3, 0);
AudioConnection          patchCord12(multiply2, 0, filter2, 0);
AudioConnection          patchCord13(multiply2, sine_fm1);
AudioConnection          patchCord14(filter1, 0, freeverb1, 0);
AudioConnection          patchCord15(filter1, 0, mixer2, 0);
AudioConnection          patchCord16(multiply1, 0, mixer1, 0);
AudioConnection          patchCord17(mixer3, 0, filter3, 0);
AudioConnection          patchCord18(freeverb1, 0, mixer2, 1);
AudioConnection          patchCord19(filter2, 0, mixer1, 1);
AudioConnection          patchCord20(sine_fm1, 0, mixer1, 2);
AudioConnection          patchCord21(filter3, 0, mixer2, 2);
AudioConnection          patchCord22(mixer2, 0, mixer1, 3);
AudioConnection          patchCord23(mixer1, mainAmp);
AudioConnection          patchCord24(mainAmp, 0, i2s1, 0);
AudioConnection          patchCord25(mainAmp, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2005.333251953125,998.6666259765625
// GUItool: end automatically generated code
