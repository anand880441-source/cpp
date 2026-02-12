#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// int main(){
//     ofstream file;

//     file.open("sample.txt",ios::app);

//     if(file.is_open()){
//         file << "First time using the file operation with the help of ofstream method." <<endl;
//         file.close();
//     }
//     return 0;
// }

//==>from user

int main()
{
    ofstream file;

    string userInp;
    file.open("sample.txt", ios::app);

    if (file.is_open())
    {
        cout << "Enter Any One-Line statement: ";
        getline(cin, userInp);
        file << userInp << endl;
        file.close();
    }
    return 0;
}