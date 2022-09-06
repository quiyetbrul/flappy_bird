#include "GameState.h"

#include "../GameOverState/GameOverState.h"

#include <iostream>
#include <memory>

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
  this->Data_->Assets_.LoadTexture("Scoring Pipe", PIPE_SCORING_FILEPATH);

  this->Data_->Assets_.LoadTexture("Land", LAND_FILEPATH);

  this->Data_->Assets_.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

  Bird_ = new Bird(this->Data_);
  Pipe_ = new Pipe(this->Data_);
  Land_ = new Land(this->Data_);
  Flash_ = new Flash(this->Data_);
  Hud_ = new HUD(this->Data_);

  Game_Background_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game State Background"));

  Score_ = 0;
  Hud_->Update(Score_);

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
    if ((this->Data_->Input_.IsSpriteClicked(this->Game_Background_Sprite_,
                                             sf::Mouse::Left,
                                             this->Data_->Window_) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
        GameStates::eGameOver != Game_State_) {
      Game_State_ = GameStates::ePlaying;
      Bird_->Tap();
    }
  }
}

void GameState::CheckCollision(const std::vector<sf::Sprite> &sprites,
                               const Bird &bird, const float scale1,
                               const float scale2) {
  for (const auto &sprite : sprites) {
    if (Collision_.CheckSpriteCollision(bird.GetSprite(), scale1, sprite,
                                        scale2)) {
      Game_State_ = GameStates::eGameOver;
      Clock_.restart();
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

    if (Clock_.getElapsedTime().asSeconds() > Pipe_->GetSpawnFrequency()) {
      Pipe_->RandomizePipeOffset();
      Pipe_->SpawnInvisiblePipe();
      Pipe_->SpawnTopPipe();
      Pipe_->SpawnBottomPipe();
      Pipe_->SpawnScoringPipe();
      Clock_.restart();
    }

    Bird_->Update(delta_time);

    CheckCollision(Land_->GetSprites(), *Bird_, /*bird_scale=*/0.625f,
                   /*land_scale=*/1.0f);
    CheckCollision(Pipe_->GetSprites(), *Bird_, /*bird_scale=*/0.625f,
                   /*pipe_scale=*/1.0f);

    std::vector<sf::Sprite> &scoring_pipes = Pipe_->GetScoringSprites();
    for (int i = 0; i < scoring_pipes.size(); i++) {
      if (Collision_.CheckSpriteCollision(Bird_->GetSprite(),
                                          /*bird_scale=*/0.625f,
                                          scoring_pipes[i],
                                          /*scoring_pipe_scale=*/1.0f)) {
        Score_++;
        std::cout << "Score: " << Score_ << std::endl;
        Hud_->Update(Score_);
        scoring_pipes.erase(scoring_pipes.begin() + i);
        if (Score_ % 10 == 0) {
          Pipe_->UpdateMovementSpeed(0.05f);
          Pipe_->UpdateSpawnFrequency(0.02f);
          Land_->UpdateMovementSpeed(0.05f);
        }
      }
    }
  }

  if (GameStates::eGameOver == Game_State_) {
    Flash_->Show(delta_time);
    if (Clock_.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
      this->Data_->Machine_.AddState(
          StateRef(new GameOverState(this->Data_, Score_)), true);
    }
  }
}

void GameState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(Game_Background_Sprite_);

  Pipe_->Draw();
  Land_->Draw();
  Bird_->Draw();
  Flash_->Draw();
  Hud_->Draw();

  this->Data_->Window_.display();
}
} // namespace Game
