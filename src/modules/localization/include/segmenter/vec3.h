#ifndef VEC3_H
#define VEC3_H
#include <math.h>

class Vec3 {
  public:
    float x;
    float y;
    float z;
    float intensity;
    float theta;
    int label;
    int scanline;

    Vec3() : x(0), y(0), z(0), intensity(0), label(-1), scanline(0) {};

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {
      label = -1;
      theta = 0;
    }

    float distance(Vec3 v1) const {
      float x_new = this->x - v1.x;
      float y_new = this->y - v1.y;
      float z_new = this->z - v1.z;
      return sqrt(x_new * x_new + y_new * y_new + z_new * z_new);
    }

    float distance_squared(const float * v1) const {
      float x_new = this->x - v1[0];
      float y_new = this->y - v1[1];
      float z_new = this->z - v1[2];
      return x_new * x_new + y_new * y_new + z_new * z_new;
    }
};

#endif

