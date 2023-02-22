#include <iostream>

// for master branch
// #include "al/core.hpp"

// for devel branch
#include <iostream>

#include "al/app/al_App.hpp"
#include "al/graphics/al_Shapes.hpp"

#include "IO.hpp"
#include "Mixer.hpp"

struct MyApp : al::App {

  Mixer mMixer; 

  void onCreate() override {
  }

  void onAnimate(double dt) override {
  }

  void onDraw(al::Graphics& g) override {
  }

  void onSound(al::AudioIOData& io) override {
    mMixer.onProcess(io);
  }
};

int main() {
  MyApp app;
  app.dimensions(600, 400);
  app.configureAudio(AUDIO_RATE, AUDIO_BLOCK_SIZE, AUDIO_OUTPUTS, AUDIO_INPUTS);
  app.start();
}
