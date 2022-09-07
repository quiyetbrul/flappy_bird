#include "AssetManager.h"

#include <iostream>

namespace Game {
void AssetManager::LoadTexture(const std::string &texture_name,
                               const std::string &file_name) {
  sf::Texture texture;
  if (!texture.loadFromFile(file_name)) {
    std::cout << "Failed to load texture: " << texture_name << std::endl;
  } else {
    this->Textures_[texture_name] = texture;
  }
}

sf::Texture &AssetManager::GetTexture(const std::string &texture_name) {
  return this->Textures_.at(texture_name);
}

void AssetManager::LoadFont(const std::string &font_name,
                            const std::string &file_name) {
  sf::Font font;
  if (!font.loadFromFile(file_name)) {
    std::cout << "Failed to load font: " << font_name << std::endl;
  } else {
    this->Fonts_[font_name] = font;
  }
}

sf::Font &AssetManager::GetFont(const std::string &font_name) {
  return this->Fonts_.at(font_name);
}

void AssetManager::LoadSound(const std::string &file_name, sf::Sound &sound,
                             sf::SoundBuffer &sound_buffer) {
  if (!sound_buffer.loadFromFile(file_name)) {
    std::cout << "Failed to load sound buffer: " << file_name << std::endl;
    return;
  }
  sound.setBuffer(sound_buffer);
}

} // namespace Game
