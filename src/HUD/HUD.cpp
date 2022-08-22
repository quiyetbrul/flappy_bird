#include "HUD.h"

#include <string>

namespace Game {
HUD::HUD(GameDataRef data) : Data_(data) {
  Score_Text_.setFont(this->Data_->Assets_.GetFont("Flappy Font"));
  Score_Text_.setString("0");
  Score_Text_.setCharacterSize(128);
  Score_Text_.setFillColor(sf::Color::White);
  Score_Text_.setOrigin(Score_Text_.getLocalBounds().width / 2.0,
                        Score_Text_.getLocalBounds().height / 2.0);
  Score_Text_.setPosition(this->Data_->Window_.getSize().x / 2.0,
                          this->Data_->Window_.getSize().y / 10.0);
}

void HUD::Draw() {
  this->Data_->Window_.draw(Score_Text_);
}

void HUD::Update(int score) {
  Score_Text_.setString(std::to_string(score));
}
} // namespace Game
