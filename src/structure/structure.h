#pragma once

#include "../vector.h"
#include <string>
#include <utility>
#include <forward_list>

namespace spp {

class StructureEntity {
public:
  /*
  enum EntityType {
    JOINT,
    BEAM,
    FORCE,
    SUPPORT
  };
  */

  uint32_t getId();
  //EntityType getType();

protected:
  //EntityType _type;
  uint32_t _id;
};

class Joint;
class Beam;

class Structure {
public:
  Structure();
  Structure(std::string filename);

  void addJoint(double x, double y);
  void addJoint(Vec2 pos);
  void addBeam();
  void addForce();
  void addSupport();

protected:
  std::forward_list<Joint*> _joints;
  std::forward_list<Beam*> _beams;
  //std::forward_list<Force*> _forces;
  //std::forward_list<Support*> _support;

};

}