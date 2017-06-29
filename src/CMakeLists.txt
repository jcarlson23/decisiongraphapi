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

set(SIMPLEPREDSRC
	TestPredicate.cpp
	${SOURCES}
)

set(SIMPLEVTKSRC
	TestVtk.cpp
	${SOURCES}
)

# create the executable for testing.
add_executable(TestSimple ${SIMPLETESTSRC})

# create the executble to exercise the predicate graph
add_executable(TestPredicate ${SIMPLEPREDSRC})

# create the VTK test application
add_executable(TestVTK ${SIMPLEVTKSRC})
target_link_libraries(TestVTK ${VTK_LIBRARIES})
