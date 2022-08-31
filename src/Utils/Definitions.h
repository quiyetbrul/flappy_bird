#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define GAME_TITLE "Flappy Bird - Quiyet Brul"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 0.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "assets/sprites/SplashBackground.png"

#define MENU_BACKGROUND_FILEPATH "assets/sprites/sky.png"
#define GAME_BACKGROUND_FILEPATH "assets/sprites/sky.png"
#define GAMEOVER_BACKGROUND_FILEPATH "assets/sprites/sky.png"

#define LAND_FILEPATH "assets/sprites/land.png"
#define LAND_MOVEMENT_SPEED 200.0f

#define GAME_TITLE_FILEPATH "assets/sprites/title.png"
#define PLAY_BUTTON_FILEPATH "assets/sprites/PlayButton.png"

#define PIPE_UP_FILEPATH "assets/sprites/PipeUp.png"
#define PIPE_DOWN_FILEPATH "assets/sprites/PipeDown.png"
#define PIPE_SCORING_FILEPATH "assets/sprites/InvisibleScoringPipe.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f

#define BIRD_FRAME_1_FILEPATH "assets/sprites/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "assets/sprites/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "assets/sprites/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "assets/sprites/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_ROTATION_SPEED 100.0f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define BIRD_FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define GRAVITY 350.0f

#define FLASH_SPEED 1500.0f

#define FLAPPY_FONT_FILEPATH "assets/fonts/FlappyFont.ttf"

#define GAME_OVER_TITLE_FILEPATH "assets/sprites/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "assets/sprites/Game-Over-Body.png"

#define HIGHSCORE_FILEPATH "assets/HighScore.txt"

enum GameStates { eReady, ePlaying, eGameOver }; // enum GameStates

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#endif // DEFINITIONS_H
