set(GAME_OVER
    GameOverState.cpp
)

add_library(game_over ${GAME_OVER})
target_include_directories(game_over PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(game_over PUBLIC game_loop state_machine utils)
