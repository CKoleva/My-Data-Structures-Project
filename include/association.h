#pragma once

#include "atp.h"
#include <vector>
#include <string>

class Association {
public:
    static Association& getInstance();

    ATP* getATP(const std::string atpName);

    void add();//need to see file reader first

private:
    std::vector<ATP*> ATPs;

    Association();
    ~Association();
    Association(const Association&) = delete;
    Association(Association&&) = delete;
    Association& operator=(const Association&) = delete;
    Association& operator=(Association&&) = delete;

    void deallocate();
};