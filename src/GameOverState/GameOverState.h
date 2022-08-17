#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../GameLoop/Game.h"
#include "../StateMachine/StateMachine.h"
#include "../Utils/Definitions.h"
#include "../Utils/State.h"

namespace Game {
class GameOverState : public State {
public:
  GameOverState(GameDataRef data);
  ~GameOverState();
  void Init();
  void HandleInput();
  void Update(float delta_time);
  void Draw(float delta_time);

private:
  GameDataRef Data_;

  sf::Sprite GameOver_Background_Sprite_;
};
} // namespace Game

#endif // GAMESTATE_H
