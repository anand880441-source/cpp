#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    char op; 
    cout << "Enter first number : ";
    cin >> n1;
    cout << "Enter operator (+, -, *, /) : ";
    cin >> op;
    cout << "Enter second number : ";
    cin >> n2;

    switch (op) {
        case '+':
            cout << "Addition : " << n1 + n2 << endl;
            break;
        case '-':
            cout << "Subtraction : " << n1 - n2 << endl;
            break;
        case '*':
            cout << "Multiplication : " << n1 * n2 << endl;
            break;
        case '/':
            if (n2 != 0)
                cout << "Division : " << n1 / n2 << endl;
            else
                cout << "Error: Division by zero" << endl;
            break;
        default:
            cout << "Invalid Operator" << endl;
    }
    return 0;
}
