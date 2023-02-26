#pragma once

#include <iostream>
#include <vector>

#include "al/io/al_AudioIOData.hpp"

#include "Track.hpp"

class Mixer {
 public:
  Mixer() = default;
  Mixer(const Mixer &m) : mTracks{m.mTracks} {}
  Mixer (Mixer &&m) {
    mTracks = m.mTracks;
    m.mTracks.clear(); // unnecessary?
  }
  ~Mixer() {
    std::cout<<"Mixer destroyed"<<std::endl;
  }
  std::vector<Track> mTracks;
};
