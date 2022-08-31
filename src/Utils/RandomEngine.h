#ifndef RANDOM_ENGINE_H
#define RANDOM_ENGINE_H

#include <random>

namespace Game {
class RandomEngine {
public:
  RandomEngine()
      : m_Generator_(m_Random_Device_()), m_Distribution_(-50, 5000) {}
  int GenerateRandomNumber() { return m_Distribution_(m_Generator_); }

private:
  std::random_device m_Random_Device_;
  std::mt19937 m_Generator_;
  std::uniform_int_distribution<int> m_Distribution_;
};
} // namespace Game

#endif // RANDOM_ENGINE_H
