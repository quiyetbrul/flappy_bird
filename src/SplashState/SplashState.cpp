#include "SplashState.h"

#include <iostream>
#include <sstream>

namespace Game {
SplashState::SplashState(GameDataRef data) : Data_(data) {}

void SplashState::Init() {
  // std::cout << "Initializing Splash State" << std::endl;
  // this->Data_->Assets_.LoadTexture("Splash State Background",
  //                                  SPLASH_SCENE_BACKGROUND_FILEPATH);
  // Background_Sprite_.setTexture(
  //     this->Data_->Assets_.GetTexture("Splash State Background"));
}

void SplashState::HandleInput() {
  sf::Event event;
  while (this->Data_->Window_.pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed ||
        (event.Event::KeyPressed &&
         event.Event::key.code == sf::Keyboard::Escape)) {
      this->Data_->Window_.close();
    }
  }
}

void SplashState::Update(float delta_time) {
  if (this->Clock_.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
    this->Data_->Machine_.AddState(StateRef(new MenuState(this->Data_)), true);
  }
}

void SplashState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(Background_Sprite_);
  this->Data_->Window_.display();
}

} // namespace Game
