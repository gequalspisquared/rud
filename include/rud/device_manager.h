#pragma once

#include <nvrhi/nvrhi.h>

#include <string>
#include <vector>

namespace rud {

struct InstanceParameters {
    // debug runtime
    // warnings as errors

    bool enable_gpu_validation = false;
    bool headless = false;

    // heap directly indexed (allow ResourceDescriptorHeap for DX12)

#if RUD_WITH_VK
    std::vector<std::string> required_vk_instance_extensions;
    std::vector<std::string> required_vk_layers;
    std::vector<std::string> optional_vk_instance_extensions;
    std::vector<std::string> optional_vk_layers;
#endif
};

struct DeviceCreationParameters : public InstanceParameters {
    bool start_maximized = false;
    bool start_fullscreen = false;

    // start borderless
    // allow mode switch
    // window pos x & y
    // refresh rate
    // swapchain buffer count
    // swapchain sample quality
    // max frames in flight

    bool enable_nvrhi_validation_layer = false;
    bool enable_vsync = false;
    bool enable_ray_tracing_extensions = false; // Vk only
    bool enable_compute_queue = false;
    bool enable_transfer_queue = false;

#if RUD_WITH_VK
    std::vector<std::string> required_vk_device_extensions;
    std::vector<std::string> optional_vk_device_extensions;
#endif
};

class DeviceManager {
public:
    static DeviceManager *create(nvrhi::GraphicsAPI api);

private:
};

} //namespace rud
