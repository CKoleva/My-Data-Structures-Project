#pragma once

#include "commandLine.h"
#include "association.h"

class Engine {
public:
    static Engine& getInstance();

private:
    static const std::size_t COMMANDS_COUNT = 15;
    const std::string validCommands[COMMANDS_COUNT] = 
    {"HELP", "LOAD", "SAVE", "FIND", "NUM_SUBORDINATES", "MANAGER", "NUM_EMPLOYEES", "OVERLOADED", "JOIN", "FIRE", "HIRE", "SALARY", "INCORPORATE", "MODERNIZE", "EXIT"};

    Association& association;

    Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;
};