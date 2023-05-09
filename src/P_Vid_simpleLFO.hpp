// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"

class VidSimpleLFO : public Plugin {

public:

  VidSimpleLFO() {}

  ~VidSimpleLFO() override {}

  VidSimpleLFO(const VidSimpleLFO&) = delete;
  VidSimpleLFO& operator=(const VidSimpleLFO&) = delete;

  void init() override {
    waveForm=WAVEFORM_SINE;

    waveform1.begin(waveForm);
    waveform1.amplitude(0.9);
  }

  void process(float k1, float k2) override {
    //float knob_1 = k1;
    //float knob_2 = k2;
    //float pitch1 = pow(knob_1, 2);
    //bool inA = g_process_mode == PROCESS_MODE_A;

    waveform1.frequency(47+(k1*200)); //49+

    if (k2 <= 0.25) {
      waveForm = WAVEFORM_SINE;
    }
    else if (k2 > 0.25 && k2 <= 0.5){
      waveForm = WAVEFORM_SQUARE;
    }
    else if (k2 > 0.5 && k2 <= 0.75){
      waveForm = WAVEFORM_TRIANGLE;
    }
    else {
      waveForm = WAVEFORM_SAWTOOTH;
    }
    waveform1.begin(waveForm);
  }

  AudioStream& getStream() override { return waveform1; }
  unsigned char getPort() override { return 0; }

private:

  AudioSynthWaveform       waveform1;
  int                      waveForm;

};

REGISTER_PLUGIN(VidSimpleLFO);
