#ifndef POLYMASTER_MODULE_H
#define POLYMASTER_MODULE_H

#include <string>

namespace pm {

class Module {
public:
    virtual ~Module() = default;
    
    virtual void initialize() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void shutdown() = 0;
    virtual std::string getName() const = 0;
};

} // namespace pm

#endif
