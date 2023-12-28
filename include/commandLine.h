#pragma once

#include <vector>
#include <string>
#include <cstddef>

class CmdLine {
public:
    CmdLine(const std::string& cmdl);

    std::size_t getSize() const;

    const std::string& operator[](std::size_t index) const;

private:
    std::vector<std::string> argv;

    void parseCmdLine(const std::string& cmdl);

    void toUpper(std::string& str);
};