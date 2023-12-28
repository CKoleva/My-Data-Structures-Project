#include "fileHandler.h"

bool FileHandler::readFile(const std::string& fileName, Association& association) {
    
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    
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

    if(lines.empty())
    {
        return false;
    }

    if (!isValidName(lines[0]))
    {
        throw std::runtime_error("The name of the ATP has to contain only alphanumeric characters and underscores")
    }

    association.add(lines[0]);

    ATP* atp = association.getATP(lines[0]);

    for (size_t i = 1; i < lines.size(); ++i) 
    {
        loadPair(lines[i], atp);
    }

    return true;
}

void FileHandler::loadPair(const std::string& line, ATP* atp) {

    size_t pos = line.find('-');

    if (line.empty() || pos == std::string::npos) {
        throw std::runtime_error("File is not in the expected format");
    }

    if (atp != nullptr) 
    {
        std::string manager = line.substr(0, pos);
        std::string employee = line.substr(pos + 1);

        if (manager.find(' ') != std::string::npos || employee.find(' ') != std::string::npos) 
        {
            throw std::runtime_error("File is not in the expected format");
        }

        atp->hire(employee, manager);
    }
}

bool isValidName(const std::string& str) {
    
    for (char ch : str) 
    {
        if (!((ch >= '0' && ch <= '9') ||
              (ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z') ||
              (ch == '_'))) 
        {
            return false; 
        }
    }

    return true;
}