#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {85, 90, 78, 92, 88};

    // Find the minimum element
    auto minScore = min_element(scores.begin(), scores.end());

    cout << "Minimum score: " << *minScore << endl;

    return 0;
}