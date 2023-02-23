#include "Plugin.hpp"

class test : public Plugin {
public:
  test(int n = 0); 
  test(const test &t);
  test (test &&t); 
  

  virtual std::unique_ptr<Plugin> clone() override; 
  

  ~test() override; 

  void out(std::array<float, AUDIO_BLOCK_SIZE> v[]) override; 

  int num;
};


