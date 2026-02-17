#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {85, 90, 78, 92, 88};

    // Create a max-heap
    make_heap(scores.begin(), scores.end());

    // Insert a new element into the heap
    scores.push_back(95);
    push_heap(scores.begin(), scores.end());

    cout << "Heap after push: ";
    for (const auto& score : scores) {
        cout << score << " ";
    }

    return 0;
}