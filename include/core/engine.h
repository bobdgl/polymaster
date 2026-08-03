#ifndef POLYMASTER_ENGINE_H
#define POLYMASTER_ENGINE_H

#include "event_bus.h"
#include "module.h"
#include "../data/types.h"
#include <map>
#include <memory>

namespace pm {

class Engine {
public:
    // Инициализация
    void initialize(uint32_t width, uint32_t height);
    
    // Главный цикл
    void update(float deltaTime);
    void render();
    
    // Управление модулями
    void registerModule(const std::string& name, std::shared_ptr<Module> module);
    Module* getModule(const std::string& name);
    
    // События
    void emitEvent(const std::string& type, const std::string& data = "");
    void subscribe(const std::string& type, EventHandler handler);
    
    // Режимы отображения
    ViewMode getViewMode() const;
    void setViewMode(ViewMode mode);
    
    // Состояние
    uint32_t getScreenWidth() const { return screen_width; }
    uint32_t getScreenHeight() const { return screen_height; }
    bool isInitialized() const { return is_initialized; }

private:
    uint32_t screen_width = 0;
    uint32_t screen_height = 0;
    ViewMode current_view_mode = ViewMode::FACE;
    bool is_initialized = false;
    
    EventBus event_bus;
    std::map<std::string, std::shared_ptr<Module>> modules;
};

} // namespace pm

#endif
