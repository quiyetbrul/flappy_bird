set(GAME_LOOP
    game.cpp
)

add_library(game_loop ${GAME_LOOP})
target_include_directories(game_loop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(game_loop PUBLIC asset_manager input_manager state_machine)
