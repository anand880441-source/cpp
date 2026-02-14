#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    deque<string> strings;
    string str;

    cout << "Enter 3 strings:\n";

    for (int i = 0; i < 3; i++) {
        cout << "String " << (i + 1) << ": ";
        cin >> str;
        strings.push_back(str);
    }

    int value;
    cout << "Enter any Index : ";
    cin >> value;

    if(value < 4 && value > 0 ){
        cout << strings.at(value-1);
    }else{
        cout << "Enter valid value b/w 1-3" << endl;
    }

    // for(string c:strings){
    //     cout<< c << endl;
    // }

    return 0;
}
