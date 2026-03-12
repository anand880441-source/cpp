#include <iostream>
#include <string>

using namespace std;

class Poly
{
    public:
        int add(int a, int b){
            return a + b;
        }

        string add(string a, string b){
            return a + b;
        }

        float add(int a, float b){
            return a + b;
        }
};

int main(){

    Poly p1;

    cout << p1.add(10, 20.4f);

    return 0;
}