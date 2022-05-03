#pragma once

#include <utility>

#include "structure.h"
#include "../vector.h"

namespace spp {

class Joint: public StructureEntity {
public:
  void moveTo(double x, double y);
  void moveTo(Vec2 pos);
  void moveTo(const Joint& otherPoint);

  Vec2& getPos();

protected:
  Joint();
  Joint(double x, double y);
  Joint(const Vec2& pos);
  Joint(const Joint& copySource);

  Vec2 _pos;

};

}