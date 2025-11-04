# Crear una librería llamada "video" con el código fuente del módulo
add_library(video
        src/Title.cpp
        src/VideoRepository.cpp
)

# Incluir headers (.hpp)
target_include_directories(video
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

message(STATUS "Módulo 'video' añadido correctamente.")