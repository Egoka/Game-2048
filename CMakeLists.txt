cmake_minimum_required(VERSION 3.16)
project(PlayTest)

set(SFML_DIR "libs/X32/SFML-2.5.1/lib/cmake/SFML")
set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)
add_executable(PlayTest main.cpp)
target_link_libraries(PlayTest sfml-graphics sfml-window sfml-system sfml-audio)
