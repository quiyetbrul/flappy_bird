#ifndef Collision_H
#define Collision_H

#include "GameLoop/Game.h"
#include "Utils/Definitions.h"

namespace Game {
class Collision {
public:
  explicit Collision();

  bool CheckSpriteCollision(const sf::Sprite &sprite1,
                            const sf::Sprite &sprite2) const;
  bool CheckSpriteCollision(const sf::Sprite &sprite1, const float scale1,
                            const sf::Sprite &sprite2,
                            const float scale2) const;
};
} // namespace Game

#endif // Collision_H
