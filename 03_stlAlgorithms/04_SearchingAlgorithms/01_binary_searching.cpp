#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {784, 845, 188, 90, 92};  // Already sorted

    sort(scores.begin(), scores.end());
    // Search for the score 90
    bool found = binary_search(scores.begin(), scores.end(), 90);

    if (found) {
        cout << "Found score 90" << endl;
    } else {
        cout << "Score 90 not found" << endl;
    }

    return 0;
}