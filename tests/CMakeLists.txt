# tests/CMakeLists.txt

add_executable(tests
        test_music.cpp
        test_video.cpp
)

target_link_libraries(tests
        PRIVATE
        music
        video
        pel_containers
)

target_include_directories(tests
        PRIVATE
        ${PROJECT_SOURCE_DIR}/music/include
        ${PROJECT_SOURCE_DIR}/video/include
        ${PROJECT_SOURCE_DIR}/libs/containers/include
)