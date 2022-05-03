#include "joint.h"

namespace spp {

void Joint::moveTo(double x, double y) {
  _pos.x = x;
  _pos.y = y;
}

void Joint::moveTo(Vec2 pos) {
  _pos = pos;
}

void Joint::moveTo(const Joint& otherPoint) {
  _pos = otherPoint._pos;
}

Vec2& Joint::getPos() {
  return _pos;
}

Joint::Joint() {}
Joint::Joint(double x, double y) : _pos(x, y) {}
Joint::Joint(const Vec2& pos) : _pos(pos) {}
Joint::Joint(const Joint& copySource) : _pos(copySource._pos) {}

}