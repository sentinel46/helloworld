cmake_minimum_required(VERSION 3.2)

#project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
project(helloworld VERSION 0.0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(version.h.in version.h)

add_library(lib lib.cpp)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra)

target_link_libraries(${PROJECT_NAME} lib)
