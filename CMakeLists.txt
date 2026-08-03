cmake_minimum_required(VERSION 3.16)
project(PolyMaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опции для платформы
option(BUILD_ANDROID "Build for Android NDK" OFF)

find_package(glm REQUIRED)
find_package(nlohmann_json REQUIRED)

# Главное ядро
set(POLYMASTER_SOURCES
    src/core/engine.cpp
    src/core/event_bus.cpp
    src/modules/scene_module.cpp
    src/modules/scene_serializer.cpp
    src/modules/input_module.cpp
    src/modules/transform_module.cpp
    src/modules/renderer_module.cpp
)

# Для Desktop
add_library(polymaster_core ${POLYMASTER_SOURCES})
target_include_directories(polymaster_core PUBLIC include)
target_link_libraries(polymaster_core PUBLIC 
    glm::glm
    nlohmann_json::nlohmann_json
)

# Для Android
if(BUILD_ANDROID)
    add_library(polymaster_native SHARED
        src/android/native.cpp
        ${POLYMASTER_SOURCES}
    )
    
    target_include_directories(polymaster_native PRIVATE include)
    target_link_libraries(polymaster_native
        GLESv2
        EGL
        android
        log
        glm::glm
        nlohmann_json::nlohmann_json
    )
endif()

# Desktop test
add_executable(polymaster_test src/main.cpp)
target_link_libraries(polymaster_test polymaster_core)

set_target_properties(polymaster_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
