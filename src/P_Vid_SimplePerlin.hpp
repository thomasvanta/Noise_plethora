// Noise Plethora Plugins
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under GPL-3.0-or-later

#pragma once

#include "Plugin.hpp"
#include "NoisePlethora.hpp"
#include "perlin.h"

class VidSimplePerlin : public Plugin {

public:
  VidSimplePerlin(){}

  ~VidSimplePerlin() override {}

  VidSimplePerlin(const VidSimplePerlin&) = delete;
  VidSimplePerlin& operator=(const VidSimplePerlin&) = delete;

  void init() override {
    waveform.arbitraryWaveform(PerlinLut, 172.0);
    //waveform.amplitude(1.2);
    waveform.begin(1.2, 50, WAVEFORM_ARBITRARY);
  }

  void process(float k1, float k2) override {
    if (k2 < 0.3){
      speed = 0;
    } else if (k2 >= 0.25 && k2 < 0.5) {
      speed = 0.2;
    } else if (k2 >= 0.5 && k2 < 0.75) {
      speed = 0.5;
    } else {
      speed = 0;
    }

    count += speed; //1 * (k2 * 0.1);
    count = fmod(count, 256);
    //fcount = count * k2;

    for (int i = 0; i < 256; i++)
    {
      PerlinLut[i] = perlin2d(i, count, 0.1 + k1 * 0.5, 1 + k1 * 3) * 40000; //32000
    }

    //waveform.arbitraryWaveform(PerlinLut, 172.0);
    //waveform1.begin(1, k2 * 15600, WAVEFORM_ARBITRARY);
    waveform.frequency(k2 * 50);
  }

  AudioStream &getStream() override { return waveform; }
  unsigned char getPort() override { return 0; }

private:

  // GUItool: begin automatically generated code
  AudioSynthWaveform waveform;             // xy=305.3333282470703,648.3333358764648

  static const int textureSize = 256;
  int16_t PerlinLut[256]; //lut size is given by the audio library
  float count = 0;
  float speed = 0;
  // float fcount = 0;
};

REGISTER_PLUGIN(VidSimplePerlin);
