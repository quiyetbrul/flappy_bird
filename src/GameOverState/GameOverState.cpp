#include "GameOverState.h"

#include "GameState/GameState.h"

#include <fstream>
#include <iostream>

namespace Game {
namespace {
bool IsFileEmpty(std::ifstream &file) {
  return file.peek() == std::ifstream::traits_type::eof();
}
} // namespace

GameOverState::GameOverState(GameDataRef data, int score)
    : Data_(data), Score_(score) {}

void GameOverState::Init() {
  std::cout << "Initializing Game Over State" << std::endl;

  std::ifstream readFile;
  readFile.open(HIGHSCORE_FILEPATH);
  if (readFile.is_open()) {
    while (!readFile.eof()) {
      if (IsFileEmpty(readFile)) {
        HighScore_ = 0;
        break;
      }
      readFile >> HighScore_;
    }
  }
  readFile.close();

  std::ofstream writeFile(HIGHSCORE_FILEPATH);
  if (writeFile.is_open()) {
    if (Score_ > HighScore_) {
      HighScore_ = Score_;
    }
    writeFile << HighScore_;
  }
  writeFile.close();

  this->Data_->Assets_.LoadTexture("Game Over State Background",
                                   GAMEOVER_BACKGROUND_FILEPATH);
  this->Data_->Assets_.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
  this->Data_->Assets_.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);

  this->Data_->Assets_.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
  this->Data_->Assets_.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
  this->Data_->Assets_.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
  this->Data_->Assets_.LoadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);

  GameOver_Background_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game Over State Background"));
  GameOver_Container_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game Over Body"));
  GameOver_Title_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Game Over Title"));
  Retry_Button_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Play Button"));

  GameOver_Container_Sprite_.setPosition(
      this->Data_->Window_.getSize().x / 2.0f -
          GameOver_Container_Sprite_.getGlobalBounds().width / 2.0f,
      this->Data_->Window_.getSize().y / 2.0f -
          GameOver_Container_Sprite_.getGlobalBounds().height / 2.0f);
  GameOver_Title_Sprite_.setPosition(
      this->Data_->Window_.getSize().x / 2.0f -
          GameOver_Title_Sprite_.getGlobalBounds().width / 2.0f,
      GameOver_Container_Sprite_.getPosition().y -
          GameOver_Title_Sprite_.getGlobalBounds().height * 1.2f);
  Retry_Button_Sprite_.setPosition(
      this->Data_->Window_.getSize().x / 2.0f -
          Retry_Button_Sprite_.getGlobalBounds().width / 2.0f,
      GameOver_Container_Sprite_.getPosition().y +
          GameOver_Container_Sprite_.getGlobalBounds().height +
          (Retry_Button_Sprite_.getGlobalBounds().height * 0.2f));

  Score_Text_.setFont(this->Data_->Assets_.GetFont("Flappy Font"));
  Score_Text_.setString(std::to_string(Score_));
  Score_Text_.setCharacterSize(56);
  Score_Text_.setFillColor(sf::Color::White);
  Score_Text_.setOrigin(
      sf::Vector2f(Score_Text_.getGlobalBounds().width / 2.0f,
                   Score_Text_.getGlobalBounds().height / 2.0f));
  Score_Text_.setPosition(
      sf::Vector2f(this->Data_->Window_.getSize().x / 10.0f * 7.2f,
                   this->Data_->Window_.getSize().y / 2.15f));

  HighScore_Text_.setFont(this->Data_->Assets_.GetFont("Flappy Font"));
  HighScore_Text_.setString(std::to_string(HighScore_));
  HighScore_Text_.setCharacterSize(56);
  HighScore_Text_.setFillColor(sf::Color::White);
  HighScore_Text_.setOrigin(
      sf::Vector2f(HighScore_Text_.getGlobalBounds().width / 2.0f,
                   HighScore_Text_.getGlobalBounds().height / 2.0f));
  HighScore_Text_.setPosition(
      sf::Vector2f(this->Data_->Window_.getSize().x / 10.0f * 7.25f,
                   this->Data_->Window_.getSize().y / 1.78f));

  for (const auto medal_pair : Medal_Score) {
    if (Score_ >= medal_pair.first) {
      Medal_.setTexture(this->Data_->Assets_.GetTexture(medal_pair.second));
      break;
    }
  }

  Medal_.setPosition(175, 465);
}

void GameOverState::HandleInput() {
  sf::Event event;
  while (this->Data_->Window_.pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed ||
        (event.Event::KeyPressed &&
         event.Event::key.code == sf::Keyboard::Escape)) {
      this->Data_->Window_.close();
    }
    if (this->Data_->Input_.IsSpriteClicked(
            Retry_Button_Sprite_, sf::Mouse::Left, this->Data_->Window_) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      this->Data_->Machine_.AddState(StateRef(new GameState(this->Data_)),
                                     true);
    }
  }
}

void GameOverState::Update(float delta_time) {}

void GameOverState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(GameOver_Background_Sprite_);
  this->Data_->Window_.draw(GameOver_Container_Sprite_);
  this->Data_->Window_.draw(GameOver_Title_Sprite_);
  this->Data_->Window_.draw(Retry_Button_Sprite_);
  this->Data_->Window_.draw(Score_Text_);
  this->Data_->Window_.draw(HighScore_Text_);
  this->Data_->Window_.draw(Medal_);
  this->Data_->Window_.display();
}

} // namespace Game
