#include <iostream>
#include <string> // Required for std::string
using namespace std;

int main()
{
    cout << "=== STRING DECLARATION AND INITIALIZATION ===" << endl;
    
    // Different ways to create strings
    string s1;                 // Empty string
    string s2 = "Hello";       // Direct initialization
    string s3("World");        // Constructor initialization
    string s4(s2);             // Copy constructor
    string s5(5, 'A');         // "AAAAA" - 5 copies of 'A'
    string s6 = s2 + " " + s3; // Concatenation

    cout << "s1: '" << s1 << "'" << endl;         // Empty
    cout << "s2: " << s2 << endl;                 // Hello
    cout << "s3: " << s3 << endl;                 // World
    cout << "s4: " << s4 << endl;                 // Hello (copy of s2)
    cout << "s5: " << s5 << endl;                 // AAAAA
    cout << "s6: " << s6 << endl;                 // Hello World
    
    cout << "\n=== STRING INPUT/OUTPUT ===" << endl;
    
    // a) Input/Output
    string name1, name2;
    cout << "Enter your full name: ";
    getline(cin, name1); // Read entire line including spaces
    cout << "Hello! " << name1 << endl;
    
    cout << "\nEnter a single word: ";
    cin >> name2;        // Read single word (stops at space)
    cout << "Word entered: " << name2 << endl;
    
    // Clear input buffer
    cin.ignore(1000, '\n');
    
    cout << "\n=== ACCESSING CHARACTERS ===" << endl;
    
    // b) Accessing Characters
    string str1 = "Hello";
    cout << "String: " << str1 << endl;
    cout << "str1[0]: " << str1[0] << endl;      // 'H' - array-like access
    cout << "str1.at(1): " << str1.at(1) << endl;   // 'e' - bounds checked
    cout << "str1.front(): " << str1.front() << endl; // 'H' - first character
    cout << "str1.back(): " << str1.back() << endl;  // 'o' - last character
    
    cout << "\n=== STRING MODIFICATION ===" << endl;
    
    // c) String Modification
    string str2 = "Hello";
    cout << "Original: " << str2 << endl;
    
    str2.append(" World");
    cout << "After append: " << str2 << endl;    // "Hello World"
    
    str2 += "!";
    cout << "After +=: " << str2 << endl;        // "Hello World!"
    
    str2.insert(5, " C++");
    cout << "After insert: " << str2 << endl;    // "Hello C++ World!"
    
    str2.erase(5, 4);
    cout << "After erase: " << str2 << endl;     // "Hello World!"
    
    str2.replace(6, 5, "There");
    cout << "After replace: " << str2 << endl;   // "Hello There!"
    
    string str3 = str2; // Make a copy before clearing
    
    str2.clear();
    cout << "After clear (empty? " << str2.empty() << "): '" << str2 << "'" << endl;
    
    str3.push_back('!');
    cout << "After push_back: " << str3 << endl; // "Hello There!!"
    
    str3.pop_back();
    cout << "After pop_back: " << str3 << endl;  // "Hello There!"
    
    cout << "\n=== STRING INFORMATION ===" << endl;
    
    // d) String Information
    string str4 = "Hello World";
    cout << "String: " << str4 << endl;
    cout << "Length: " << str4.length() << endl;     // 11
    cout << "Size: " << str4.size() << endl;         // 11
    cout << "Empty? " << str4.empty() << endl;       // 0 (false)
    cout << "Capacity: " << str4.capacity() << endl; // Current allocated space
    cout << "Max size: " << str4.max_size() << endl; // Maximum possible size
    
    cout << "\n=== SUBSTRINGS AND SEARCHING ===" << endl;
    
    // e) Substrings and Searching
    string str5 = "Hello World Programming";
    cout << "String: " << str5 << endl;
    
    string sub = str5.substr(6, 5);
    cout << "Substring(6,5): " << sub << endl;  // "World"
    
    // Searching
    cout << "\nSearch operations:" << endl;
    size_t pos1 = str5.find("World");
    cout << "find(\"World\"): " << pos1 << endl;  // 6
    
    size_t pos2 = str5.find('o');
    cout << "find('o'): " << pos2 << endl;        // 4 (first 'o')
    
    size_t pos3 = str5.rfind('o');
    cout << "rfind('o'): " << pos3 << endl;       // 7 (last 'o' from end)
    
    size_t pos4 = str5.find("xyz");
    cout << "find(\"xyz\"): ";
    if (pos4 == string::npos) {
        cout << "string::npos (not found)" << endl;
    } else {
        cout << pos4 << endl;
    }
    
    // Check if contains
    if (str5.find("World") != string::npos) {
        cout << "\"World\" was found in the string!" << endl;
    }
    
    cout << "\n=== STRING COMPARISON ===" << endl;
    
    // f) Comparison
    string fruit1 = "apple";
    string fruit2 = "banana";
    string fruit3 = "apple";
    
    cout << "fruit1: " << fruit1 << endl;
    cout << "fruit2: " << fruit2 << endl;
    cout << "fruit3: " << fruit3 << endl;
    
    cout << "\nComparison results:" << endl;
    cout << "fruit1.compare(fruit2): " << fruit1.compare(fruit2) << endl; // Negative
    cout << "fruit1.compare(fruit3): " << fruit1.compare(fruit3) << endl; // 0 (equal)
    cout << "fruit2.compare(fruit1): " << fruit2.compare(fruit1) << endl; // Positive
    
    cout << "\nUsing operators:" << endl;
    cout << "(fruit1 == fruit2): " << (fruit1 == fruit2) << endl;     // 0 (false)
    cout << "(fruit1 != fruit2): " << (fruit1 != fruit2) << endl;     // 1 (true)
    cout << "(fruit1 == fruit3): " << (fruit1 == fruit3) << endl;     // 1 (true)
    cout << "(fruit1 < fruit2): " << (fruit1 < fruit2) << endl;       // 1 (true)
    cout << "(fruit2 > fruit1): " << (fruit2 > fruit1) << endl;       // 1 (true)
    
    cout << "\n=== STRING ITERATION ===" << endl;
    
    // String iteration
    string iterStr = "Hello";
    cout << "String: " << iterStr << endl;
    
    cout << "Using range-based for loop: ";
    for(char c : iterStr) {
        cout << c << " ";
    }
    cout << endl;
    
    cout << "Using index-based for loop: ";
    for(int i = 0; i < iterStr.length(); i++) {
        cout << iterStr[i] << " ";
    }
    cout << endl;
    
    cout << "\n=== STRING CONVERSION ===" << endl;
    
    // String to number conversion
    string numStr = "123";
    int num = stoi(numStr);
    cout << "String \"" << numStr << "\" to int: " << num << endl;
    
    // Number to string conversion
    int value = 456;
    string valueStr = to_string(value);
    cout << "Int " << value << " to string: \"" << valueStr << "\"" << endl;
    
    double pi = 3.14159;
    string piStr = to_string(pi);
    cout << "Double " << pi << " to string: \"" << piStr << "\"" << endl;
    
    cout << "\n=== STRING WITH NUMBERS ===" << endl;
    
    // Mixing strings with numbers
    string result = "The answer is " + to_string(42);
    cout << result << endl;
    
    cout << "\n=== PROGRAM COMPLETED SUCCESSFULLY ===" << endl;
    
    return 0;
}