set(COLLISION
    Collision.cpp
)

add_library(collision ${COLLISION})
target_include_directories(collision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(collision PUBLIC game_loop utils)
