#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dc_accA;        //xy=865,2193
AudioSynthNoisePink      pink2;          //xy=880,2683
AudioSynthToneSweep      tonesweep4;     //xy=889,2734
AudioSynthToneSweep      tonesweep3;     //xy=980,2518
AudioSynthNoiseWhite     noise2;         //xy=1000,2463
AudioEffectMultiply      multiply7;      //xy=1034,2699
AudioSynthKarplusStrong  string1;        //xy=1035,2778
AudioSynthWaveformDc     dc_accB;        //xy=1073,3118
AudioSynthWaveform       waveform_7;     //xy=1098,1523
AudioSynthWaveform       waveform_6;     //xy=1103,1418
AudioSynthWaveform       waveform_8;     //xy=1103,1618
AudioSynthToneSweep      tonesweep2;     //xy=1115,2318
AudioSynthNoiseWhite     noise1;         //xy=1135,2263
AudioSynthNoisePink      pink1;          //xy=1160,2073
AudioSynthWaveformSine   LFO1;           //xy=1159,2546
AudioSynthToneSweep      tonesweep1;     //xy=1169,2124
AudioEffectMultiply      multiply5;      //xy=1180,2478
AudioEffectMultiply      multiply8;      //xy=1185,2753
AudioSynthWaveform       waveform_0;     //xy=1186,2986
AudioSynthWaveform       waveform_1;     //xy=1186,3031
AudioSynthWaveform       waveform_2;     //xy=1186,3076
AudioSynthWaveform       waveform_3;     //xy=1186,3171
AudioSynthWaveform       waveform_4;     //xy=1186,3216
AudioSynthWaveform       waveform_5;     //xy=1186,3261
AudioEffectMultiply      multiply3;      //xy=1314,2089
AudioEffectMultiply      multiply4;      //xy=1315,2278
AudioEffectMultiply      multiply6;      //xy=1320,2538
AudioEffectBitcrusher    bitcrusher1;    //xy=1330,2753
AudioMixer4              mixer4;         //xy=1391,3031
AudioMixer4              mixer5;         //xy=1396,3201
AudioFilterStateVariable waveform7_filter; //xy=1443,1523
AudioFilterStateVariable waveform8_filter; //xy=1446,1594
AudioFilterStateVariable waveform6_filter; //xy=1448,1453
AudioEffectMultiply      multiply13;     //xy=1460,2593
AudioEffectMultiply      multiply11;     //xy=1470,2138
AudioEffectMultiply      multiply12;     //xy=1470,2333
AudioEffectMultiply      multiply14;     //xy=1470,2808
AudioEffectMultiply      multiply10;     //xy=1523,3058
AudioEffectMultiply      multiply9;      //xy=1528,3238
AudioEffectEnvelope      waveform6_envelope; //xy=1648,1453
AudioEffectEnvelope      waveform7_envelope; //xy=1648,1523
AudioEffectEnvelope      waveform8_envelope; //xy=1651,1594
AudioSynthSimpleDrum     drum;           //xy=1788,1848
AudioSynthNoisePink      drum_pinknoise; //xy=1797,1999
AudioSynthWaveformDc     drum_noise_dc;  //xy=1797,2059
AudioMixer4              mixer6;         //xy=1853,1498
AudioFilterStateVariable filter3;        //xy=1868,2767
AudioFilterStateVariable filter1;        //xy=1873,2503
AudioFilterStateVariable filter2;        //xy=1873,2632
AudioFilterStateVariable filter4;        //xy=1878,2917
AudioFilterStateVariable drum_filter;    //xy=1938,1858
AudioSynthWaveformSine   drum_noise_tremolo;          //xy=1937,2114
AudioEffectMultiply      multiply;       //xy=1957,2014
AudioEffectBitcrusher    drum_bitcrusher; //xy=2108,1910
AudioEffectMultiply      multiply1;      //xy=2120,2032
AudioMixer4              mixer_acc_sub2; //xy=2193,2628
AudioMixer4              mixer_acc_sub1; //xy=2198,2498
AudioMixer4              mixer_acc_sub3; //xy=2203,2768
AudioMixer4              mixer_acc_sub4; //xy=2208,2908
AudioMixer4              mixer_drum;     //xy=2298,1863
AudioMixer4              mixer_acc_out;  //xy=2423,2693
AudioAmplifier           drum_amp;       //xy=2458,1863
AudioInputI2S            i2s;            //xy=2468,2083
AudioMixer4              mixer1;         //xy=2780,1799
AudioMixer4              mixer2;         //xy=2782,1954
AudioMixer4              mixer1_2;       //xy=2937,1884
AudioAmplifier           mainAmp;        //xy=3087,1884
AudioOutputI2S           i2s1;           //xy=3237,1884
AudioOutputUSB           usb1;           //xy=3246,1976
AudioConnection          patchCord1(dc_accA, 0, multiply11, 1);
AudioConnection          patchCord2(dc_accA, 0, multiply12, 1);
AudioConnection          patchCord3(dc_accA, 0, multiply13, 1);
AudioConnection          patchCord4(dc_accA, 0, multiply14, 1);
AudioConnection          patchCord5(pink2, 0, multiply7, 0);
AudioConnection          patchCord6(tonesweep4, 0, multiply7, 1);
AudioConnection          patchCord7(tonesweep3, 0, multiply5, 1);
AudioConnection          patchCord8(noise2, 0, multiply5, 0);
AudioConnection          patchCord9(multiply7, 0, multiply8, 0);
AudioConnection          patchCord10(string1, 0, multiply8, 1);
AudioConnection          patchCord11(dc_accB, 0, multiply10, 1);
AudioConnection          patchCord12(dc_accB, 0, multiply9, 1);
AudioConnection          patchCord13(waveform_7, 0, waveform7_filter, 0);
AudioConnection          patchCord14(waveform_6, 0, waveform6_filter, 0);
AudioConnection          patchCord15(waveform_8, 0, waveform8_filter, 0);
AudioConnection          patchCord16(waveform_8, 0, waveform7_filter, 1);
AudioConnection          patchCord17(waveform_8, 0, waveform6_filter, 1);
AudioConnection          patchCord18(tonesweep2, 0, multiply4, 1);
AudioConnection          patchCord19(noise1, 0, multiply4, 0);
AudioConnection          patchCord20(pink1, 0, multiply3, 0);
AudioConnection          patchCord21(LFO1, 0, multiply6, 1);
AudioConnection          patchCord22(tonesweep1, 0, multiply3, 1);
AudioConnection          patchCord23(multiply5, 0, multiply6, 0);
AudioConnection          patchCord24(multiply8, bitcrusher1);
AudioConnection          patchCord25(waveform_0, 0, mixer4, 0);
AudioConnection          patchCord26(waveform_1, 0, mixer4, 1);
AudioConnection          patchCord27(waveform_2, 0, mixer4, 2);
AudioConnection          patchCord28(waveform_3, 0, mixer5, 0);
AudioConnection          patchCord29(waveform_4, 0, mixer5, 1);
AudioConnection          patchCord30(waveform_5, 0, mixer5, 2);
AudioConnection          patchCord31(multiply3, 0, multiply11, 0);
AudioConnection          patchCord32(multiply4, 0, multiply12, 0);
AudioConnection          patchCord33(multiply6, 0, multiply13, 0);
AudioConnection          patchCord34(bitcrusher1, 0, multiply14, 0);
AudioConnection          patchCord35(mixer4, 0, multiply10, 0);
AudioConnection          patchCord36(mixer5, 0, multiply9, 0);
AudioConnection          patchCord37(waveform7_filter, 0, waveform7_envelope, 0);
AudioConnection          patchCord38(waveform8_filter, 0, waveform8_envelope, 0);
AudioConnection          patchCord39(waveform6_filter, 0, waveform6_envelope, 0);
AudioConnection          patchCord40(multiply13, 0, filter3, 0);
AudioConnection          patchCord41(multiply11, 0, filter1, 0);
AudioConnection          patchCord42(multiply12, 0, filter2, 0);
AudioConnection          patchCord43(multiply14, 0, filter4, 0);
AudioConnection          patchCord44(multiply10, 0, mixer_acc_sub1, 1);
AudioConnection          patchCord45(multiply10, 0, mixer_acc_sub2, 1);
AudioConnection          patchCord46(multiply9, 0, mixer_acc_sub3, 1);
AudioConnection          patchCord47(multiply9, 0, mixer_acc_sub4, 1);
AudioConnection          patchCord48(waveform6_envelope, 0, mixer6, 0);
AudioConnection          patchCord49(waveform7_envelope, 0, mixer6, 1);
AudioConnection          patchCord50(waveform8_envelope, 0, mixer6, 2);
AudioConnection          patchCord51(drum, 0, drum_filter, 0);
AudioConnection          patchCord52(drum_pinknoise, 0, multiply, 0);
AudioConnection          patchCord53(drum_noise_dc, 0, multiply, 1);
AudioConnection          patchCord54(mixer6, 0, mixer1, 0);
AudioConnection          patchCord55(filter3, 0, mixer_acc_sub3, 0);
AudioConnection          patchCord56(filter1, 0, mixer_acc_sub1, 0);
AudioConnection          patchCord57(filter2, 0, mixer_acc_sub2, 0);
AudioConnection          patchCord58(filter4, 0, mixer_acc_sub4, 0);
AudioConnection          patchCord59(drum_filter, 0, mixer_drum, 0);
AudioConnection          patchCord60(drum_filter, 0, drum_bitcrusher, 0);
AudioConnection          patchCord61(drum_noise_tremolo, 0, multiply1, 1);
AudioConnection          patchCord62(multiply, 0, multiply1, 0);
AudioConnection          patchCord63(drum_bitcrusher, 0, mixer_drum, 2);
AudioConnection          patchCord64(multiply1, 0, mixer_drum, 1);
AudioConnection          patchCord65(mixer_acc_sub2, 0, mixer_acc_out, 1);
AudioConnection          patchCord66(mixer_acc_sub1, 0, mixer_acc_out, 0);
AudioConnection          patchCord67(mixer_acc_sub3, 0, mixer_acc_out, 2);
AudioConnection          patchCord68(mixer_acc_sub4, 0, mixer_acc_out, 3);
AudioConnection          patchCord69(mixer_drum, drum_amp);
AudioConnection          patchCord70(mixer_acc_out, 0, mixer2, 0);
AudioConnection          patchCord71(drum_amp, 0, mixer1, 3);
AudioConnection          patchCord72(i2s, 0, mixer2, 2);
AudioConnection          patchCord73(i2s, 1, mixer2, 3);
AudioConnection          patchCord74(mixer1, 0, mixer1_2, 0);
AudioConnection          patchCord75(mixer2, 0, mixer1_2, 1);
AudioConnection          patchCord76(mixer1_2, mainAmp);
AudioConnection          patchCord77(mainAmp, 0, i2s1, 0);
AudioConnection          patchCord78(mainAmp, 0, i2s1, 1);
AudioConnection          patchCord79(mainAmp, 0, usb1, 0);
AudioConnection          patchCord80(mainAmp, 0, usb1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=3022,1814
// GUItool: end automatically generated code
