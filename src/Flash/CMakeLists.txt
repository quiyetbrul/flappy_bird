set(FLASH
    flash.cpp
)

add_library(flash ${FLASH})
target_include_directories(flash PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(flash PUBLIC asset_manager game_loop utils)
