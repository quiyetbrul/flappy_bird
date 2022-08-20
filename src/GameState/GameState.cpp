#include "GameState.h"

#include <iostream>
#include <sstream>
#include <tuple>

namespace Game {
GameState::GameState(GameDataRef data) : Data_(data) {}

void GameState::Init() {
  std::cout << "Initializing Game State" << std::endl;
  this->Data_->Assets_.LoadTexture("Game State Background",
                                   GAME_BACKGROUND_FILEPATH);

  this->Data_->Assets_.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
  this->Data_->Assets_.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
  this->Data_->Assets_.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
  this->Data_->Assets_.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

  this->Data_->Assets_.LoadTexture("PipeUp Background", PIPE_UP_FILEPATH);
  this->Data_->Assets_.LoadTexture("PipeDown Background", PIPE_DOWN_FILEPATH);

  this->Data_->Assets_.LoadTexture("Land", LAND_FILEPATH);

  Bird_ = new Bird(this->Data_);
  Pipe_ = new Pipe(this->Data_);
  Land_ = new Land(this->Data_);

  Game_Background_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game State Background"));

  Game_State_ = GameStates::eReady;
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
                                            this->Data_->Window_) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      if (GameStates::eGameOver != Game_State_) {
        Game_State_ = GameStates::ePlaying;
        // TODO: create clock setter/getter to animate bird better
        Bird_->Tap();
      }
    }
  }
}

void GameState::Update(float delta_time) {
  if (GameStates::eGameOver != Game_State_) {
    Bird_->Animate(delta_time);
    Land_->MoveLand(delta_time);
  }

  if (GameStates::ePlaying == Game_State_) {
    Pipe_->MovePipes(delta_time);

    // TODO: change pipe spawn frequency after certain score
    if (Clock_.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
      Pipe_->RandomizePipeOffset(); // TODO: change pipe gap
      Pipe_->SpawnInvisiblePipe();
      Pipe_->SpawnTopPipe();
      Pipe_->SpawnBottomPipe();
      Clock_.restart();
    }

    Bird_->Update(delta_time);

    std::vector<sf::Sprite> land_sprites = Land_->GetSprites();
    for (const auto &land_sprite : land_sprites) {
      if (Collission_.CheckSpriteCollision(Bird_->GetSprite(), land_sprite)) {
        Game_State_ = GameStates::eGameOver;
        Clock_.restart();
      }
    }

    std::vector<sf::Sprite> pipe_sprites = Pipe_->GetSprites();
    for (const auto &pipe_sprite : pipe_sprites) {
      if (Collission_.CheckSpriteCollision(Bird_->GetSprite(), pipe_sprite)) {
        Game_State_ = GameStates::eGameOver;
        Clock_.restart();
      }
    }
  }
}

void GameState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(Game_Background_Sprite_);

  Bird_->DrawBird();
  Pipe_->DrawPipe();
  Land_->DrawLand();

  this->Data_->Window_.display();
}
} // namespace Game
