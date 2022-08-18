#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>

namespace Game {
class InputManager {
public:
  InputManager(){};
  ~InputManager(){};

  bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
                       sf::RenderWindow &window);

  sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};
} // namespace Game

#endif // INPUT_MANAGER_H
