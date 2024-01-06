add_library(cmdline)

target_include_directories(
    cmdline
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_sources(
    cmdline
    PUBLIC
    commandLine.cpp
)