#ifndef POLYMASTER_SCENE_MODULE_H
#define POLYMASTER_SCENE_MODULE_H

#include "../core/module.h"
#include "../data/types.h"

namespace pm {

class SceneModule : public Module {
public:
    void initialize() override;
    void update(float deltaTime) override;
    void shutdown() override;
    std::string getName() const override { return "scene"; }
    
    void createDefaultCube();
    Mesh* getMesh();

private:
    Mesh default_mesh;
    bool initialized = false;
};

} // namespace pm

#endif
