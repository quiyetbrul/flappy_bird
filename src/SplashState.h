#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include "Game.h"
#include "State.h"

namespace Game {
class SplashState : public State {
public:
  SplashState(GameDataRef data);
  ~SplashState();

  void Init();
  void HandleInput();
  void Update(float delta_time);
  void Draw(float delta_time);

private:
  GameDataRef Data_;
  sf::Clock Clock_;

  sf::Sprite Background_Sprite_;
};
} // namespace Game

#endif // SPLASH_STATE_H
