#ifndef PIPE_H
#define PIPE_H

#include "Game.h"

#include <vector>

namespace Game {
class Pipe {
public:
  Pipe(GameDataRef data);
  ~Pipe();

  void DrawPipe();
  void SpawnTopPipe();
  void SpawnBottomPipe();
  void SpawnInvisiblePipe();
  void MovePipes(float delta_time);

private:
  GameDataRef Data_;
  std::vector<sf::Sprite> Pipe_Sprites_;
};
} // namespace Game

#endif // PIPE_H
