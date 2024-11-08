set(ASSET_MANAGER
    AssetManager.cpp
)

add_library(asset_manager ${ASSET_MANAGER})
target_include_directories(asset_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(asset_manager PUBLIC sfml-system sfml-window sfml-graphics sfml-audio)
