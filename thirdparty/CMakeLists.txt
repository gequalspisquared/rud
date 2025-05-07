# assimp
set(ASSIMP_BUILD_TESTS
    OFF
    CACHE BOOL ""
)
set(ASSIMP_INSTALL
    OFF
    CACHE BOOL ""
)
set(ASSIMP_WARNINGS_AS_ERRORS
    OFF
    CACHE BOOL ""
)
add_subdirectory(assimp)

# DirectXShaderCompiler set(LLVM_ENABLE_PROJECTS "clang;lld" CACHE STRING ""
# FORCE ) set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "" FORCE ) set(BUILD_TESTING OFF
# CACHE BOOL "" FORCE ) set(LLVM_ENABLE_WARNINGS OFF CACHE BOOL "" FORCE )
# set(DXC_BUILD_SHARED_LIBS OFF # RUD_BUILD_SHARED CACHE BOOL "" FORCE )
# include(
# "${CMAKE_CURRENT_SOURCE_DIR}/DirectXShaderCompiler/cmake/caches/PredefinedParams.cmake"
# ) add_subdirectory(DirectXShaderCompiler)

# glfw
set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "" FORCE
)
set(GLFW_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE
)
set(GLFW_BUILD_EXAMPLES
    OFF
    CACHE BOOL "" FORCE
)
set(GLFW_INSTALL
    OFF
    CACHE BOOL "" FORCE
)
add_subdirectory(glfw)

# glm
set(GLM_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE
)
add_subdirectory(glm)

# imgui

# NVRHI
set(NVRHI_WITH_VULKAN
    ON
    CACHE BOOL "" FORCE
)
set(NVRHI_WITH_DX12
    OFF
    CACHE BOOL "" FORCE
)
set(NVRHI_WITH_DX11
    OFF
    CACHE BOOL "" FORCE
)
set(NVRHI_BUILD_SHARED
    OFF
    # RUD_BUILD_SHARED
    CACHE BOOL "" FORCE
)
set(NVRHI_INSTALL
    OFF
    CACHE BOOL "" FORCE
)
add_subdirectory(NVRHI)

# spdlog
set(SPDLOG_BUILD_SHARED
    OFF
    # RUD_BUILD_SHARED
    CACHE BOOL "" FORCE
)
add_subdirectory(spdlog)

# stb
