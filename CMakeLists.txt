cmake_minimum_required(VERSION 3.25)

project(untitled C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${CMAKE_PROJECT_NAME})


set(sources
        src/main.cpp
        src/main.hpp
        src/ui/ui.cpp
        src/ui/ui.hpp
        src/core/task2.cpp
        src/core/task2.h
        src/core/task5.cpp
        src/core/task5.h
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        C_VISIBILITY_PRESET hidden
        POSITION_INDEPENDENT_CODE ON
)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(Freetype CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_sources(${CMAKE_PROJECT_NAME}
        PRIVATE
        ${sources}
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ports/imguiDock/)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        ${OPENGL_gl_LIBRARY}
        glfw
        Freetype::Freetype
        implot::implot
        imgui::imgui
)

install(TARGETS ${CMAKE_PROJECT_NAME}
        COMPONENT ${CMAKE_PROJECT_NAME}
        RUNTIME DESTINATION bin
)
install(FILES ${resource_files} DESTINATION bin COMPONENT ${CMAKE_PROJECT_NAME})