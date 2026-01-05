cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(particles)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")

set(GLAD_SOURCES "src/glad.c")

add_executable(particles ${SOURCES} ${GLAD_SOURCES})

target_include_directories(particles PRIVATE 
    include
    include/glad
    include/KHR
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)


target_link_libraries(particles PRIVATE OpenGL::GL glfw glm m)
