set(ENGINE_SOURCES
    engine.cpp
)

add_library(EngineLibrary ${ENGINE_SOURCES})

target_include_directories(EngineLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(engine engine.cpp)

target_link_libraries(engine EngineLibrary)
