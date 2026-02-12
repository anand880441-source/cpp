#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file;
    int n;
    
    file.open("sample.txt", ios::trunc);

    if (file.is_open())
    {
        cout << "Enter number of terms for Fibonacci series: ";
        cin >> n;
        
        int a = 0, b = 1;
                
        for (int i = 0; i < n; i++)
        {
            file << a << endl;
            int temp = a + b;
            a = b;
            b = temp;
        }
        
        file.close();
    }
    return 0;
}