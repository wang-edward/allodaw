#include <iostream>

// for master branch
// #include "al/core.hpp"

// for devel branch
#include <iostream>

#include "al/app/al_App.hpp"
#include "al/graphics/al_Shapes.hpp"

#include "IO.hpp"
#include "Mixer.hpp"


class test : public Plugin {
public:
  test(int n = 0) {
    num = n;
  }
  test(const test &t) {
    num = t.num;
  }
  test (test &&t) {
    num = t.num;
  }

  ~test() {
    std::cout<<"inherit destroyed!"<<std::endl;
  }

  void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) override {
    for (int i=0;i<v->size();i++) {
      std::cout<<(*v)[i]<<std::endl;
    }
  }

  int num;
};

struct MyApp : al::App {

  Mixer mMixer; 
  test t;

  void onCreate() override {
    // Track t;
    // t.mPlugins.emplace_back(std::make_unique<up_Plugin>());
    // mMixer.mTracks.emplace_back(t);
    auto bro = std::make_unique<test>(2);
    auto guy = std::make_unique<test>(1);
    std::vector<std::unique_ptr<test> > mVec;
    mVec.emplace_back(std::move(bro)); // explicit move
    mVec.emplace_back(std::move(guy)); // explicit move
    for (auto &x : mVec) {
      std::cout<<x->num<<std::endl;
    }

    std::cout<<bro->num<<std::endl; // should segfault 

    // mVec.emplace_back(bro); // implicit move
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
