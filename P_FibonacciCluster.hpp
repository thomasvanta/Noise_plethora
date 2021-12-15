// Noise Plethora
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported
// See LICENSE.txt for the complete license text

#pragma once

#include "Plugin.hpp"

class FibonacciCluster : public Plugin {

public:

  FibonacciCluster()
    : patchCord1(noise1, 0, waveform1, 0)
    , patchCord2(noise1, 0, waveform2, 0)
    , patchCord3(noise1, 0, waveform3, 0)
    , patchCord4(noise1, 0, waveform4, 0)
    , patchCord5(noise1, 0, waveform5, 0)
    , patchCord6(noise1, 0, waveform6, 0)
    , patchCord7(noise1, 0, waveform7, 0)
    , patchCord8(noise1, 0, waveform8, 0)
    , patchCord9(noise1, 0, waveform9, 0)
    , patchCord10(noise1, 0, waveform10, 0)
    , patchCord11(noise1, 0, waveform11, 0)
    , patchCord12(noise1, 0, waveform12, 0)
    , patchCord13(noise1, 0, waveform13, 0)
    , patchCord14(noise1, 0, waveform14, 0)
    , patchCord15(noise1, 0, waveform15, 0)
    , patchCord16(noise1, 0, waveform16, 0)
    , patchCord17(waveform16, 0, mixer4, 3)
    , patchCord18(waveform14, 0, mixer4, 1)
    , patchCord19(waveform15, 0, mixer4, 2)
    , patchCord20(waveform13, 0, mixer4, 0)
    , patchCord21(waveform8, 0, mixer2, 3)
    , patchCord22(waveform6, 0, mixer2, 1)
    , patchCord23(waveform7, 0, mixer2, 2)
    , patchCord24(waveform12, 0, mixer3, 3)
    , patchCord25(waveform5, 0, mixer2, 0)
    , patchCord26(waveform10, 0, mixer3, 1)
    , patchCord27(waveform11, 0, mixer3, 2)
    , patchCord28(waveform9, 0, mixer3, 0)
    , patchCord29(waveform4, 0, mixer1, 3)
    , patchCord30(waveform2, 0, mixer1, 1)
    , patchCord31(waveform3, 0, mixer1, 2)
    , patchCord32(waveform1, 0, mixer1, 0)
    , patchCord33(mixer4, 0, mixer5, 3)
    , patchCord34(mixer3, 0, mixer5, 2)
    , patchCord35(mixer2, 0, mixer5, 1)
    , patchCord36(mixer1, 0, mixer5, 0)
  {}

  ~FibonacciCluster() override {}

  FibonacciCluster(const FibonacciCluster&) = delete;
  FibonacciCluster& operator=(const FibonacciCluster&) = delete;

  void init() override {
    mixer1.gain(0,1);
    mixer1.gain(1,1);
    mixer1.gain(2,1);
    mixer1.gain(3,1);
    mixer2.gain(0,1);
    mixer2.gain(1,1);
    mixer2.gain(2,1);
    mixer2.gain(3,1);
    mixer3.gain(0,1);
    mixer3.gain(1,1);
    mixer3.gain(2,1);
    mixer3.gain(3,1);
    mixer4.gain(0,1);
    mixer4.gain(1,1);
    mixer4.gain(2,1);
    mixer4.gain(3,1);
    mixer5.gain(0,1);
    mixer5.gain(1,1);
    mixer5.gain(2,1);
    mixer5.gain(3,1);

    int masterWaveform= WAVEFORM_SAWTOOTH;
    float masterVolume=0.2;

    waveform1.begin(masterVolume, 794, masterWaveform);
    waveform2.begin(masterVolume, 647, masterWaveform);
    waveform3.begin(masterVolume, 524, masterWaveform);
    waveform4.begin(masterVolume, 444, masterWaveform);
    waveform5.begin(masterVolume, 368, masterWaveform);
    waveform6.begin(masterVolume, 283, masterWaveform);
    waveform7.begin(masterVolume, 283, masterWaveform);
    waveform8.begin(masterVolume, 283, masterWaveform);
    waveform9.begin(masterVolume, 283, masterWaveform);
    waveform10.begin(masterVolume, 283, masterWaveform);
    waveform11.begin(masterVolume, 283, masterWaveform);
    waveform12.begin(masterVolume, 283, masterWaveform);
    waveform13.begin(masterVolume, 283, masterWaveform);
    waveform14.begin(masterVolume, 283, masterWaveform);
    waveform15.begin(masterVolume, 283, masterWaveform);
    waveform16.begin(masterVolume, 283, masterWaveform);
  }

  void process(float k1, float k2) override {
    float knob_1 = k1;
    float knob_2 = k2;

    float pitch1 = pow(knob_1, 2);
    float pitch2 = pow(knob_2, 2);
    float spread= pitch2/2+0.1;

    float f1 = 40+pitch1*5000;
    float f2 = f1*(2*spread+1);
    float f3 = f1+f2*spread;
    float f4 = f2+f3*spread;
    float f5 = f3+f4*spread;
    float f6 = f4+f5*spread;
    float f7 = f5+f6*spread;
    float f8 = f6+f7*spread;
    float f9 = f7+f8*spread;
    float f10 = f8+f9*spread;
    float f11 = f9+f10*spread;
    float f12 = f10+f11*spread;
    float f13 = f11+f12*spread;
    float f14 = f12+f13*spread;
    float f15 = f13+f14*spread;
    float f16 = f14+f15*spread;

    waveform1.frequency(f1);
    waveform2.frequency(f2);
    waveform3.frequency(f3);
    waveform4.frequency(f4);
    waveform5.frequency(f5);
    waveform6.frequency(f6);
    waveform7.frequency(f7);
    waveform8.frequency(f8);
    waveform9.frequency(f9);
    waveform10.frequency(f10);
    waveform11.frequency(f11);
    waveform12.frequency(f12);
    waveform13.frequency(f13);
    waveform14.frequency(f14);
    waveform15.frequency(f15);
    waveform16.frequency(f16);
  }

  AudioStream& getStream() override { return mixer5; }
  unsigned char getPort() override { return 0; }

private:

  AudioSynthNoiseWhite     noise1;         //xy=296.75,791.75
  AudioSynthWaveformModulated waveform16; //xy=581.75,1167.5
  AudioSynthWaveformModulated waveform14; //xy=583.75,1062.5
  AudioSynthWaveformModulated waveform15; //xy=583.75,1107.5
  AudioSynthWaveformModulated waveform13; //xy=584.75,1020
  AudioSynthWaveformModulated waveform8; //xy=591.75,747.5
  AudioSynthWaveformModulated waveform6; //xy=593.75,642.5
  AudioSynthWaveformModulated waveform7; //xy=593.75,687.5
  AudioSynthWaveformModulated waveform12; //xy=592.75,958.5
  AudioSynthWaveformModulated waveform5; //xy=594.75,600
  AudioSynthWaveformModulated waveform10; //xy=594.75,853.5
  AudioSynthWaveformModulated waveform11; //xy=594.75,898.5
  AudioSynthWaveformModulated waveform9; //xy=595.75,811
  AudioSynthWaveformModulated waveform4; //xy=599.75,532.25
  AudioSynthWaveformModulated waveform2; //xy=601.75,427.25
  AudioSynthWaveformModulated waveform3; //xy=601.75,472.25
  AudioSynthWaveformModulated waveform1;   //xy=602.75,384.75
  AudioMixer4              mixer4; //xy=801.75,1111.25
  AudioMixer4              mixer3; //xy=812.75,902.25
  AudioMixer4              mixer2; //xy=818.75,691.25
  AudioMixer4              mixer1;         //xy=819.75,476
  AudioMixer4              mixer5;         //xy=1066.75,688
  AudioConnection          patchCord1;
  AudioConnection          patchCord2;
  AudioConnection          patchCord3;
  AudioConnection          patchCord4;
  AudioConnection          patchCord5;
  AudioConnection          patchCord6;
  AudioConnection          patchCord7;
  AudioConnection          patchCord8;
  AudioConnection          patchCord9;
  AudioConnection          patchCord10;
  AudioConnection          patchCord11;
  AudioConnection          patchCord12;
  AudioConnection          patchCord13;
  AudioConnection          patchCord14;
  AudioConnection          patchCord15;
  AudioConnection          patchCord16;
  AudioConnection          patchCord17;
  AudioConnection          patchCord18;
  AudioConnection          patchCord19;
  AudioConnection          patchCord20;
  AudioConnection          patchCord21;
  AudioConnection          patchCord22;
  AudioConnection          patchCord23;
  AudioConnection          patchCord24;
  AudioConnection          patchCord25;
  AudioConnection          patchCord26;
  AudioConnection          patchCord27;
  AudioConnection          patchCord28;
  AudioConnection          patchCord29;
  AudioConnection          patchCord30;
  AudioConnection          patchCord31;
  AudioConnection          patchCord32;
  AudioConnection          patchCord33;
  AudioConnection          patchCord34;
  AudioConnection          patchCord35;
  AudioConnection          patchCord36;

};

REGISTER_PLUGIN(FibonacciCluster);
