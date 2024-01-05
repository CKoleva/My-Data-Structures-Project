#include "atp.h"

//Public methods
ATP::ATP(const std::string& name) {
    this->manager = new Node("CEO_to");
    this->name = name;    
}

ATP::ATP(const ATP& other) : manager(this->copy(other.manager)) {}

ATP& ATP::operator= (const ATP& other) {
    
    if(this != &other) 
    {
        this->dealocate(this->manager);
        this->manager = this->copy(other.manager);
        this->name = other.name;
    }

    return *this;
}

ATP::~ATP() {
    this->dealocate(this->manager);
}

std::string ATP::getName() {
    return this->name;
}

bool ATP::find(const std::string& employee) const {
    return findHelper(this->manager, employee) != nullptr;
}

std::size_t ATP::numSubordinates(const std::string& employee) const {
   
    Node* foundEmployee = findHelper(this->manager, employee);

    std::size_t count = 0;

    countSubordinates(this->manager, foundEmployee, count);

    return count;    
}

std::string ATP::getManager(const std::string& employee) const {

    Node* foundEmployee = findHelper(this->manager, employee);

    Node* manager = getManagerHelper(this->manager, foundEmployee);

    if (!manager)
    {
        return "";
    }
    
    return manager->name;
}

std::size_t ATP::numEmployees() const {

    std::size_t count = 0;

    countEmployees(this->manager, count);

    return count; 
}

std::size_t ATP::overloaded(std::size_t overloadNumber) const {

    std::size_t count = 0;

    overloadedHelper(this->manager, overloadNumber, count);

    return count;
}

void ATP::fire(const std::string& employee) {

    if(this->manager->name == employee) 
    {
        throw std::logic_error("Cannot fire CEO_to!");
    }

    Node* foundEmployee = findHelper(this->manager, employee);

    fireHelper(foundEmployee);

    return;
}

void ATP::hire(const std::string& employee, const std::string& manager) {
    
    Node* foundEmployee = findHelper(this->manager, employee);

    Node* foundManager = findHelper(this->manager, manager);

    if (!foundEmployee)
    {
        foundManager->subordinates.push_back(new Node(employee));
        return;
    }
    
    if (findHelper(foundEmployee, manager))
    {
        throw std::logic_error("Cannot hire a subordinate to be manager of his direct or indirect manager.");
    }
    
    Node* immediateManager = getManagerHelper(this->manager, foundEmployee);

    removeSubordinate(immediateManager, foundEmployee);

    foundManager->subordinates.push_back(foundEmployee);
}

std::size_t ATP::maxChainLength() {

    return maxDepth(this->manager);
}

std::size_t ATP::salary(const std::string& employee) const {

    Node* foundEmployee = findHelper(this->manager, employee);

    return calculateSalary(foundEmployee);
}

void ATP::incorporate() {
    
    incorporateHelper(this->manager);

    return;
}

void ATP::modernize() {

    modernizeHelper(this->manager, 0);

    return;
}

//Private methods
ATP::Node::Node(const std::string& name) {
    this->name = name;
}

void ATP::dealocate(Node* manager) {
    
    if(!manager)
    {
        return;
    }

    for(std::size_t i = 0; i < manager->subordinates.size(); ++i)
    {
        dealocate(manager->subordinates[i]);
    }

    delete manager;
}

ATP::Node* ATP::copy(Node* manager) {
    
    if(!manager)
    {
        return manager;
    }

    Node* newManager = new Node(manager->name);

    for(Node* subordinate : manager->subordinates)
    {
        Node* copiedSubordinate = copy(subordinate);
        newManager->subordinates.push_back(copiedSubordinate);
    }

    return newManager;
}

ATP::Node* ATP::findHelper(Node* manager, const std::string& employee) const {
    
    if (!manager) {
        return nullptr;
    }

    if(manager->name == employee)
    {
        return manager;
    }

    for(Node* subordinate : manager->subordinates)
    {
        Node* foundEmployee = findHelper(subordinate, employee);
        if (foundEmployee) {
            return foundEmployee;
        }
    }

    return nullptr;
}

void ATP::countSubordinates(const Node* manager, Node* employee, std::size_t& count) const {
    
    if (!manager) 
    {
        return;
    }

    if (manager == employee) 
    {
        count = manager->subordinates.size();
        return;
    }

    for (const Node* subordinate : manager->subordinates) 
    {
        countSubordinates(subordinate, employee, count);
    }
}

ATP::Node* ATP::getManagerHelper(Node* manager, Node* employee) const {
    
    if (!manager || employee == manager) 
    {
        return nullptr;
    }

    for (Node* subordinate : manager->subordinates) 
    {

        if (subordinate == employee) 
        {
            return manager;
        }

        Node* foundManager = getManagerHelper(subordinate, employee);

        if (foundManager) 
        {
            return foundManager;
        }
    }

    return nullptr; 
}

void ATP::countEmployees(const Node* manager, std::size_t& count) const {

    if(!manager)
    {
        return;
    }

    ++count;

    for (const Node* subordinate : manager->subordinates)
    {
        countEmployees(subordinate, count);
    }
}

std::size_t ATP::overloadedHelper(const Node* manager, std::size_t overloadNumber, std::size_t& count) const {

    if(!manager)
    {
        return;
    }   

    std::size_t currCounter = 0;

    for(Node* subodinate : manager->subordinates)
    {
        currCounter = manager->subordinates.size() + overloadedHelper(subodinate, overloadNumber, count);
    }

    if (currCounter > overloadNumber)
    {
        ++count;
    }
    
    return currCounter;
}

void ATP::fireHelper(Node* employee) {

    Node* immediateManager = getManagerHelper(this->manager, employee);

    immediateManager->subordinates.insert
            (immediateManager->subordinates.end(),
             employee->subordinates.begin(),
             employee->subordinates.end());

    removeSubordinate(immediateManager, employee);
}

void ATP::removeSubordinate(Node* manager, Node* employee) {

    for (size_t i = 0; i < manager->subordinates.size(); ++i) 
    {
        if (manager->subordinates[i] == employee) 
        {
            manager->subordinates.erase(manager->subordinates.begin() + i);
            break;
        }
    }
}

std::size_t ATP::maxDepth(Node* manager) const {
    
    if (!manager)
    {
        return 0;
    }
    
    std::size_t maxSubodinateDepth = 0;
    for (Node* subordinate : manager->subordinates)
    {
        maxSubodinateDepth = std::max(maxSubodinateDepth, maxDepth(subordinate));
    }
    
    return 1 + maxSubodinateDepth;
}

std::size_t ATP::calculateSalary(Node* employee) const {
    
    std::size_t directSubord = employee->subordinates.size();

    if (directSubord == 0)
    {
        return 0;
    }

    std::size_t indirectSubord = 0;
    countEmployees(employee, indirectSubord);

    if (indirectSubord > 0)
    {
        indirectSubord -= 1;
    }
    
    indirectSubord -= directSubord;

    return 500 * directSubord + 50 * indirectSubord;
}

void ATP::incorporateHelper(Node* manager) {

    if (!manager)
    {
        return;
    }    
    
    for(Node* subordinate : manager->subordinates)
    {
        incorporateHelper(subordinate);
    }

    if (manager->subordinates.size() < 2)
    {
        return;
    }
    
    Node* toBePromoted = toPromote(manager->subordinates);

    for(Node* coworker : manager->subordinates)
    {
        if (coworker != toBePromoted)
        {
            toBePromoted->subordinates.push_back(coworker);
        }
    }

    std::vector<Node*>::iterator newEndIt = std::remove_if(manager->subordinates.begin(), manager->subordinates.end(),
                                [toBePromoted](const Node* employee){return employee != toBePromoted;} );

    manager->subordinates.erase(newEndIt, manager->subordinates.end());
}

ATP::Node* ATP::toPromote(std::vector<Node*>& subordinates) const {

    if (subordinates.empty()) 
    {
        return nullptr;
    }

    Node* highestSalaryNode = subordinates[0];
    std::size_t highestSalary = calculateSalary(subordinates[0]);

    for (Node* subordinate : subordinates) 
    {
        std::size_t subordinateSalary = calculateSalary(subordinate);

        if (subordinateSalary > highestSalary ||
            (subordinateSalary == highestSalary &&
             subordinate->name < highestSalaryNode->name)) 
        {
            highestSalaryNode = subordinate;
            highestSalary = subordinateSalary;
        }
    }

    return highestSalaryNode;
}

void ATP::modernizeHelper(Node* manager, std::size_t level) {

    if (!manager)
    {
        return;
    }

    for(Node* subordinate : manager->subordinates)
    {
        modernizeHelper(subordinate, level - 1);
    }

    if (manager->subordinates.size() == 0 || level % 2 == 0)
    {
        return;
    }

    this->fireHelper(manager);

    return;
}