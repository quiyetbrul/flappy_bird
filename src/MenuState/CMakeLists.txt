set(MENU_STATE
    MenuState.cpp
)

add_library(menu_state ${MENU_STATE})
target_include_directories(menu_state PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(menu_state PUBLIC game_loop game_state state_machine utils)
