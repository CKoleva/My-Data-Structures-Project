#include "commandLine.h"
#include <stdexcept>
#include <cstddef>

//Public methods
CmdLine::CmdLine(const std::string& cmdl) {

    parseCmdLine(cmdl);

}

std::size_t CmdLine::getSize() const {

    return this->argv.size();

}

const std::string& CmdLine::operator[](std::size_t index) const {
    
    if (index < argv.size()) 
    {
        return argv[index];
    } 
    else 
    {
        throw std::out_of_range("Index out of range");
    }

}

//Private methods
void CmdLine::toUpper(std::string& str)
{
    for (char ch : str)
    {
        toupper(ch);
    }
}

void CmdLine::parseCmdLine(const std::string& str) {

    std::string word;
    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while (start != std::string::npos) 
    {
        start = str.find_first_not_of(' ', end);
        
        if (start != std::string::npos) 
        {
            end = str.find(' ', start); 

            if (end == std::string::npos) 
            {
                word = str.substr(start);
            }
            else 
            {
                word = str.substr(start, end - start); 
            }

            argv.push_back(word);
        }
    }

    if(argv.empty()) return;
    
    toUpper(this->argv[0]);
}