#ifndef CLAMP_H
#define CLAMP_H

namespace Game {
inline float Clamp(float var, float min, float max) {
  if (var >= max) {
    return var = max;
  } else if (var <= min) {
    return var = min;
  } else {
    return var;
  }
}
} // namespace Game

#endif // CLAMP_H
