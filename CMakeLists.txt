cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

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

# # Include FetchContent module
# include(FetchContent)

# # Define SFML
# FetchContent_Declare(
#   SFML
#   GIT_REPOSITORY https://github.com/SFML/SFML.git
#   GIT_TAG 2.5.1 # Specify the version you need
# )

# # Download SFML if not found
# FetchContent_GetProperties(SFML)
# if(NOT sfml_POPULATED)
#   FetchContent_Populate(SFML)
#   add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
# endif()

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

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

add_subdirectory(src/AssetManager)
add_subdirectory(src/Bird)
add_subdirectory(src/Collision)
add_subdirectory(src/Flash)
add_subdirectory(src/GameLoop)
add_subdirectory(src/GameOverState)
add_subdirectory(src/GameState)
add_subdirectory(src/HUD)
add_subdirectory(src/InputManager)
add_subdirectory(src/Land)
add_subdirectory(src/MenuState)
add_subdirectory(src/Pipe)
add_subdirectory(src/SplashState)
add_subdirectory(src/StateMachine)
add_subdirectory(src/Utils)

add_executable(${PROJECT_NAME}
                              src/main.cpp
                              )

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

target_link_libraries(${PROJECT_NAME} PUBLIC
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio

    asset_manager
    bird
    collision
    flash
    game_loop
    game_over
    game_state
    hud
    input_manager
    land
    menu_state
    pipe
    splash_state
    state_machine
    utils
)

# Set executable install location
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Set install location for resources
install(DIRECTORY assets
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)
