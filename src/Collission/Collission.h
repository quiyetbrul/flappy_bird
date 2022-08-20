#ifndef COLLISSION_H
#define COLLISSION_H

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

namespace Game {
class Collission {
public:
  Collission();

  bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
};
} // namespace Game

#endif // COLLISSION_H
