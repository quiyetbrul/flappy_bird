#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Bird/Bird.h"
#include "../Collission/Collission.h"
#include "../Land/Land.h"
#include "../Pipe/Pipe.h"
#include "../StateMachine/StateMachine.h"
#include "../Utils/Definitions.h"
#include "../Utils/State.h"

namespace Game {
class GameState : public State {
public:
  GameState(GameDataRef data);

  void Init();
  void HandleInput();
  void Update(float delta_time);
  void Draw(float delta_time);

private:
  GameDataRef Data_;

  sf::Clock Clock_;

  sf::Sprite Game_Background_Sprite_;

  Bird *Bird_;
  Pipe *Pipe_;
  Land *Land_;
  Collission Collission_;

  int Game_State_;
};
} // namespace Game

#endif // GAMESTATE_H
