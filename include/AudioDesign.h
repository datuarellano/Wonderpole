#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dc_accA;        //xy=1933,1933
AudioSynthNoisePink      pink2;          //xy=1948,2423
AudioSynthToneSweep      tonesweep4;     //xy=1957,2474
AudioSynthToneSweep      tonesweep3;     //xy=2048,2258
AudioSynthNoiseWhite     noise2;         //xy=2068,2203
AudioEffectMultiply      multiply7;      //xy=2102,2439
AudioSynthKarplusStrong  string1;        //xy=2103,2518
AudioSynthWaveformDc     dc_accB;        //xy=2141,2858
AudioSynthWaveform       waveform_7;     //xy=2166,1263
AudioSynthWaveform       waveform_6;     //xy=2171,1158
AudioSynthWaveform       waveform_8;     //xy=2171,1358
AudioSynthToneSweep      tonesweep2;     //xy=2183,2058
AudioSynthNoiseWhite     noise1;         //xy=2203,2003
AudioSynthNoisePink      pink1;          //xy=2228,1813
AudioSynthWaveformSine   LFO1;           //xy=2227,2286
AudioSynthToneSweep      tonesweep1;     //xy=2237,1864
AudioEffectMultiply      multiply5;      //xy=2248,2218
AudioEffectMultiply      multiply8;      //xy=2253,2493
AudioSynthWaveform       waveform_0;     //xy=2254,2726
AudioSynthWaveform       waveform_1;     //xy=2254,2771
AudioSynthWaveform       waveform_2;     //xy=2254,2816
AudioSynthWaveform       waveform_3;     //xy=2254,2911
AudioSynthWaveform       waveform_4;     //xy=2254,2956
AudioSynthWaveform       waveform_5;     //xy=2254,3001
AudioEffectMultiply      multiply3;      //xy=2382,1829
AudioEffectMultiply      multiply4;      //xy=2383,2018
AudioEffectMultiply      multiply6;      //xy=2388,2278
AudioEffectBitcrusher    bitcrusher1;    //xy=2398,2493
AudioMixer4              mixer4;         //xy=2459,2771
AudioMixer4              mixer5;         //xy=2464,2941
AudioFilterStateVariable waveform7_filter; //xy=2511,1263
AudioFilterStateVariable waveform8_filter; //xy=2514,1334
AudioFilterStateVariable waveform6_filter; //xy=2516,1193
AudioEffectMultiply      multiply13;     //xy=2528,2333
AudioEffectMultiply      multiply11;     //xy=2538,1878
AudioEffectMultiply      multiply12;     //xy=2538,2073
AudioEffectMultiply      multiply14;     //xy=2538,2548
AudioEffectMultiply      multiply10;     //xy=2591,2798
AudioEffectMultiply      multiply9;      //xy=2596,2978
AudioEffectEnvelope      waveform6_envelope; //xy=2716,1193
AudioEffectEnvelope      waveform7_envelope; //xy=2716,1263
AudioEffectEnvelope      waveform8_envelope; //xy=2719,1334
AudioSynthSimpleDrum     drum;           //xy=2856,1588
AudioSynthNoisePink      drum_pinknoise; //xy=2865,1739
AudioSynthWaveformDc     drum_noise_dc;  //xy=2865,1799
AudioMixer4              mixer6;         //xy=2921,1238
AudioFilterStateVariable filter3;        //xy=2936,2507
AudioFilterStateVariable filter1;        //xy=2941,2243
AudioFilterStateVariable filter2;        //xy=2941,2372
AudioFilterStateVariable filter4;        //xy=2946,2657
AudioFilterStateVariable drum_filter;    //xy=3006,1598
AudioSynthWaveformSine   drum_noise_tremolo; //xy=3005,1854
AudioEffectMultiply      multiply;       //xy=3025,1754
AudioEffectBitcrusher    drum_bitcrusher; //xy=3176,1650
AudioEffectMultiply      multiply1;      //xy=3188,1772
AudioMixer4              mixer_acc_sub2; //xy=3261,2368
AudioMixer4              mixer_acc_sub1; //xy=3266,2238
AudioMixer4              mixer_acc_sub3; //xy=3271,2508
AudioMixer4              mixer_acc_sub4; //xy=3276,2648
AudioMixer4              mixer_drum;     //xy=3366,1603
AudioMixer4              mixer_acc_out;  //xy=3491,2433
AudioAmplifier           drum_amp;       //xy=3526,1603
AudioInputI2S            i2s;            //xy=3536,1823
AudioMixer4              mixer1;         //xy=3848,1539
AudioMixer4              mixer2;         //xy=3850,1694
AudioAmplifier           mainAmp_LEFT;        //xy=4070.0000610351562,1595.250023841858
AudioAmplifier           mainAmp_RIGHT; //xy=4071.2500610351562,1643.7500247955322
AudioOutputI2S           i2s1;           //xy=4273.7500648498535,1595.2500247955322
AudioOutputUSB           usb1;           //xy=4290.2500648498535,1699.7500247955322
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
AudioConnection          patchCord74(mixer1, mainAmp_LEFT);
AudioConnection          patchCord75(mixer2, mainAmp_RIGHT);
AudioConnection          patchCord76(mainAmp_LEFT, 0, i2s1, 0);
AudioConnection          patchCord77(mainAmp_LEFT, 0, usb1, 0);
AudioConnection          patchCord78(mainAmp_RIGHT, 0, i2s1, 1);
AudioConnection          patchCord79(mainAmp_RIGHT, 0, usb1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=4087.5000610351562,1486.5000228881836
// GUItool: end automatically generated code
