cmake_minimum_required(VERSION 3.14)

# Project
project(
    RUD
    VERSION 0.1.0
    LANGUAGES CXX
)

# Options
option(RUD_BUILD_SHARED "Build RUD as a shared library (.dll/.so)" OFF)
option(RUD_BUILD_EXAMPLES "Build the examples that come with RUD" ON)

if(RUD_BUILD_SHARED)
    set(BUILD_SHARED_LIBS ON)
else()
    set(BUILD_SHARED_LIBS OFF)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Include guards
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
            "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

# Add dependencies
add_subdirectory(thirdparty)

# Add source files

# NOTE: GLOB_RECURSE is a bad practice since it may not detect new files
# automatically.
file(GLOB_RECURSE headers CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/_impl.cpp"
)

# Create library
add_library(${PROJECT_NAME} ${headers} ${sources})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

if(RUD_BUILD_SHARED)
    set_target_properties(
        ${PROJECT_NAME} PROPERTIES CMAKE_POSITION_INDEPENDENT_CODE ON
    )
endif()

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(
    ${PROJECT_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->"
)

# Link dependencies

# Note that nvrhi_vk/_dx12/_dx11 must come before the main nvrhi for static
# libraries
target_link_libraries(${PROJECT_NAME} PRIVATE nvrhi_vk)
target_link_libraries(
    ${PROJECT_NAME} PRIVATE assimp glfw glm::glm nvrhi spdlog::spdlog
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
           $<INSTALL_INTERFACE:include/rud> # <prefix>/include/rud
)

# Build examples

# This must be done after RUD has been built
if(RUD_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
