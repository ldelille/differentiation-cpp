cmake_minimum_required(VERSION 3.17)
project(Derivation)

set(CMAKE_CXX_STANDARD 17)

set(Header_FILES Number.h Operation.h Expression.h Addition.h Variable.h Multiplication.h)

set(SOURCE_FILES Number.cpp Operation.cpp Expression.cpp Addition.cpp Variable.cpp Multiplication.cpp)

add_library(Derivation_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
