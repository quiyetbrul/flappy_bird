#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameLoop/Game.h"
#include "StateMachine/StateMachine.h"
#include "Utils/Definitions.h"
#include "Utils/State.h"

namespace Game {
class GameOverState : public State {
public:
  GameOverState(GameDataRef data, int score);

  void Init() override;
  void HandleInput() override;
  void Update(float delta_time) override;
  void Draw(float delta_time) override;

private:
  GameDataRef Data_;

  sf::Sprite GameOver_Background_Sprite_;

  sf::Sprite GameOver_Title_Sprite_;
  sf::Sprite GameOver_Container_Sprite_;
  sf::Sprite Retry_Button_Sprite_;
  sf::Sprite Medal_;

  sf::Text Score_Text_;
  sf::Text HighScore_Text_;

  int Score_;
  int HighScore_;
};
} // namespace Game

#endif // GAMEOVERSTATE_H
