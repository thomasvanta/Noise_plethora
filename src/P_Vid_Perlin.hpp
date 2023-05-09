// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"
#include "perlin.h"

class VidPerlin : public Plugin {

public:
  VidPerlin()
      : patchCord1(waveform1, 0, waveformMod1, 0)
  {}

  ~VidPerlin() override {}

  VidPerlin(const VidPerlin&) = delete;
  VidPerlin& operator=(const VidPerlin&) = delete;

  void init() override {

    GenerateTexture(0.1);
    SampleTextureIntoLut();

    waveformMod1.arbitraryWaveform(PerlinLut, 172.0);
    waveformMod1.begin(1, 50, WAVEFORM_ARBITRARY);
    //waveformMod1.phaseModulation(180);
    waveform1.begin(1, 50, WAVEFORM_SINE);
  }

  void process(float k1, float k2) override {

    //float pitch1 = pow(k_1, 2);
    //waveform1.frequency(20+(pitch1*1000));
    //waveform1.begin(waveForm);

    SampleTextureIntoLut((int)k2 * textureSize, (int)k2 * textureSize);
    waveformMod1.arbitraryWaveform(PerlinLut, 172.0);
    //waveform1.begin(1, k1 * 15600, WAVEFORM_ARBITRARY);
    waveformMod1.frequency(25 + k1 * 75);
  }

  AudioStream &getStream() override { return waveformMod1; }
  unsigned char getPort() override { return 0; }

private:

  int waveForm;

  // GUItool: begin automatically generated code
  AudioSynthWaveform waveform1;             // xy=305.3333282470703,648.3333358764648
  AudioSynthWaveformModulated waveformMod1; // xy=475.88893127441406,517.2221565246582
  AudioConnection patchCord1;

  static const int textureSize = 256;
  int16_t PerlinLut[256]; //lut size is given by the audio library
  int16_t PerlinTexture[textureSize][textureSize];

  void GenerateTexture(float freq, int depth = 4 ){
    for (int x = 0; x < textureSize; x++)
    {
      for (int y = 0; y < textureSize; y++)
      {
        PerlinTexture[x][y] = perlin2d(x, y, freq, depth) * 32000;
      }
    }
  }

  void SampleTextureIntoLut(int x = 0, int y = 0){
    for (int i = 0; i < 256; i++)
    {
      PerlinLut[i] = PerlinTexture[(x+i) % textureSize][y % textureSize];
    }
  }

};

REGISTER_PLUGIN(VidPerlin);
