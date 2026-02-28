#include <iostream>

using namespace std;

class Lenovo
{
    // function members....
public:
    void display()
    {
        cout << "The Lenovo class is a parent class" << endl;
    }
};

class Legion : public Lenovo
{
public:
    void display1()
    {
        cout << "The Legion class is a child class of it's Lenovo parent class" << endl;
    }
};

class Yoga : public Lenovo
{
public:
    void display2()
    {
        cout << "The Yoga class is a child class of it's Lenovo parent class" << endl;
    }
};

class Loq : public Lenovo
{
public:
    void display3()
    {
        cout << "The Loq class is a child class of it's Lenovo parent class" << endl;
    }
};

int main()
{

    Yoga y1;

    y1.display();
    y1.display2();

    Legion l1;

    l1.display();
    l1.display1();
    return 0;
}