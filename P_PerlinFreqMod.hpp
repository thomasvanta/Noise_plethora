// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"
#include "perlin.h"

class PerlinFreqMod : public Plugin
{

public:
  PerlinFreqMod()
      : patchCord1(waveform1, 0, waveformMod1, 0)
  {}

  ~PerlinFreqMod() override {}

  PerlinFreqMod(const PerlinFreqMod &) = delete;
  PerlinFreqMod &operator=(const PerlinFreqMod &) = delete;

  void init() override {

    for (int i = 0; i < 256; i++)
    {
      PerlinLut[i] = perlin1d(i, 51, 4) * 32000;
    }

    waveformMod1.arbitraryWaveform(PerlinLut, 17200.0);
    waveformMod1.begin(1, 100, WAVEFORM_ARBITRARY);
    //waveformMod1.phaseModulation(180);
    waveform1.begin(1, 50, WAVEFORM_SAWTOOTH);
  }

  void process(float k1, float k2) override {

    waveform1.frequency(50 + k2 * 400);

    waveformMod1.arbitraryWaveform(PerlinLut, 17200.0);
    //waveform1.begin(1, k1 * 15600, WAVEFORM_ARBITRARY);
    waveformMod1.frequency(k1 * 15600);
  }

  AudioStream &getStream() override { return waveformMod1; }
  unsigned char getPort() override { return 0; }

private:

  // GUItool: begin automatically generated code
  AudioSynthWaveform waveform1;             // xy=305.3333282470703,648.3333358764648
  AudioSynthWaveformModulated waveformMod1; // xy=475.88893127441406,517.2221565246582
  AudioConnection patchCord1;

  static const int textureSize = 256;
  int16_t PerlinLut[256]; //lut size is given by the audio library

};

REGISTER_PLUGIN(PerlinFreqMod);
