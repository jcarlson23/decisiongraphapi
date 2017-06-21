cmake_minimum_required(VERSION 3.4.3)

if(NOT DEFINED DTGRAPH_VERSION_MAJOR)
       set(DTGRAPH_VERSION_MAJOR 0)
endif()
if(NOT DEFINED DTGRAPH_VERSION_MINOR)
       set(DTGRAPH_VERSION_MINOR 1)
endif()

include_directories(include)

add_subdirectory(src)
