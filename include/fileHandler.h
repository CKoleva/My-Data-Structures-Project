#pragma once

#include "association.h"
#include "fstream"

class FileHandler {
public:
    static void readFile(const std::string& fileName, Association& association, const std::string& atpName);

    static void loadPair(std::string& line, ATP* atp);
private:
};