cmake_minimum_required(VERSION 3.4.3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED DTGRAPH_VERSION_MAJOR)
       set(DTGRAPH_VERSION_MAJOR 0)
endif()
if(NOT DEFINED DTGRAPH_VERSION_MINOR)
       set(DTGRAPH_VERSION_MINOR 1)
endif()

# for the graphics we're going to use VTK
find_package(VTK REQUIRED)

vtk_module_config(VTK
  vtkCommonCore
  vtkCommonDataModel
  vtkFiltersGeometry
  vtkInteractionStyle
  vtkRendering${VTK_RENDERING_BACKEND}
)
include(${VTK_USE_FILE})

include_directories(include)

add_subdirectory(src)
