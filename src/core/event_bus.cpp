#include "../../include/core/event_bus.h"
#include <iostream>

namespace pm {

void EventBus::subscribe(const std::string& event_type, EventHandler handler) {
    subscribers[event_type].push_back(handler);
    std::cout << "[EventBus] Subscribed to: " << event_type << std::endl;
}

void EventBus::emit(const std::string& event_type, const std::string& data) {
    std::cout << "[EventBus] Emitting: " << event_type << " | Data: " << data << std::endl;
    
    auto it = subscribers.find(event_type);
    if (it != subscribers.end()) {
        Event event{event_type, data};
        for (auto& handler : it->second) {
            handler(event);
        }
    }
}

} // namespace pm
