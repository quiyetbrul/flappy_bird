#ifndef LAND_H
#define LAND_H

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

#include <vector>

namespace Game {
class Land {
public:
  Land(GameDataRef data);

  void MoveLand(float delta_time);
  void DrawLand();
  const std::vector<sf::Sprite> &GetSprites() const;

private:
  GameDataRef Data_;
  std::vector<sf::Sprite> Land_Sprites_;
};
} // namespace Game

#endif // LAND_H
