#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Bird/Bird.h"
#include "../Collision/Collision.h"
#include "../Flash/Flash.h"
#include "../HUD/HUD.h"
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

  void CheckCollision(const std::vector<sf::Sprite> &sprites, Bird &bird,
                      float scale1, float scale2);

private:
  GameDataRef Data_;

  sf::Clock Clock_;

  sf::Sprite Game_Background_Sprite_;

  Bird *Bird_;
  Pipe *Pipe_;
  Land *Land_;
  Collision Collision_;
  Flash *Flash_;
  HUD *Hud_;

  int Game_State_;

  int Score_;
};
} // namespace Game

#endif // GAMESTATE_H
