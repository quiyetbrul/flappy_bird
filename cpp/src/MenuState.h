#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "Game.h"
#include "State.h"

namespace Game {
class MenuState : public State {
public:
  MenuState(GameDataRef data);
  ~MenuState();
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
