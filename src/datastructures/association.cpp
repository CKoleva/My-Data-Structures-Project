#include "association.h"

//Public methods
Association& Association::getInstance() {

    static Association instance;
    
    return instance;
}   

ATP* Association::getATP(const std::string atpName) {

    for(ATP* atp : this->ATPs)
    {
        if (atp->getName() == atpName)
        {
            return atp;
        }
    }

    return nullptr;
}

//Private methods
Association::~Association() {
    this->deallocate();
}

void Association::deallocate() {
    for(ATP* atp : this->ATPs)
    {
        delete atp;
    }

    this->ATPs.clear();
}

