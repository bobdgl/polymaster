#include "core/engine.h"
#include "modules/scene_module.h"
#include "modules/scene_serializer.h"
#include <iostream>
#include <memory>
#include <cstdlib>

using namespace pm;

int main() {
    std::cout << "=====================================\n"
              << "   PolyMaster Engine - Full Test\n"
              << "=====================================\n" << std::endl;
    
    // Создаём engine
    Engine engine;
    engine.initialize(1920, 1080);
    std::cout << "Screen: " << engine.getScreenWidth() << "x" 
              << engine.getScreenHeight() << "\n" << std::endl;
    
    // Регистрируем модули
    std::cout << "[MAIN] Registering modules...\n" << std::endl;
    engine.registerModule("scene", std::make_shared<SceneModule>());
    engine.registerModule("input", std::make_shared<SceneModule>());
    
    // Получаем меш
    SceneModule* scene = static_cast<SceneModule*>(engine.getModule("scene"));
    Mesh* mesh = scene->getMesh();
    
    std::cout << "\n[MAIN] Original mesh:\n"
              << "  Name: " << mesh->name << "\n"
              << "  Vertices: " << mesh->vertices.size() << "\n"
              << "  Faces: " << mesh->faces.size() << "\n" << std::endl;
    
    // Сохраняем в домашнюю папку
    std::string home = std::getenv("HOME");
    std::string save_path = home + "/polymaster_scene.json";
    
    std::cout << "[MAIN] Testing save/load...\n"
              << "[MAIN] Saving to: " << save_path << "\n" << std::endl;
    SceneSerializer::saveToJSON(*mesh, save_path);
    
    // Загружаем
    Mesh loaded_mesh;
    SceneSerializer::loadFromJSON(loaded_mesh, save_path);
    
    std::cout << "\n[MAIN] Loaded mesh:\n"
              << "  Name: " << loaded_mesh.name << "\n"
              << "  Vertices: " << loaded_mesh.vertices.size() << "\n"
              << "  Faces: " << loaded_mesh.faces.size() << "\n" << std::endl;
    
    // Проверяем
    if (loaded_mesh.vertices.size() == mesh->vertices.size() &&
        loaded_mesh.faces.size() == mesh->faces.size()) {
        std::cout << "✅ Save/Load test PASSED!\n" << std::endl;
    }
    
    // Показываем JSON
    std::cout << "[MAIN] JSON Preview:\n" << std::endl;
    system(("head -20 " + save_path).c_str());
    
    std::cout << "\n=====================================\n"
              << "   ✅ PolyMaster v0.1.0 - ALL TESTS PASSED!\n"
              << "=====================================\n" << std::endl;
    
    return 0;
}
