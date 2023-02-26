#include <iostream>

// for master branch
// #include "al/core.hpp"

// for devel branch
#include <iostream>

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

int main() {

  Mixer mMixer; 

  Track t;
  // t.mPlugins.emplace_back(std::make_unique<up_Plugin>()); // doesnt work
  // mMixer.mTracks.emplace_back(t); // cant define copy constructor of Track 
  auto bro = std::make_unique<CustomPlugin>(2);
  auto guy = std::make_unique<Custom2>(1);
  std::vector<std::unique_ptr<Plugin> > mVec;
  mVec.emplace_back(std::move(bro)); // explicit move
  mVec.emplace_back(std::move(guy)); // explicit move

  std::array<float,AUDIO_BLOCK_SIZE> dummy;
  for (auto &x : mVec) {
    x->out(&dummy);
  }

  // std::cout<<bro->num<<std::endl; // should segfault 

  // mVec.emplace_back(bro); // implicit move


}
