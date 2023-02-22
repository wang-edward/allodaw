#pragma once

class Plugin {
  public:
  virtual float out(float v[]) = 0;
  virtual ~Plugin() {}

};
