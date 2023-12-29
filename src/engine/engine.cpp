#include "engine.h"

//Public methods
Engine& Engine::getInstance() 
{
    static Engine instance;

    return instance;
}

void start(); //tbd

Engine::~Engine() {}

//Private methods
Engine::Engine() : association(Association::getInstance()) {}

void Engine::execute(CmdLine& cmdl) {
    
    if (!isValid(cmdl))
    {
        return;
    }

    std::string command = cmdl[0];

    if (command == "HELP")
    {
        this->help();
    }
    else if(command == "LOAD" && cmdl.getSize() == 2)
    {
        if (!isValidATPName(cmdl[1]))
        {
            std::cout << "The name of the ATP should contain olny alphanumerical characters and underscore.\n";
            return;
        }

        this->load(cmdl[1]);

        std::cout << cmdl[1] << " loaded successfully!\n";
    }
    else if(command == "LOAD" && cmdl.getSize() == 3)
    {
        if (!isValidATPName(cmdl[1]))
        {
            std::cout << "The name of the ATP should contain olny alphanumerical characters and underscore.\n";
            return;
        }
        
        this->load(cmdl[1], cmdl[2]);

        std::cout << cmdl[1] << " loaded successfully!\n";
    }
    else if(command == "SAVE" && cmdl.getSize() == 2) //tbd
    {
        this->save(cmdl[1]);
    }
    else if(command == "SAVE" && cmdl.getSize() == 3) //tbd
    {
        this->save(cmdl[1], cmdl[2]);
    }
    else if(command == "FIND")
    {
        this->find(cmdl[1], cmdl[2]);
    }
    else if(command == "NUM_SUBORDINATES")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        if (!atp->find(cmdl[2]))
        {
            std::cout << "There is no " << cmdl[2] << " in " << cmdl[1] << ".\n";
            return;
        }
        
        std::size_t result = this->num_subordinates(cmdl[1], cmdl[2]);
        
        if (result == 0)
        {
            std::cout << cmdl[2] << " has no subordinates.\n";
            return;
        }

        std::cout << cmdl[2] << " has " << result << " subordinates.\n";
        
    }
    else if(command == "MANAGER")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        if (!atp->find(cmdl[2]))
        {
            std::cout << "There is no " << cmdl[2] << " in " << cmdl[1] << ".\n";
            return;
        }

        std::string result = this->manager(cmdl[1], cmdl[2]);

        if (result == "")
        {
            std::cout << cmdl[2] << " has no manager.\n";
            return;
        }

        std::cout << "The manager of " + cmdl[2] + " is " + result + ".\n";

    }
    else if(command == "NUM_EMPLOYEES")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        std::size_t result = this->num_employees(cmdl[1]);

        if (result == 0)
        {
            std::cout << "There are no employees in " << cmdl[1] << ".\n";
            return;
        }

        std::cout << "There are " << result << " employees in " << cmdl[1] << ".\n";

    }
    else if(command == "OVERLOADED")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        std::size_t result = this->overloaded(cmdl[1]);

        if (result == 0)
        {
            std::cout << "There are no overloaded eployees in " << cmdl[1] << ".\n";
            return;
        }

        std::cout << "There are " << result << " overoaded employees in " << cmdl[1] << ".\n";
    }
    else if(command == "JOIN")      //tbd
    {
        this->join(cmdl[1], cmdl[2], cmdl[3]);
    }
    else if(command == "FIRE")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        if (!atp->find(cmdl[2]))
        {
            std::cout << "There is no " << cmdl[2] << " in " << cmdl[1] << ".\n";
            return;
        }

        this->fire(cmdl[1], cmdl[2]);
        std::cout << cmdl[2] << " was fired.\n";

    }
    else if(command == "HIRE")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        if (!atp->find(cmdl[3]))
        {
            std::cout << "There is no " << cmdl[3] << " in " << cmdl[1] << ".\n";
            return;
        }

        this->hire(cmdl[1], cmdl[2], cmdl[3]);
        std::cout << cmdl[2] << " was fired.\n";

    }
    else if(command == "SALARY")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        if (!atp->find(cmdl[2]))
        {
            std::cout << "There is no " << cmdl[2] << " in " << cmdl[1] << ".\n";
            return;
        }

        std::cout << "The salary is " << this->salary(cmdl[1], cmdl[2]) << " euro.\n";
    }
    else if(command == "INCORPORATE")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        this->incorporate(cmdl[1]);
        std::cout << cmdl[1] << " incorporated.\n";
    }
    else if(command == "MODERNIZE")
    {
        ATP* atp = this->association.getATP(cmdl[1]);

        if (!atp)
        {
            std::cout << cmdl[1] + " is an unknown office!\n";
            return;
        }

        this->modernize(cmdl[1]);
        std::cout << cmdl[1] << " modernized.\n";
    }
    else if(command == "EXIT")
    {
        this->exit();
    }
    
}

bool Engine::isValid(CmdLine& cmdl) const {

    std::string command = cmdl[0];
    std::size_t argc = cmdl.getSize();

    bool found = false;

    for (size_t i = 0; i < COMMANDS_COUNT; i++)
    {
        if(command == validCommands[i])
            found = true;
    }
    
    if (found == false)
    {
        std::cout << "Invald command! Type \"help\" to see all supported commands.\n";
        return false;
    }

    if ((command == "HELP" || command == "EXIT") && argc != 1)
    {
        std::cout << "Invalid number of arguments!. Type \"help\" to see all supported commands.\n";
        return false;
    }

    if ((command == "NUM_EMPLOYEES" || command == "OVERLOADED" || command == "INCORPORATE" || command == "MODERNIZE") && argc != 2)
    {
        std::cout << "Invalid number of arguments!. Type \"help\" to see all supported commands.\n";
        return false;
    }

    if ((command == "NUM_SUBORDINATES" || command == "FIND" || command == "MANAGER" || command == "FIRE" || "SALARY") && argc != 3)
    {
        std::cout << "Invalid number of arguments!. Type \"help\" to see all supported commands.\n";
        return false;
    }

    if ((command == "JOIN" || command == "HIRE") && argc != 4)
    {
        std::cout << "Invalid number of arguments!. Type \"help\" to see all supported commands.\n";
        return false;
    }

    if ((command == "LOAD" || command == "SAVE") && !(argc == 2 || argc == 3))
    {
        std::cout << "Invalid number of arguments!. Type \"help\" to see all supported commands.\n";
        return false;
    }
}

void Engine::help() const {

    std::cout << "The following commands are supported:\n"
    << "lead <ATP-name>	                            loads <ATP-name> from the standars input until Ctrl+z/Ctrl+d\n" 
    << "lead <ATP-name> <file-name>	                loads <ATP-name> from <file-name>\n" 
    << "save <ATP-name>	                            prints <ATP-name>\n" 
    << "save <ATP-name> <file-name>	                saves <ATP-name> to <file-name>\n"
    << "find <ATP-name> <employee>		            checks if <employee> works in <ATP-name>\n"
    << "num_subordinates <ATP-name> <employee>      displays the number of direct subordinates of <employee> in <ATP-name>\n"
    << "manager <ATP-name> <employee>               displays the immediate manager of <employee> in <ATP-name>\n"
    << "num_employees <ATP-name>                    displays the number of employees in <ATP-name>\n"
    << "overloaded <ATP-name>                       displays the number of overloaded managers in <ATP-name>\n"            
    << "join <ATP-1> <ATP-2> <ATP-new>              joins <ATP-1> and <ATP-2> into a new object <ATP-new>\n"
    << "fire <ATP-name> <employee>                  fires <employee> from <ATP-name>\n"
    << "hire <ATP-name> <employee> <manager>        hires <employee> as a subordinate of <manager> in <ATP-name>\n"
    << "salary <ATP-name> <employee>                displays the salary of <employee> in <ATP-name>\n"
    << "incorporate <ATP-name>                      incorporates <ATP-name>\n"
    << "modernize <ATP-name>                        modernizes <ATP-name>\n"
    << "exit                                        exits the program\n";

    return;
}

void Engine::load(const std::string& atpName, const std::string& fileName) {
    
    FileHandler::readFile(fileName, this->association, atpName);
}

void Engine::load(const std::string& atpName) {
    
    this->association.add(atpName);

    ATP* atp = association.getATP(atpName);

    std::string managerEmployeePair;

    while (std::getline(std::cin, managerEmployeePair)) {
        if (managerEmployeePair.size() >= 2 && managerEmployeePair[0] == '^' &&
            (managerEmployeePair[1] == 'Z' || managerEmployeePair[1] == 'D')) 
        {
            break; 
        }

        if (managerEmployeePair.empty()) 
        {
            std::cout << "Invalid input. Please provide manager-employee pairs.\n";
            continue;
        }

        FileHandler::loadPair(managerEmployeePair, atp);
    }
}

std::string Engine::find(const std::string& atpName, const std::string& employee) const {
    
    ATP* atp = this->association.getATP(atpName);

    if (!atp)
    {
        return atpName + " is an unknown office!";
    }

    if (atp->find(employee))
    {
        return employee + " is employed in " + atpName + ".";
    }
    
    return employee + " is not employed in " + atpName + ".";
}

std::size_t Engine::num_subordinates(const std::string& atpName, const std::string& employee) const {
    
    ATP* atp = this->association.getATP(atpName);
    
    return atp->numSubordinates(employee);
}

std::string Engine::manager(const std::string& atpName, const std::string& employee) const {
    
    ATP* atp = this->association.getATP(atpName);

    return atp->getManager(employee);
}

std::size_t Engine::num_employees(const std::string& atpName) const {
    
    ATP* atp = this->association.getATP(atpName);

    return atp->numEmployees();
}

std::size_t Engine::overloaded(const std::string& atpName) const {
    
    ATP* atp = this->association.getATP(atpName);
    
    const std::size_t overloadNumber = 20;

    return atp->overloaded(overloadNumber);
}

void Engine::fire(const std::string& atpName, const std::string& employee) {
    
    ATP* atp = this->association.getATP(atpName);
    
    markUnsaved(atp, true);

    atp->fire(employee);

    return;
}

void Engine::hire(const std::string& atpName, const std::string& employee, const std::string& manager) {
    
    ATP* atp = this->association.getATP(atpName);

    atp->hire(employee, manager);
    
    markUnsaved(atp, true);

    return;
}

std::size_t Engine::salary(const std::string& atpName, const std::string& employee) const {
    
    ATP* atp = this->association.getATP(atpName);

    return atp->salary(employee);
}

void Engine::incorporate(const std::string& atpName) {

    ATP* atp = this->association.getATP(atpName);
    
    atp->incorporate();

    markUnsaved(atp, true);

    return;
}

void Engine::modernize(const std::string& atpName) {

    ATP* atp = this->association.getATP(atpName);
    
    atp->modernize();

    markUnsaved(atp, true);

    return;
}

void Engine::exit() {

    std::vector<ATP*> ATPs = this->association.getATPs();

    for (int i = 0; i < ATPs.size(); ++i)
    {
        if (unsavedChanges[i])
        {
            std::cout << ATPs[i]->getName() << " is modified, but not saved.\nEnter file name to save it:\n";

            std::string fileName;

            std::cin >> fileName;

            if (!checkFileName(fileName))
            {
                return;
            }

            this->save(ATPs[i]->getName(), fileName);
        }   
    }
    
    std::cout << "Goodbye!\n";
    endProgram = true;
}

bool Engine::checkFileName(const std::string& fileName) const {
    size_t nameSize = fileName.size();
    
    if (nameSize < 5 || fileName.substr(nameSize - 4) != ".txt") {
        std::cout << "Invalid file. This program supports XXX.txt files where XXX is the name of the file.\n";
        return false;
    }

    const std::string forbiddenSymbols = "/\\:*?\"<>|{}#%&=@$+!'";
    if (fileName.find_first_of(forbiddenSymbols) != std::string::npos) {
        std::cout << "File name contains forbidden symbols (/\\:*?\"<>|{}#%&=@$+!).\n";
        return false;
    }
    
    return true;
}

void Engine::markUnsaved(ATP* atp, const bool value) {

    std::vector<ATP*> ATPs = this->association.getATPs();

    for(std::size_t i = 0; i < ATPs.size(); ++i)
    {
        if (ATPs[i] == atp)
        {
            this->unsavedChanges[i] = value;
            return;
        }
    }
}

bool Engine::isValidATPName(const std::string& str) const {
    
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
