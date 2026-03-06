#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    
    public:
       string userName;
       
    protected:   
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
    
        Child(string name, int balance):BankAccount(name, balance){}
        
        void display1(){
            cout << "User name is:->" << userName << endl;
            
            cout << "Current balance is:->" << bankBalance << endl;
        }
        
};
// class Child : public BankAccount{
    
//     public:
      
//       void display1(){
//           cout << "Current     BankBalance is:->" << bankBalance << endl;
//       }
    
// };


int main(){
    
    Child c1("Samir singh", 675);
    c1.display1();

    return 0;
}