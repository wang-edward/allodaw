#pragma once

#include <vector>

#include "al/io/al_AudioIOData.hpp"

#include "Track.hpp"

class Mixer {
 public:
  Mixer();
  Mixer(std::vector<Track> tracks);
  void onProcess(al::AudioIOData& io);
  std::vector<Track> mTracks;
};
