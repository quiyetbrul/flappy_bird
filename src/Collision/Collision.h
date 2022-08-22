#ifndef Collision_H
#define Collision_H

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

namespace Game {
class Collision {
public:
  Collision();

  bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
  bool CheckSpriteCollision(sf::Sprite sprite1, float scale1,
                            sf::Sprite sprite2, float scale2);
};
} // namespace Game

#endif // Collision_H
