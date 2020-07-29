cmake_minimum_required(VERSION 3.16)
project(PlayTest)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1/lib/cmake/SFML")
set(CMAKE_CXX_STANDARD 14)
add_executable(PlayTest main.cpp)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)
