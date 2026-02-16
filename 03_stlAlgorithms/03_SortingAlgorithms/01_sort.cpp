#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {

    // ============== VECTOR ===============

    vector<int> scores = {85, 90, 78, 92, 88};

    sort(scores.begin(), scores.end());

    cout << "Sorted scores: ";
    for (const auto& score : scores) {
        cout << score << " ";
    }
    cout << '\n';

    // ============= LIST ===============

    list<int> l1 = {85, 90, 78, 92, 88};

    l1.sort();

    cout << "Sorted l1: ";
    for (const auto& score : l1) {
        cout << score << " ";
    }

    return 0;
}