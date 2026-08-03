#include "../../include/modules/input_module.h"
#include <iostream>

namespace pm {

void InputModule::initialize() {
    std::cout << "[InputModule] Initializing..." << std::endl;
}

void InputModule::update(float deltaTime) {}

void InputModule::shutdown() {
    std::cout << "[InputModule] Shutting down..." << std::endl;
}

} // namespace pm
