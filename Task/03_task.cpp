// #include <iostream>
// #include <string>
// #include <fstream>
// #include <map>

// using namespace std;

// class Addition
// {
// public:
//     int num1 = 10;
//     int num2 = 20;
//     map<string, int> r1 = {{"Add", 0}};
//     void display()
//     {
//         ++r1["Add"];
//         cout << "The Addition is : " << this->num1 + this->num2 << endl;
//     }
// };

// class Subtraction
// {
// public:
//     int num1 = 10;
//     int num2 = 20;
//     map<string, int> r1 = {{"Sub", 0}};
//     void display()
//     {
//         ++r1["Sub"];
//         cout << "The Subtraction is : " << this->num1 - this->num2 << endl;
//     }
// };

// class Multiplication
// {
// public:
//     int num1 = 10;
//     int num2 = 20;
//     map<string, int> r1 = {{"Mul", 0}};
//     void display()
//     {
//         ++r1["Mul"];
//         cout << "The Multiplication is : " << this->num1 * this->num2 << endl;
//     }
// };

// class Division
// {
// public:
//     int num1 = 20;
//     int num2 = 10;
//     map<string, int> r1 = {{"Div", 0}};
//     void display()
//     {
//         ++r1["Div"];
//         if (num2 == 0)
//         {
//             cout << "Division by zero is not possible.." << endl;
//         }
//         else
//         {
//             cout << "The Division is : " << this->num1 / this->num2 << endl;
//         }
//     }
// };

// class Calculator : public Addition, public Subtraction, public Division, public Multiplication
// {
// public:
//     string name2 = "Children";
//     void display()
//     {
//         cout << "" << this->name2 << endl;
//     }
// };

// void fileOperation()
// {
//     ofstream file;
//     file.open("Result.txt", ios::app);

//     Calculator result1;

//     result1.Addition::display();
//     result1.Subtraction::display();
//     result1.Multiplication::display();
//     result1.Division::display();

//     if (file.is_open())
//     {
//         file << "\nThe result is : " << endl;
//         file << "Addition: " << result1.Addition::num1 + result1.Addition::num2 << endl;
//         file << "Subtraction: " << result1.Subtraction::num1 - result1.Subtraction::num2 << endl;
//         file << "Multiplication: " << result1.Multiplication::num1 * result1.Multiplication::num2 << endl;
//         file << "Division: " << result1.Division::num1 / result1.Division::num2 << endl;

//         file << "\nCounter :" << endl;
//         file << "Additon function called : " << result1.Addition::r1["Add"] << " times" << endl;
//         file << "Subtraction function called : " << result1.Subtraction::r1["Sub"] << " times" << endl;
//         file << "Multiplication function called : " << result1.Multiplication::r1["Mul"] << " times" << endl;
//         file << "Division function called : " << result1.Division::r1["Div"] << " times" << endl;
//         file.close();
//     }
// };

// int main()
// {
//     fileOperation();
//     return 0;
// }



#include <iostream>
#include<map>
#include<fstream>

using namespace std;

map<string, int> m1 = {
    {"Add", 0},
    {"Sub", 0},
    {"Mul", 0},
    {"Div", 0}
};


void fileOperation(int a, int b, double result, char oper){
    cout << "The write opration is initiated.." << endl;
    
    ofstream file;
    file.open("Practice.txt", ios::app);
    
    if(file.is_open()){
        file << "The actual operator is->  " << oper << endl;
        file << "The value of a: " << a << " and the value of b is: " << b << endl;
        file << "The result is: " << result << endl;
    }
    file.close();
}

class Add{
    
    //Function members...
    
    public:
    
    
      void add(int a, int b){
          cout << "The addition of two number is:  " << a+b << endl;
          cout << "The fileOperation got called pls wait for some moments to append the information" << endl;
          fileOperation(a, b, a+b, '+');
          cout << "The fileOperation is done without any error"<<endl;
          cout << "The frequency is been traced..." << endl;
          m1["Add"]++;
      }
    
};

class Sub{
    //Function members...
    
    public:
    
      void sub(int a, int b){
          cout << "The subtraction of two number is:  " << a-b << endl;
          cout << "The fileOperation got called pls wait for some moments to append the information" << endl;
          fileOperation(a, b, a-b, '-');
          cout << "The fileOperation is done without any error"<<endl;
          cout << "The frequency is been traced..." << endl;
          m1["Sub"]++;
      }

};

class Mul{
    //Function members...
    
    public:
    
      void mul(int a, int b){
          cout << "The multiplication of two number is:  " << a*b << endl;
          cout << "The fileOperation got called pls wait for some moments to append the information" << endl;
          fileOperation(a, b, a*b, '*');
          cout << "The fileOperation is done without any error"<<endl;
          cout << "The frequency is been traced..." << endl;
          m1["Mul"]++;

      }
   
};

class Div{
    //Function members...
    
    public:
    
      void divison(int a, int b){
          if(b != 0){
                cout << "The addition of two number is:  " << a/b << endl;
                cout << "The fileOperation got called pls wait for some moments to append the information" << endl;
                fileOperation(a, b, a/b, '/');
                cout << "The fileOperation is done without any error"<<endl;
               cout << "The frequency is been traced..." << endl;
               m1["div"]++;

          }
          else{
              cout << "The second number must be more than 0" << endl;
          }
      }
   
};

class Cal : public Add, public Sub, public Mul, public Div{
    
    //Funciton members....
    
    void display(){
        cout << "The display funvtion got called " << endl;
    }
    
    
};

int main()
{
    cout<<"The actual execution begin..." << endl;
    
    Cal c1;
    
    c1.add(10, 20);

    return 0;
}