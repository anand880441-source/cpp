#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){

    list<int> l1;

    int size;
    cout << "Enter number of elements : ";
    cin >> size;

    for(int i = 0; i<size; i++){
        int element;
        cout << "Enter your " << i+1 << " Element : ";
        cin >> element;
        l1.push_back(element);
    }

    ofstream outfile("result.txt");

    
    for(const auto& ele : l1){
        outfile << ele << " ";
    }

    outfile << "\n";
    outfile << "Max Element : ";
    outfile << "\n";
    outfile << "Min Element : ";
    outfile << "\n";
    outfile.close();
    cout << "Results stored in result.txt\n";

    return 0;
}