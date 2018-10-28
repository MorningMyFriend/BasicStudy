cmake_minimum_required(VERSION 3.10)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/Union)
file(GLOB Union ${PROJECT_SOURCE_DIR}/Union/*.h ${PROJECT_SOURCE_DIR}/Union/*.cpp)
add_executable(union example/union_main.cpp ${Union})

include_directories(${PROJECT_SOURCE_DIR}/StackAndQue)
file(GLOB StackAndQue ${PROJECT_SOURCE_DIR}/StackAndQue/*.h ${PROJECT_SOURCE_DIR}/StackAndQue/*.cpp)
add_executable(stack example/stack_main.cpp StackAndQue)
