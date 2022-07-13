#include "AssetManager.h"

#include <iostream>

namespace Game {
void AssetManager::LoadTexture(std::string texture_name,
                               std::string file_name) {
  sf::Texture texture;
  if (!texture.loadFromFile(file_name)) {
    std::cout << "Failed to load texture!" << std::endl;
  } else {
    this->Textures_[texture_name] = texture;
  }
}

sf::Texture &AssetManager::GetTexture(std::string texture_name) {
  return this->Textures_.at(texture_name);
}

void AssetManager::LoadFont(std::string texture_name, std::string file_name) {
  sf::Font font;
  if (!font.loadFromFile(file_name)) {
    std::cout << "Failed to load texture!" << std::endl;
  } else {
    this->Fonts_[texture_name] = font;
  }
}

sf::Font &AssetManager::GetFont(std::string texture_name) {
  return this->Fonts_.at(texture_name);
}

} // namespace Game
