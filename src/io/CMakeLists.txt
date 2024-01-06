set(FILEHANDLER_SOURCES
    fileHandler.cpp
)

add_library(FileHandlerLibrary ${FILEHANDLER_SOURCES})

target_include_directories(FileHandlerLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(io io.cpp ${FILEHANDLER_SOURCES}) 

target_link_libraries(io FileHandlerLibrary)