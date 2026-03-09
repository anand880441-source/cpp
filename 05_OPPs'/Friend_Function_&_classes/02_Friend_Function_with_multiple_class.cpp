#include <iostream>
using namespace std;

class Tringle;

class Rectangle
{
private:
    int num1;

public:
    Rectangle(int numA) {
        num1 = numA;
    }

    friend void calculate(Rectangle, Tringle);
};

class Tringle
{
private:
    int num2;

public:
    Tringle(int numB){
        num2 = numB;
    }

    friend void calculate(Rectangle, Tringle);
};

void calculate(Rectangle objA, Tringle objB)
{
    cout << "Sum: " << objA.num1 + objB.num2 << endl;
}

int main()
{
    Rectangle objA(5);
    Tringle objB(7);
    calculate(objA, objB);
    return 0;
}