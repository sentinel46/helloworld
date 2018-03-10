cmake_minimum_required(VERSION 3.2)

set(VER 0.0.1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(VER 0.0.$ENV{TRAVIS_BUILD_NUMBER})
endif()
project(helloworld VERSION ${VER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(version.h.in version.h)

add_library(lib lib.cpp)

add_executable(${PROJECT_NAME} main.cpp)

add_executable(test_${PROJECT_NAME} test_main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra)

set_target_properties(test_${PROJECT_NAME} PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} lib)

target_link_libraries(test_${PROJECT_NAME}
    ${Boost_LIBRARIES}
    lib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT altdaedroth@gmail.com)

include(CPack)

enable_testing()

add_test(test_version_valid test_${PROJECT_NAME})
