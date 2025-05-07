# RUD
RUD is a rendering/game engine that utilizes modern graphics APIs (GAPIs) for
achieving maximum performance and real-time framerates. RUD currently supports
Vulkan, DirectX12, and DirectX11 by leveraging the
[NVRHI](https://github.com/NVIDIA-RTX/NVRHI) hardware interface by NVidia.

## Requirements
There are a few things necessary to get RUD to properly build:
- CMake >=3.14
- A C++ compiler (clang was used during development, but any should work)

## Dependencies
- [assimp](https://github.com/assimp/assimp):
For importing a wide variety of 3D model formats
- [DirectXShaderCompiler](https://github.com/microsoft/DirectXShaderCompiler):
For compiling HLSL shader code into SPIR-V for Vulkan and DXIL for DirectX12
- [GLFW](https://github.com/glfw/glfw):
For windowing and input handling
- [glm](https://github.com/g-truc/glm):
For 3D math
- [imgui](https://github.com/ocornut/imgui):
For an easy to use and extensible GUI system
- [NVRHI](https://github.com/NVIDIA-RTX/NVRHI):
An easy to use GAPI abstraction for Vulkan, DirectX12, and DirectX11
- [spdlog](https://github.com/gabime/spdlog):
A fast and highly configurable logging library
- [stb](https://github.com/nothings/stb)
Provides a plethora of useful utilities, primarily used for loading textures
