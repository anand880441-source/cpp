#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores1 = {85, 90, 78, 92, 88};
    vector<int> scores2 = {85, 90, 78, 92, 88};

    // Check if both vectors are equal
    bool areEqual = equal(scores1.begin(), scores1.end(), scores2.begin());

    if (areEqual) {
        cout << "The vectors are equal." << endl;
    } else {
        cout << "The vectors are not equal." << endl;
    }

    return 0;
}