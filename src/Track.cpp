#include "Track.hpp"

// call to implicitly deleted constructor of unique_ptr<Plugin>

// Track:: Track(const Track& t) : mPlugins{t.mPlugins}{
//   for (auto p : t.mPlugins) {
//     mPlugins.emplace_back(p);
//   }
// }
