#pragma once

#include "association.h"
#include "fstream"

class FileHandler {
public:
    static bool readFile(const std::string& fileName, Association& association);

private:
    static void loadPair(std::string& line, ATP* atp);
};