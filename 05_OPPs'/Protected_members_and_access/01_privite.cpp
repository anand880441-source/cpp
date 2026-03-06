#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    
    public:
       string userName;
       
    private:   
       int bankBalance;
       
    public:
       
       BankAccount(string name, int balance){
           userName = name;
           bankBalance = balance;
       }
       
       void displayUserDetail(){
           cout << "Account holder name is:->" << this->userName << endl;
           cout << "Current balance is:->" << this->bankBalance << endl;
       }
    
};

class Child : public BankAccount{
    
    public:
      
       void display1(){
           cout << "Current     BankBalance is:->" << bankBalance << endl;
       }
    
};


int main(){
    
    BankAccount p1("Samir singh", 7869);
    p1.displayUserDetail();
    BankAccount p2("Utkarsh", 9876);
    p2.displayUserDetail();

    return 0;
}