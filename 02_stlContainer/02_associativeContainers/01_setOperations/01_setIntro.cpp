#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {10, 20, 30};
    s.insert(40);  // Insert element
    s.erase(20);   // Remove element

    for (int num : s) {
        cout << num << " ";
    }
    return 0;
}