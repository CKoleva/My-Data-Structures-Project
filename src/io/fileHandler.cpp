#include "fileHandler.h"

void FileHandler::readFile(const std::string& fileName, Association& association, const std::string& atpName) {
    
    std::vector<std::string> lines;

    std::string filePath = "../../../../" + fileName;
    std::ifstream file(filePath);
    
    if (!file.is_open()) 
    {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;

    while (std::getline(file, line)) 
    {
        lines.push_back(line); 
    }

    file.close();

    association.add(atpName);

    ATP* atp = association.getATP(atpName);

    for (size_t i = 0; i < lines.size(); ++i) 
    {
        loadPair(lines[i], atp, association);
    }
}

void FileHandler::loadPair(const std::string& line, ATP* atp, Association& association) {

    size_t pos = line.find('-');

    if (line.empty() || pos == std::string::npos) 
    {
        association.removeATP(atp);
        delete atp;
        throw std::runtime_error("The provided data was not in the expected format");
    }

    if (atp != nullptr) 
    {
        std::string manager = line.substr(0, pos);
        std::string employee = line.substr(pos + 1);

        if (manager.find(' ') != std::string::npos || employee.find(' ') != std::string::npos) 
        {
            association.removeATP(atp);
            delete atp;
            throw std::runtime_error("The provided data was not in the expected format");
        }

        if (!atp->find(manager))
        {
            association.removeATP(atp);
            delete atp;
            throw std::runtime_error("The provided data was not in the expected format");
        }
        
        atp->hire(employee, manager);
    }
}

void FileHandler::writeFile(const std::string& filename, Association& association, const std::string& atpName) {

    ATP* atp = association.getATP(atpName);

    std::string hierarchy = atp->hierarchyRepresentation();

    std::string filePath = "../../../../" + filename;
    std::ofstream file(filePath);

    if (file.is_open()) 
    {
        file << hierarchy;
        file.close();
    } 
    else 
    {
        throw std::runtime_error("Unable to open file");
    }
}