#include "../../include/modules/scene_module.h"
#include <iostream>
#include <glm/glm.hpp>

namespace pm {

void SceneModule::initialize() {
    std::cout << "[SceneModule] Initializing..." << std::endl;
    createDefaultCube();
    initialized = true;
}

void SceneModule::update(float deltaTime) {
    if (initialized) {
        // Обновляем сцену
    }
}

void SceneModule::shutdown() {
    std::cout << "[SceneModule] Shutting down..." << std::endl;
    initialized = false;
}

void SceneModule::createDefaultCube() {
    default_mesh.name = "Cube";
    
    // Создаём куб (8 вершин)
    default_mesh.vertices = {
        {{-1, -1, -1}, {0, 0, -1}, {0, 0}},
        {{1, -1, -1}, {0, 0, -1}, {1, 0}},
        {{1, 1, -1}, {0, 0, -1}, {1, 1}},
        {{-1, 1, -1}, {0, 0, -1}, {0, 1}},
        {{-1, -1, 1}, {0, 0, 1}, {0, 0}},
        {{1, -1, 1}, {0, 0, 1}, {1, 0}},
        {{1, 1, 1}, {0, 0, 1}, {1, 1}},
        {{-1, 1, 1}, {0, 0, 1}, {0, 1}},
    };
    
    // 12 полигонов (6 граней * 2 треугольника)
    default_mesh.faces = {
        // Front
        {0, 1, 2}, {0, 2, 3},
        // Back
        {4, 6, 5}, {4, 7, 6},
        // Left
        {4, 0, 3}, {4, 3, 7},
        // Right
        {1, 5, 6}, {1, 6, 2},
        // Top
        {3, 2, 6}, {3, 6, 7},
        // Bottom
        {4, 5, 1}, {4, 1, 0}
    };
    
    std::cout << "[SceneModule] Default cube created: "
              << default_mesh.vertices.size() << " vertices, "
              << default_mesh.faces.size() << " faces" << std::endl;
}

Mesh* SceneModule::getMesh() {
    return &default_mesh;
}

} // namespace pm
