#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<string> attendance = {"Jenil", "Mahir", "Yashvi", "Mahir"};

    attendance.insert("Krishna");  // Insert a duplicate

    for (auto& name : attendance) {
        cout << name << " ";
    }
    return 0;
}