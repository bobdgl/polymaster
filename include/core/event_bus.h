#ifndef POLYMASTER_EVENT_BUS_H
#define POLYMASTER_EVENT_BUS_H

#include <string>
#include <functional>
#include <vector>
#include <map>

namespace pm {

struct Event {
    std::string type;
    std::string data;
};

using EventHandler = std::function<void(const Event&)>;

class EventBus {
public:
    // Подписаться на событие
    void subscribe(const std::string& event_type, EventHandler handler);
    
    // Отправить событие
    void emit(const std::string& event_type, const std::string& data = "");

private:
    std::map<std::string, std::vector<EventHandler>> subscribers;
};

} // namespace pm

#endif
