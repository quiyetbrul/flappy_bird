#ifndef Bird_h
#define Bird_h

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

#include <vector>

namespace Game {
class Bird {
public:
  explicit Bird(GameDataRef data);

  void Draw() const;
  void Animate(float delta_time);
  void Update(float delta_time);
  void Tap();

  const sf::Sprite &GetSprite() const;

private:
  GameDataRef Data_;
  sf::Sprite Bird_Sprite_;
  int Bird_State_;
  float Rotation_;

  std::vector<sf::Texture> Animation_Frames_;
  unsigned int Animation_Iterator_;
  int Animation_Frames_Size_;
  sf::Clock Animation_Clock_;

  sf::Clock Movement_Clock_;
};
} // namespace Game

#endif // Bird_h
