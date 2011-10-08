project(opencv_examples)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)

add_executable(tile_two_images src/tile_two_images.cpp)

target_link_libraries(tile_two_images ${OpenCV_LIBS})

execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory
                        ${CMAKE_SOURCE_DIR}/data
                        ${CMAKE_BINARY_DIR}/data)
