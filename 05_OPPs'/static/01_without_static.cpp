#include <iostream>

using namespace std;

class CreateObj
{
public:
    int count = 0;

    CreateObj()
    {
        ++count;
        cout << "The counter incremented to trace the number of objects.." << endl;
    }

    void display()
    {
        cout << "count : " << count << endl;
    }
};

int main()
{

    CreateObj o;
    o.display();

    CreateObj o1;
    o1.display();

    CreateObj o2;
    o2.display();

    return 0;
}