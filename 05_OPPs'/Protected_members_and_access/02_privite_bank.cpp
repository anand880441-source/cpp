#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string toLower(string data) {
    for (int i = 0; i < data.length(); i++) {
        data[i] = tolower(data[i]);
    }
    return data;
}


class Bank {
public:
    string userName;
    int pass = 1234;

    Bank(string name, int balance) {
        userName = toLower(name);
        bankBalance = balance;
    }

    void displayUserDetail(int inputPass) {
        if (inputPass == pass) {
            cout << "\nAccount holder name: " << userName << endl;
            cout << "Current balance: " << bankBalance << endl;
        } else {
            cout << "Access Denied: Incorrect Password!" << endl;
        }
    }

private:
    int bankBalance;
};

int main() {
    vector <Bank> accounts = {
        Bank("Anand", 5000),
        Bank("Kishan", 145050)
    };

    string searchName;
    cout << "Enter User Name: ";
    cin >> searchName;

    bool found = false;
    for (auto &account : accounts) {
        if (account.userName == toLower(searchName)) {
            found = true;
            int inputPass;
            cout << "Enter Your Four Digit Password: ";
            cin >> inputPass;
            account.displayUserDetail(inputPass);
            break; 
        }
    }

    if (!found) {
        cout << "Error: User name does not exist." << endl;
    }

    return 0;
}
