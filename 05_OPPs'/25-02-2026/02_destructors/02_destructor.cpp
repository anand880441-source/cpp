#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int age;

    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
        cout << "name :  "<< name << "  age : " <<age <<endl;
    }

    ~Student(){
        cout << "The particular object getting destroyed." <<endl;
    }
};


void studentObject(){
    cout << "Student Object called outside int main() function." <<endl;
    Student s2("moltec",22);
};

int main()
{
    Student s1("spino",18);
    Student s2("divon",19);
    studentObject();
    return 0;
}