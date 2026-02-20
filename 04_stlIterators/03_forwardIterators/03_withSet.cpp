#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> s1 = {"Samir singh", "amit singh", "sumit"};
    
    auto itr2 = s1.begin();
    
    while(itr2 != s1.end()){
        cout << "Forwarrd Iterator current value:  " << *itr2 << endl;
        ++itr2;
    }
    
    cout << "Map Element are beign printed one by one..." << endl;

    return 0;
}