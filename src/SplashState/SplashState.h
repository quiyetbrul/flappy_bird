#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include "GameLoop/Game.h"
#include "MenuState/MenuState.h"
#include "StateMachine/StateMachine.h"
#include "Utils/Definitions.h"
#include "Utils/State.h"

namespace Game {
class SplashState : public State {
public:
  SplashState(GameDataRef data);

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
