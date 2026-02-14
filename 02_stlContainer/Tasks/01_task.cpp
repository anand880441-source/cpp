#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {};

    for (int i = 0; i < 5; i++)
    {
        int num;
        printf("Enter %d numbers : ", i + 1);
        scanf("%d", &num);
        v.push_back(num);
    }

    cout << "Out : " << " ";
    for (int num : v)
    {
        cout << num << " ";
    }

    
    sort(v.begin(), v.end());

    cout << "Sorted : " << " ";
    for (int num : v)
    {
        cout << num << " ";
    }

    
    reverse(v.begin(), v.end());
    cout << "Reversed : "<< " ";
    for (int num : v)
    {
        cout << num << " ";
    }

    return 0;
}