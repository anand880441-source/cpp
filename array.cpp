#include <iostream>
using namespace std;

int main()
{

    // int arr[] = {1,2,3,4,5};
    // int length = sizeof(arr)/sizeof(arr[0]);

    // cout << length;

    int n;
    cout << "Enter Number of elements: ";
    cin >> n;
    
    // Dynamic allocation instead of VLA
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a Number: " << endl;
        cin >> arr[i];
        cout << "Current value of index: " << i << " is " << arr[i] << endl;
    }

    delete[] arr; 

    return 0;
}