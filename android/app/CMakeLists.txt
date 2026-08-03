cmake_minimum_required(VERSION 3.22)
project(PolyMaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Native library
add_library(polymaster_native SHARED
    src/main/cpp/native.cpp
)

# Логирование
target_link_libraries(polymaster_native
    log
    android
)

target_include_directories(polymaster_native PRIVATE
    src/main/cpp
)
