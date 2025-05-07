cmake_minimum_required(VERSION 3.14)

project(testing LANGUAGES CXX)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} RUD)
