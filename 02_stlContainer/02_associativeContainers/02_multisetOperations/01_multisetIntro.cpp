#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms = {10, 20, 30, 20}; // Allows duplicate 20
    ms.insert(30);

    for (int num : ms) {
        cout << num << " ";
    }
    return 0;
}