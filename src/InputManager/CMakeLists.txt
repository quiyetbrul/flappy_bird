set(INPUT_MANAGER
    InputManager.cpp
)

add_library(input_manager ${INPUT_MANAGER})
target_include_directories(input_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(input_manager PUBLIC sfml-system sfml-window sfml-graphics sfml-audio)
