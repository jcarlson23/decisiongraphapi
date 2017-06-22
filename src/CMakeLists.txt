set(SOURCES
	DTNode.cpp
	DTEdge.cpp
	DTGraph.cpp)

# create the library...
add_library(DTGraph STATIC ${SOURCES})
