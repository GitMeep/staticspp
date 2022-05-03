#include "beam.h"
#include "joint.h"

namespace spp {

Beam::Beam(Joint* start, Joint* end) : _start(start), _end(end) {}

Vec2 Beam::posAlong(double t) {
  return _start->getPos() + (_end->getPos() - _start->getPos()).scale(t);
}

Vec2 Beam::posAtDist(double d) {
  return _start->getPos() + (_end->getPos() - _start->getPos()).normalize().scale(d);
}

}