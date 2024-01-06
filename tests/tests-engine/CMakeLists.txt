add_executable(enigneTests)

target_sources(
    enigneTests
    PUBLIC
    tests-engine.cpp
)

target_link_libraries(
    enigneTests
    PUBLIC
    Catch2::Catch2WithMain
    engine
)

add_test(NAME EngineTests COMMAND enigneTests)