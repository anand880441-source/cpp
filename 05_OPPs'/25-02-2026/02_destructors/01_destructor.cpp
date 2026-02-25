#include <iostream>
using namespace std;

class Student {
private:
    string name;

public:
    // Parameterized Constructor
    Student(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student student1("Krishna");
    Student student2("Priyasha");

    return 0;
}