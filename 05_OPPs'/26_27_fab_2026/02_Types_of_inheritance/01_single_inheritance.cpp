#include <iostream>
#include <string>

using namespace std;

class Laptop
{
    // Common Data members...
public:
    string Ram = "Ram Available";
    string Storage = "Storage Available";
    string Mother_Boards = "MotherBoard is Available";

    // Common Functions members....

    void display()
    {
        cout << "Parent function got caled and the common data members are : " << endl;
        cout << "Ram : " << this->Ram << endl;
        cout << "Storage : " << this->Storage << endl;
        cout << "Mother Board : " << this->Mother_Boards << endl;
    }
};

class Lenovo : public Laptop
{
    // Distinct Data members..
public:
    string Storage_Type;
    string Ram_version;

    Lenovo(string Storage_Type, string Ram_version)
    {
        this->Storage_Type = Storage_Type;
        this->Ram_version = Ram_version;
    }
    void display1()
    {
        cout << "Children function is getting called : " << endl;
        cout << "Storage_Type : " << this->Storage_Type << endl;
        cout << "Ram_version : " << this->Ram_version << endl;
    }
};

int main()
{
    Lenovo l1("SSD", "16GB");
    l1.display();
    l1.display1();

    return 0;
}