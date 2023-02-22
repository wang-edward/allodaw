#include "Mixer.hpp"

Mixer:: Mixer() {

}

Mixer:: Mixer(std::vector<Track> tracks) : mTracks(tracks) {}

void Mixer:: onProcess(al::AudioIOData& io) {
  for (auto t : mTracks) {
    t.calculateBuffer();
  }
  while (io()) {
    for (auto t : mTracks) {
      io.out(0) += t();
    }
    io.out(1) = io.out(0); // cheat calculations with mono
  }
}

