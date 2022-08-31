#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>

namespace Game {
class InputManager {
public:
  InputManager(){};
  ~InputManager(){};

  bool IsSpriteClicked(const sf::Sprite &object, sf::Mouse::Button button,
                       sf::RenderWindow &window);

  sf::Vector2i GetMousePosition(const sf::RenderWindow &window) const;
};
} // namespace Game

#endif // INPUT_MANAGER_H
