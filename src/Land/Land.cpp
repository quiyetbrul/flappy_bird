#include "Land.h"

namespace Game {
Land::Land(GameDataRef data)
    : Data_(data), Land_Movement_Speed_(LAND_MOVEMENT_SPEED) {
  sf::Sprite Land_Sprite(this->Data_->Assets_.GetTexture("Land"));
  sf::Sprite Land_Sprite2(this->Data_->Assets_.GetTexture("Land"));

  Land_Sprite.setPosition(0, this->Data_->Window_.getSize().y -
                                 Land_Sprite.getGlobalBounds().height);
  Land_Sprite2.setPosition(Land_Sprite.getGlobalBounds().width,
                           this->Data_->Window_.getSize().y -
                               Land_Sprite.getGlobalBounds().height);

  Land_Sprites_.push_back(Land_Sprite);
  Land_Sprites_.push_back(Land_Sprite2);
}

void Land::Draw() {
  for (unsigned short int i = 0; i < Land_Sprites_.size(); i++) {
    this->Data_->Window_.draw(Land_Sprites_[i]);
  }
}

void Land::MoveLand(float delta_time) {
  for (unsigned short int i = 0; i < Land_Sprites_.size(); i++) {
    sf::Vector2f land_position(this->Data_->Window_.getSize().x,
                               Land_Sprites_[i].getPosition().y);

    float movement_speed = Land_Movement_Speed_ * delta_time;

    Land_Sprites_[i].move(-movement_speed, 0.0f);

    if (Land_Sprites_[i].getPosition().x <
        0 - Land_Sprites_[i].getGlobalBounds().width) {
      Land_Sprites_[i].setPosition(land_position);
    }
  }
}

const std::vector<sf::Sprite> &Land::GetSprites() const {
  return Land_Sprites_;
}

void Land::UpdateMovementSpeed(const float update_movement_speed) {
  float max_freq = 250.0f;
  printf("BEFORE LAND: %f\n", Land_Movement_Speed_);
  Land_Movement_Speed_ < max_freq
      ? Land_Movement_Speed_ += update_movement_speed
      : Land_Movement_Speed_ = max_freq;
  printf("AFTER LAND: %f\n", Land_Movement_Speed_);
}

} // namespace Game
