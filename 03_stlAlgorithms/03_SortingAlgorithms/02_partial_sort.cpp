#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {85, 90, 78, 92, 88};

    // Partially sort the first 3 elements
    partial_sort(scores.begin(), scores.begin() + 3, scores.end());

    cout << "Partially sorted scores: ";
    for (const auto& score : scores) {
        cout << score << " ";
    }

    return 0;
}