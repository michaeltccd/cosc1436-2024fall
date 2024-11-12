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

// Pointers can be passed as parameters
//void DisplayIntArray(int arr[], int size)
void DisplayIntArray(int* arr, int size)
{
    for (int index = 0; index < 100; ++index)
        std::cout << arr[index] << " ";
    std::cout << std::endl;
};

void ArrayPointerDemo()
{
    int values[100];

    // Array variables are pointers
    int* ptrValues = values;

    for (int index = 0; index < 100; ++index)
    {
        //Pointer arithmetic
        //  Add/subtraction
        //  Value is always multiplied by sizeof(T) so you are referencing a whole element
        //arr[index] = arr + index = arr + (sizeof(T) * index)
        // arr[index] = *(arr + index)        
        *(ptrValues + index) = index + 1;
    };
    /*for (int index = 0; index < 100; ++index)
        values[index] = index + 1;*/

    DisplayIntArray(ptrValues, 100);

    int localVariable = 100;
    DisplayIntArray(&localVariable, 1);
}

void NewArrayDemo()
{
    //double arr[100];

    //Dynamically allocate array at runtime
    int size;
    std::cout << "How many elements: ";
    std::cin >> size;

    //Array decl won't work at runtime
    // new T[size]
    //   Size must be integral and > 0
    // Ensure you delete this when done
    double* arr = new double[size];

    //Arrays and pointers are interchangeable so nothing else changes
    for (int index = 0; index < size; ++index)
    {
        std::cout << "Enter a value: ";
        std::cin >> arr[index];

        if (arr[index] == 0)
            break;
    };

    //Cleanup
    //delete arr; // This is wrong by the way
    delete[] arr; // Required for arrays
};

void NewArrayDemo2()
{
    while (true)
    {
        NewArrayDemo();

        std::cout << "Keep going (Y/N)? ";
        
        char choice;
        std::cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    };
};

// Employee is pass by reference, any changes to employee are visible to caller
void InitializeEmployeeByRef(int& employee)
{
    //No need to validate argument

    std::cout << "Enter the employee ID: ";
    //std::getline(std::cin, employee.Name);
    std::cin >> employee;
};

// Employee is pass by value (memory address)
// When dereferencing the pointer then any changes to value are visible to caller
void InitializeEmployeeByPtr(int* employee)
{    
    //Validate pointer
    if (employee)  //employee != nullptr || employee != NULL
    {
        //employee++;

        std::cout << "Enter the employee ID: ";
        //std::getline(std::cin, employee.Name);
        std::cin >> *employee;
    };
};

void PassByRefVsPointerDemo()
{
    //Employee employee;
    int employeeId;

    //Pass by ref - must pass a variable
    InitializeEmployeeByRef(employeeId);

    // Pass by value - must pass the address of variable
    InitializeEmployeeByPtr(&employeeId);

    InitializeEmployeeByPtr(nullptr);
};

int main()
{
    //StackDemo();
    //EmptyDemo();
    //DynamicMemoryDemo();
    //ArrayPointerDemo();
    NewArrayDemo2();
}
