#include "Track.hpp"

Track:: Track() {

}

// Track:: Track(std::vector<up_Plugin> plugins) : mPlugins(plugins) {}

void Track:: calculateBuffer() {
  if (mPlugins.size()==0) {
    return;
  }
  zero(mBuffer, AUDIO_BLOCK_SIZE);

  // for (auto const& p : mPlugins) {
  //   p->out(mBuffer);
  // }
} 

float Track:: operator()() {
  if (inRange()) {
    return mBuffer[mPos];
  }
  advance();
  return 0;
}

bool Track:: inRange() {
  return mPos < AUDIO_BLOCK_SIZE;
}

bool Track:: advance() {
  if (++mPos < AUDIO_BLOCK_SIZE) {
    return true; 
  } else {
    return false;
  }
}
