#include <iostream>
#include <iomanip>
#include <string>

void StackDemo()
{
    double localDouble = 45.6;

    //Declare a pointer to a double
    // Pointer is always a memory address
    // Pointer is always either 4 or 8 bytes long 
    // Pointer value is always an integral value

    // Pointers have 2 data points: integral value (memory address), value they reference (in memory)
    // address-of :: & variable
    //     Type of expression is T* where T is the type of the variable 
    double* ptrDouble = &localDouble; //pointer to double

    //Assign new value to value at memory address
    *ptrDouble = 89.7;
    
    //Type coercion doesn't behave the same with pointers
    int localInt = 56;
    localDouble = localInt;
    //ptrDouble = &localInt; not allowed

    // double* != double
    //   ptrDouble = 90.6;   

    // Dereferencing a pointer
    //  dereference-op :: *E
    //    Type of expression is T where E is T*
    std::cout << ptrDouble << " " << *ptrDouble << std::endl;
    std::cout << (*ptrDouble == localDouble) << std::endl;
};

void EmptyDemo()
{
    float payRate = 12.50;

    // Always init to 0 or valid memory
    //float* pPayRate = NULL;    // C, old school, not recommended
    float* pPayRate = nullptr;   // C++, recommended

    //Print value and dereferenced value
    std::cout << pPayRate << " = ";

    //Always verify pointer before dereferencing
    //    if (ptr != nullptr)
    //    if (ptr != NULL) //not recommended
    //    if (ptr)
    //if (pPayRate != nullptr)
    if (pPayRate)
        std::cout << *pPayRate;
    std::cout << std::endl;
}

struct Employee
{
    int Id;
    std::string Name;

    int DummyValues[1000];
};

void DynamicMemoryDemo()
{
    const int MaxEmployees = 100;
    Employee* employees[MaxEmployees] = {0};
    int id = 1000;

    //int numberOfEmployees = 0;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        std::string name;
        std::cout << "Enter name or empty to quit: ";
        std::getline(std::cin, name);

        if (name == "")
            break;

        //Add to array 
        // new-op ::  new T; returns T*
        Employee* employee = new Employee;        
        //(*employee).Id = ++id;
        employee->Id = ++id;
        employee->Name = name;
        employees[index] = employee;
        //++numberOfEmployees;
    };

    //Print employees
    for (int index = 0; index < MaxEmployees; ++index)
    {
        //If done then abort
        if (employees[index] == nullptr)
            break;

        std::cout << "[" << employees[index]->Id << "] " << employees[index]->Name << std::endl;
    };

    // Ensure that any memory allocated by new is cleaned up using delete
    //  delete-op ::= delete E;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)
            break;

        //Delete the memory
        Employee* employee = employees[index];
        delete employee;
        employees[index] = nullptr;  //Always reset to null to avoid issues
        delete employees[index];  //This works
        //employee->Id = 20;  //Going to fail 
        
        //delete &index;  //Bad things will happen
    };
}

int main()
{
    //StackDemo();
    //EmptyDemo();
    DynamicMemoryDemo();
}
