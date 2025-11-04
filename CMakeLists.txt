cmake_minimum_required(VERSION 3.25)

# Nombre del proyecto
project(EjerciciosColaborativos3 LANGUAGES CXX)

# Configuración de compilación
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir los submódulos
add_subdirectory(music)
add_subdirectory(video)
add_subdirectory(app)
add_subdirectory(tests)  # opcional