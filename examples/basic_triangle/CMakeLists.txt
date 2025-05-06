cmake_minimum_required(VERSION 3.14)

project(basic_triangle LANGUAGES CXX)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(basic_triangle ${sources})
target_link_libraries(basic_triangle RUD)
