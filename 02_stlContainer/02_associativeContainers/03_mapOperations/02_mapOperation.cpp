/**
 * Map Operations Demo - C++ STL Map
 * 
 * A map stores key-value pairs. Keys are UNIQUE and SORTED automatically.
 * Like a dictionary/phonebook - you look up by key, get the value.
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <map>        // for map
#include <string>     // for strings
using namespace std;

int main() {
    cout << "=== C++ STL MAP Operations Demo ===\n";
    cout << "Map = Key-Value pairs, UNIQUE keys, SORTED by key\n";
    cout << "Think of it as a DICTIONARY (word -> meaning)\n\n";
    
    // ============================================================
    // CREATE a map
    // ============================================================
    cout << "1. CREATING a map:\n";
    map<int, string> student;  // key: roll number, value: name
    map<string, int> age;      // key: name, value: age
    cout << "Created empty maps\n\n";
    
    // ============================================================
    // 1. insert() - Adding key-value pairs
    // ============================================================
    cout << "2. insert() - Adding elements:\n";
    
    // Method 1: Using insert with pair
    student.insert({1, "John"});     // {1, "John"}
    student.insert({2, "Alice"});    // {2, "Alice"}
    student.insert({3, "Bob"});      // {3, "Bob"}
    
    // Method 2: Using make_pair
    student.insert(make_pair(4, "Charlie"));
    
    // Method 3: Using pair constructor
    student.insert(pair<int, string>(5, "Diana"));
    
    cout << "After inserts (roll -> name):\n";
    for (auto& p : student) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "✓ Notice: Keys are SORTED automatically (1,2,3,4,5)!\n\n";
    
    // ============================================================
    // 2. operator[key] - Access/Insert (MOST COMMON)
    // ============================================================
    cout << "3. operator[] - Access or Insert:\n";
    
    // If key EXISTS: returns value
    cout << "student[2] = " << student[2] << " (key exists)\n";
    
    // If key DOESN'T EXIST: creates new entry with default value
    cout << "student[6] doesn't exist, so...\n";
    student[6] = "Eve";  // Creates {6, "Eve"}
    cout << "After student[6] = \"Eve\":\n";
    for (auto& p : student) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
    
    // Another example with string keys
    cout << "String keys example:\n";
    map<string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;
    
    cout << "Scores:\n";
    for (auto& p : scores) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }
    cout << "✓ Notice: Keys are SORTED alphabetically!\n\n";
    
    // ============================================================
    // 3. at(key) - Access with bounds checking
    // ============================================================
    cout << "4. at() - Safe access with bounds checking:\n";
    
    try {
        cout << "student.at(2) = " << student.at(2) << "\n";
        cout << "student.at(3) = " << student.at(3) << "\n";
        
        // This will throw exception if key doesn't exist
        // student.at(99);  // Uncomment to see exception
    }
    catch (const out_of_range& e) {
        cout << "Exception: Key not found!\n";
    }
    cout << "\n";
    
    // ============================================================
    // 4. find(key) - Search for a key
    // ============================================================
    cout << "5. find() - Searching for keys:\n";
    
    auto it = student.find(3);
    if (it != student.end()) {
        cout << "Found: Key " << it->first << " -> Value: " << it->second << "\n";
    }
    
    it = student.find(99);
    if (it == student.end()) {
        cout << "Key 99 not found (returns end())\n";
    }
    cout << "\n";
    
    // ============================================================
    // 5. erase(key) - Remove by key
    // ============================================================
    cout << "6. erase() - Removing elements:\n";
    
    cout << "Before erase:\n";
    for (auto& p : student) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // Erase by key
    student.erase(4);
    cout << "\nAfter erase(4):\n";
    for (auto& p : student) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // Erase by iterator
    it = student.find(5);
    if (it != student.end()) {
        student.erase(it);
        cout << "\nAfter erasing key 5 using iterator:\n";
        for (auto& p : student) {
            cout << "  " << p.first << " -> " << p.second << "\n";
        }
    }
    cout << "\n";
    
    // ============================================================
    // 6. size() and empty()
    // ============================================================
    cout << "7. size() and empty():\n";
    cout << "Map size: " << student.size() << " elements\n";
    cout << "Is empty? " << (student.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. clear() - Remove all elements
    // ============================================================
    cout << "8. clear() - Removing all elements:\n";
    student.clear();
    cout << "After clear - Size: " << student.size() << "\n";
    cout << "Is empty? " << (student.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 8. DIFFERENT INITIALIZATION METHODS
    // ============================================================
    cout << "9. Different initialization methods:\n";
    
    // Method 1: Empty + insert
    map<int, string> m1;
    m1[1] = "One";
    m1[2] = "Two";
    cout << "m1 (empty + insert): ";
    for (auto& p : m1) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";
    
    // Method 2: Initializer list (C++11)
    map<int, string> m2 = {{1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};
    cout << "m2 (initializer list): ";
    for (auto& p : m2) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";
    
    // Method 3: From another map
    map<int, string> m3(m2);
    cout << "m3 (copy of m2): ";
    for (auto& p : m3) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n\n";
    
    // ============================================================
    // 9. DIFFERENT TYPES OF MAPS
    // ============================================================
    cout << "10. Maps with different key/value types:\n";
    
    // Map with string key, int value
    map<string, int> phonebook;
    phonebook["John"] = 123456;
    phonebook["Alice"] = 789012;
    phonebook["Bob"] = 345678;
    
    cout << "Phonebook (name -> number):\n";
    for (auto& p : phonebook) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
    
    // Map with int key, double value
    map<int, double> prices;
    prices[101] = 29.99;
    prices[102] = 49.99;
    prices[103] = 19.99;
    
    cout << "Prices (product ID -> price):\n";
    for (auto& p : prices) {
        cout << "  " << p.first << " -> $" << p.second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 10. count() - Check if key exists
    // ============================================================
    cout << "11. count() - Check if key exists:\n";
    
    if (phonebook.count("John") > 0) {
        cout << "John exists in phonebook\n";
    }
    
    if (phonebook.count("Zebra") == 0) {
        cout << "Zebra not found in phonebook\n";
    }
    cout << "\n";
    
    // ============================================================
    // 11. lower_bound() and upper_bound()
    // ============================================================
    cout << "12. lower_bound() and upper_bound():\n";
    
    map<int, string> numbers = {
        {10, "Ten"}, {20, "Twenty"}, {30, "Thirty"},
        {40, "Forty"}, {50, "Fifty"}
    };
    
    auto lb = numbers.lower_bound(25);  // First key >= 25
    auto ub = numbers.upper_bound(35);  // First key > 35
    
    cout << "lower_bound(25): " << lb->first << " -> " << lb->second << "\n";
    cout << "upper_bound(35): " << ub->first << " -> " << ub->second << "\n\n";
    
    // ============================================================
    // 12. PRACTICAL EXAMPLE 1: Word counter
    // ============================================================
    cout << "13. PRACTICAL EXAMPLE - Word Frequency Counter:\n";
    
    map<string, int> wordCount;
    string words[] = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    
    cout << "Words: ";
    for (string w : words) cout << w << " ";
    cout << "\n";
    
    // Count each word
    for (string w : words) {
        wordCount[w]++;  // If key exists, increment; if not, create with 0 then increment
    }
    
    cout << "Word frequencies:\n";
    for (auto& p : wordCount) {
        cout << "  " << p.first << " appears " << p.second << " times\n";
    }
    cout << "\n";
    
    // ============================================================
    // 13. PRACTICAL EXAMPLE 2: Student grades
    // ============================================================
    cout << "14. PRACTICAL EXAMPLE - Student Grades:\n";
    
    map<string, char> grades;
    
    // Add grades
    grades["Alice"] = 'A';
    grades["Bob"] = 'B';
    grades["Charlie"] = 'A';
    grades["Diana"] = 'C';
    
    cout << "Student Grades:\n";
    for (auto& p : grades) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }
    
    // Update a grade
    grades["Bob"] = 'A';  // Bob improved!
    cout << "\nAfter Bob improved:\n";
    cout << "  Bob: " << grades["Bob"] << "\n";
    
    // Check if student exists
    string studentName = "Eve";
    if (grades.find(studentName) == grades.end()) {
        cout << "\n" << studentName << " not found in grade book\n";
    }
    cout << "\n";
    
    // ============================================================
    // 14. PRACTICAL EXAMPLE 3: Inventory system
    // ============================================================
    cout << "15. PRACTICAL EXAMPLE - Store Inventory:\n";
    
    map<string, int> inventory;
    
    // Add items
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 25;
    inventory["Keyboard"] = 10;
    inventory["Monitor"] = 7;
    
    cout << "Current inventory:\n";
    for (auto& p : inventory) {
        cout << "  " << p.first << ": " << p.second << " units\n";
    }
    
    // Sell some items
    inventory["Mouse"] -= 3;
    inventory["Laptop"] -= 1;
    
    cout << "\nAfter sales:\n";
    for (auto& p : inventory) {
        cout << "  " << p.first << ": " << p.second << " units\n";
    }
    
    // Remove discontinued item
    inventory.erase("Keyboard");
    cout << "\nAfter removing Keyboard:\n";
    for (auto& p : inventory) {
        cout << "  " << p.first << ": " << p.second << " units\n";
    }
    cout << "\n";
    
    // ============================================================
    // 15. ITERATOR TRAVERSAL
    // ============================================================
    cout << "16. Iterator traversal:\n";
    
    map<int, string> traverse = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}};
    
    cout << "Forward (begin -> end):\n";
    for (auto it = traverse.begin(); it != traverse.end(); ++it) {
        cout << "  " << it->first << " -> " << it->second << "\n";
    }
    
    cout << "\nReverse (rbegin -> rend):\n";
    for (auto it = traverse.rbegin(); it != traverse.rend(); ++it) {
        cout << "  " << it->first << " -> " << it->second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 16. MAP vs MULTIMAP
    // ============================================================
    cout << "17. Map vs Multimap:\n";
    cout << "✓ Map:   Unique keys only\n";
    cout << "✓ Multimap: Duplicate keys allowed\n\n";
    
    // ============================================================
    // 17. QUICK REFERENCE - Map Operations
    // ============================================================
    cout << "18. MAP OPERATIONS - QUICK REFERENCE:\n";
    cout << "╔══════════════╦════════════════════════════════════╦══════════════╗\n";
    cout << "║ Operation    ║ Description                        ║ Complexity   ║\n";
    cout << "╠══════════════╬════════════════════════════════════╬══════════════╣\n";
    cout << "║ m[key] = val ║ Insert or update (creates if new) ║ O(log n)     ║\n";
    cout << "║ m.at(key)    ║ Access with bounds checking       ║ O(log n)     ║\n";
    cout << "║ m.insert({k,v})║ Insert key-value pair           ║ O(log n)     ║\n";
    cout << "║ m.erase(key) ║ Remove by key                     ║ O(log n)     ║\n";
    cout << "║ m.find(key)  ║ Find element by key               ║ O(log n)     ║\n";
    cout << "║ m.count(key) ║ Check if key exists (0 or 1)      ║ O(log n)     ║\n";
    cout << "║ m.size()     ║ Number of key-value pairs         ║ O(1)         ║\n";
    cout << "║ m.empty()    ║ Check if map is empty             ║ O(1)         ║\n";
    cout << "║ m.clear()    ║ Remove all elements               ║ O(n)         ║\n";
    cout << "╚══════════════╩════════════════════════════════════╩══════════════╝\n";
    
    cout << "\n=== End of Map Operations Demo ===\n";
    
    return 0;
}