cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

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
