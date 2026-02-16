#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>
using namespace std;

int main() {

    //================== VECTOR =====================

    vector<int> scores = {85, 90, 78, 92, 88};

    // Search for the score 92 in vector
    auto it = find(scores.begin(), scores.end(), 92);

    if (it != scores.end()) {
        cout << "Found score: " << *it << endl;
    } else {
        cout << "Score not found" << endl;
    }



    //================== SET =====================

    set<int> s1 = {85, 90, 78, 92, 88};

    // Search for the score 92 in set
    auto itr = find(s1.begin(), s1.end(), 92);

    if (itr != s1.end()) {
        cout << "Found element: " << *it << endl;
    } else {
        cout << "element not found" << endl;
    }


    deque<int> d1 = {85, 90, 78, 92, 88};

    // Search for the score 92 in set
    auto itrr = find(d1.begin(), d1.end(), 92);

    if (itrr != d1.end()) {
        cout << "Found element: " << *it << endl;
    } else {
        cout << "element not found" << endl;
    }

    return 0;
}