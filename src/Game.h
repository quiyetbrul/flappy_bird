#ifndef GAME_H
#define GAME_H

#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"
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
  Game(int screen_width, int screen_height, std::string game_title);
  ~Game();

private:
  const float DELTATIME_ = 1/60.0f;
  sf::Clock Clock_;
  GameDataRef Data_ = std::make_shared<GameData>();

  void Run();
};
} // namespace Game

#endif // GAME_H
