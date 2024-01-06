#pragma once

#include "atp.h"
#include <vector>
#include <string>
#include <iostream>

class Association {
public:
    static Association& getInstance();

    ATP* getATP(const std::string& atpName);

    std::vector<ATP*> getATPs() const;

    void add(const std::string& atpName);

    void add(ATP* atp);

    void removeATP(ATP* atp);

    ~Association();

private:
    std::vector<ATP*> ATPs;

    Association();
    Association(const Association&) = delete;
    Association(Association&&) = delete;
    Association& operator=(const Association&) = delete;
    Association& operator=(Association&&) = delete;

    void deallocate();
};