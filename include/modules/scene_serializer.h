#ifndef POLYMASTER_SCENE_SERIALIZER_H
#define POLYMASTER_SCENE_SERIALIZER_H

#include "../data/types.h"
#include <string>

namespace pm {

class SceneSerializer {
public:
    static bool saveToJSON(const Mesh& mesh, const std::string& filename);
    static bool loadFromJSON(Mesh& mesh, const std::string& filename);
};

} // namespace pm

#endif
