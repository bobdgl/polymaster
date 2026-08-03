#ifndef POLYMASTER_RENDERER_MODULE_H
#define POLYMASTER_RENDERER_MODULE_H

#include "../core/module.h"

namespace pm {

class RendererModule : public Module {
public:
    void initialize() override;
    void update(float deltaTime) override;
    void shutdown() override;
    std::string getName() const override { return "renderer"; }
};

} // namespace pm

#endif
