#include "Bird.h"

namespace Game {
Bird::Bird(GameDataRef data)
    : Data_(data), Bird_State_(BIRD_STATE_STILL), Rotation_(0.0f),
      Animation_Iterator_(0) {
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 1"));
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 2"));
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 3"));
  Animation_Frames_.push_back(this->Data_->Assets_.GetTexture("Bird Frame 4"));

  Bird_Sprite_.setTexture(Animation_Frames_[Animation_Iterator_]);

  Bird_Sprite_.setPosition((this->Data_->Window_.getSize().x / 4.0f) -
                               (Bird_Sprite_.getGlobalBounds().width / 2.0f),
                           (this->Data_->Window_.getSize().y / 2.0f) -
                               (Bird_Sprite_.getGlobalBounds().height / 2.0f));

  auto origin = sf::Vector2f(Bird_Sprite_.getGlobalBounds().width / 2.0f,
                             Bird_Sprite_.getGlobalBounds().height / 2.0f);
  Bird_Sprite_.setOrigin(origin);
}

void Bird::Draw() const {
  const_cast<sf::Sprite &>(Bird_Sprite_).setScale(1.0f, 1.0f);
  this->Data_->Window_.draw(Bird_Sprite_);
}

void Bird::Animate([[maybe_unused]] float delta_time) {
  if (Animation_Clock_.getElapsedTime().asSeconds() >
      BIRD_ANIMATION_DURATION / Animation_Frames_.size()) {
    if (Animation_Iterator_ < Animation_Frames_.size() - 1) {
      Animation_Iterator_++;
    } else {
      Animation_Iterator_ = 0;
    }
    Bird_Sprite_.setTexture(Animation_Frames_[Animation_Iterator_]);
    Animation_Clock_.restart();
  }
}

void Bird::Update(float delta_time) {
  if (BIRD_STATE_FALLING == Bird_State_) {
    Bird_Sprite_.move(0.0f, GRAVITY * delta_time);
    Rotation_ += BIRD_ROTATION_SPEED * delta_time;
    if (Rotation_ > 25.0f) {
      Rotation_ = 25.0f;
    }
    Bird_Sprite_.setRotation(Rotation_);
  } else if (BIRD_STATE_FLYING == Bird_State_) {
    Bird_Sprite_.move(0.0f, -BIRD_FLYING_SPEED * delta_time);
    Rotation_ -= BIRD_ROTATION_SPEED * delta_time;
    if (Rotation_ < -25.0f) {
      Rotation_ = -25.0f;
    }
    Bird_Sprite_.setRotation(Rotation_);
  }

  if (Movement_Clock_.getElapsedTime().asSeconds() > FLYING_DURATION) {
    Bird_State_ = BIRD_STATE_FALLING;
  }
}

void Bird::Tap() {
  Movement_Clock_.restart();
  Bird_State_ = BIRD_STATE_FLYING;
}

const sf::Sprite &Bird::GetSprite() const { return Bird_Sprite_; }
} // namespace Game
