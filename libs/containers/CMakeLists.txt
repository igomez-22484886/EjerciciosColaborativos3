add_library(pel_containers INTERFACE)
target_include_directories(pel_containers INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include   # donde están pel/Vector.h y pel/Dynarray.h
)
