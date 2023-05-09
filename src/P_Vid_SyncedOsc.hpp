// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"

class VidSyncedOsc : public Plugin {

public:

  VidSyncedOsc() {}

  ~VidSyncedOsc() override {}

  VidSyncedOsc(const VidSyncedOsc&) = delete;
  VidSyncedOsc& operator=(const VidSyncedOsc&) = delete;

  void init() override {

    waveForm=WAVEFORM_SINE;
    waveform1.begin(0.75, 50, waveForm);
    //waveform1.amplitude(1);
    //waveform1.frequency(25);
  }

  void process(float k1, float k2) override {
    //float knob_1 = k1;
    //float knob_2 = k2;
    //float pitch1 = pow(knob_1, 2);
    //bool inA = g_process_mode == PROCESS_MODE_A;

    waveform1.frequency(floor(k1*18) * 50); //49+
    

    if (k2 <= 0.25) {
      waveForm = WAVEFORM_SINE;
    }
    else if (k2 > 0.25 && k2 <= 0.5){
      waveForm = WAVEFORM_TRIANGLE;
    }
    else if (k2 > 0.5 && k2 <= 0.75){
      waveForm = WAVEFORM_SAWTOOTH_REVERSE;
    }
    else {
      waveForm = WAVEFORM_SAWTOOTH;
    }
    waveform1.begin(waveForm);

    //waveform1.phase( fract(k1 * 20));
  }

  AudioStream& getStream() override { return waveform1; }
  unsigned char getPort() override { return 0; }

private:

  AudioSynthWaveform       waveform1;
  int                      waveForm;

};

REGISTER_PLUGIN(VidSyncedOsc);
