#ifndef CLAMP_H
#define CLAMP_H

namespace {
inline float Clamp(float var, float min, float max) {
  if (var >= max) {
    return var = max;
  } else if (var <= min) {
    return var = min;
  } else {
    return var;
  }
}
} // namespace

#endif // CLAMP _H
