#include "core/engine.h"
#include "modules/scene_module.h"
#include <iostream>
#include <memory>

using namespace pm;

int main() {
    std::cout << "\n========== PolyMaster Engine ==========\n" << std::endl;
    
    Engine engine;
    engine.initialize(1920, 1080);
    
    engine.registerModule("scene", std::make_shared<SceneModule>());
    
    SceneModule* scene = static_cast<SceneModule*>(engine.getModule("scene"));
    Mesh* mesh = scene->getMesh();
    
    std::cout << "✅ Mesh: " << mesh->name << std::endl;
    std::cout << "✅ Vertices: " << mesh->vertices.size() << std::endl;
    std::cout << "✅ Faces: " << mesh->faces.size() << std::endl;
    
    for (int i = 0; i < 5; i++) {
        engine.update(0.016f);
        engine.render();
    }
    
    std::cout << "\n✅ SUCCESS - PolyMaster Core Works!\n" << std::endl;
    return 0;
}
