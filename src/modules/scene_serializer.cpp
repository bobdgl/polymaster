#include "../../include/modules/scene_serializer.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace pm {

bool SceneSerializer::saveToJSON(const Mesh& mesh, const std::string& filename) {
    std::cout << "[SceneSerializer] Saving to: " << filename << std::endl;
    
    json j;
    j["mesh_name"] = mesh.name;
    j["vertices_count"] = mesh.vertices.size();
    j["faces_count"] = mesh.faces.size();
    
    // Сохраняем вершины
    json vertices_array = json::array();
    for (const auto& v : mesh.vertices) {
        json vertex = {
            {"x", v.position.x},
            {"y", v.position.y},
            {"z", v.position.z},
            {"nx", v.normal.x},
            {"ny", v.normal.y},
            {"nz", v.normal.z},
            {"u", v.uv.x},
            {"v", v.uv.y},
            {"selected", v.selected}
        };
        vertices_array.push_back(vertex);
    }
    j["vertices"] = vertices_array;
    
    // Сохраняем грани
    json faces_array = json::array();
    for (const auto& f : mesh.faces) {
        json face = {
            {"v1", f.v1},
            {"v2", f.v2},
            {"v3", f.v3},
            {"nx", f.normal.x},
            {"ny", f.normal.y},
            {"nz", f.normal.z},
            {"selected", f.selected}
        };
        faces_array.push_back(face);
    }
    j["faces"] = faces_array;
    
    // Пишем в файл
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[SceneSerializer] Failed to open file for writing" << std::endl;
        return false;
    }
    
    file << j.dump(2);
    file.close();
    
    std::cout << "[SceneSerializer] Saved successfully!" << std::endl;
    return true;
}

bool SceneSerializer::loadFromJSON(Mesh& mesh, const std::string& filename) {
    std::cout << "[SceneSerializer] Loading from: " << filename << std::endl;
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[SceneSerializer] Failed to open file for reading" << std::endl;
        return false;
    }
    
    json j;
    file >> j;
    file.close();
    
    mesh.name = j["mesh_name"];
    
    // Загружаем вершины
    mesh.vertices.clear();
    for (const auto& v_json : j["vertices"]) {
        Vertex v;
        v.position = {v_json["x"], v_json["y"], v_json["z"]};
        v.normal = {v_json["nx"], v_json["ny"], v_json["nz"]};
        v.uv = {v_json["u"], v_json["v"]};
        v.selected = v_json["selected"];
        mesh.vertices.push_back(v);
    }
    
    // Загружаем грани
    mesh.faces.clear();
    for (const auto& f_json : j["faces"]) {
        Face f;
        f.v1 = f_json["v1"];
        f.v2 = f_json["v2"];
        f.v3 = f_json["v3"];
        f.normal = {f_json["nx"], f_json["ny"], f_json["nz"]};
        f.selected = f_json["selected"];
        mesh.faces.push_back(f);
    }
    
    std::cout << "[SceneSerializer] Loaded: " 
              << mesh.vertices.size() << " vertices, "
              << mesh.faces.size() << " faces" << std::endl;
    return true;
}

} // namespace pm
