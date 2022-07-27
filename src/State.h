#ifndef STATE_H
#define STATE_H

namespace Game {
class State {
public:
  virtual void Init() = 0;
  virtual void HandleInput() = 0;
  virtual void Update(float delta_time) = 0;
  virtual void Draw(float delta_time) = 0;

  virtual void Pause(){};
  virtual void Resume(){};
};
} // namespace Game

#endif // STATE_H
