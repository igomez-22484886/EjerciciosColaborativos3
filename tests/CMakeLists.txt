# Crear un ejecutable separado para pruebas o demostraciones
add_executable(tests
        ${CMAKE_CURRENT_SOURCE_DIR}/test_music.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test_video.cpp
)

# Enlazar con las librerías de los módulos
target_link_libraries(tests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/music
        ${CMAKE_CURRENT_SOURCE_DIR}/video
)

# Incluir los headers
target_include_directories(tests
        PRIVATE
        ${PROJECT_SOURCE_DIR}/music/include
        ${PROJECT_SOURCE_DIR}/video/include
)

message(STATUS "Ejecutable de pruebas configurado correctamente.")