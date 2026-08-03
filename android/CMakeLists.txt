cmake_minimum_required(VERSION 3.16)
project(PolyMasterNDK)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим необходимые библиотеки
find_package(glm REQUIRED)
find_package(nlohmann_json REQUIRED)

# Используем C++ код из главного проекта
set(POLYMASTER_SRC
    ../src/core/engine.cpp
    ../src/core/event_bus.cpp
    ../src/modules/scene_module.cpp
    ../src/modules/scene_serializer.cpp
    ../src/modules/input_module.cpp
    ../src/modules/transform_module.cpp
    ../src/modules/renderer_module.cpp
)

# Native library
add_library(polymaster_native SHARED
    src/native.cpp
    ${POLYMASTER_SRC}
)

target_include_directories(polymaster_native PRIVATE
    ../include
    ${ANDROID_NDK}/sources/android/native_app_glue
)

target_link_libraries(polymaster_native
    GLESv2
    EGL
    android
    log
    glm::glm
    nlohmann_json::nlohmann_json
)
