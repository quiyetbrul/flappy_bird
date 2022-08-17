#include "Game.h"

namespace Game {
Game::Game(int screen_width, int screen_height, std::string game_title) {
  this->Data_->Window_.create(sf::VideoMode(screen_width, screen_height),
                              game_title,
                              sf::Style::Close | sf::Style::Titlebar);
  // this->Data_->Machine_.AddState(StateRef(new SplashState(this->Data_)), true);

  this->Run();
}

Game::~Game() { this->Data_->Window_.close(); }

void Game::Run() {
  float newTime, frameTime, interpolation;

  float currentTime = this->Clock_.getElapsedTime().asSeconds();
  float accumulator = 0.0f;

  while (this->Data_->Window_.isOpen()) {
    this->Data_->Machine_.ProcessStateChanges();
    newTime = this->Clock_.getElapsedTime().asSeconds();

    // handle changes in game time for smooth movement
    frameTime = newTime - currentTime;
    if (frameTime > 0.25f) {
      frameTime = 0.25f;
    }
    currentTime = newTime;
    accumulator += frameTime;

    while (accumulator >= this->DELTATIME_) {
      this->Data_->Machine_.GetActiveState()->HandleInput();
      this->Data_->Machine_.GetActiveState()->Update(this->DELTATIME_);
      accumulator -= this->DELTATIME_;
    }

    // interpolation for smooth movement
    interpolation = accumulator / this->DELTATIME_;
    this->Data_->Machine_.GetActiveState()->Draw(interpolation);
  }
}
} // namespace Game
