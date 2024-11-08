set(GAME_STATE
    GameState.cpp
)

add_library(game_state ${GAME_STATE})
target_include_directories(game_state PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(game_state PUBLIC bird collision flash hud land pipe state_machine utils game_over)
