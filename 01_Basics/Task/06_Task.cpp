#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    string oneLineStatement;
    ifstream file;

    file.open("sample.txt");

    if (file.is_open())
    {
        cout << "The actual data is gonna print for a given file below : " << endl;
        while (getline(file, oneLineStatement))
        {
            cout << oneLineStatement << endl;
        }

        file.close();
    }

    ofstream file1;

    file1.open("sample.txt", ios::app);

    if (file1.is_open())
    {
        file1 << "First time using the file operation with the help of ofstream method." << endl;
        file1.close();
    }
    return 0;
}