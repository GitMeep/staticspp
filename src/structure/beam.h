#pragma once

#include "../vector.h"
#include "structure.h"

namespace spp {

class Beam: public StructureEntity {
public:
  Beam(Joint* start, Joint* end);

  // get position at fraction t along the beam
  Vec2 posAlong(double t);

  // get position at distance t along the beam
  Vec2 posAtDist(double d);

protected:
  Joint *_start, *_end;

};

}