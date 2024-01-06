add_executable(datastructuresTests)

target_sources(
    datastructuresTests
    PUBLIC
    tests-datastructures.cpp
)

target_link_libraries(
    datastructuresTests
    PUBLIC
    Catch2::Catch2WithMain
    datastructures
)

add_test(NAME DataStructuresTests COMMAND datastructuresTests)