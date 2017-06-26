set(SOURCES
	DTNode.cpp
	DTEdge.cpp
	DTGraph.cpp)

# create the library...
add_library(DTGraph STATIC ${SOURCES})

set(SIMPLETESTSRC
	TestSimpleCreation.cpp
	${SOURCES}
)

# create the executable for testing.
add_executable(TestSimple ${SIMPLETESTSRC})

