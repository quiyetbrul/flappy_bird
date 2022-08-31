#include "Flash.h"

#include <iostream>

namespace Game {
Flash::Flash(GameDataRef data) : Data_(data), Flash_On_(true) {
  Shape_.setSize(sf::Vector2f(this->Data_->Window_.getSize()));
  Shape_.setFillColor(sf::Color(255, 255, 255, 0));
}

void Flash::Show(float delta_time) {
  float alpha = 0;
  if (Flash_On_) {
    alpha = (float)Shape_.getFillColor().a + (FLASH_SPEED * delta_time);
    if (alpha >= 255.0f) {
      alpha = 255.0f;
      Flash_On_ = false;
    }
    Shape_.setFillColor(sf::Color(255, 255, 255, (sf::Uint8)alpha));
  } else {
    alpha = (float)Shape_.getFillColor().a - (FLASH_SPEED * delta_time);
    if (alpha <= 255.0f) {
      alpha = 0.0f;
    }
    Shape_.setFillColor(sf::Color(255, 255, 255, (sf::Uint8)alpha));
  }
}

void Flash::Draw() const { this->Data_->Window_.draw(Shape_); }

} // namespace Game 
