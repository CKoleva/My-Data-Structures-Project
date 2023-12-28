set(FILEHANDLER_SOURCES
    fileHandler.cpp
    # Add other source files related to ATP if any
)

add_library(FileHandlerLibrary ${FILEHANDLER_SOURCES})

target_include_directories(FileHandlerLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)