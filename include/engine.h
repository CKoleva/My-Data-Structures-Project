#pragma once

#include <iostream>
#include "commandLine.h"
#include "association.h"
#include "fileHandler.h"

class Engine {
public:
    static Engine& getInstance();

    void start();

private:
    static const std::size_t COMMANDS_COUNT = 15;
    const std::string validCommands[COMMANDS_COUNT] = 
    {"HELP", "LOAD", "SAVE", "FIND", "NUM_SUBORDINATES", "MANAGER", "NUM_EMPLOYEES", "OVERLOADED", "JOIN", "FIRE", "HIRE", "SALARY", "INCORPORATE", "MODERNIZE", "EXIT"};

    Association& association;
    std::vector<bool> unsavedChanges;
    bool endProgram;

    Engine();
    ~Engine();
    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;

    void execute(CmdLine& cmdl);

    bool isValid(CmdLine& cmdl) const;

    void help() const;

    void load(const std::string& atpName, const std::string& fileName);

    void load(const std::string& atpName);

    void save(const std::string& atpName, const std::string& fileName);

    std::string save(const std::string& atpName);

    std::string find(const std::string& atpName, const std::string& employee) const;

    std::size_t num_subordinates(const std::string& atpName, const std::string& employee) const;

    std::string manager(const std::string& atpName, const std::string& employee) const;

    std::size_t num_employees(const std::string& atpName) const;

    std::size_t overloaded(const std::string& atpName) const;

    void join(const ATP* atp1, const ATP* atp2, const std::string& atpResultName);

    void fire(const std::string& atpName, const std::string& employee);

    void hire(const std::string& atpName, const std::string& employee, const std::string& manager);

    std::size_t salary(const std::string& atpName, const std::string& employee) const;

    void incorporate(const std::string& atpName);

    void modernize(const std::string& atpName);

    void exit();

    bool checkFileName(const std::string& fileName) const;
    
    void markUnsaved(ATP* atp, const bool value); 

    bool isValidATPName(const std::string& str) const;

    void joinTrees(const ATP* atp1, const ATP* atp2, const std::string& atpResultName);
};