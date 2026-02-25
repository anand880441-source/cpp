#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int mark1, mark2; // Separate variables for marks

public:
    // Parameterized Constructor
    Student(string n, int m1, int m2) : name(n), mark1(m1), mark2(m2) {}

    // Copy Constructor
    Student(const Student &s) : name(s.name), mark1(s.mark1), mark2(s.mark2) {}

    void display() {
        cout << "Name: " << name << ", Marks: " << mark1 << ", " << mark2 << endl;
    }
};

int main() {
    Student student1("Arjun", 85, 90);

    Student student2 = student1; // Copy constructor is called

    student1.display();
    student2.display();

    return 0;
}
