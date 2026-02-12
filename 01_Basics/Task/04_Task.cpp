#include <iostream>
using namespace std;

int main(){
    int num;
    int res = 0;
    int temp;
    cout << "Enter any Number : ";
    cin >> num;

    temp = num;

    while(temp > 0){
        res = res * 10 + temp % 10;
        temp = temp / 10;
    }

    if(res == num){
        cout << num << " is a Palindrome" << endl;
    }
    else{
        cout << num << " is NOT a Palindrome" << endl;
    }

    return 0;
}