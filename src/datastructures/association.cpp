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
        std::cout << atpName;
        throw std::runtime_error(" already exists.");
        return;
    }
    
    ATP* atp = new ATP(atpName);
    this->ATPs.push_back(atp);

}

void Association::add(ATP* atp) {

    this->ATPs.push_back(atp);
}

void Association::removeATP(ATP* atp)
{
    for(std::size_t i = 0; i < this->ATPs.size(); ++i)
    {
        if (this->ATPs[i] == atp)
        {
            delete atp;
            this->ATPs.erase(this->ATPs.begin() + i);
        }
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

