set(ATP_SOURCES
    atp.cpp
)

set(ASSOCIATION_SOURCES
    association.cpp
)

add_library(ATPLibrary ${ATP_SOURCES})
add_library(AssociationLibrary ${ASSOCIATION_SOURCES})

target_include_directories(ATPLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(AssociationLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(atp atp.cpp ${ATP_SOURCES})
add_executable(association association.cpp ${ASSOCIATION_SOURCES})