#include "GameState.h"
#include "Definitions.h"
#include "StateMachine.h"

#include <iostream>
#include <sstream>

namespace Game {
GameState::GameState(GameDataRef data) : Data_(data) {}

void GameState::Init() {
  std::cout << "Initializing Game State" << std::endl;
  this->Data_->Assets_.LoadTexture("Game State Background",
                                   GAME_BACKGROUND_FILEPATH);

  this->Data_->Assets_.LoadTexture("PipeUp Background", PIPE_UP_FILEPATH);
  this->Data_->Assets_.LoadTexture("PipeDown Background", PIPE_DOWN_FILEPATH);
  this->Data_->Assets_.LoadTexture("Land", LAND_FILEPATH);

  Pipe_ = new Pipe(this->Data_);
  Land_ = new Land(this->Data_);

  Game_Background_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game State Background"));
}

void GameState::HandleInput() {
  sf::Event event;
  while (this->Data_->Window_.pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed ||
        (event.Event::KeyPressed &&
         event.Event::key.code == sf::Keyboard::Escape)) {
      this->Data_->Window_.close();
    }
    if (this->Data_->Input_.IsSpriteClicked(this->Game_Background_Sprite_,
                                            sf::Mouse::Left,
                                            this->Data_->Window_)) {
    }
  }
}

void GameState::Update(float delta_time) {
  Pipe_->MovePipes(delta_time);
  Land_->MoveLand(delta_time);
  if (Clock_.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
    Pipe_->SpawnInvisiblePipe();
    Pipe_->SpawnTopPipe();
    Pipe_->SpawnBottomPipe();
    Clock_.restart();
  }
}
void GameState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(Game_Background_Sprite_);

  Pipe_->DrawPipe();
  Land_->DrawLand();

  this->Data_->Window_.display();
}
} // namespace Game
