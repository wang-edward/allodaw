#include "Track.hpp"

Track:: Track(const Track& t) : mSource(t.mSource->clone()) {
  for (const up_Plugin &p : t.mPlugins) {
    mPlugins.emplace_back(std::move(p));
  }
}
