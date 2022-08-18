#include "Pipe.h"

#include <iostream>

namespace Game {
Pipe::Pipe(GameDataRef data) : Data_(data) {
  Land_Height_ = this->Data_->Assets_.GetTexture("Land").getSize().y;
  Pipe_Spawn_Y_Offset_ = 0;
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
  Pipe_Spawn_Y_Offset_ = rand() % (Land_Height_ / 2) + 1;
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
      sf::Vector2f position = Pipe_Sprites_[i].getPosition();
      float pipe_movement = PIPE_MOVEMENT_SPEED * delta_time;
      Pipe_Sprites_[i].move(-pipe_movement, 0);
    }
  }
}
} // namespace Game
