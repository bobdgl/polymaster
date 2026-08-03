#ifndef POLYMASTER_INPUT_MODULE_H
#define POLYMASTER_INPUT_MODULE_H

#include "../core/module.h"

namespace pm {

class InputModule : public Module {
public:
    void initialize() override;
    void update(float deltaTime) override;
    void shutdown() override;
    std::string getName() const override { return "input"; }
};

} // namespace pm

#endif
