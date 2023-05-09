// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"
#include "perlin.h"

class VidPerlinFreqMod : public Plugin
{

public:
  VidPerlinFreqMod()
      : patchCord1(waveform2, 0, multiply1, 1),
      patchCord2(waveform1, 0, multiply1, 0)
  {}

  ~VidPerlinFreqMod() override {}

  VidPerlinFreqMod(const VidPerlinFreqMod &) = delete;
  VidPerlinFreqMod &operator=(const VidPerlinFreqMod &) = delete;

  void init() override {

    for (int i = 0; i < 256; i++)
    {
      PerlinLut[i] = perlin1d(i, 51, 4) * 32000;
    }

    waveform2.arbitraryWaveform(PerlinLut, 17200.0);
    waveform2.begin(1, 100, WAVEFORM_ARBITRARY);
    //waveformMod1.phaseModulation(180);
    waveform1.begin(1, 50, WAVEFORM_SAWTOOTH);
  }

  void process(float k1, float k2) override {

    waveform1.frequency(50 + k2 * 400);

    waveform2.arbitraryWaveform(PerlinLut, 17200.0);
    //waveform1.begin(1, k1 * 15600, WAVEFORM_ARBITRARY);
    waveform2.frequency(k1 * 15600);
  }

  AudioStream &getStream() override { return multiply1; }
  unsigned char getPort() override { return 0; }

private:

  // GUItool: begin automatically generated code
  AudioSynthWaveform waveform2;  // xy=461,487
  AudioSynthWaveform waveform1;  // xy=462,413
  AudioEffectMultiply multiply1; // xy=684,445

  AudioConnection patchCord1;
  AudioConnection patchCord2;

  static const int textureSize = 256;
  int16_t PerlinLut[256]; //lut size is given by the audio library

};

REGISTER_PLUGIN(VidPerlinFreqMod);
