#include <iostream>
using namespace std;

class Utility {
public:
    // Static function to add two numbers
    static int add(int a, int b) {
        return a + b;
    }

    // Static function to calculate the square of a number
    static int square(int num) {
        return num * num;
    }
};

int main() {
    // Calling static functions without creating an object
    cout << "Sum: " << Utility::add(10, 20) << endl;       // Output: Sum: 30
    cout << "Square: " << Utility::square(5) << endl;     // Output: Square: 25

    return 0;
}