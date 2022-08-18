#ifndef PIPE_H
#define PIPE_H

#include "../GameLoop/Game.h"
#include "../Land/Land.h"
#include "../Utils/Definitions.h"

#include <vector>

namespace Game {
class Pipe {
public:
  Pipe(GameDataRef data);

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
