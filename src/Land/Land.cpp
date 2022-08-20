#include "Land.h"

namespace Game {
Land::Land(GameDataRef data) : Data_(data) {
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

void Land::DrawLand() {
  for (unsigned short int i = 0; i < Land_Sprites_.size(); i++) {
    this->Data_->Window_.draw(Land_Sprites_[i]);
  }
}

void Land::MoveLand(float delta_time) {
  for (unsigned short int i = 0; i < Land_Sprites_.size(); i++) {
    sf::Vector2f land_position(this->Data_->Window_.getSize().x,
                               Land_Sprites_[i].getPosition().y);

    float land_movement = PIPE_MOVEMENT_SPEED * delta_time;

    Land_Sprites_[i].move(-land_movement, 0.0f);

    if (Land_Sprites_[i].getPosition().x <
        0 - Land_Sprites_[i].getGlobalBounds().width) {
      Land_Sprites_[i].setPosition(land_position);
    }
  }
}

const std::vector<sf::Sprite> &Land::GetSprites() const {
  return Land_Sprites_;
}

} // namespace Game
