#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
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

private:
  std::map<std::string, sf::Texture> Textures_;
  std::map<std::string, sf::Font> Fonts_;
};
} // namespace Game

#endif // ASSET_MANAGER_H
