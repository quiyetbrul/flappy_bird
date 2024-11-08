set(PIPE
    Pipe.cpp
)

add_library(pipe ${PIPE})
target_include_directories(pipe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(pipe PUBLIC game_loop land utils)
