#include <iostream>

// for master branch
// #include "al/core.hpp"

// for devel branch
#include <iostream>

#include "al/app/al_App.hpp"
#include "al/graphics/al_Shapes.hpp"

#include "IO.hpp"
#include "Mixer.hpp"


class CustomPlugin : public Plugin {
public:
  CustomPlugin(int n = 0) {
    num = n;
  }
  CustomPlugin(const CustomPlugin &p) {
    num = p.num;
  }
  CustomPlugin (CustomPlugin &&p) {
    num = p.num;
  }

  ~CustomPlugin() {
    std::cout<<"inherit destroyed!"<<std::endl;
  }

  void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) override {
    std::cout<<"Custom Plugin"<<std::endl;
  }

  int num;
};

class Custom2 : public Plugin {
 public:
  Custom2(int n=2) {
     num = n;
  }
  Custom2(const Custom2 &p) {
     num = p.num;
  }
  Custom2(Custom2 &&p) {
     num = p.num;
  }
  ~Custom2() {
    std::cout<<"custom2 destroyed"<<std::endl;
  }
  void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) override {
    std::cout<<"Custom 2"<<std::endl;
  }

   int num;
};

struct MyApp : al::App {

  Mixer mMixer; 
  CustomPlugin t;

  void onCreate() override {
    Track t;
    // t.mPlugins.emplace_back(std::make_unique<up_Plugin>());
    // mMixer.mTracks.emplace_back(t);
    auto bro = std::make_unique<CustomPlugin>(2);
    auto guy = std::make_unique<Custom2>(1);
    std::vector<std::unique_ptr<Plugin> > mVec;
    mVec.emplace_back(std::move(bro)); // explicit move
    mVec.emplace_back(std::move(guy)); // explicit move
                                       //
    std::array<float,AUDIO_BLOCK_SIZE> dummy;
    for (auto &x : mVec) {
      x->out(&dummy);
    }

    // std::cout<<bro->num<<std::endl; // should segfault 

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
