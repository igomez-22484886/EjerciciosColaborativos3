# tests/CMakeLists.txt

# Executable with both test files
add_executable(tests
        test_music.cpp
        test_video.cpp
)

# Link with project libraries
target_link_libraries(tests
        PRIVATE
        music          # target from libs/music/CMakeLists.txt
        video          # target from libs/video/CMakeLists.txt
        pel_containers # target from libs/containers/CMakeLists.txt
)

# Include headers from modules
target_include_directories(tests
        PRIVATE
        ${PROJECT_SOURCE_DIR}/music/include
        ${PROJECT_SOURCE_DIR}/video/include
        ${PROJECT_SOURCE_DIR}/libs/containers/include
)