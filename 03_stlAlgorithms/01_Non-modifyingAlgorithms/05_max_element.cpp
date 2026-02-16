#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {85, 90, 78, 92, 88};

    // Find the maximum element
    auto maxScore = max_element(scores.begin(), scores.end());

    cout << "Maximum score: " << *maxScore << endl;

    return 0;
}