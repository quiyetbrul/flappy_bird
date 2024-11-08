#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <map>

namespace Game {
class AssetManager {
public:
  AssetManager() = default;
  ~AssetManager() = default;

  void LoadTexture(const std::string &texture_name,
                   const std::string &file_name);
  sf::Texture &GetTexture(const std::string &texture_name);

  void LoadFont(const std::string &font_name, const std::string &file_name);
  sf::Font &GetFont(const std::string &font_name);

  void LoadSound(const std::string &file_name, sf::Sound &sound,
                 sf::SoundBuffer &sound_buffer);
  sf::Sound &GetSound(const std::string &font_name);

private:
  std::map<std::string, sf::Texture> Textures_;
  std::map<std::string, sf::Font> Fonts_;
};
} // namespace Game

#endif // ASSET_MANAGER_H
