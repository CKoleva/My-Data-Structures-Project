#pragma once

#include <iostream>
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
    static bool unsavedChanges;
    static bool endProgram;

    Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;

    void execute(CmdLine& cmdl);

    bool isValid(CmdLine& cmdl) const;

    void help() const;

//tbd
    void load(const std::string& atpName, const std::string& fileName);

//tbd
    void load(const std::string& atpName);

//tbd
    void save(const std::string& atpName, const std::string& fileName) const;

//tbd
    void save(const std::string& atpName) const;

    std::string find(const std::string& atpName, const std::string& employee) const;

    std::size_t num_subordinates(const std::string& atpName, const std::string& employee) const;

    std::string manager(const std::string& atpName, const std::string& employee) const;

    std::size_t num_employees(const std::string& atpName) const;

    std::size_t overloaded(const std::string& atpName) const;

//tbd
    void join(const std::string& atp1, const std::string& atp2, const std::string& atpResult);

    void fire(const std::string& atpName, const std::string& employee);

    void hire(const std::string& atpName, const std::string& employee, const std::string& manager);

    std::size_t salary(const std::string& atpName, const std::string& employee) const;

    void incorporate(const std::string& atpName);

    void modernize(const std::string& atpName);

    void exit();
};