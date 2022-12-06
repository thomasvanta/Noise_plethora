// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"
#include "perlin.h"

class Perlin : public Plugin {

public:
  Perlin()
      : patchCord1(waveform1, 0, waveformMod1, 0)
  {}

  ~Perlin() override {}

  Perlin(const TestPlugin&) = delete;
  Perlin& operator=(const Perlin&) = delete;

  void init() override {

    GenerateTexture(100);
    SampleTextureIntoLut();
    waveformMod1.arbitraryWaveform(PerlinLut, 172.0);

    waveformMod1.begin(1, 50, WAVEFORM_ARBITRARY);
    waveFormMod1.phaseModulation(180);
    waveform1.begin(1, 15625, WAVEFORM_SAWTOOTH);
  }

  void process(float k1, float k2) override {

    //float pitch1 = pow(k_1, 2);
    //waveform1.frequency(20+(pitch1*1000));
    //waveform1.begin(waveForm);

    SampleTextureIntoLut((int)(k1 * 0.5), (int)(k2 * 0.5));
    waveformMod1.arbitraryWaveform(PerlinLut, 172.0);
  }

  AudioStream& getStream() override { return waveform1; }
  unsigned char getPort() override { return 0; }

private:

  int waveForm;

  // GUItool: begin automatically generated code
  AudioSynthWaveform waveform1;             // xy=305.3333282470703,648.3333358764648
  AudioSynthWaveformModulated waveformMod1; // xy=475.88893127441406,517.2221565246582
  AudioConnection patchCord1;

  int16_t PerlinLut[256];
  int16_t PerlinTexture[512][512];

  void GenerateTexture(float freq, int depth = 4 ){
    for (int x = 0; x < 512; x++)
    {
      for (int y = 0; y < 512; y++)
      {
        PerlinTexture[x][y] = perlin2d(x, y, freq, depth);
      }
    }
  }

  void SampleTextureIntoLut(int x = 0, int y = 0){
    for (int i = 0; i < 256; i++)
    {
      PerlinLut[i] = PerlinTexture[x % 512][y % 512];
    }
  }

};

REGISTER_PLUGIN(Perlin);
