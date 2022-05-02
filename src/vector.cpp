#include "vector.h"

#include <type_traits>
#include <math.h>

namespace spp {

  Vec2::Vec2() : x(0), y(0) {}

  Vec2::Vec2(double x, double y) : x(x), y(y) {}

  Vec2::Vec2(std::initializer_list<double> values) {
    auto it = values.begin();
    x = *it;
    y = *(++it);
  }

  Vec2 Vec2::operator+(const Vec2& other)  {
    return Vec2(x + other.x, y + other.y);
  }

  Vec2 Vec2::operator-(const Vec2& other) {
    return Vec2(x - other.x, y - other.y);
  }

  Vec2& Vec2::operator+=(const Vec2& other) {
    return add(other);
  }

  Vec2& Vec2::add(const Vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  Vec2& Vec2::operator-=(const Vec2& other) {
    return subtract(other);
  }

  Vec2& Vec2::subtract(const Vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  double Vec2::magSq() {
    return pow(x, 2) + pow(y, 2);
  }

  double Vec2::mag() {
    return sqrt(magSq());
  }

  double Vec2::dot(const Vec2& other) {
    return x * other.x + y * other.y;
  }

  double Vec2::det(const Vec2& other) {
    return x * other.y - other.x * y;
  }

  Vec2& Vec2::normalize() {
    double magnitude = mag();
    x /= magnitude;
    y /= magnitude;

    return *this;
  }

  std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
    os << "[" << vec.x << ", " << vec.y << ']';
    return os;
  }

}