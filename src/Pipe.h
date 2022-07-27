#ifndef PIPE_H
#define PIPE_H

#include "Game.h"

#include <vector>

namespace Game {
class Pipe {
public:
  Pipe(GameDataRef data);
  ~Pipe();

  void SpawnTopPipe();
  void SpawnBottomPipe();
  void SpawnInvisiblePipe();

  void RandomizePipeOffset();

  void DrawPipe();
  void MovePipes(float delta_time);

private:
  GameDataRef Data_;
  std::vector<sf::Sprite> Pipe_Sprites_;

  int Land_Height_;
  int Pipe_Spawn_Y_Offset_;
};
} // namespace Game

#endif // PIPE_H
