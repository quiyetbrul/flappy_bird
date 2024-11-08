set(HUD
    HUD.cpp
)

add_library(hud ${HUD})
target_include_directories(hud PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(hud PUBLIC game_loop utils)
