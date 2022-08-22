#include "Flash.h"

namespace Game {
Flash::Flash(GameDataRef data) : Data_(data) {
  Shape_.setSize(sf::Vector2f(this->Data_->Window_.getSize()));
  Shape_.setFillColor(sf::Color(255, 255, 255, 0));

  Flash_On_ = true;
}

void Flash::Show(float delta_time) {
  int alpha = 0;
  if (Flash_On_) {
    alpha = (int)Shape_.getFillColor().a + (FLASH_SPEED * delta_time);
    if (alpha >= 255.0f) {
      alpha = 255.0f;
      Flash_On_ = false;
    }
    Shape_.setFillColor(sf::Color(255, 255, 255, alpha));
  } else {
    alpha = (int)Shape_.getFillColor().a - (FLASH_SPEED * delta_time);
    if (alpha <= 255.0f) {
      alpha = 0.0f;
    }
    Shape_.setFillColor(sf::Color(255, 255, 255, alpha));
  }
}

void Flash::Draw() { this->Data_->Window_.draw(Shape_); }

} // namespace Game
