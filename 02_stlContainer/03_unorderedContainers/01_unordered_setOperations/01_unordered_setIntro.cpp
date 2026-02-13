#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> studentIDs = {101, 102, 103};

    studentIDs.insert(104);  // Insert a student ID
    studentIDs.erase(102);   // Remove student ID

    for (int id : studentIDs) {
        cout << id << " ";  
    }
    return 0;
}