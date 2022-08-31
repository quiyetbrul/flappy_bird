#include "MenuState.h"

#include <iostream>
#include <sstream>

namespace Game {
MenuState::MenuState(GameDataRef data) : Data_(data) {}

void MenuState::Init() {
  std::cout << "Initializing Menu State" << std::endl;
  this->Data_->Assets_.LoadTexture("Main Menu Background",
                                   MENU_BACKGROUND_FILEPATH);
  this->Data_->Assets_.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
  this->Data_->Assets_.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

  this->Menu_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Main Menu Background"));
  this->Title_Sprite_.setTexture(this->Data_->Assets_.GetTexture("Game Title"));
  this->Play_Button_Sprite_.setTexture(
      this->Data_->Assets_.GetTexture("Play Button"));

  this->Title_Sprite_.setPosition(
      (SCREEN_WIDTH / 2.0f) - (this->Title_Sprite_.getGlobalBounds().width / 2),
      this->Title_Sprite_.getGlobalBounds().height / 2.0f);
  this->Play_Button_Sprite_.setPosition(
      (SCREEN_WIDTH / 2.0f) -
          (this->Play_Button_Sprite_.getGlobalBounds().width / 2.0f),
      (SCREEN_HEIGHT / 2.0f) -
          (this->Play_Button_Sprite_.getGlobalBounds().height / 2.0f));
}

void MenuState::HandleInput() {
  sf::Event event;

  while (this->Data_->Window_.pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed ||
        (event.Event::KeyPressed &&
         event.Event::key.code == sf::Keyboard::Escape)) {
      this->Data_->Window_.close();
    }

    if (this->Data_->Input_.IsSpriteClicked(
            this->Play_Button_Sprite_, sf::Mouse::Left, this->Data_->Window_) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      // Switch To Game Mode
      this->Data_->Machine_.AddState(StateRef(new GameState(this->Data_)),
                                     true);
    }
  }
}

void MenuState::Update(float delta_time) {}

void MenuState::Draw(float delta_time) {
  this->Data_->Window_.clear(sf::Color::Black);
  this->Data_->Window_.draw(Menu_Sprite_);
  this->Data_->Window_.draw(Title_Sprite_);
  this->Data_->Window_.draw(Play_Button_Sprite_);
  this->Data_->Window_.display();
}

} // namespace Game
