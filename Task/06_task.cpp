#include <iostream>

using namespace std;

class Config {
private:
    static int value;

public:
    static void setValue(int v) {
        value = v;
    }

    static int getValue() {
        return value;
    }
};

int Config::value = 0;

int main() {
    Config c1;
    c1.setValue(415);

    cout << "The value is : " << c1.getValue() << endl; 

    return 0;
}
