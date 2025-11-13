# Crear el ejecutable principal
add_executable(app
        main.cpp
)

# Enlazar librerías
target_link_libraries(app
        PRIVATE
        music
        video
        pel_containers
)

# Incluir headers de módulos
target_include_directories(app
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libs/music/include
        ${PROJECT_SOURCE_DIR}/libs/video/include
)