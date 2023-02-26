#include "Plugin.hpp"

class CustomPlugin : public Plugin {
public:
  CustomPlugin(int n = 0); 
  CustomPlugin(const CustomPlugin &p);
  CustomPlugin (CustomPlugin &&p); 
  

  virtual std::unique_ptr<Plugin> clone() override; 
  

  ~CustomPlugin() override; 

  void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) override; 

  int num; // for testing deep copy
};


