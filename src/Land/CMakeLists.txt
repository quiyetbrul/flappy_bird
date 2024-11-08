set(LAND
    Land.cpp
)

add_library(land ${LAND})
target_include_directories(land PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(land PUBLIC game_loop utils)
