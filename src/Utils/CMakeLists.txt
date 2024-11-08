set(UTILS
    Utils.cpp
)

add_library(utils ${UTILS})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
