// #include <iostream>
// #include <string>

// using namespace std;

// class Laptop
// {
//     // Common Data members...
// public:
//     string Ram = "Ram Available";
//     string Storage = "Storage Available";
//     string Mother_Boards = "MotherBoard is Available";

//     // Common Functions members....

//     void display()
//     {
//         cout << "Parent function got caled and the common data members are : " << endl;
//         cout << "Ram : " << this->Ram << endl;
//         cout << "Storage : " << this->Storage << endl;
//         cout << "Mother Board : " << this->Mother_Boards << endl;
//     }
// };

// class Lenovo : public Laptop
// {
//     // Distinct Data members..
// public:
//     string Storage_Type;
//     string Ram_version;

//     Lenovo(string Storage_Type, string Ram_version)
//     {
//         this->Storage_Type = Storage_Type;
//         this->Ram_version = Ram_version;
//     }
//     void display1()
//     {
//         cout << "Children function is getting called : " << endl;
//         cout << "Storage_Type : " << this->Storage_Type << endl;
//         cout << "Ram_version : " << this->Ram_version << endl;
//     }
//     void accessParentVariable()
//     {
//         cout << "The storage value is : " << Storage << endl;
//     }
// };

// class LanovoSubBrand : public Lenovo
// {

// public:
//     LanovoSubBrand() : Lenovo("Default SSD", "8GB") {}
//     void display2()
//     {
//         cout << "This function is declared inside LenovoSubBrand who is a children class of its Lenovo parent only" << endl;
//         cout << "Storage_Type : " << Storage_Type << endl;
//         cout << "Ram_version : " << Ram_version << endl;
//     }
// };

// int main()
// {
//     // Lenovo l1("SSD", "16GB");
//     // l1.display();
//     // l1.display1();
//     // l1.accessParentVariable();

//     LanovoSubBrand l2;
//     l2.display2();

//     return 0;
// }


#include<iostream>
#include<string>

using namespace std;

class Parent{
    public:
    //Data members....
        string name;
        int a;
          
    // Constructor....
        Parent(string name, int a){
              cout << "The parent constructor is called through children class first" << endl;
              this->name = name;
              this->a = a;
              cout << "The work is done..." << endl;
          }
          
    // Fucntion members...
        void display(){
              cout << "The name of parent class is:  " << this->name << " the value is " << this->a << endl;
          }
};

class Parent2 : public Parent{
    public:
    //Data members....
        string name2;
        int a1;
          
    // Constructor....
        Parent2(string name, string name2, int a, int a1): Parent(name, a){
              cout << "The parent2 constructor is called through children class first" << endl;
              this->name2 = name2;
              this->a1 = a1;
              cout << "The work is done..." << endl;
          }
          
    // Fucntion members...
        void display(){
              cout << "The name of parent class is:  " << this->name2<< " the value is " << this->a1<<endl;
          }
};


class Children : public Parent2{
    public:
    //Data members....
        string name1;
          
    // Constructor....
        Children(string name1, string name, string name2, int a, int a1): Parent2(name, name2, a, a1){
              cout << "The Children constructor is called after the parent construtor is called" << endl;
              this->name1 = name1;
              cout << "The work is done..." << endl;
          }
          
    // Fucntion members...
        void display1(){
              cout << "The name of children class is:  " << this->name1 << endl;
          }
};


int main(){
    
    Children b1("Parent", "Children", "parent2", 34, 56);
    b1.display1();
    b1.display();
    return 0;
}