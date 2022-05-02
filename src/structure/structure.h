#pragma once

#include <string>
#include <utility>
#include <forward_list>

#include "joint.h"
#include "beam.h"

namespace spp {

class Structure {
public:
  Structure();
  Structure(std::string filename);

protected:
  std::forward_list<Joint*> _points;
  std::forward_list<Beam*> _beams;

};

}