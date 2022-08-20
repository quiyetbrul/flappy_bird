#include "Bird.h"

namespace Game {
Bird::Bird(GameDataRef data) : Data_(data) {
  Animation_Iterator_ = 0;
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 1"));
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 2"));
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 3"));
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 4"));

  Animation_Frames_Size_ = Animation_Frames_.size();

  Bird_Sprite_.setTexture(Animation_Frames_[Animation_Iterator_]);
}

void Bird::DrawBird() { this->Data_->Window_.draw(Bird_Sprite_); }

void Bird::Animate(float delta_time) {
  if (Clock_.getElapsedTime().asSeconds() >
      BIRD_ANIMATION_DURATION / Animation_Frames_Size_) {
    if (Animation_Iterator_ < Animation_Frames_Size_ - 1) {
      Animation_Iterator_++;
    } else {
      Animation_Iterator_ = 0;
    }
    Bird_Sprite_.setTexture(Animation_Frames_[Animation_Iterator_]);
    Clock_.restart();
  }
}

} // namespace Game
