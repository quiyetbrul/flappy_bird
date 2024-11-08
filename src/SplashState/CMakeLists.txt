set(SPLASH_STATE
    SplashState.cpp
)

add_library(splash_state ${SPLASH_STATE})
target_include_directories(splash_state PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(splash_state PUBLIC game_loop menu_state state_machine utils)
