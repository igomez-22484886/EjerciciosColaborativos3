add_library(video
        src/Title.cpp
        src/VideoRepository.cpp
        include/Title.h
)

target_include_directories(video
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(video
        PUBLIC pel_containers
)

message(STATUS "Módulo 'video' añadido correctamente.")
