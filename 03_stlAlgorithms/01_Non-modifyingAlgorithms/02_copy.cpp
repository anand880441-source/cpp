#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> originalScores = {85, 90, 78, 92, 88};
    vector<int> copiedScores(5);

    // Copy elements from originalScores to copiedScores
    copy(originalScores.begin(), originalScores.end(), copiedScores.begin());

    cout << "Copied scores: ";
    for (const auto& score : copiedScores) {
        cout << score << " ";
    }

    return 0;
}