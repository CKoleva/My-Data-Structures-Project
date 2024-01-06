add_library(io)

target_include_directories(
    io
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_sources(
    io
    PUBLIC
    fileHandler.cpp
)