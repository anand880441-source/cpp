#include <iostream>
#include <string>
using namespace std;

class Cars
{
public:
    virtual void engine()
    {
        cout << "Engine" << endl;
    }

    virtual ~Cars() {cout << "Cars is destroyed" << endl;}
};

class Tata : public Cars
{
public:
    void engine() override
    {
        cout << "CNG" << endl;
    }
};

int main()
{
    // Cars *c1 = new Tata;
    // c1->engine();

    // delete c1;
    // return 0;

    Cars* c1;
    Tata c2;
    c1 = &c2;
    c1->engine();
    return 0;
}

// #include <iostream>

// using namespace std;

// class Animal
// {

// public:
//     void speak()
//     {
//         cout << "make sound" << endl;
//     }
// };

// class Dog : public Animal
// {

// public:
//     void speak()
//     {
//         cout << "Bark" << endl;
//     }
// };

// int main()
// {

//     Dog d1;

//     d1.speak();

//     Animal a1;

//     a1.speak();

//     return 0;
// }