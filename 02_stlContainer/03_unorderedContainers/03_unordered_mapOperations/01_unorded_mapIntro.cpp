#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> rollNumbers;
    rollNumbers[101] = "Priyesha";
    rollNumbers[102] = "Arjun";
    rollNumbers.insert({103, "Yashvi"});

    for (auto& [roll, name] : rollNumbers) {
        cout << roll << ": " << name << endl;
    }
    return 0;
}