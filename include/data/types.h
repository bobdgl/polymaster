#ifndef POLYMASTER_TYPES_H
#define POLYMASTER_TYPES_H

#include <vector>
#include <glm/glm.hpp>
#include <memory>

namespace pm {

// Вершина
struct Vertex {
    glm::vec3 position;     // x, y, z
    glm::vec3 normal;       // нормаль
    glm::vec2 uv;          // текстурные координаты
    bool selected = false;  // выбрана ли
};

// Грань (полигон)
struct Face {
    uint32_t v1, v2, v3;   // индексы вершин
    glm::vec3 normal;      // нормаль грани
    bool selected = false;
};

// Ребро
struct Edge {
    uint32_t v1, v2;       // индексы вершин
    bool selected = false;
};

// Сетка (меш)
struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
    std::vector<Edge> edges;
    std::string name;
};

// Трансформация
struct Transform {
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 rotation = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);
    glm::mat4 matrix = glm::mat4(1.0f);
};

// Режимы отображения
enum class ViewMode {
    FACE = 0,
    EDGE = 1,
    VERTEX = 2
};

// Состояние выделения
struct SelectionState {
    std::vector<uint32_t> selected_ids;
    ViewMode type = ViewMode::FACE;
    uint32_t count = 0;
};

} // namespace pm

#endif
