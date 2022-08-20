#ifndef Bird_h
#define Bird_h

#include <vector>

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

namespace Game {
class Bird {
public:
  Bird(GameDataRef data);

  void DrawBird();
  void Animate(float delta_time);

private:
  GameDataRef Data_;
  sf::Sprite Bird_Sprite_;

  std::vector<sf::Texture> Animation_Frames_;
  unsigned int Animation_Iterator_;
  unsigned int Animation_Frames_Size_;
  sf::Clock Clock_;
};
} // namespace Game

#endif // Bird_h
