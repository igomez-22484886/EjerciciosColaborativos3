# Crear una librería llamada "music" con el código fuente del módulo
add_library(music
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Song.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Album.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MusicRepository.cpp
)

# Indicar dónde están los headers (.hpp)
target_include_directories(music
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Opcional: mostrar en consola cuando se compila
message(STATUS "Módulo 'music' añadido correctamente.")
