#ifndef HUD_H
#define HUD_H

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

namespace Game {
class HUD {
public:
  explicit HUD(GameDataRef data);

  void Draw() const;
  void Update(int score);

private:
  GameDataRef Data_;
  sf::Text Score_Text_;
};
} // namespace Game

#endif // HUD_H
