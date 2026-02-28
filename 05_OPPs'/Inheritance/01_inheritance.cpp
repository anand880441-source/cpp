#include <iostream>
using namespace std;

class Vehicle {
public:
    string brand = "Toyota";
    void honk() {
        cout << "Beep! Beep!" << endl;
    }
};

class Car : public Vehicle {
public:
    string model = "Corolla";
};

int main() {
    Car myCar;
    cout << "Brand : " << myCar.brand << "\n";
    cout << "Model: " << myCar.model << "\n";
    myCar.honk();
    return 0;
}