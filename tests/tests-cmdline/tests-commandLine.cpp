#include "catch2/catch_all.hpp"
#include "commandLine.h"

TEST_CASE("CmdLine class tests") {
    SECTION("Test getSize() with different command lines") {
        CmdLine cmdLine1("");
        REQUIRE(cmdLine1.getSize() == 0);

        CmdLine cmdLine2("command    arg1 arg2 arg3");
        REQUIRE(cmdLine2.getSize() == 4);
    }

    SECTION("Test operator[] with valid and invalid indices") {
        CmdLine cmdLine("command arg1 arg2 arg3");
        REQUIRE(cmdLine[0] == "COMMAND");
        REQUIRE(cmdLine[2] == "arg2");
    }

    SECTION("Test parsing command line with leading/trailing spaces") {
        CmdLine cmdLine("  command  arg1   arg2  ");
        REQUIRE(cmdLine.getSize() == 3);
        REQUIRE(cmdLine[0] == "COMMAND");
        REQUIRE(cmdLine[2] == "arg2");
    }
}
