set(ATP_SOURCES
    atp.cpp
    # Add other source files related to ATP if any
)

set(ASSOCIATION_SOURCES
    association.cpp
    # Add other source files related to ATP if any
)

# Create a library from the sources
add_library(ATPLibrary ${ATP_SOURCES})
add_library(AssociationLibrary ${ASSOCIATION_SOURCES})

# Include directories to locate headers
target_include_directories(ATPLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(AssociationLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)
