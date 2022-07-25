#include "Pipe.h"
#include "Definitions.h"

#include <iostream>

namespace Game {
Pipe::Pipe(GameDataRef data) : Data_(data) {}

void Pipe::SpawnTopPipe() {
  sf::Sprite Pipe_Up_Sprite(
      this->Data_->Assets_.GetTexture("PipeDown Background"));
  Pipe_Up_Sprite.setPosition(this->Data_->Window_.getSize().x, 0);
  Pipe_Sprites_.push_back(Pipe_Up_Sprite);
}

void Pipe::SpawnBottomPipe() {
  sf::Sprite Pipe_Bottom_Sprite(
      this->Data_->Assets_.GetTexture("PipeUp Background"));
  Pipe_Bottom_Sprite.setPosition(
      this->Data_->Window_.getSize().x,
      this->Data_->Window_.getSize().y -
          Pipe_Bottom_Sprite.getGlobalBounds().height);
  Pipe_Sprites_.push_back(Pipe_Bottom_Sprite);
}

void Pipe::SpawnInvisiblePipe() {
  sf::Sprite Pipe_Invisible_Sprite(
      this->Data_->Assets_.GetTexture("PipeDown Background"));
  Pipe_Invisible_Sprite.setPosition(
      this->Data_->Window_.getSize().x,
      this->Data_->Window_.getSize().y -
          Pipe_Invisible_Sprite.getGlobalBounds().height);
  Pipe_Invisible_Sprite.setColor(sf::Color(0, 0, 0, 0));
  Pipe_Sprites_.push_back(Pipe_Invisible_Sprite);
}

void Pipe::DrawPipe() {
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
      float pipe_movement = PIPE_MOVEMENT_SPEED * delta_time;
      Pipe_Sprites_[i].move(-pipe_movement, 0);
    }
  }
}
} // namespace Game
