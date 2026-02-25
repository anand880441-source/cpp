#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string comp_name;
    int milage;
    string model;

    void print() {
        cout << "\nThe print function is defined inside Car class:" << endl;
        cout << "Company name is : " << this->comp_name << endl;
        cout << "Car milage is : " << this->milage << endl;
        cout << "Car model is : " << this->model << endl;
    }
};

int main() {
    Car c1;
    c1.comp_name = "Toyota";
    c1.milage = 40;
    c1.model = "supra Mk4";
    c1.print();

    Car c2;
    c2.comp_name = "Tata";
    c2.milage = 70;
    c2.model = "nano";
    c2.print();
    return 0;
}
