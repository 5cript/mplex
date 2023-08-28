cmake_minimum_required(VERSION 3.16)

project(mplex VERSION 1.0.0)

add_library(mplex INTERFACE)

target_include_directories(mplex INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
)