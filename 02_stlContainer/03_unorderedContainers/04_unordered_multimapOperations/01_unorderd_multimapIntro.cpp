#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_multimap<string, string> courses;
    courses.insert({"DSA", "Prof. Jenil"});
    courses.insert({"DSA", "Prof. Krishna"});
    courses.insert({"Web Dev", "Prof. Yashvi"});

    for (auto& [course, professor] : courses) {
        cout << course << ": " << professor << endl;
    }
    return 0;
}