#include "../../include/core/engine.h"
#include <iostream>

namespace pm {

void Engine::initialize(uint32_t width, uint32_t height) {
    screen_width = width;
    screen_height = height;
    is_initialized = true;
    
    std::cout << "[Engine] Initialized: " << width << "x" << height << std::endl;
}

void Engine::update(float deltaTime) {
    // Обновляем все модули
    for (auto& [name, module] : modules) {
        module->update(deltaTime);
    }
}

void Engine::render() {
    // Рендерим кадр
    std::cout << "[Engine] Rendering frame..." << std::endl;
}

void Engine::registerModule(const std::string& name, std::shared_ptr<Module> module) {
    modules[name] = module;
    module->initialize();
    std::cout << "[Engine] Registered module: " << name << std::endl;
}

Module* Engine::getModule(const std::string& name) {
    auto it = modules.find(name);
    if (it != modules.end()) {
        return it->second.get();
    }
    return nullptr;
}

void Engine::emitEvent(const std::string& type, const std::string& data) {
    event_bus.emit(type, data);
}

void Engine::subscribe(const std::string& type, EventHandler handler) {
    event_bus.subscribe(type, handler);
}

ViewMode Engine::getViewMode() const {
    return current_view_mode;
}

void Engine::setViewMode(ViewMode mode) {
    current_view_mode = mode;
    emitEvent("view_mode_changed", 
        "Mode: " + std::to_string(static_cast<int>(mode)));
}

} // namespace pm
