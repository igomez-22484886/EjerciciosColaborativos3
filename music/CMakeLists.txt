add_library(music
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Song.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Album.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MusicRepository.cpp
)

target_include_directories(music
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(music
        PUBLIC pel_containers
)

# target_include_directories(music PUBLIC ${PROJECT_SOURCE_DIR}/common/include)

message(STATUS "Módulo 'music' añadido correctamente.")
