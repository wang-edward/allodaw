#pragma once
#include <iostream>
#include <array>
#include <memory>

#include "IO.hpp"


class Plugin {
  public:
  Plugin() = default;
  Plugin(const Plugin& p) = default;
  virtual void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) = 0;
  virtual ~Plugin(); 

  virtual std::unique_ptr<Plugin> clone() = 0;

  // virtual std::unique_ptr<Plugin> clone() {
  //   return std::make_unique<Plugin>(*this);
  // }


};

typedef std::unique_ptr<Plugin> up_Plugin; 
