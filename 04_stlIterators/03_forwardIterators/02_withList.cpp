#include <iostream>
#include <list>

using namespace std;

int main()
{
    list <char> v = {'a', 'b', 'c', 'd'};

    auto itr = v.begin();
    while(itr != v.end()){
        cout << "Forward Iterator current value : " << *itr << endl;
        itr++;
    }

    return 0;
}