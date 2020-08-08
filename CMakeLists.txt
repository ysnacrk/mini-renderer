cmake_minimum_required(VERSION 2.8)

project(OpenGLModel)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES 
                     ${PROJECT_SOURCE_DIR}/main.cpp
                     ${PROJECT_SOURCE_DIR}/glad.c
                     ${PROJECT_SOURCE_DIR}/shader.cpp
                     ${PROJECT_SOURCE_DIR}/vertexbuffer.cpp
                     ${PROJECT_SOURCE_DIR}/indexbuffer.cpp
                     ${PROJECT_SOURCE_DIR}/renderer.cpp
                     ${PROJECT_SOURCE_DIR}/vertexarray.cpp
                     ${PROJECT_SOURCE_DIR}/imgui/imgui.cpp
                     ${PROJECT_SOURCE_DIR}/imgui/imgui_demo.cpp
                     ${PROJECT_SOURCE_DIR}/imgui/imgui_draw.cpp
                     ${PROJECT_SOURCE_DIR}/imgui/imgui_impl_glfw_gl3.cpp
                     
                     )
set(PROJECT_HEADERS 
                        ${PROJECT_INCLUDE_DIR}/)



find_package(glfw3 3.3 REQUIRED)

find_package(glm REQUIRED)
include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw)

