cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# set project name and version
project (flappy_bird)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME} src/Main/main.cpp)

add_subdirectory(src/AssetManager)
add_subdirectory(src/GameLoop)
add_subdirectory(src/GameOverState)
add_subdirectory(src/GameState)
add_subdirectory(src/InputManager)
add_subdirectory(src/Land)
add_subdirectory(src/MenuState)
add_subdirectory(src/Pipe)
add_subdirectory(src/SplashState)
add_subdirectory(src/StateMachine)
add_subdirectory(src/Utils)

target_link_libraries(${PROJECT_NAME} 
                                    AssetManager
                                    GameLoop
                                    GameOverState
                                    GameState
                                    InputManager
                                    Land
                                    MenuState
                                    Pipe
                                    SplashState
                                    StateMachine
                                    Utils)
