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

  void Draw();
  void MovePipes(float delta_time);

  const std::vector<sf::Sprite> &GetSprites() const;

  void SpawnScoringPipe();
  std::vector<sf::Sprite> &GetScoringSprites();

  void UpdateMovementSpeed(const float update_movement_speed);
  void UpdateSpawnFrequency(const float update_movement_speed);

  float GetSpawnFrequency() const;

private:
  GameDataRef Data_;
  std::vector<sf::Sprite> Pipe_Sprites_;
  std::vector<sf::Sprite> Scoring_Sprites_;

  int Land_Height_;
  float Pipe_Spawn_Y_Offset_;
  float Pipe_Movement_Speed_;
  float Pipe_Spawn_Frequency_;
};
} // namespace Game

#endif // PIPE_H
