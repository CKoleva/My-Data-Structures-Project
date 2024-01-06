#pragma once

#include <string>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <queue>

class Association;

class ATP {
public:
    ATP(const std::string& name);

    ATP(const ATP& other);

    ATP& operator= (const ATP& other);

    ~ATP();

    std::string getName();

    std::string hierarchyRepresentation();

    bool find(const std::string& employee) const;

    std::size_t numSubordinates(const std::string& employee) const;

    std::string getManager(const std::string& employee) const;

    std::size_t numEmployees() const;

    std::size_t overloaded(std::size_t overloadNumber) const;

    void fire(const std::string& employee);

    void hire(const std::string& employee, const std::string& manager);

    std::size_t maxChainLength();

    std::size_t salary(const std::string& employee) const;

    void incorporate();

    void modernize();

    void mergeATPs(const ATP* atp1, const ATP* atp2);

private:
    struct Node
    {
        std::string name;
        std::vector<Node*> subordinates;    

        Node(const std::string& name);
    };

    Node* manager;
    std::string name;

    void dealocate(Node* manager);

    Node* copy(Node* manager);

    void hierarchyRepresentationHelper(Node* manager, std::string& result);

    void sortTree(Node* manager);

    void sortSubordinates(Node* manager);

    Node* findHelper(Node* manager, const std::string& employee) const;

    void countSubordinates(const Node* current, Node* employee, std::size_t& count) const;

    Node* getManagerHelper(Node* manager, Node* employee) const;

    void countEmployees(const Node* manager, std::size_t& count) const;

    std::size_t overloadedHelper(const Node* manager, std::size_t overloadNumber, std::size_t& count) const;

    void fireHelper(Node* employee);

    void removeSubordinate(Node* manager, Node* employee);

    std::size_t maxDepth(Node* manager) const;

    std::size_t calculateSalary(Node* employee) const;

    void incorporateHelper(Node* manager);

    Node* toPromote(std::vector<Node*>& subordinates) const;

    void modernizeHelper(Node* manager, std::size_t level);

};