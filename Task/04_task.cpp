#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;

public:
    static int totalEmployees;
    Employee(string n) : name(n)
    {
        totalEmployees++;
    }

    static int getTotal()
    {
        return totalEmployees;
    }
};

int Employee::totalEmployees = 0;

int main()
{
    Employee e1("Exampple");
    Employee e2("Hello");
    cout << "total=" << Employee::getTotal() << endl;

    return 0;
}
