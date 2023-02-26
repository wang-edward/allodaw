#pragma once
#include <iostream>
#include <array>

#include "IO.hpp"

class Plugin {
  public:
  virtual void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) = 0;
  virtual ~Plugin() {
    std::cout<<"destroyed"<<std::endl;
  }


};
