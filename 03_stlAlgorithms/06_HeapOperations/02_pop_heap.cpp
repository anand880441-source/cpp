#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {85, 90, 78, 92, 88};

    // Create a max-heap
    make_heap(scores.begin(), scores.end());

    // Remove the root element of the heap
    pop_heap(scores.begin(), scores.end());
    scores.pop_back();

    cout << "Heap after pop: ";
    for (const auto& score : scores) {
        cout << score << " ";
    }

    return 0;
}