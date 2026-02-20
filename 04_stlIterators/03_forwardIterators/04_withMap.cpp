#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int, string> m1;

    m1[0] = "Samir1";
    m1[1] = "amit1";
    m1[2] = "saurav";

    auto itr3 = m1.begin();

    while (itr3 != m1.end())
    {
        cout << "Forward Iterator and tthe keyy is:  " << itr3->first << "it's value is:  " << itr3->second << endl;
        ++itr3;
    }

    return 0;
}