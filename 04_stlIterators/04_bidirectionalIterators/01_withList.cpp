#include <iostream>
#include <list>

using namespace std;

int main(){

    list <char> l1 = {'a','b','c','d'};

    auto itr = l1.end();

    while(itr != l1.begin()){
        --itr;
        cout << "backword Itrator current value : " << *itr << endl;
    }

    return 0;

}