#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameLoop/Game.h"
#include "GameState/GameState.h"
#include "StateMachine/StateMachine.h"
#include "Utils/Definitions.h"
#include "Utils/State.h"

namespace Game {
class MenuState : public State {
public:
  MenuState(GameDataRef data);

  void Init();
  void HandleInput();
  void Update(float delta_time);
  void Draw(float delta_time);

private:
  GameDataRef Data_;

  sf::Sprite Menu_Sprite_;
  sf::Sprite Title_Sprite_;
  sf::Sprite Play_Button_Sprite_;
};
} // namespace Game

#endif // MENUSTATE_H
