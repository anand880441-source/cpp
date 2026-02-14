// #include <iostream>
// #include <vector>
// #include <cstdio>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     vector<int> v;
//     int num;
//     for (int i = 0; i < 10; i++)
//     {
//         printf("Enter %d numbers : ", i + 1);
//         scanf("%d", &num);
//         v.push_back(num);
//     }

//     vector<int> temp;
//     for (int i = 0; i < v.size(); i++)
//     {
//         // if(v.at(i)%2 != 0){
//         //     temp.push_back(v.at(i));
//         // }
//         if(i%2 != 0){
//             temp.push_back(v.at(i));
//         }
//     }
//     v = temp;
//     cout << "\nSize : "<<v.size() <<"\n";

//     for (int num : v)
//     {
//         cout << num << " ";
//     }
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector <int> v(10);
    
    cout << "enter 10 element" << endl;
    for(int i=0;i<10;i++){
        cin >> v[i];
    }
    
    for(int i=9;i>=0;i--){
        if(i%2==0){
            v.erase(v.begin()+i);
            cout << "\nindex element that is removed :- " << i << endl;
        }
    }
    
    cout << "\nremaining element are :- " << endl;
    
    for(int value : v){
        cout << value << " ";
    }
    
    cout << "\ntotal size :- " << v.size() << endl;
    
    return 0;
}