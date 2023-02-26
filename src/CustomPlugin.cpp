#include "CustomPlugin.hpp"

CustomPlugin:: CustomPlugin(int n) {
  num = n;
}
CustomPlugin:: CustomPlugin(const CustomPlugin &p) {
  num = p.num;
}
CustomPlugin:: CustomPlugin (CustomPlugin &&p) {
  num = p.num;
}

std::unique_ptr<Plugin> CustomPlugin:: clone() {
  return std::make_unique<CustomPlugin>(*this);
}
  
CustomPlugin:: ~CustomPlugin() {
  std::cout<<"inherited class destroyed!"<<std::endl;
}

void CustomPlugin:: out(std::array<float, AUDIO_BLOCK_SIZE> v[]) {
  for (int i=0;i<v->size();i++) {
    std::cout<<(*v)[i]<<std::endl;
  }
}

