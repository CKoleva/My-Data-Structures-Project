add_executable(cmdlineTests)

target_sources(
    cmdlineTests
    PUBLIC
    tests-commandLine.cpp
)

target_link_libraries(
    cmdlineTests
    PUBLIC
    Catch2::Catch2WithMain
    cmdline
)

add_test(NAME CmdLineTests COMMAND cmdlineTests)