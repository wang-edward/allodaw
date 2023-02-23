#pragma once

#include <vector>

#include "al/io/al_AudioIOData.hpp"

#include "IO.hpp"
#include "Plugin.hpp"

typedef std::unique_ptr<Plugin> up_Plugin; 

class Track {
 public:
  Track();
  Track(const Track& t);
  // Track(std::vector<up_Plugin> plugins);
  void calculateBuffer();
  float operator()(); 
 // private:
  // bool inRange();
  // bool advance();
  up_Plugin mSource;
  // int mPos;
  std::vector< up_Plugin > mPlugins;
  // float mBuffer[AUDIO_BLOCK_SIZE] = { 0 };  
};

/// Utility function to efficiently clear buffer (set all to 0)
template <class T>
static void zero(T* buf, unsigned int n) {
  memset(buf, 0, n * sizeof(T));
}
