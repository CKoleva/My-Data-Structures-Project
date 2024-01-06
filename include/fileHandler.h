#pragma once

#include "association.h"
#include "fstream"

class FileHandler {
public:
    static void readFile(const std::string& fileName, Association& association, const std::string& atpName);

    static void loadPair(const std::string& line, ATP* atp, Association& association);
    
    static void writeFile(const std::string& filename, Association& association, const std::string& atpName);

private:
};