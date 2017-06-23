set(SOURCES
	TestSimpleCreation.cpp
)

# create the executable
add_executable(TestSimple ${SOURCES})

# link the static DTGraph library
target_link_libraries(TestSimple DTGraph)
