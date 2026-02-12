#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d = {10, 20, 30};
    d.push_front(5); // Add at front
    d.push_back(40); // Add at end
    d.pop_front();   // Remove first element

    for (int num : d) {
        cout << num << " ";
    }
    return 0;
}