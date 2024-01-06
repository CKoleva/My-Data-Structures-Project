#include "association.h"

//Public methods
Association& Association::getInstance() {

    static Association instance;
    
    return instance;
}   

ATP* Association::getATP(const std::string& atpName) {

    for(ATP* atp : this->ATPs)
    {
        if (atp->getName() == atpName)
        {
            return atp;
        }
    }

    return nullptr;
}

std::vector<ATP*> Association::getATPs() const {
    return this->ATPs;
}

void Association::add(const std::string& atpName) {
    
    if (this->getATP(atpName))
    {
        std::cout << atpName << " already exists.\n";
        return;
    }
    
}

void Association::add(ATP* atp) {

    this->ATPs.push_back(atp);
}

void Association::removeATP(ATP* atp)
{
    std::vector<ATP*>::iterator it = std::find(ATPs.begin(), ATPs.end(), atp);
    if (it != ATPs.end()) 
    {
        ATPs.erase(it);
        delete atp;
    }
}

Association::~Association() {
    this->deallocate();
}

//Private methods
Association::Association() {}

void Association::deallocate() {
    for(ATP* atp : this->ATPs)
    {
        delete atp;
    }

    this->ATPs.clear();
}

