enable_testing()

find_package(Catch2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(tests-atp tests-atp.cpp)
add_executable(tests-association tests-association.cpp)
add_executable(tests-cmdline tests-commandLine.cpp)
add_executable(tests-filehandler tests-fileHandler.cpp)
add_executable(tests-engine tests-engine.cpp)
# Add other test executables for cmdline, filehandler, engine, etc., as needed

# Link each test executable with the corresponding module's library and Catch2
target_link_libraries(tests-atp ATPLibrary Catch2::Catch2)
target_link_libraries(tests-association AssociationLibrary Catch2::Catch2)
target_link_libraries(tests-cmdline CommandLineLibrary Catch2::Catch2)
target_link_libraries(tests-filehandler FileHandlerLibrary Catch2::Catch2)
target_link_libraries(tests-engine EngineLibrary Catch2::Catch2)

# Add tests to CTest (optional but useful)
add_test(NAME ATPTests COMMAND tests-atp)
add_test(NAME AssociationTests COMMAND tests-association)
add_test(NAME CmdLineTests COMMAND tests-cmdline)
add_test(NAME FileHandlerTests COMMAND tests-filehandler)
add_test(NAME EngineTests COMMAND tests-engine)

# Optionally, if you want to organize tests into a test suite:
# ctest_add_tests(TESTS tests-atp tests-association)
# Add other tests similarly
