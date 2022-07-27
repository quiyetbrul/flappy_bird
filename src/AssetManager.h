#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "include/SFML/Graphics.hpp"
#include <map>

namespace Game {
class AssetManager {
public:
  AssetManager(){};
  ~AssetManager(){};

  void LoadTexture(std::string texture_name, std::string file_name);
  sf::Texture &GetTexture(std::string texture_name);

  void LoadFont(std::string font_name, std::string file_name);
  sf::Font &GetFont(std::string font_name);

private:
  std::map<std::string, sf::Texture> Textures_;
  std::map<std::string, sf::Font> Fonts_;
};
} // namespace Game

#endif // ASSET_MANAGER_H
