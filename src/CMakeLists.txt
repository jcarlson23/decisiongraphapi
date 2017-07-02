set(SOURCES
	DTNode.cpp
	DTEdge.cpp
	DTGraph.cpp
	vtkGraphInteraction.cpp)

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
target_link_libraries(TestSimple ${VTK_LIBRARIES})

# create the executble to exercise the predicate graph
add_executable(TestPredicate ${SIMPLEPREDSRC})
target_link_libraries(TestPredicate ${VTK_LIBRARIES})

# create the VTK test application
add_executable(TestVTK ${SIMPLEVTKSRC})
target_link_libraries(TestVTK ${VTK_LIBRARIES})
