#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <char> v = {'a', 'b', 'c', 'd'};

    auto itr = v.begin();
    while(itr != v.end()){
        cout << "Forward Iterator current value : " << *itr << endl;
        itr++;
    }

    return 0;
}