#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    m[1] = "Alice";
    m[2] = "Bob";
    m.insert({3, "Charlie"});

    for (auto& [key, value] : m) {
        cout << key << ": " << value << endl;
    }
    return 0;
}