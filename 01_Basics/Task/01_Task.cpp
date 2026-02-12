#include <iostream>
using namespace std;

int add(int n1, int n2){
    return n1+n2;
}
int sub(int n1, int n2){
    return n1-n2;
}
int mul(int n1, int n2){
    return n1*n2;
}
float division(int n1, int n2){
    if(n2 == 0){
        cout << "number is not divisible by 0." << endl;
    }
    return n1 / n2;
}

int main(){

    int n1,n2;
    cout << "Enter first number : ";
    cin >> n1;
    cout << "Enter second number : ";
    cin >> n2;

    cout <<"Addition : " << add(n1,n2) <<endl;
    cout <<"Subtraction : " << sub(n1,n2) <<endl;
    cout <<"Multiplication : " << mul(n1,n2) <<endl;
    cout <<"Division : " << division(n1,n2) <<endl;

    return 0;
}