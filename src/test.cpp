#include "test.hpp"

test:: test(int n) {
  num = n;
}
test:: test(const test &t) {
  num = t.num;
}
test:: test (test &&t) {
  num = t.num;
}

std::unique_ptr<Plugin> test:: clone() {
  return std::make_unique<test>(*this);
}
  
test:: ~test() {
  std::cout<<"inherit destroyed!"<<std::endl;
}

void test:: out(std::array<float, AUDIO_BLOCK_SIZE> v[]) {
  for (int i=0;i<v->size();i++) {
    std::cout<<(*v)[i]<<std::endl;
  }
}

