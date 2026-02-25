#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
    Student() {
        name = "Unknown";
        rollNumber = 0;
    }

    void display() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student student1; 
    student1.display();
    return 0;
}