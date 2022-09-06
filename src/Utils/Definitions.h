#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>

const std::string GAME_TITLE = "Flappy Bird - Quiyet Brul";

const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 1024;

const float SPLASH_STATE_SHOW_TIME = 0.0f;
const std::string SPLASH_SCENE_BACKGROUND_FILEPATH =
    "../assets/sprites/SplashBackground.png";

const std::string MENU_BACKGROUND_FILEPATH =  "../assets/sprites/sky.png";
const std::string GAME_BACKGROUND_FILEPATH = "../assets/sprites/sky.png";
const std::string GAMEOVER_BACKGROUND_FILEPATH = "../assets/sprites/sky.png";

const std::string LAND_FILEPATH = "../assets/sprites/land.png";
const float LAND_MOVEMENT_SPEED = 200.0f;

const std::string GAME_TITLE_FILEPATH = "../assets/sprites/title.png";
const std::string PLAY_BUTTON_FILEPATH = "../assets/sprites/PlayButton.png";

const std::string PIPE_UP_FILEPATH = "../assets/sprites/PipeUp.png";
const std::string PIPE_DOWN_FILEPATH = "../assets/sprites/PipeDown.png";
const std::string PIPE_SCORING_FILEPATH =
    "../assets/sprites/InvisibleScoringPipe.png";
const float PIPE_MOVEMENT_SPEED = 200.0f;
const float PIPE_SPAWN_FREQUENCY = 3.0f;

const std::string BIRD_FRAME_1_FILEPATH = "../assets/sprites/bird-01.png";
const std::string BIRD_FRAME_2_FILEPATH = "../assets/sprites/bird-02.png";
const std::string BIRD_FRAME_3_FILEPATH = "../assets/sprites/bird-03.png";
const std::string BIRD_FRAME_4_FILEPATH = "../assets/sprites/bird-04.png";
const float BIRD_ANIMATION_DURATION = 0.4f;
const float BIRD_ROTATION_SPEED = 100.0f;
const int BIRD_STATE_STILL = 1;
const int BIRD_STATE_FALLING = 2;
const int BIRD_STATE_FLYING = 3;
const float BIRD_FLYING_SPEED = 350.0f;
const float FLYING_DURATION = 0.25f;
const float GRAVITY = 350.0f;

const float FLASH_SPEED = 1500.0f;

const std::string FLAPPY_FONT_FILEPATH = "../assets/fonts/FlappyFont.ttf";

const std::string GAME_OVER_TITLE_FILEPATH =
    "../assets/sprites/Game-Over-Title.png";
const std::string GAME_OVER_BODY_FILEPATH = "../assets/sprites/Game-Over-Body.png";

const std::string HIGHSCORE_FILEPATH = "../assets/HighScore.txt";

enum GameStates { eReady, ePlaying, eGameOver }; // enum GameStates

const float TIME_BEFORE_GAME_OVER_APPEARS = 1.5f;

#endif // DEFINITIONS_H
