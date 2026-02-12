#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "Size: " << arr.size() << endl;
    cout << "First Element: " << arr.front() << endl;
    cout << "Last Element: " << arr.back() << endl;
    return 0;
}