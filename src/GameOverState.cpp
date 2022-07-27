#include "GameOverState.h"
#include "Definitions.h"
#include "StateMachine.h"

#include <iostream>
#include <sstream>

namespace Game {
GameOverState::GameOverState(GameDataRef data) : Data_(data) {}

void GameOverState::Init() {
  std::cout << "Initializing Game Over State" << std::endl;
  this->Data_->Assets_.LoadTexture("Game Over State Background",
                                   GAME_BACKGROUND_FILEPATH);
  GameOver_Background_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game Over State Background"));
}

void GameOverState::HandleInput() {
  sf::Event event;
  while (this->Data_->Window_.pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed ||
        (event.Event::KeyPressed &&
         event.Event::key.code == sf::Keyboard::Escape)) {
      this->Data_->Window_.close();
    }
  }
}

void GameOverState::Update(float delta_time) {}

void GameOverState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(GameOver_Background_Sprite_);
  this->Data_->Window_.display();
}

} // namespace Game
