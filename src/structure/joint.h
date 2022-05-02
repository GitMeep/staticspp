#pragma once

#include <utility>

#include "../vector.h"

namespace spp {

class Joint {
public:
  uint32_t& getId();

  void moveTo(double x, double y);
  void moveTo(Vec2 pos);
  void moveTo(const Joint& otherPoint);

  const Vec2& getPos();

protected:
  Joint();
  Joint(double x, double y);
  Joint(const Vec2& pos);
  Joint(const Joint& copySource);

  Vec2 _pos;
  uint32_t _id; // unique id among all joints in a structure

};

}