set(STATE_MACHINE
    StateMachine.cpp
)

add_library(state_machine ${STATE_MACHINE})
target_include_directories(state_machine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(state_machine PUBLIC utils)
