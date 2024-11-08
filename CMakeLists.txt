cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# set project name and version
project (flappy_bird)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING
      "Choose the type of build (Debug or Release)" FORCE)
endif()

# Export compile commands for completion engines (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(${PROJECT_NAME}
                              src/Main/main.cpp
                              src/AssetManager/AssetManager.cpp
                              src/Bird/Bird.cpp
                              src/Collision/Collision.cpp
                              src/Flash/Flash.cpp
                              src/GameLoop/Game.cpp
                              src/GameOverState/GameOverState.cpp
                              src/GameState/GameState.cpp
                              src/HUD/HUD.cpp
                              src/InputManager/InputManager.cpp
                              src/Land/Land.cpp
                              src/MenuState/MenuState.cpp
                              src/Pipe/Pipe.cpp
                              src/SplashState/SplashState.cpp
                              src/StateMachine/StateMachine.cpp
                              src/Utils/Utils.cpp)

add_definitions(-DSPLASH_SCENE_BACKGROUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/SplashBackground.png\")
add_definitions(-DMENU_BACKGROUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/sky.png\")
add_definitions(-DGAME_BACKGROUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/sky.png\")
add_definitions(-DGAMEOVER_BACKGROUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/sky.png\")
add_definitions(-DLAND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/land.png\")
add_definitions(-DGAME_TITLE_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/title.png\")
add_definitions(-DPLAY_BUTTON_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/PlayButton.png\")
add_definitions(-DPIPE_UP_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/PipeUp.png\")
add_definitions(-DPIPE_DOWN_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/PipeDown.png\")
add_definitions(-DPIPE_SCORING_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/InvisibleScoringPipe.png\")
add_definitions(-DBIRD_FRAME_1_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/bird-01.png\")
add_definitions(-DBIRD_FRAME_2_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/bird-02.png\")
add_definitions(-DBIRD_FRAME_3_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/bird-03.png\")
add_definitions(-DBIRD_FRAME_4_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/bird-04.png\")
add_definitions(-DFLAPPY_FONT_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/fonts/FlappyFont.ttf\")
add_definitions(-DGAME_OVER_TITLE_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/Game-Over-Title.png\")
add_definitions(-DGAME_OVER_BODY_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/Game-Over-Body.png\")
add_definitions(-DBRONZE_MEDAL_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/Bronze-Medal.png\")
add_definitions(-DSILVER_MEDAL_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/Silver-Medal.png\")
add_definitions(-DGOLD_MEDAL_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/Gold-Medal.png\")
add_definitions(-DPLATINUM_MEDAL_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/sprites/Platinum-Medal.png\")
add_definitions(-DHIGHSCORE_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/HighScore.txt\")
add_definitions(-DHIT_SOUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/audio/Hit.wav\")
add_definitions(-DPOINT_SOUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/audio/Point.wav\")
add_definitions(-DWING_SOUND_FILEPATH=\"${CMAKE_SOURCE_DIR}/assets/audio/Wing.wav\")

# Using INSTALL_RPATH_USE_LINK_PATH
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    INSTALL_RPATH_USE_LINK_PATH TRUE)

# Set executable RPATH
set_target_properties(${PROJECT_NAME}
  PROPERTIES
      INSTALL_RPATH
        "${CMAKE_INSTALL_PREFIX}/lib"
  )

target_link_libraries(${PROJECT_NAME}
                                    sfml-system
                                    sfml-window
                                    sfml-graphics
                                    sfml-audio)

# Set executable install location
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Set install location for resources
install(DIRECTORY assets
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)
