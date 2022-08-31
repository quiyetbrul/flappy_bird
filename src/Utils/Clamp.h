#ifndef CLAMP_H
#define CLAMP_H

namespace Game {
inline float Clamp(int var, int min, int max) {
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
