#include <iostream>

using namespace std;

class CreateObj
{
public:
    static int count;

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

int CreateObj::count = 0;

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