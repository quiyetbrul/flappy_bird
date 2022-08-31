#ifndef GAME_H
#define GAME_H

#include "../AssetManager/AssetManager.h"
#include "../InputManager/InputManager.h"
#include "../StateMachine/StateMachine.h"

#include <memory>
#include <string>

namespace Game {
struct GameData {
  StateMachine Machine_;
  sf::RenderWindow Window_;
  AssetManager Assets_;
  InputManager Input_;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game {
public:
  Game(const int screen_width, const int screen_height,
       const std::string &game_title);

private:
  const float DELTATIME_ = 1.0f / 60.0f;
  sf::Clock Clock_;
  GameDataRef Data_ = std::make_shared<GameData>();

  void Run();
};
} // namespace Game

#endif // GAME_H
