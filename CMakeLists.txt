cmake_minimum_required(VERSION 3.16)
project(DK)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})

find_package(SFML 2 COMPONENTS window graphics audio REQUIRED)

add_compile_options(-Wall -Wextra)

add_executable(DK main.cpp DKBoard.cpp DKBoard.h Mario.h DKView.cpp DKView.h DKControl.cpp DKControl.h EndScreen.cpp EndScreen.h)

target_link_libraries(DK sfml-system sfml-window sfml-graphics sfml-audio)