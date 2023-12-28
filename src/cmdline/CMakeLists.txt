set(CMDLINE_SOURCES
    commandLine.cpp
    # Add other source files related to ATP if any
)

add_library(CommandLineLibrary ${CMDLINEFILEHANDLER_SOURCES})

target_include_directories(CommandLineLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)