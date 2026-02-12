#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {10, 20, 30};
    l.push_front(5);  
    l.push_back(40); 
    l.reverse();     

    auto it = l.begin();
    advance(it, 2);  
    l.insert(it, 25);

    for (int num : l) {
        cout << num << " ";
    }
    return 0;
}