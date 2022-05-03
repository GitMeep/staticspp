#pragma once

#include <utility>
#include <ostream>
namespace spp {

class Vec2 {
public:
  double x, y;

  // constructors
  Vec2();
  Vec2(double x, double y);
  Vec2(std::initializer_list<double> values);

  // operators
  Vec2 operator+(const Vec2& other);
  
  Vec2 operator-(const Vec2& other);

  Vec2& operator+=(const Vec2& other);
  Vec2& add(const Vec2& other);

  Vec2& operator-=(const Vec2& other);
  Vec2& subtract(const Vec2& other);

  template <typename T>
  Vec2 operator*(const T& scalar) {
    static_assert(std::is_scalar_v<T>, "You can only multiply a vector with a scalar");

    return Vec2(x * scalar, y * scalar);
  }

  template <typename T>
  Vec2 operator/(const T& scalar) {
    static_assert(std::is_scalar_v<T>, "You can only divide a vector with a scalar");

    return Vec2(x / scalar, y / scalar);
  }

  template <typename T>
  Vec2& scale(const T& scalar) {
    static_assert(std::is_scalar_v<T>, "You can only scale a vector with a scalar");

    x *= scalar;
    y *= scalar;

    return *this;
  }

  template <typename T>
  Vec2& operator*=(const T& scalar) {
    return scale(scalar);
  }

  template <typename T>
  Vec2& shrink(const T& scalar) {
    static_assert(std::is_scalar_v<T>, "You can only shrink a vector with a scalar");

    x /= scalar;
    y /= scalar;

    return *this;
  }

  template <typename T>
  Vec2& operator/=(const T& scalar) {
    return shrink(scalar);
  }

  bool operator==(const Vec2& other) {
    return x == other.x && y == other.y;
  }

  // Dot product with another vector
  double dot(const Vec2& other);

  double det(const Vec2& other);

  // Normalize vector. Keep's direction but makes size 1.
  Vec2& normalize();

  // Vector magnitude. Use magSq() if exact size isn't important.
  double mag();

  // Vector magnitude squared. Faster than mag(), use if precise size is not important, only comparisons.
  double magSq();

  friend std::ostream& operator<<(std::ostream& os, const Vec2& vec);

};

}