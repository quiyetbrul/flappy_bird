#include "Pipe.h"

#include "../Utils/RandomEngine.h"

#include <iostream>

namespace Game {
Pipe::Pipe(GameDataRef data)
    : Data_(data), Pipe_Spawn_Y_Offset_(0),
      Pipe_Movement_Speed_(PIPE_MOVEMENT_SPEED),
      Pipe_Spawn_Frequency_(PIPE_SPAWN_FREQUENCY) {
  Land_Height_ = this->Data_->Assets_.GetTexture("Land").getSize().y;
}

void Pipe::SpawnTopPipe() {
  sf::Sprite Top_Pipe_Sprite(
      this->Data_->Assets_.GetTexture("PipeDown Background"));
  Top_Pipe_Sprite.setPosition(this->Data_->Window_.getSize().x,
                              -Pipe_Spawn_Y_Offset_);
  Pipe_Sprites_.push_back(Top_Pipe_Sprite);
}

void Pipe::SpawnBottomPipe() {
  sf::Sprite Bottom_Pipe_Sprite(
      this->Data_->Assets_.GetTexture("PipeUp Background"));
  Bottom_Pipe_Sprite.setPosition(
      this->Data_->Window_.getSize().x,
      this->Data_->Window_.getSize().y -
          Bottom_Pipe_Sprite.getGlobalBounds().height - Pipe_Spawn_Y_Offset_);
  Pipe_Sprites_.push_back(Bottom_Pipe_Sprite);
}

void Pipe::SpawnInvisiblePipe() {
  sf::Sprite Pipe_Invisible_Sprite(
      this->Data_->Assets_.GetTexture("PipeDown Background"));
  Pipe_Invisible_Sprite.setPosition(this->Data_->Window_.getSize().x,
                                    -Pipe_Spawn_Y_Offset_);
  Pipe_Invisible_Sprite.setColor(sf::Color(0, 0, 0, 0));
  Pipe_Sprites_.push_back(Pipe_Invisible_Sprite);
}

void Pipe::RandomizePipeOffset() {
  RandomEngine Random_Engine_;
  Pipe_Spawn_Y_Offset_ =
      Random_Engine_.GenerateRandomNumber() % (Land_Height_ / 2) + 1;
}

void Pipe::Draw() {
  for (unsigned int i = 0; i < Pipe_Sprites_.size(); i++) {
    this->Data_->Window_.draw(Pipe_Sprites_[i]);
  }
}

void Pipe::MovePipes(float delta_time) {
  for (unsigned int i = 0; i < Pipe_Sprites_.size(); i++) {
    if (Pipe_Sprites_[i].getPosition().x <
        0 - Pipe_Sprites_[i].getGlobalBounds().width) {
      Pipe_Sprites_.erase(Pipe_Sprites_.begin() + i);
    } else {
      float movement_speed = Pipe_Movement_Speed_ * delta_time;
      Pipe_Sprites_[i].move(-movement_speed, 0);
    }
  }

  for (unsigned int i = 0; i < Scoring_Sprites_.size(); i++) {
    if (Scoring_Sprites_[i].getPosition().x <
        0 - Scoring_Sprites_[i].getGlobalBounds().width) {
      Scoring_Sprites_.erase(Scoring_Sprites_.begin() + i);
    } else {
      float movement_speed = Pipe_Movement_Speed_ * delta_time;
      Scoring_Sprites_[i].move(-movement_speed, 0);
    }
  }
}

const std::vector<sf::Sprite> &Pipe::GetSprites() const {
  return Pipe_Sprites_;
}

void Pipe::SpawnScoringPipe() {
  sf::Sprite Scoring_Pipe(this->Data_->Assets_.GetTexture("Scoring Pipe"));
  Scoring_Pipe.setPosition(this->Data_->Window_.getSize().x, 0);
  Scoring_Sprites_.push_back(Scoring_Pipe);
}

std::vector<sf::Sprite> &Pipe::GetScoringSprites() { return Scoring_Sprites_; }

void Pipe::UpdateMovementSpeed(const float update_movement_speed) {
  float max_freq = 250.0f;
  printf("BEFORE PIPE MOVEMENT SPEED: %f\n", Pipe_Movement_Speed_);
  Pipe_Movement_Speed_ < max_freq
      ? Pipe_Movement_Speed_ += update_movement_speed
      : Pipe_Movement_Speed_ = max_freq;
  printf("AFTER PIPE MOVEMENT SPEED: %f\n", Pipe_Movement_Speed_);
}

void Pipe::UpdateSpawnFrequesncy(const float update_spawn_frequency) {
  float max_freq = 1.0f;
  printf("BEFORE PIPE FREQ SPEED: %f\n", Pipe_Spawn_Frequency_);
  Pipe_Spawn_Frequency_ > max_freq
      ? Pipe_Spawn_Frequency_ -= update_spawn_frequency
      : Pipe_Spawn_Frequency_ = max_freq;
  printf("AFTER PIPE FREQ SPEED: %f\n", Pipe_Spawn_Frequency_);
}

float Pipe::GetSpawnFrequency() { return Pipe_Spawn_Frequency_; }

} // namespace Game
