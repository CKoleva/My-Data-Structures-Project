set(CMDLINE_SOURCES
    commandLine.cpp
)

add_library(CommandLineLibrary ${CMDLINE_SOURCES})

target_include_directories(CommandLineLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(cmdline cmdline.cpp ${CMDLINE_SOURCES})

target_link_libraries(cmdline CommandLineLibrary)
