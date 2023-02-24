#pragma once

#include <vector>

#include "al/io/al_AudioIOData.hpp"

#include "IO.hpp"
#include "Plugin.hpp"


class Track {
 public:
  Track() = default;
  Track(const Track& t); 
  void calculateBuffer();
  float operator()(); 

  up_Plugin mSource;
  std::vector< up_Plugin > mPlugins;
};

/// Utility function to efficiently clear buffer (set all to 0)
template <class T>
static void zero(T* buf, unsigned int n) {
  memset(buf, 0, n * sizeof(T));
}
