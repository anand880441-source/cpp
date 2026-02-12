#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string oneLineStatement;
    ifstream file;

    file.open("sample.txt");

    if(file.is_open()){
        cout << "The actual data is gonna print for a given file below : " << endl;
        while(getline(file,oneLineStatement)){
            cout <<oneLineStatement<<endl;
        }
        
        file.close();
    }
    return 0;
}