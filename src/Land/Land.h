#ifndef LAND_H
#define LAND_H

#include "GameLoop/Game.h"
#include "Utils/Definitions.h"

#include <vector>

namespace Game {
class Land {
public:
  Land(GameDataRef data);

  void MoveLand(float delta_time);
  void Draw();
  const std::vector<sf::Sprite> &GetSprites() const;
  void UpdateMovementSpeed(const float update_movement_speed);

private:
  GameDataRef Data_;
  std::vector<sf::Sprite> Land_Sprites_;
  float Land_Movement_Speed_;
};
} // namespace Game

#endif // LAND_H
