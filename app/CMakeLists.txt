# Crear el ejecutable principal
add_executable(app
        main.cpp
)

# Enlazar las librerías creadas en los otros módulos
target_link_libraries(app
        PRIVATE
        music
        video
)

# Incluir los headers de otros módulos para poder usar sus clases
target_include_directories(app
        PRIVATE
        ${PROJECT_SOURCE_DIR}/music/include
        ${PROJECT_SOURCE_DIR}/video/include
)

message(STATUS "Ejecutable principal 'app' configurado correctamente.")