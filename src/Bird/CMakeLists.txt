set(BIRD
    bird.cpp
)

add_library(bird ${BIRD})
target_include_directories(asset_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(bird PUBLIC game_loop utils)
