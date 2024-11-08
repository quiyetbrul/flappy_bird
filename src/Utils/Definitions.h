#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>
#include <utility>

const std::string GAME_TITLE = "Flappy Bird - Quiyet Brul";
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;
const float SPLASH_STATE_SHOW_TIME = 0.0f;
const float LAND_MOVEMENT_SPEED = 200.0f;
const float PIPE_MOVEMENT_SPEED = 200.0f;
const float PIPE_SPAWN_FREQUENCY = 3.0f;
const float BIRD_ANIMATION_DURATION = 0.4f;
const float BIRD_ROTATION_SPEED = 100.0f;
const int BIRD_STATE_STILL = 1;
const int BIRD_STATE_FALLING = 2;
const int BIRD_STATE_FLYING = 3;
const float BIRD_FLYING_SPEED = 350.0f;
const float FLYING_DURATION = 0.25f;
const float GRAVITY = 350.0f;
const float FLASH_SPEED = 1500.0f;
const std::pair<int, std::string> Medal_Score[4] = {
    std::make_pair(/*PLATINUM_MEDAL_SCORE*/ 100, "Platinum Medal"),
    std::make_pair(/*GOLD_MEDAL_SCORE*/ 25, "Gold Medal"),
    std::make_pair(/*SILVER_MEDAL_SCORE*/ 5, "Silver Medal"),
    std::make_pair(/*BRONZE_MEDAL_SCORE*/ 0, "Bronze Medal")};
enum GameStates { eReady, ePlaying, eGameOver }; // enum GameStates
const float TIME_BEFORE_GAME_OVER_APPEARS = 1.5f;

#endif // DEFINITIONS_H
