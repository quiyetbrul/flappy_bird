#include "InputManager.h"

namespace Game {
bool InputManager::IsSpriteClicked(const sf::Sprite &object,
                                   sf::Mouse::Button button,
                                   sf::RenderWindow &window) {
  if (sf::Mouse::isButtonPressed(button)) {
    sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
                         object.getGlobalBounds().width,
                         object.getGlobalBounds().height);
    if (tempRect.contains(GetMousePosition(window))) {
      return true;
    }
  }
  return false;
}

sf::Vector2i
InputManager::GetMousePosition(const sf::RenderWindow &window) const {
  return sf::Mouse::getPosition(window);
}

} // namespace Game
