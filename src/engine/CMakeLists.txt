add_library(engine)

target_include_directories(
    engine
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_sources(
    engine
    PUBLIC
    engine.cpp
    ../cmdline/commandLine.cpp
    ../datastructures/association.cpp
    ../io/fileHandler.cpp
    ../datastructures/atp.cpp
)