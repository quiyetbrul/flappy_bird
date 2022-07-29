#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../include/SFML/Graphics.hpp"

namespace Game {
class InputManager {
public:
  InputManager(){};
  ~InputManager(){};

  bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
                       sf::RenderWindow &window);

  sf::Vector2i GetMousePosition(sf::RenderWindow &window);

  // void Update();

  // bool IsKeyPressed(sf::Keyboard::Key key);
  // bool IsKeyReleased(sf::Keyboard::Key key);
  // bool IsKeyDown(sf::Keyboard::Key key);
};
} // namespace Game

#endif // INPUT_MANAGER_H
