cmake_minimum_required(VERSION 3.25)
project(EjerciciosColaborativos3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libs/containers)
# add_subdirectory(common)

add_subdirectory(music)
add_subdirectory(video)
add_subdirectory(app)
add_subdirectory(tests)  # opcional
