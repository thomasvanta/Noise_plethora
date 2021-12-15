
#pragma once

#include "Plugin.hpp"

class PrimeCnoise  : public Plugin {

  public:

    PrimeCnoise()
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

    ~PrimeCnoise() override {}

    // delete copy constructors
    PrimeCnoise(const PrimeCnoise&) = delete;
    PrimeCnoise& operator=(const PrimeCnoise&) =delete;

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

      int masterWaveform= WAVEFORM_TRIANGLE_VARIABLE;
      float masterVolume=100;

      waveform1.begin(masterVolume, 200, masterWaveform);
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

      float multfactor=pitch1*12+0.5;

      waveform1.frequency(53*multfactor);
      waveform2.frequency(127*multfactor);
      waveform3.frequency(199*multfactor);
      waveform4.frequency(283*multfactor);
      waveform5.frequency(383*multfactor);
      waveform6.frequency(467*multfactor);
      waveform7.frequency(577*multfactor);
      waveform8.frequency(661*multfactor);
      waveform9.frequency(769*multfactor);
      waveform10.frequency(877*multfactor);
      waveform11.frequency(983*multfactor);
      waveform12.frequency(1087*multfactor);
      waveform13.frequency(1193*multfactor);
      waveform14.frequency(1297*multfactor);
      waveform15.frequency(1429*multfactor);
      waveform16.frequency(1523*multfactor);

      noise1.amplitude(knob_2*0.2);
    }

    AudioStream& getStream() override { return mixer5; }
    unsigned char getPort() override { return 0; }

  private:

    AudioSynthNoiseWhite     noise1;
    AudioSynthWaveformModulated waveform16;
    AudioSynthWaveformModulated waveform14;
    AudioSynthWaveformModulated waveform15;
    AudioSynthWaveformModulated waveform13;
    AudioSynthWaveformModulated waveform8;
    AudioSynthWaveformModulated waveform6;
    AudioSynthWaveformModulated waveform7;
    AudioSynthWaveformModulated waveform12;
    AudioSynthWaveformModulated waveform5;
    AudioSynthWaveformModulated waveform10;
    AudioSynthWaveformModulated waveform11;
    AudioSynthWaveformModulated waveform9;
    AudioSynthWaveformModulated waveform4;
    AudioSynthWaveformModulated waveform2;
    AudioSynthWaveformModulated waveform3;
    AudioSynthWaveformModulated waveform1;
    AudioMixer4       mixer4;
    AudioMixer4       mixer3;
    AudioMixer4       mixer2;
    AudioMixer4       mixer1;
    AudioMixer4       mixer5;


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

REGISTER_PLUGIN(PrimeCnoise);
