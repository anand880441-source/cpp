/**
 * Set Operations Demo - C++ STL Set
 * Simple version without helper functions
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "=== C++ STL Set Operations Demo (Simple Version) ===\n\n";
    
    // ============================================================
    // 1. insert() - Adding elements
    // ============================================================
    cout << "1. insert() - Adding elements:\n";
    set<int> s;
    
    // insert returns pair<iterator, bool>
    auto result = s.insert(30);
    cout << "Inserted 30: " << (result.second ? "Success" : "Failed") << "\n";
    
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    
    // Try duplicate insert
    result = s.insert(30);
    cout << "Inserted 30 again: " << (result.second ? "Success" : "Failed (Duplicate!)") << "\n";
    
    // Display set
    cout << "Set after inserts: { ";
    for (int x : s) cout << x << " ";
    cout << "}\n";
    cout << "Size: " << s.size() << "\n\n";
    
    // ============================================================
    // 2. erase() - Removing elements
    // ============================================================
    cout << "2. erase() - Removing elements:\n";
    
    // Erase by value
    int erased = s.erase(20);
    cout << "Erased 20: " << erased << " element removed\n";
    
    // Erase by iterator
    auto it = s.find(40);
    if (it != s.end()) {
        s.erase(it);
        cout << "Erased 40 using iterator\n";
    }
    
    // Erase non-existent value
    erased = s.erase(999);
    cout << "Erased 999: " << erased << " element removed\n";
    
    cout << "Set after erases: { ";
    for (int x : s) cout << x << " ";
    cout << "}\n\n";
    
    // ============================================================
    // 3. find() - Searching elements
    // ============================================================
    cout << "3. find() - Searching:\n";
    
    it = s.find(30);
    if (it != s.end()) {
        cout << "Found: " << *it << "\n";
    } else {
        cout << "30 not found\n";
    }
    
    it = s.find(100);
    if (it == s.end()) {
        cout << "100 not found\n";
    }
    cout << "\n";
    
    // ============================================================
    // 4. count() - Check existence
    // ============================================================
    cout << "4. count() - Check existence:\n";
    cout << "Count of 30: " << s.count(30) << " (1=exists, 0=not)\n";
    cout << "Count of 100: " << s.count(100) << "\n\n";
    
    // ============================================================
    // 5. size() and empty()
    // ============================================================
    cout << "5. size() and empty():\n";
    cout << "Size: " << s.size() << "\n";
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 6. clear() - Remove all elements
    // ============================================================
    cout << "6. clear() - Remove all:\n";
    s.clear();
    cout << "After clear - Size: " << s.size() << "\n";
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. Different initialization methods
    // ============================================================
    cout << "7. Initialization methods:\n";
    
    // Initializer list
    set<int> set1 = {5, 2, 8, 2, 1, 9, 3};
    cout << "set1 (initializer list): { ";
    for (int x : set1) cout << x << " ";
    cout << "} (duplicates removed, sorted)\n";
    
    // From vector
    vector<int> vec = {10, 30, 20, 50, 40, 30, 20};
    set<int> set2(vec.begin(), vec.end());
    cout << "set2 (from vector): { ";
    for (int x : set2) cout << x << " ";
    cout << "}\n";
    
    // Copy constructor
    set<int> set3(set2);
    cout << "set3 (copy): { ";
    for (int x : set3) cout << x << " ";
    cout << "}\n\n";
    
    // ============================================================
    // 8. Iterators and traversal
    // ============================================================
    cout << "8. Iterator traversal:\n";
    set<string> names = {"Alice", "Bob", "Charlie", "David"};
    
    cout << "Forward (begin->end): ";
    for (auto it = names.begin(); it != names.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Reverse (rbegin->rend): ";
    for (auto it = names.rbegin(); it != names.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
    
    // ============================================================
    // 9. lower_bound() and upper_bound()
    // ============================================================
    cout << "9. lower_bound() and upper_bound():\n";
    set<int> boundSet = {10, 20, 30, 40, 50, 60};
    
    auto lb = boundSet.lower_bound(25);  // First element >= 25
    auto ub = boundSet.upper_bound(25);  // First element > 25
    
    cout << "lower_bound(25): " << *lb << "\n";
    cout << "upper_bound(25): " << *ub << "\n";
    
    auto range = boundSet.equal_range(35);
    cout << "equal_range(35): [" << *range.first << ", " << *range.second << ")\n\n";
    
    // ============================================================
    // 10. Custom comparator - descending order
    // ============================================================
    cout << "10. Custom comparator (descending):\n";
    set<int, greater<int>> descSet = {1, 2, 3, 4, 5, 6};
    cout << "Descending set: { ";
    for (int x : descSet) cout << x << " ";
    cout << "}\n\n";
    
    // ============================================================
    // 11. Set of custom objects
    // ============================================================
    cout << "11. Set of custom objects:\n";
    
    class Person {
    public:
        int id;
        string name;
        Person(int i, string n) : id(i), name(n) {}
        bool operator<(const Person& other) const {
            return id < other.id;
        }
    };
    
    set<Person> people;
    people.insert(Person(103, "Alice"));
    people.insert(Person(101, "Bob"));
    people.insert(Person(105, "Charlie"));
    
    cout << "People sorted by ID: ";
    for (const auto& p : people) {
        cout << "{" << p.id << "," << p.name << "} ";
    }
    cout << "\n\n";
    
    // ============================================================
    // 12. merge() and extract() (C++17)
    // ============================================================
    cout << "12. merge() and extract() (C++17):\n";
    
    set<int> a = {1, 2, 3, 4, 5};
    set<int> b = {4, 5, 6, 7, 8};
    
    cout << "Set A: { 1 2 3 4 5 }\n";
    cout << "Set B: { 4 5 6 7 8 }\n";
    
    a.merge(b);  // Transfer unique elements from b to a
    
    cout << "After merge:\n";
    cout << "Set A: { ";
    for (int x : a) cout << x << " ";
    cout << "}\n";
    cout << "Set B: { ";
    for (int x : b) cout << x << " ";
    cout << "}\n";
    
    // extract
    auto node = a.extract(3);
    cout << "Extracted: " << node.value() << "\n";
    
    node.value() = 33;
    a.insert(move(node));
    cout << "After modify and reinsert: { ";
    for (int x : a) cout << x << " ";
    cout << "}\n\n";
    
    // ============================================================
    // 13. Practical examples
    // ============================================================
    cout << "13. Practical examples:\n";
    
    // Duplicate remover
    vector<int> data = {5, 2, 8, 2, 1, 5, 9, 1, 3};
    set<int> unique(data.begin(), data.end());
    cout << "Original: 5 2 8 2 1 5 9 1 3\n";
    cout << "Unique:   ";
    for (int x : unique) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 14. Performance summary
    // ============================================================
    cout << "14. Set Performance:\n";
    cout << "   insert()  - O(log n)\n";
    cout << "   erase()   - O(log n)\n";
    cout << "   find()    - O(log n)\n";
    cout << "   count()   - O(log n)\n";
    cout << "   size()    - O(1)\n";
    cout << "   empty()   - O(1)\n";
    cout << "   clear()   - O(n)\n";
    
    cout << "\n=== End of Set Operations Demo ===\n";
    
    return 0;
}