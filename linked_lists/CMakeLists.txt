cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(LinkedListsLib)

add_executable(stack_creation src/stack_from_linked_list.cpp)
target_include_directories(stack_creation PRIVATE include)

add_executable(linked_lists_insertion src/linked_lists_insertion.cpp)
target_include_directories(linked_lists_insertion PRIVATE include)
