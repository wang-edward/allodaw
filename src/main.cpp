#include <iostream>

// for master branch
// #include "al/core.hpp"

// for devel branch
#include <iostream>

#include "al/app/al_App.hpp"
#include "al/graphics/al_Shapes.hpp"

#include "IO.hpp"
#include "Mixer.hpp"
#include "test.hpp"

struct MyApp : al::App {

  Mixer mMixer; 
  test tester;

  void onCreate() override {
    Track t;
   
    auto ptr_tester = std::make_unique<test>();
    // t.mPlugins.emplace_back(std::make_unique<test>());
    // t.mPlugins.emplace_back(std::move(ptr_tester));

    // works before this

    mMixer.mTracks.emplace_back(t);
    
    // auto bro = std::make_unique<test>(2);
    // auto guy = std::make_unique<test>(1);
    // std::vector<std::unique_ptr<test> > mVec;
    // mVec.emplace_back(std::move(bro)); // explicit move
    // mVec.emplace_back(std::move(guy)); // explicit move
    // for (auto &x : mVec) {
    //   std::cout<<x->num<<std::endl;
    // }

    // std::cout<<bro->num<<std::endl; // should segfault 

    // mVec.emplace_back(bro); // implicit move doesnt work
  }

  void onAnimate(double dt) override {
  }

  void onDraw(al::Graphics &g) override {
  }

  void onSound(al::AudioIOData &io) override {
    // mMixer.onProcess(io);
  }
};

int main() {
  MyApp app;
  app.dimensions(600, 400);
  app.configureAudio(AUDIO_RATE, AUDIO_BLOCK_SIZE, AUDIO_OUTPUTS, AUDIO_INPUTS);
  app.start();
}
