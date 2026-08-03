#ifndef POLYMASTER_TRANSFORM_MODULE_H
#define POLYMASTER_TRANSFORM_MODULE_H

#include "../core/module.h"
#include "../data/types.h"

namespace pm {

class TransformModule : public Module {
public:
    void initialize() override;
    void update(float deltaTime) override;
    void shutdown() override;
    std::string getName() const override { return "transform"; }
};

} // namespace pm

#endif
