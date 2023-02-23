#pragma once

#include <vector>

#include "al/io/al_AudioIOData.hpp"

#include "Track.hpp"

class Mixer {
 public:
  std::vector<Track> mTracks;
};
