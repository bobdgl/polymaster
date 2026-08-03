#include "../../include/modules/renderer_module.h"
#include <iostream>

namespace pm {

void RendererModule::initialize() {
    std::cout << "[RendererModule] Initializing (stub mode)..." << std::endl;
}

void RendererModule::update(float deltaTime) {
}

void RendererModule::shutdown() {
    std::cout << "[RendererModule] Shutdown" << std::endl;
}

} // namespace pm
