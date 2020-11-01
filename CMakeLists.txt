cmake_minimum_required(VERSION 3.14)
project(test_derivation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(Derivation_run ${SOURCE_FILES})

include_directories(Derivation_lib)
add_subdirectory(Derivation_lib)

target_link_libraries(Derivation_run Derivation_lib)

add_subdirectory(Google_tests)