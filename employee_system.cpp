
#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    int id;
    std::string name;
    std::string position;
    double salary;
    
    Employee(int i, std::string n, std::string p, double s) 
        : id(i), name(n), position(p), salary(s) {}
    
    void display() {
        std::cout << "ID: " << id << " | Name: " << name 
                  << " | Position: " << position << " | Salary: $" << salary << "\n";
    }
};

class EmployeeManager {
    std::vector<Employee> employees;
public:
    void addEmployee(int id, std::string name, std::string pos, double sal) {
        employees.push_back(Employee(id, name, pos, sal));
        std::cout << "Employee added successfully!\n";
    }
    
    void showAll() {
        std::cout << "\n=== All Employees ===\n";
        for(auto& emp : employees) emp.display();
    }
    
    Employee* findById(int id) {
        for(auto& emp : employees)
            if(emp.id == id) return &emp;
        return nullptr;
    }
};

int main() {
    EmployeeManager manager;
    manager.addEmployee(101, "John Doe", "Developer", 75000);
    manager.addEmployee(102, "Jane Smith", "Manager", 90000);
    manager.showAll();
    return 0;
}

