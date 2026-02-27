#include <iostream>
#include <string>

using namespace std;

class ParentA{
    public:
        string name = "ParentA";
        void display(){
            cout << "This name of my parentA class is : "<<this->name <<endl;
        }
};

class ParentB{
    public:
        string name1 = "ParentB";
        void display(){
            cout << "This name of my parentB class is : "<<this->name1 <<endl;
        }
};

class Children : public ParentA, public ParentB{
    public:
        string name2 = "Children";
        // void display(){
        //     cout << "This name of my children class is : "<<this->name2 <<endl;
        // }
};

int main(){

    Children c1;
    c1.ParentA::display();
    c1.ParentB::display();

    return 0;
}