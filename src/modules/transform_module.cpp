#include "../../include/modules/transform_module.h"
#include <iostream>

namespace pm {

void TransformModule::initialize() {
    std::cout << "[TransformModule] Initializing..." << std::endl;
}

void TransformModule::update(float deltaTime) {}

void TransformModule::shutdown() {
    std::cout << "[TransformModule] Shutting down..." << std::endl;
}

} // namespace pm
