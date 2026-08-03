cmake_minimum_required(VERSION 3.16)
project(PolyMaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLM_INCLUDE_DIR /usr/include)

include_directories(${GLM_INCLUDE_DIR} /usr/include)

# Главное ядро БЕЗ scene_serializer для GitHub Actions
set(POLYMASTER_SOURCES
    src/core/engine.cpp
    src/core/event_bus.cpp
    src/modules/scene_module.cpp
    src/modules/input_module.cpp
    src/modules/transform_module.cpp
    src/modules/renderer_module.cpp
)

add_library(polymaster_core ${POLYMASTER_SOURCES})
target_include_directories(polymaster_core PUBLIC include)

# Desktop test
add_executable(polymaster_test src/main.cpp)
target_link_libraries(polymaster_test polymaster_core)

set_target_properties(polymaster_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
