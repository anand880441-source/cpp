/**
 * Multimap Operations Demo - C++ STL Multimap
 * SIMPLE VERSION - No type conflicts!
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    cout << "=== C++ STL MULTIMAP Operations Demo ===\n";
    cout << "Multimap = Map that ALLOWS DUPLICATE KEYS\n\n";
    
    // ============================================================
    // CREATE a multimap
    // ============================================================
    cout << "1. CREATING a multimap:\n";
    multimap<int, string> mm;
    cout << "Created empty multimap\n\n";
    
    // ============================================================
    // 1. insert() - Adding elements (DUPLICATE KEYS ALLOWED!)
    // ============================================================
    cout << "2. insert() - Adding key-value pairs:\n";
    
    mm.insert({1, "India"});
    mm.insert({2, "USA"});
    mm.insert({3, "Japan"});
    
    // Add DUPLICATE keys
    mm.insert({1, "Indonesia"});
    mm.insert({2, "UK"});
    mm.insert({1, "Iran"});
    mm.insert({3, "Jamaica"});
    
    cout << "Multimap contents (key -> value):\n";
    for (auto& p : mm) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "✓ Duplicate keys are KEPT!\n\n";
    
    // ============================================================
    // 2. count(key) - How many values for a key?
    // ============================================================
    cout << "3. count() - Counting values for a key:\n";
    cout << "Key 1 appears " << mm.count(1) << " times\n";
    cout << "Key 2 appears " << mm.count(2) << " times\n";
    cout << "Key 3 appears " << mm.count(3) << " times\n";
    cout << "Key 99 appears " << mm.count(99) << " times\n\n";
    
    // ============================================================
    // 3. find(key) - Find FIRST occurrence of a key
    // ============================================================
    cout << "4. find() - Finding FIRST occurrence:\n";
    auto it = mm.find(2);
    if (it != mm.end()) {
        cout << "Found key " << it->first << " -> " << it->second;
        cout << " (first value for key 2)\n";
    }
    
    it = mm.find(99);
    if (it == mm.end()) {
        cout << "Key 99 not found\n\n";
    }
    
    // ============================================================
    // 4. erase(key) - Removes ALL occurrences of a key
    // ============================================================
    cout << "5. erase() - Removing elements:\n";
    cout << "Before erase - Size: " << mm.size() << "\n";
    
    int removed = mm.erase(1);
    cout << "Removed " << removed << " entries with key 1\n";
    cout << "After erase - Size: " << mm.size() << "\n";
    
    cout << "Multimap after erase(1):\n";
    for (auto& p : mm) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 5. equal_range() - Get ALL values for a key
    // ============================================================
    cout << "6. equal_range() - Get ALL values for a key:\n";
    
    multimap<int, string> courses = {
        {1, "Math"},
        {2, "Physics"},
        {1, "Algebra"},
        {3, "Chemistry"},
        {1, "Calculus"},
        {2, "Mechanics"}
    };
    
    cout << "All courses:\n";
    for (auto& p : courses) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // USE A NEW VARIABLE for each equal_range call!
    cout << "\nAll courses for key 1:\n";
    auto range1 = courses.equal_range(1);
    for (auto it = range1.first; it != range1.second; ++it) {
        cout << "  " << it->first << " -> " << it->second << "\n";
    }
    
    cout << "\nAll courses for key 2:\n";
    auto range2 = courses.equal_range(2);
    for (auto it = range2.first; it != range2.second; ++it) {
        cout << "  " << it->first << " -> " << it->second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 6. PRACTICAL EXAMPLE 1: Student courses (DIFFERENT MAP TYPE)
    // ============================================================
    cout << "7. PRACTICAL EXAMPLE - Student Course Registration:\n";
    
    // This is a DIFFERENT multimap - string keys, string values
    multimap<string, string> registration;
    
    registration.insert({"Alice", "Math"});
    registration.insert({"Bob", "Physics"});
    registration.insert({"Alice", "Computer Science"});
    registration.insert({"Charlie", "Chemistry"});
    registration.insert({"Alice", "English"});
    registration.insert({"Bob", "Math"});
    
    cout << "All registrations:\n";
    for (auto& p : registration) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // USE A NEW VARIABLE for string multimap
    cout << "\nAlice's courses:\n";
    auto alice_courses = registration.equal_range("Alice");
    for (auto it = alice_courses.first; it != alice_courses.second; ++it) {
        cout << "  " << it->second << "\n";
    }
    
    cout << "\nBob is taking " << registration.count("Bob") << " courses\n\n";
    
    // ============================================================
    // 7. PRACTICAL EXAMPLE 2: Dictionary with multiple meanings
    // ============================================================
    cout << "8. PRACTICAL EXAMPLE - Dictionary:\n";
    
    // ANOTHER DIFFERENT multimap - string keys, string values
    multimap<string, string> dictionary;
    
    dictionary.insert({"run", "to move quickly on foot"});
    dictionary.insert({"run", "to operate (e.g., run a program)"});
    dictionary.insert({"run", "a series of performances"});
    dictionary.insert({"bank", "financial institution"});
    dictionary.insert({"bank", "side of a river"});
    
    cout << "Dictionary entries:\n";
    for (auto& p : dictionary) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }
    
    // USE YET ANOTHER NEW VARIABLE
    cout << "\nAll meanings of 'run':\n";
    auto run_meanings = dictionary.equal_range("run");
    int i = 1;
    for (auto it = run_meanings.first; it != run_meanings.second; ++it) {
        cout << "  " << i++ << ". " << it->second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 8. size(), empty(), clear()
    // ============================================================
    cout << "9. size(), empty(), clear():\n";
    cout << "Size: " << mm.size() << "\n";
    cout << "Is empty? " << (mm.empty() ? "Yes" : "No") << "\n";
    
    mm.clear();
    cout << "After clear - Size: " << mm.size() << "\n";
    cout << "Is empty? " << (mm.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 9. DIFFERENT INITIALIZATION METHODS
    // ============================================================
    cout << "10. Different initialization methods:\n";
    
    // Method 1: Empty + insert
    multimap<int, string> mm1;
    mm1.insert({1, "One"});
    mm1.insert({1, "Uno"});
    cout << "mm1: ";
    for (auto& p : mm1) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";
    
    // Method 2: Initializer list
    multimap<int, string> mm2 = {
        {1, "Apple"},
        {2, "Banana"},
        {1, "Apricot"},
        {3, "Cherry"}
    };
    cout << "mm2: ";
    for (auto& p : mm2) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n\n";
    
    // ============================================================
    // 10. QUICK REFERENCE
    // ============================================================
    cout << "11. MULTIMAP OPERATIONS - QUICK REFERENCE:\n";
    cout << "  insert({k,v}) - Add pair (duplicates OK)\n";
    cout << "  erase(key)    - Remove ALL entries with this key\n";
    cout << "  find(key)     - Find FIRST occurrence\n";
    cout << "  count(key)    - How many values for this key\n";
    cout << "  equal_range(key) - Get ALL values for a key\n";
    cout << "  size()        - Number of pairs\n";
    cout << "  empty()       - Check if empty\n";
    cout << "  clear()       - Remove all\n";
    cout << "\n!!! IMPORTANT: multimap has NO [] operator and NO at() !!!\n";
    
    cout << "\n=== End of Multimap Operations Demo ===\n";
    
    return 0;
}