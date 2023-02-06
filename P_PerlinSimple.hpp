// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"
#include "perlin.h"

class PerlinSimple : public Plugin {

public:
  PerlinSimple(){}

  ~PerlinSimple() override {}

  PerlinSimple(const PerlinSimple&) = delete;
  PerlinSimple& operator=(const PerlinSimple&) = delete;

  void init() override {
    waveform.begin(1, 50, WAVEFORM_ARBITRARY);
  }

  void process(float k1, float k2) override {

    count += 1 * k2;
    count = fmod(count,32000);
    //fcount = count * k2;

    for (int i = 0; i < 256; i++)
    {
      PerlinLut[i] = perlin2d(i, count, k1 * 500, 2) * 32000;
    }

    waveform.arbitraryWaveform(PerlinLut, 17200.0);
    //waveform1.begin(1, k2 * 15600, WAVEFORM_ARBITRARY);
    waveform.frequency(k2 * 15600);
  }

  AudioStream &getStream() override { return waveform; }
  unsigned char getPort() override { return 0; }

private:

  // GUItool: begin automatically generated code
  AudioSynthWaveform waveform;             // xy=305.3333282470703,648.3333358764648

  static const int textureSize = 256;
  int16_t PerlinLut[256]; //lut size is given by the audio library
  float count = 0;
  //float fcount = 0;
};

REGISTER_PLUGIN(PerlinSimple);
