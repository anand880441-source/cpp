#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){

    vector<int> v;

    int size;
    cout << "Enter number of elements : ";
    cin >> size;

    for(int i = 0; i<size; i++){
        int element;
        cout << "Enter your " << i+1 << " Element : ";
        cin >> element;
        v.push_back(element);
    }

    ofstream outfile("output.txt");

    
    for(const auto& ele : v){
        outfile << ele << " ";
    }
    outfile << "\n";

    sort(v.begin(),v.end());

    outfile << "After sort : ";
    for(const auto& ele : v){
        outfile << ele << " ";
    }
    outfile << "\n";

    reverse(v.begin(),v.end());

    outfile << "After Reverse : ";
    for(const auto& ele : v){
        outfile << ele << " ";
    }
    outfile << "\n";

    outfile.close();
    cout << "Results stored in output.txt\n";

    return 0;
}