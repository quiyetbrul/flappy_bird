#ifndef FLASH_H
#define FLASH_H

#include "../GameLoop/Game.h"
#include "../Utils/Definitions.h"

namespace Game {
class Flash {

public:
  explicit Flash(GameDataRef data);
  void Show(float delta_time);
  void Draw() const;

private:
  GameDataRef Data_;
  sf::RectangleShape Shape_;
  bool Flash_On_;
};
} // namespace Game

#endif // FLASH_H
