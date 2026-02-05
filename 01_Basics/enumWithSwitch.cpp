#include <iostream>
using namespace std;

enum word
{
    LOW,
    MEDIUM,
    HIGH
};

int main()
{

    enum word a1 = LOW;
    enum word a2 = MEDIUM;
    enum word a3 = HIGH;

    cout << "The value of returned by a1 is : " << a2 << endl;

    switch (a3)
    {
    case 0:
        cout << "The case0 is executed" << endl;
        break;
    case 1:
        cout << "The case1 is executed" << endl;
        break;
    default:
        cout << "The default is executed" << endl;
    }

    return 0;
}