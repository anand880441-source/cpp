#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template <typename T1, typename T2>
void add(T1 a, T2 b)
{
    auto c = a + b;

    if constexpr (is_same_v<T2, string>)
    {
        cout << "Greeting: " << c << "!" << endl;
    }
    else
    {
        cout << "Addition : " << c << endl;
    }
}

int main()
{
    int num;
    cout << "Type 1 for Performing Addition" << endl;
    cout << "Type 2 to display Greeting Message" << endl;
    cout << "Enter your choosen number : ";
    cin >> num;

    if (num == 1)
    {
        double n1, n2;
        cout << "First Number : ";
        cin >> n1;
        cout << "Second Number : ";
        cin >> n2;

        add(n1, n2);
    }
    else if (num == 2)
    {
        string name;
        cout << "Enter your first name : ";
        cin >> name;

        // add(string("a"), string("b"));
        add(string("Hello "), name);
    }

    return 0;
}
