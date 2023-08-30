#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// TeensyAudioDesign: begin automatically generated code
// the following JSON string contains the whole project, 
// it's included in all generated files.
// JSON string:[{"type":"settings","data":{"main":{},"arduino":{"Board":{"Platform":"","Board":"","Options":""}},"BiDirDataWebSocketBridge":{},"workspaces":{},"sidebar":{},"palette":{},"editor":{},"devTest":{},"IndexedDBfiles":{"testFileNames":"testFile.txt"},"NodeDefGenerator":{},"NodeDefManager":{},"NodeHelpManager":{},"OSC":{}}},{"type":"tab","id":"Main","label":"Main","nodes":[],"links":[],"export":true,"isMain":false,"mainNameType":"tabName","mainNameExt":".ino","isAudioMain":false,"generateCppDestructor":false,"extraClassDeclarations":"","settings":{"scaleFactor":0.8}},{"id":"20230813T161538_439Z_cbff","type":"group","name":"Accelerometer A","tag":"","comment":"","w":876,"h":867,"textSize":14,"nodes":["noise1","tonesweep2","pink1","tonesweep1","multiply4","multiply3","20230813T161817_184Z_f1fd","20230813T161817_184Z_bd53","20230813T161817_185Z_1df5","20230813T161903_990Z_8e18","20230813T172012_070Z_cd","20230813T172012_070Z_e2e0","20230813T172012_070Z_186f","20230813T172111_453Z_99b9","20230813T173752_977Z_6aa8","20230813T173152_387Z_97ec","20230813T162045_793Z_7621","20230816T121832_452Z_9aeb","20230816T121841_991Z_d8da","20230816T121845_529Z_3d59","20230816T121847_113Z_44ec","20230816T121955_706Z_32c3","20230816T124931_787Z_2838"],"border_color":"rgba(153,153,153,1)","individualListBoxMode":true,"exportAsClass":true,"x":645,"y":1720,"z":"Main","bgColor":"rgba(221,255,187,1)","wires":[]},{"id":"20230814T143355_676Z_3b8d","type":"group","name":"OUTPUT","tag":"","comment":"","w":600,"h":271,"textSize":14,"nodes":["mixer1","20230814T143041_822Z_8166","20230814T143234_367Z_d1ec","sgtl5000_1","mainAmp","i2s1"],"border_color":"rgba(153,153,153,1)","individualListBoxMode":true,"exportAsClass":true,"x":2475,"y":1175,"z":"Main","bgColor":"rgba(185,255,243,1)","wires":[]},{"id":"20230814T143458_094Z_b1db","type":"group","name":"Ribbon","tag":"","comment":"","w":1206,"h":404,"textSize":14,"nodes":["waveform1","filter2","20230821T035324_270Z_cdd1","20230821T035400_591Z_84ab","20230821T035609_948Z_451b","20230821T035758_832Z_2076","20230821T035858_646Z_3563","20230823T065245_319Z_7663","20230823T065245_320Z_26ac","20230823T065245_320Z_b236"],"border_color":"rgba(153,153,153,1)","individualListBoxMode":true,"exportAsClass":true,"x":958.75,"y":855,"z":"Main","bgColor":"rgba(255,221,198,1)","wires":[]},{"id":"20230815T141132_481Z_fb86","type":"group","name":"Filter Gates and Sub Mixer","tag":"","comment":"","w":967,"h":578,"textSize":14,"nodes":["mixer2","20230815T140646_006Z_c520","20230815T140648_755Z_4831","20230815T140650_779Z_1034","filter1","filter3","20230813T161817_185Z_2898","20230813T172012_070Z_eed9","20230815T140034_949Z_1d66","20230816T124632_083Z_9f19","20230816T124704_679Z_d7fe","20230816T124708_884Z_ee39","20230816T124711_243Z_4bf7"],"border_color":"rgba(153,153,153,1)","individualListBoxMode":true,"exportAsClass":true,"x":1743.75,"y":1995,"z":"Main","bgColor":"rgba(186,255,132,1)","wires":[]},{"id":"20230815T162053_402Z_a1c8","type":"group","name":"Accelerometer B","tag":"","comment":"","w":632,"h":469,"textSize":14,"nodes":["20230815T152825_563Z_7702","20230815T154157_444Z_f5cd","20230815T160816_293Z_fce7","20230815T160828_766Z_6b7c","20230815T160828_767Z_d963","20230815T160828_767Z_9408","20230815T153035_214Z_d7b7","20230815T154157_444Z_cd12","20230816T120105_625Z_13f1","20230816T120853_156Z_9989","20230816T120901_313Z_bd30"],"border_color":"rgba(153,153,153,1)","individualListBoxMode":true,"exportAsClass":true,"x":775,"y":2416,"z":"Main","bgColor":"rgba(180,255,235,1)","wires":[]},{"id":"20230816T124632_083Z_9f19","type":"UI_Label","name":"LEFT","tag":"","comment":"","w":60,"h":30,"textSize":14,"text":"","parentGroup":"20230815T141132_481Z_fb86","x":1620,"y":1755,"z":"Main","bgColor":"#F6F8BC","wires":[]},{"id":"20230816T124704_679Z_d7fe","type":"UI_Label","name":"RIGHT","tag":"","comment":"","w":60,"h":30,"textSize":14,"text":"","parentGroup":"20230815T141132_481Z_fb86","x":1615,"y":1890,"z":"Main","bgColor":"#F6F8BC","wires":[]},{"id":"20230816T124708_884Z_ee39","type":"UI_Label","name":"FORE","tag":"","comment":"","w":60,"h":30,"textSize":14,"text":"","parentGroup":"20230815T141132_481Z_fb86","x":1625,"y":2025,"z":"Main","bgColor":"#F6F8BC","wires":[]},{"id":"20230816T124711_243Z_4bf7","type":"UI_Label","name":"BACK","tag":"","comment":"","w":60,"h":30,"textSize":14,"text":"","parentGroup":"20230815T141132_481Z_fb86","x":1625,"y":2165,"z":"Main","bgColor":"#F6F8BC","wires":[]},{"id":"20230816T124814_474Z_2f99","type":"UI_Label","name":"Microphone -> RIGHT","tag":"","comment":"","w":173,"h":30,"textSize":14,"text":"","x":1995,"y":1505,"z":"Main","bgColor":"#F6F8BC","wires":[]},{"id":"20230816T124931_787Z_2838","type":"group","name":"group","tag":"","comment":"","w":492,"h":155,"textSize":14,"nodes":[],"border_color":"#999","individualListBoxMode":"false","exportAsClass":"false","parentGroup":"20230813T161538_439Z_cbff","x":783.75,"y":1407,"z":"Main","bgColor":"#ddffbb","wires":[]},{"id":"20230822T114219_105Z_2a9","type":"UI_Label","name":"Piezo -> LEFT ","tag":"","comment":"","w":129,"h":30,"textSize":14,"text":"","x":1970,"y":1460,"z":"Main","bgColor":"#F6F8BC","wires":[]},{"id":"20230816T121955_706Z_32c3","type":"AudioSynthWaveformDc","name":"dc_accA","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":337.5,"y":1495,"z":"Main","bgColor":"#F8BCBC","wires":[["20230816T121832_452Z_9aeb:1","20230816T121841_991Z_d8da:1","20230816T121845_529Z_3d59:1","20230816T121847_113Z_44ec:1"]]},{"id":"20230813T172012_070Z_cd","type":"AudioSynthNoisePink","name":"pink2","parentGroup":"20230813T161538_439Z_cbff","x":352.5,"y":1985,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T172012_070Z_186f:0"]]},{"id":"20230813T172012_070Z_e2e0","type":"AudioSynthToneSweep","name":"tonesweep4","parentGroup":"20230813T161538_439Z_cbff","x":361.5,"y":2036,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T172012_070Z_186f:1"]]},{"id":"20230813T161817_184Z_bd53","type":"AudioSynthNoiseWhite","name":"noise2","parentGroup":"20230813T161538_439Z_cbff","x":472.5,"y":1765,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T161817_185Z_1df5:0"]]},{"id":"20230813T161817_184Z_f1fd","type":"AudioSynthToneSweep","name":"tonesweep3","parentGroup":"20230813T161538_439Z_cbff","x":452.5,"y":1820,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T161817_185Z_1df5:1"]]},{"id":"20230821T035609_948Z_451b","type":"AudioSynthWaveform","name":"waveform_6","comment":"","arraySize":"","parentGroup":"20230814T143458_094Z_b1db","x":575,"y":720,"z":"Main","bgColor":"#E6E0F8","wires":[["filter2:0"]]},{"id":"waveform1","type":"AudioSynthWaveform","name":"waveform_7","comment":"","arraySize":"","parentGroup":"20230814T143458_094Z_b1db","x":570,"y":825,"z":"Main","bgColor":"#E6E0F8","wires":[["20230821T035324_270Z_cdd1:0"]]},{"id":"20230823T065245_319Z_7663","type":"AudioSynthWaveform","name":"waveform_8","comment":"","arraySize":"","parentGroup":"20230814T143458_094Z_b1db","x":575,"y":920,"z":"Main","bgColor":"#E6E0F8","wires":[["20230823T065245_320Z_26ac:0","20230821T035324_270Z_cdd1:1","filter2:1"]]},{"id":"tonesweep2","type":"AudioSynthToneSweep","name":"tonesweep2","parentGroup":"20230813T161538_439Z_cbff","x":587.5,"y":1620,"z":"Main","bgColor":"#E6E0F8","wires":[["multiply4:1"]]},{"id":"20230813T172012_070Z_186f","type":"AudioEffectMultiply","name":"multiply7","parentGroup":"20230813T161538_439Z_cbff","x":506.5,"y":2001,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T172111_453Z_99b9:0"]]},{"id":"20230813T173152_387Z_97ec","type":"AudioSynthKarplusStrong","name":"string1","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":507.5,"y":2080,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T172111_453Z_99b9:1"]]},{"id":"20230816T120105_625Z_13f1","type":"AudioSynthWaveformDc","name":"dc_accB","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":545,"y":2420,"z":"Main","bgColor":"#F8B2B2","wires":[["20230816T120853_156Z_9989:1","20230816T120901_313Z_bd30:1"]]},{"id":"pink1","type":"AudioSynthNoisePink","name":"pink1","parentGroup":"20230813T161538_439Z_cbff","x":632.5,"y":1375,"z":"Main","bgColor":"#E6E0F8","wires":[["multiply3:0"]]},{"id":"tonesweep1","type":"AudioSynthToneSweep","name":"tonesweep1","parentGroup":"20230813T161538_439Z_cbff","x":641.5,"y":1426,"z":"Main","bgColor":"#E6E0F8","wires":[["multiply3:1"]]},{"id":"noise1","type":"AudioSynthNoiseWhite","name":"noise1","parentGroup":"20230813T161538_439Z_cbff","x":607.5,"y":1565,"z":"Main","bgColor":"#E6E0F8","wires":[["multiply4:0"]]},{"id":"20230813T161817_185Z_1df5","type":"AudioEffectMultiply","name":"multiply5","parentGroup":"20230813T161538_439Z_cbff","x":652.5,"y":1780,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T161903_990Z_8e18:0"]]},{"id":"20230813T162045_793Z_7621","type":"AudioSynthWaveformSine","name":"LFO1","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":631.9444580078125,"y":1848,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T161903_990Z_8e18:1"]]},{"id":"20230813T172111_453Z_99b9","type":"AudioEffectMultiply","name":"multiply8","parentGroup":"20230813T161538_439Z_cbff","x":657.5,"y":2055,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T173752_977Z_6aa8:0"]]},{"id":"20230815T152825_563Z_7702","type":"AudioSynthWaveform","name":"waveform_0","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":658.75,"y":2288,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T153035_214Z_d7b7:0"]]},{"id":"20230815T154157_444Z_f5cd","type":"AudioSynthWaveform","name":"waveform_1","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":658.75,"y":2333,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T153035_214Z_d7b7:1"]]},{"id":"20230815T160816_293Z_fce7","type":"AudioSynthWaveform","name":"waveform_2","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":658.75,"y":2378,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T153035_214Z_d7b7:2"]]},{"id":"20230815T160828_766Z_6b7c","type":"AudioSynthWaveform","name":"waveform_3","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":658.75,"y":2473,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T154157_444Z_cd12:0"]]},{"id":"20230815T160828_767Z_d963","type":"AudioSynthWaveform","name":"waveform_4","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":658.75,"y":2518,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T154157_444Z_cd12:1"]]},{"id":"20230815T160828_767Z_9408","type":"AudioSynthWaveform","name":"waveform_5","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":658.75,"y":2563,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T154157_444Z_cd12:2"]]},{"id":"multiply3","type":"AudioEffectMultiply","name":"multiply3","parentGroup":"20230813T161538_439Z_cbff","x":786.5,"y":1391,"z":"Main","bgColor":"#E6E0F8","wires":[["20230816T121832_452Z_9aeb:0"]]},{"id":"multiply4","type":"AudioEffectMultiply","name":"multiply4","parentGroup":"20230813T161538_439Z_cbff","x":787.5,"y":1580,"z":"Main","bgColor":"#E6E0F8","wires":[["20230816T121841_991Z_d8da:0"]]},{"id":"20230813T161903_990Z_8e18","type":"AudioEffectMultiply","name":"multiply6","parentGroup":"20230813T161538_439Z_cbff","x":792.5,"y":1840,"z":"Main","bgColor":"#E6E0F8","wires":[["20230816T121845_529Z_3d59:0"]]},{"id":"20230813T173752_977Z_6aa8","type":"AudioEffectBitcrusher","name":"bitcrusher1","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":802.5,"y":2055,"z":"Main","bgColor":"#E6E0F8","wires":[["20230816T121847_113Z_44ec:0"]]},{"id":"20230815T153035_214Z_d7b7","type":"AudioMixer4","name":"mixer4","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":863.75,"y":2333,"z":"Main","bgColor":"#E6E0F8","wires":[["20230816T120853_156Z_9989:0"]]},{"id":"20230815T154157_444Z_cd12","type":"AudioMixer4","name":"mixer5","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":868.75,"y":2503,"z":"Main","bgColor":"#E6E0F8","wires":[["20230816T120901_313Z_bd30:0"]]},{"id":"filter2","type":"AudioFilterStateVariable","name":"waveform6_filter","comment":"","arraySize":"","parentGroup":"20230814T143458_094Z_b1db","x":920,"y":755,"z":"Main","bgColor":"#E6E0F8","wires":[["20230821T035758_832Z_2076:0"],[],[]]},{"id":"20230821T035324_270Z_cdd1","type":"AudioFilterStateVariable","name":"waveform7_filter","comment":"","arraySize":"","parentGroup":"20230814T143458_094Z_b1db","x":915,"y":825,"z":"Main","bgColor":"#E6E0F8","wires":[["20230821T035858_646Z_3563:0"],[],[]]},{"id":"20230823T065245_320Z_26ac","type":"AudioFilterStateVariable","name":"waveform8_filter","comment":"","arraySize":"","parentGroup":"20230814T143458_094Z_b1db","x":918,"y":896.5,"z":"Main","bgColor":"#E6E0F8","wires":[["20230823T065245_320Z_b236:0"],[],[]]},{"id":"20230816T121832_452Z_9aeb","type":"AudioEffectMultiply","name":"multiply11","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":942.5,"y":1440,"z":"Main","bgColor":"#E6E0F8","wires":[["filter1:0"]]},{"id":"20230816T121841_991Z_d8da","type":"AudioEffectMultiply","name":"multiply12","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":942.5,"y":1635,"z":"Main","bgColor":"#E6E0F8","wires":[["filter3:0"]]},{"id":"20230816T121845_529Z_3d59","type":"AudioEffectMultiply","name":"multiply13","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":932.5,"y":1895,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T161817_185Z_2898:0"]]},{"id":"20230816T121847_113Z_44ec","type":"AudioEffectMultiply","name":"multiply14","comment":"","arraySize":1,"parentGroup":"20230813T161538_439Z_cbff","x":942.5,"y":2110,"z":"Main","bgColor":"#E6E0F8","wires":[["20230813T172012_070Z_eed9:0"]]},{"id":"20230816T120853_156Z_9989","type":"AudioEffectMultiply","name":"multiply10","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":995,"y":2360,"z":"Main","bgColor":"#E6E0F8","wires":[["mixer2:1","20230815T140646_006Z_c520:1"]]},{"id":"20230816T120901_313Z_bd30","type":"AudioEffectMultiply","name":"multiply9","comment":"","arraySize":1,"parentGroup":"20230815T162053_402Z_a1c8","x":1000,"y":2540,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140648_755Z_4831:1","20230815T140650_779Z_1034:1"]]},{"id":"20230821T035758_832Z_2076","type":"AudioEffectEnvelope","name":"waveform6_envelope","comment":"","arraySize":1,"parentGroup":"20230814T143458_094Z_b1db","x":1120,"y":755,"z":"Main","bgColor":"#E6E0F8","wires":[["20230821T035400_591Z_84ab:0"]]},{"id":"20230821T035858_646Z_3563","type":"AudioEffectEnvelope","name":"waveform7_envelope","comment":"","arraySize":1,"parentGroup":"20230814T143458_094Z_b1db","x":1120,"y":825,"z":"Main","bgColor":"#E6E0F8","wires":[["20230821T035400_591Z_84ab:1"]]},{"id":"20230823T065245_320Z_b236","type":"AudioEffectEnvelope","name":"waveform8_envelope","comment":"","arraySize":1,"parentGroup":"20230814T143458_094Z_b1db","x":1123,"y":896.5,"z":"Main","bgColor":"#E6E0F8","wires":[["20230821T035400_591Z_84ab:2"]]},{"id":"20230822T154842_327Z_579b","type":"AudioSynthSimpleDrum","name":"drum","comment":"","arraySize":1,"x":1260,"y":1150,"z":"Main","bgColor":"#E6E0F8","wires":[["20230822T160554_071Z_4bf7:0"]]},{"id":"20230822T160809_779Z_eb2d","type":"AudioSynthNoisePink","name":"drum_pinknoise","comment":"","arraySize":1,"x":1255,"y":1255,"z":"Main","bgColor":"#E6E0F8","wires":[["20230822T160817_310Z_13d6:0"]]},{"id":"20230823T155112_776Z_5f1f","type":"AudioSynthWaveformDc","name":"drum_noise_dc","comment":"","arraySize":1,"x":1255,"y":1315,"z":"Main","bgColor":"#E6E0F8","wires":[["20230822T160817_310Z_13d6:1"]]},{"id":"20230821T035400_591Z_84ab","type":"AudioMixer4","name":"mixer6","comment":"","arraySize":1,"parentGroup":"20230814T143458_094Z_b1db","x":1325,"y":800,"z":"Main","bgColor":"#E6E0F8","wires":[["mixer1:0"]]},{"id":"filter1","type":"AudioFilterStateVariable","name":"filter1","parentGroup":"20230815T141132_481Z_fb86","x":1345,"y":1805,"z":"Main","bgColor":"#E6E0F8","wires":[["mixer2:0"],[],[]]},{"id":"filter3","type":"AudioFilterStateVariable","name":"filter2","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1345,"y":1934.25,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140646_006Z_c520:0"],[],[]]},{"id":"20230813T161817_185Z_2898","type":"AudioFilterStateVariable","name":"filter3","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1340,"y":2069.25,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140648_755Z_4831:0"],[],[]]},{"id":"20230813T172012_070Z_eed9","type":"AudioFilterStateVariable","name":"filter4","parentGroup":"20230815T141132_481Z_fb86","x":1350,"y":2219.25,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140650_779Z_1034:0"],[],[]]},{"id":"20230822T160554_071Z_4bf7","type":"AudioFilterStateVariable","name":"drum_filter","comment":"","arraySize":1,"x":1410,"y":1160,"z":"Main","bgColor":"#E6E0F8","wires":[["20230822T160502_109Z_8843:0","20230822T162029_803Z_3fca:0"],[],[]]},{"id":"20230822T160817_310Z_13d6","type":"AudioEffectMultiply","name":"multiply","comment":"","arraySize":1,"x":1415,"y":1270,"z":"Main","bgColor":"#E6E0F8","wires":[["20230822T160502_109Z_8843:1"]]},{"id":"20230822T162029_803Z_3fca","type":"AudioEffectBitcrusher","name":"drum_bitcrusher","comment":"","arraySize":1,"x":1585,"y":1285,"z":"Main","bgColor":"#E6E0F8","wires":[["20230822T160502_109Z_8843:2"]]},{"id":"mixer2","type":"AudioMixer4","name":"mixer_acc_sub1","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1670,"y":1800,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140034_949Z_1d66:0"]]},{"id":"20230815T140646_006Z_c520","type":"AudioMixer4","name":"mixer_acc_sub2","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1665,"y":1930,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140034_949Z_1d66:1"]]},{"id":"20230815T140648_755Z_4831","type":"AudioMixer4","name":"mixer_acc_sub3","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1675,"y":2070,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140034_949Z_1d66:2"]]},{"id":"20230815T140650_779Z_1034","type":"AudioMixer4","name":"mixer_acc_sub4","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1680,"y":2210,"z":"Main","bgColor":"#E6E0F8","wires":[["20230815T140034_949Z_1d66:3"]]},{"id":"20230822T160502_109Z_8843","type":"AudioMixer4","name":"mixer_drum","comment":"","arraySize":1,"x":1770,"y":1165,"z":"Main","bgColor":"#E6E0F8","wires":[["20230823T072624_286Z_96f4:0"]]},{"id":"20230815T140034_949Z_1d66","type":"AudioMixer4","name":"mixer_acc_out","comment":"","arraySize":"","parentGroup":"20230815T141132_481Z_fb86","x":1895,"y":1995,"z":"Main","bgColor":"#E6E0F8","wires":[["20230814T143041_822Z_8166:0"]]},{"id":"20230823T072624_286Z_96f4","type":"AudioAmplifier","name":"drum_amp","comment":"","arraySize":1,"x":1930,"y":1165,"z":"Main","bgColor":"#E6E0F8","wires":[["mixer1:3"]]},{"id":"20230814T143627_927Z_748d","type":"AudioInputI2S","name":"i2s","comment":"","x":1940,"y":1385,"z":"Main","bgColor":"#E6E0F8","wires":[["20230814T143041_822Z_8166:2"],["20230814T143041_822Z_8166:3"]]},{"id":"mixer1","type":"AudioMixer4","name":"mixer1","parentGroup":"20230814T143355_676Z_3b8d","x":2252.2222968207466,"y":1101,"z":"Main","bgColor":"#E6E0F8","wires":[["20230814T143234_367Z_d1ec:0"]]},{"id":"20230814T143041_822Z_8166","type":"AudioMixer4","name":"mixer2","comment":"","arraySize":"","parentGroup":"20230814T143355_676Z_3b8d","x":2254.2222968207466,"y":1256,"z":"Main","bgColor":"#E6E0F8","wires":[["20230814T143234_367Z_d1ec:1"]]},{"id":"sgtl5000_1","type":"AudioControlSGTL5000","name":"sgtl5000_1","parentGroup":"20230814T143355_676Z_3b8d","x":2494.2222968207466,"y":1116,"z":"Main","bgColor":"#E6E0F8","wires":[]},{"id":"20230814T143234_367Z_d1ec","type":"AudioMixer4","name":"mixer1_2","comment":"","arraySize":"","parentGroup":"20230814T143355_676Z_3b8d","x":2409.2222968207466,"y":1186,"z":"Main","bgColor":"#E6E0F8","wires":[["mainAmp:0"]]},{"id":"mainAmp","type":"AudioAmplifier","name":"mainAmp","parentGroup":"20230814T143355_676Z_3b8d","x":2559.2222968207466,"y":1186,"z":"Main","bgColor":"#E6E0F8","wires":[["i2s1:0","i2s1:1"]]},{"id":"i2s1","type":"AudioOutputI2S","name":"i2s1","parentGroup":"20230814T143355_676Z_3b8d","x":2709.2222968207466,"y":1186,"z":"Main","bgColor":"#E6E0F8","wires":[]}]




// Audio Processing Nodes
AudioSynthWaveformDc            dc_accA; //xy=337.5,1495
AudioSynthNoisePink             pink2; //xy=352.5,1985
AudioSynthToneSweep             tonesweep4; //xy=361.5,2036
AudioSynthNoiseWhite            noise2; //xy=472.5,1765
AudioSynthToneSweep             tonesweep3; //xy=452.5,1820
AudioSynthWaveform              waveform_6; //xy=575,720
AudioSynthWaveform              waveform_7;      //xy=570,825
AudioSynthWaveform              waveform_8; //xy=575,920
AudioSynthToneSweep             tonesweep2;     //xy=587.5,1620
AudioEffectMultiply             multiply7; //xy=506.5,2001
AudioSynthKarplusStrong         string1; //xy=507.5,2080
AudioSynthWaveformDc            dc_accB; //xy=545,2420
AudioSynthNoisePink             pink1;          //xy=632.5,1375
AudioSynthToneSweep             tonesweep1;     //xy=641.5,1426
AudioSynthNoiseWhite            noise1;         //xy=607.5,1565
AudioEffectMultiply             multiply5; //xy=652.5,1780
AudioSynthWaveformSine          LFO1; //xy=631.9444580078125,1848
AudioEffectMultiply             multiply8; //xy=657.5,2055
AudioSynthWaveform              waveform_0; //xy=658.75,2288
AudioSynthWaveform              waveform_1; //xy=658.75,2333
AudioSynthWaveform              waveform_2; //xy=658.75,2378
AudioSynthWaveform              waveform_3; //xy=658.75,2473
AudioSynthWaveform              waveform_4; //xy=658.75,2518
AudioSynthWaveform              waveform_5; //xy=658.75,2563
AudioEffectMultiply             multiply3;      //xy=786.5,1391
AudioEffectMultiply             multiply4;      //xy=787.5,1580
AudioEffectMultiply             multiply6; //xy=792.5,1840
AudioEffectBitcrusher           bitcrusher1; //xy=802.5,2055
AudioMixer4                     mixer4; //xy=863.75,2333
AudioMixer4                     mixer5; //xy=868.75,2503
AudioFilterStateVariable        waveform6_filter;        //xy=920,755
AudioFilterStateVariable        waveform7_filter; //xy=915,825
AudioFilterStateVariable        waveform8_filter; //xy=918,896.5
AudioEffectMultiply             multiply11; //xy=942.5,1440
AudioEffectMultiply             multiply12; //xy=942.5,1635
AudioEffectMultiply             multiply13; //xy=932.5,1895
AudioEffectMultiply             multiply14; //xy=942.5,2110
AudioEffectMultiply             multiply10; //xy=995,2360
AudioEffectMultiply             multiply9; //xy=1000,2540
AudioEffectEnvelope             waveform6_envelope; //xy=1120,755
AudioEffectEnvelope             waveform7_envelope; //xy=1120,825
AudioEffectEnvelope             waveform8_envelope; //xy=1123,896.5
AudioSynthSimpleDrum            drum; //xy=1260,1150
AudioSynthNoisePink             drum_pinknoise; //xy=1255,1255
AudioSynthWaveformDc            drum_noise_dc; //xy=1255,1315
AudioMixer4                     mixer6; //xy=1325,800
AudioFilterStateVariable        filter1;        //xy=1345,1805
AudioFilterStateVariable        filter2;        //xy=1345,1934.25
AudioFilterStateVariable        filter3; //xy=1340,2069.25
AudioFilterStateVariable        filter4; //xy=1350,2219.25
AudioFilterStateVariable        drum_filter; //xy=1410,1160
AudioEffectMultiply             multiply; //xy=1415,1270
AudioEffectBitcrusher           drum_bitcrusher; //xy=1585,1285
AudioMixer4                     mixer_acc_sub1;         //xy=1670,1800
AudioMixer4                     mixer_acc_sub2; //xy=1665,1930
AudioMixer4                     mixer_acc_sub3; //xy=1675,2070
AudioMixer4                     mixer_acc_sub4; //xy=1680,2210
AudioMixer4                     mixer_drum; //xy=1770,1165
AudioMixer4                     mixer_acc_out; //xy=1895,1995
AudioAmplifier                  drum_amp; //xy=1930,1165
AudioInputI2S                   i2s; //xy=1940,1385
AudioMixer4                     mixer1;         //xy=2252.2222968207466,1101
AudioMixer4                     mixer2; //xy=2254.2222968207466,1256
AudioMixer4                     mixer1_2; //xy=2409.2222968207466,1186
AudioAmplifier                  mainAmp;        //xy=2559.2222968207466,1186
AudioOutputI2S                  i2s1;           //xy=2709.2222968207466,1186

// Audio Connections (all connections (aka wires or links))
AudioConnection        patchCord1(dc_accA, 0, multiply11, 1);
AudioConnection        patchCord2(dc_accA, 0, multiply12, 1);
AudioConnection        patchCord3(dc_accA, 0, multiply13, 1);
AudioConnection        patchCord4(dc_accA, 0, multiply14, 1);
AudioConnection        patchCord5(pink2, 0, multiply7, 0);
AudioConnection        patchCord6(tonesweep4, 0, multiply7, 1);
AudioConnection        patchCord7(noise2, 0, multiply5, 0);
AudioConnection        patchCord8(tonesweep3, 0, multiply5, 1);
AudioConnection        patchCord9(waveform_6, 0, waveform6_filter, 0);
AudioConnection        patchCord10(waveform_7, 0, waveform7_filter, 0);
AudioConnection        patchCord11(waveform_8, 0, waveform8_filter, 0);
AudioConnection        patchCord12(waveform_8, 0, waveform7_filter, 1);
AudioConnection        patchCord13(waveform_8, 0, waveform6_filter, 1);
AudioConnection        patchCord14(tonesweep2, 0, multiply4, 1);
AudioConnection        patchCord15(multiply7, 0, multiply8, 0);
AudioConnection        patchCord16(string1, 0, multiply8, 1);
AudioConnection        patchCord17(dc_accB, 0, multiply10, 1);
AudioConnection        patchCord18(dc_accB, 0, multiply9, 1);
AudioConnection        patchCord19(pink1, 0, multiply3, 0);
AudioConnection        patchCord20(tonesweep1, 0, multiply3, 1);
AudioConnection        patchCord21(noise1, 0, multiply4, 0);
AudioConnection        patchCord22(multiply5, 0, multiply6, 0);
AudioConnection        patchCord23(LFO1, 0, multiply6, 1);
AudioConnection        patchCord24(multiply8, 0, bitcrusher1, 0);
AudioConnection        patchCord25(waveform_0, 0, mixer4, 0);
AudioConnection        patchCord26(waveform_1, 0, mixer4, 1);
AudioConnection        patchCord27(waveform_2, 0, mixer4, 2);
AudioConnection        patchCord28(waveform_3, 0, mixer5, 0);
AudioConnection        patchCord29(waveform_4, 0, mixer5, 1);
AudioConnection        patchCord30(waveform_5, 0, mixer5, 2);
AudioConnection        patchCord31(multiply3, 0, multiply11, 0);
AudioConnection        patchCord32(multiply4, 0, multiply12, 0);
AudioConnection        patchCord33(multiply6, 0, multiply13, 0);
AudioConnection        patchCord34(bitcrusher1, 0, multiply14, 0);
AudioConnection        patchCord35(mixer4, 0, multiply10, 0);
AudioConnection        patchCord36(mixer5, 0, multiply9, 0);
AudioConnection        patchCord37(waveform6_filter, 0, waveform6_envelope, 0);
AudioConnection        patchCord38(waveform7_filter, 0, waveform7_envelope, 0);
AudioConnection        patchCord39(waveform8_filter, 0, waveform8_envelope, 0);
AudioConnection        patchCord40(multiply11, 0, filter1, 0);
AudioConnection        patchCord41(multiply12, 0, filter2, 0);
AudioConnection        patchCord42(multiply13, 0, filter3, 0);
AudioConnection        patchCord43(multiply14, 0, filter4, 0);
AudioConnection        patchCord44(multiply10, 0, mixer_acc_sub1, 1);
AudioConnection        patchCord45(multiply10, 0, mixer_acc_sub2, 1);
AudioConnection        patchCord46(multiply9, 0, mixer_acc_sub3, 1);
AudioConnection        patchCord47(multiply9, 0, mixer_acc_sub4, 1);
AudioConnection        patchCord48(waveform6_envelope, 0, mixer6, 0);
AudioConnection        patchCord49(waveform7_envelope, 0, mixer6, 1);
AudioConnection        patchCord50(waveform8_envelope, 0, mixer6, 2);
AudioConnection        patchCord51(drum, 0, drum_filter, 0);
AudioConnection        patchCord52(drum_pinknoise, 0, multiply, 0);
AudioConnection        patchCord53(drum_noise_dc, 0, multiply, 1);
AudioConnection        patchCord54(mixer6, 0, mixer1, 0);
AudioConnection        patchCord55(filter1, 0, mixer_acc_sub1, 0);
AudioConnection        patchCord56(filter2, 0, mixer_acc_sub2, 0);
AudioConnection        patchCord57(filter3, 0, mixer_acc_sub3, 0);
AudioConnection        patchCord58(filter4, 0, mixer_acc_sub4, 0);
AudioConnection        patchCord59(drum_filter, 0, mixer_drum, 0);
AudioConnection        patchCord60(drum_filter, 0, drum_bitcrusher, 0);
AudioConnection        patchCord61(multiply, 0, mixer_drum, 1);
AudioConnection        patchCord62(drum_bitcrusher, 0, mixer_drum, 2);
AudioConnection        patchCord63(mixer_acc_sub1, 0, mixer_acc_out, 0);
AudioConnection        patchCord64(mixer_acc_sub2, 0, mixer_acc_out, 1);
AudioConnection        patchCord65(mixer_acc_sub3, 0, mixer_acc_out, 2);
AudioConnection        patchCord66(mixer_acc_sub4, 0, mixer_acc_out, 3);
AudioConnection        patchCord67(mixer_drum, 0, drum_amp, 0);
AudioConnection        patchCord68(mixer_acc_out, 0, mixer2, 0);
AudioConnection        patchCord69(drum_amp, 0, mixer1, 3);
AudioConnection        patchCord70(i2s, 0, mixer2, 2);
AudioConnection        patchCord71(i2s, 1, mixer2, 3);
AudioConnection        patchCord72(mixer1, 0, mixer1_2, 0);
AudioConnection        patchCord73(mixer2, 0, mixer1_2, 1);
AudioConnection        patchCord74(mixer1_2, 0, mainAmp, 0);
AudioConnection        patchCord75(mainAmp, 0, i2s1, 0);
AudioConnection        patchCord76(mainAmp, 0, i2s1, 1);

// Control Nodes (all control nodes (no inputs or outputs))
AudioControlSGTL5000     sgtl5000_1;     //xy=2494.2222968207466,1116



// TeensyAudioDesign: end automatically generated code
