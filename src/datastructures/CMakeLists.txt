add_library(datastructures)

target_include_directories(
    datastructures
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_sources(
    datastructures
    PUBLIC
    atp.cpp
    association.cpp
)