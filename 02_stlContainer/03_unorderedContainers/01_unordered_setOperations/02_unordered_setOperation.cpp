/**
 * Unordered Set Operations Demo - C++ STL Unordered Set
 * 
 * An unordered_set stores UNIQUE elements but in NO PARTICULAR ORDER.
 * It uses HASH TABLE internally, giving O(1) average time complexity!
 * Think of it as: SET but UNSORTED and FASTER!
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <unordered_set>  // for unordered_set
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "=== C++ STL UNORDERED SET Operations Demo ===\n";
    cout << "Unordered Set = UNIQUE elements, NO order, FAST (O(1) average)\n";
    cout << "Underlying data structure: HASH TABLE\n\n";
    
    // ============================================================
    // CREATE an unordered_set
    // ============================================================
    cout << "1. CREATING an unordered_set:\n";
    unordered_set<int> us;
    cout << "Created empty unordered_set\n\n";
    
    // ============================================================
    // 1. insert() - Adding elements
    // ============================================================
    cout << "2. insert() - Adding elements:\n";
    
    us.insert(30);
    us.insert(10);
    us.insert(50);
    us.insert(20);
    us.insert(40);
    
    cout << "After inserting: 30, 10, 50, 20, 40\n";
    
    // Try to insert duplicate
    auto result = us.insert(30);
    cout << "Insert 30 again: " << (result.second ? "Success" : "DUPLICATE REJECTED!") << "\n";
    
    cout << "Unordered set contents: ";
    for (int x : us) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "✓ Notice: NO particular order! (Order may vary each run)\n";
    cout << "✓ Unique elements only (duplicates rejected)\n\n";
    
    // ============================================================
    // 2. find() - Search for element (FAST!)
    // ============================================================
    cout << "3. find() - Searching for elements:\n";
    
    auto it = us.find(20);
    if (it != us.end()) {
        cout << "Found: " << *it << "\n";
    } else {
        cout << "20 not found\n";
    }
    
    it = us.find(99);
    if (it == us.end()) {
        cout << "99 not found (returns end())\n";
    }
    cout << "✓ Time complexity: O(1) average, O(n) worst case\n\n";
    
    // ============================================================
    // 3. count() - Check if element exists
    // ============================================================
    cout << "4. count() - Checking existence:\n";
    cout << "Count of 20: " << us.count(20) << " (1 = exists)\n";
    cout << "Count of 99: " << us.count(99) << " (0 = doesn't exist)\n";
    cout << "✓ Always returns 0 or 1 (unique elements)\n\n";
    
    // ============================================================
    // 4. erase() - Removing elements
    // ============================================================
    cout << "5. erase() - Removing elements:\n";
    
    cout << "Before erase - Size: " << us.size() << "\n";
    cout << "Contents: ";
    for (int x : us) cout << x << " ";
    cout << "\n";
    
    // Erase by value
    int erased = us.erase(20);
    cout << "Erased 20: " << erased << " element removed\n";
    
    // Erase by iterator
    it = us.find(40);
    if (it != us.end()) {
        us.erase(it);
        cout << "Erased 40 using iterator\n";
    }
    
    cout << "After erase - Size: " << us.size() << "\n";
    cout << "Contents: ";
    for (int x : us) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 5. size() and empty()
    // ============================================================
    cout << "6. size() and empty():\n";
    cout << "Current size: " << us.size() << "\n";
    cout << "Is empty? " << (us.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 6. clear() - Remove all elements
    // ============================================================
    cout << "7. clear() - Removing all elements:\n";
    us.clear();
    cout << "After clear - Size: " << us.size() << "\n";
    cout << "Is empty? " << (us.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. DIFFERENT INITIALIZATION METHODS
    // ============================================================
    cout << "8. Different initialization methods:\n";
    
    // Method 1: Empty + insert
    unordered_set<int> us1;
    us1.insert(5);
    us1.insert(2);
    us1.insert(8);
    us1.insert(2);  // Duplicate - rejected!
    cout << "us1 (empty + insert): ";
    for (int x : us1) cout << x << " ";
    cout << "\n";
    
    // Method 2: Initializer list
    unordered_set<int> us2 = {5, 2, 8, 2, 1, 5, 9, 3};
    cout << "us2 (initializer list {5,2,8,2,1,5,9,3}): ";
    for (int x : us2) cout << x << " ";
    cout << "  (duplicates removed, UNSORTED!)\n";
    
    // Method 3: From another set
    unordered_set<int> us3(us2);
    cout << "us3 (copy of us2): ";
    for (int x : us3) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 8. BUCKET INTERFACE - Understanding hash table
    // ============================================================
    cout << "9. BUCKET INTERFACE - How hash table works:\n";
    
    unordered_set<int> hash_demo = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    
    cout << "Hash table statistics:\n";
    cout << "  Number of buckets: " << hash_demo.bucket_count() << "\n";
    cout << "  Load factor: " << hash_demo.load_factor() << "\n";
    cout << "  Max load factor: " << hash_demo.max_load_factor() << "\n";
    
    // Show which bucket each element is in
    cout << "\nBucket distribution:\n";
    for (int x : hash_demo) {
        cout << "  Element " << x << " is in bucket " << hash_demo.bucket(x) << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 9. rehash() and reserve() - Performance tuning
    // ============================================================
    cout << "10. rehash() and reserve() - Performance tuning:\n";
    
    unordered_set<int> perf;
    perf.reserve(100);  // Reserve space for 100 elements
    cout << "After reserve(100): Buckets = " << perf.bucket_count() << "\n";
    
    for (int i = 0; i < 50; i++) {
        perf.insert(i);
    }
    cout << "After inserting 50 elements:\n";
    cout << "  Size: " << perf.size() << "\n";
    cout << "  Buckets: " << perf.bucket_count() << "\n";
    cout << "  Load factor: " << perf.load_factor() << "\n\n";
    
    // ============================================================
    // 10. STRING KEYS - Very common use case
    // ============================================================
    cout << "11. STRING KEYS - Unordered set of strings:\n";
    
    unordered_set<string> colors;
    colors.insert("red");
    colors.insert("blue");
    colors.insert("green");
    colors.insert("yellow");
    colors.insert("red");  // Duplicate - rejected!
    
    cout << "Colors: ";
    for (const string& c : colors) {
        cout << c << " ";
    }
    cout << "\n";
    cout << "Number of colors: " << colors.size() << "\n";
    
    // Fast lookup
    if (colors.find("blue") != colors.end()) {
        cout << "Blue is in the set\n";
    }
    cout << "\n";
    
    // ============================================================
    // 11. CUSTOM HASH FUNCTION - For custom objects
    // ============================================================
    cout << "12. CUSTOM OBJECTS with unordered_set:\n";
    
    class Person {
    public:
        string name;
        int age;
        
        Person(string n, int a) : name(n), age(a) {}
        
        // Need operator== for unordered_set
        bool operator==(const Person& other) const {
            return name == other.name && age == other.age;
        }
    };
    
    // Custom hash function
    struct PersonHash {
        size_t operator()(const Person& p) const {
            return hash<string>()(p.name) ^ hash<int>()(p.age);
        }
    };
    
    unordered_set<Person, PersonHash> people;
    people.insert(Person("Alice", 25));
    people.insert(Person("Bob", 30));
    people.insert(Person("Alice", 25));  // Duplicate - rejected!
    
    cout << "People in set:\n";
    for (const auto& p : people) {
        cout << "  " << p.name << " (" << p.age << ")\n";
    }
    cout << "Size: " << people.size() << " (duplicates rejected)\n\n";
    
    // ============================================================
    // 12. PRACTICAL EXAMPLE 1: Fast duplicate checker
    // ============================================================
    cout << "13. PRACTICAL EXAMPLE - Fast Duplicate Checker:\n";
    
    vector<int> numbers = {1, 2, 3, 4, 5, 1, 2, 3, 6, 7, 8, 9, 1};
    unordered_set<int> seen;
    
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << "\n";
    
    cout << "Duplicates found:\n";
    for (int n : numbers) {
        if (seen.find(n) != seen.end()) {
            cout << "  " << n << " is a duplicate!\n";
        } else {
            seen.insert(n);
        }
    }
    cout << "\n";
    
    // ============================================================
    // 13. PRACTICAL EXAMPLE 2: Unique word counter
    // ============================================================
    cout << "14. PRACTICAL EXAMPLE - Unique Word Counter:\n";
    
    string text = "the cat in the hat sat on the mat";
    unordered_set<string> unique_words;
    string word = "";
    
    cout << "Text: " << text << "\n";
    
    // Simple word splitter
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                unique_words.insert(word);
                word = "";
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) unique_words.insert(word);
    
    cout << "Unique words: ";
    for (const string& w : unique_words) {
        cout << w << " ";
    }
    cout << "\n";
    cout << "Total unique words: " << unique_words.size() << "\n";
    cout << "Total words: 8\n\n";
    
    // ============================================================
    // 14. SET vs UNORDERED_SET - COMPARISON
    // ============================================================
    cout << "15. SET vs UNORDERED_SET - Which to use?\n";
    cout << "\n╔════════════════╦════════════════════════╦══════════════════════════╗\n";
    cout << "║ Feature        ║ set                    ║ unordered_set            ║\n";
    cout << "╠════════════════╬════════════════════════╬══════════════════════════╣\n";
    cout << "║ Order          ║ SORTED                 ║ NO ORDER (random)        ║\n";
    cout << "║ Duplicates     ║ NO                     ║ NO                       ║\n";
    cout << "║ Implementation ║ Red-Black Tree         ║ Hash Table               ║\n";
    cout << "║ Insert         ║ O(log n)               ║ O(1) average, O(n) worst║\n";
    cout << "║ Find           ║ O(log n)               ║ O(1) average, O(n) worst║\n";
    cout << "║ Erase          ║ O(log n)               ║ O(1) average, O(n) worst║\n";
    cout << "║ Memory         ║ Less                   ║ More (hash table)        ║\n";
    cout << "║ Iterator       ║ Bidirectional          ║ Forward only             ║\n";
    cout << "╚════════════════╩════════════════════════╩══════════════════════════╝\n";
    
    cout << "\n--- When to use UNORDERED_SET ---\n";
    cout << "✓ Need FAST O(1) lookups/inserts\n";
    cout << "✓ Order doesn't matter\n";
    cout << "✓ Working with large data sets\n";
    cout << "✓ Implementing caches\n";
    cout << "✓ Duplicate detection\n";
    cout << "✓ Counting unique items\n";
    
    cout << "\n--- When to use SET ---\n";
    cout << "✓ Need elements in SORTED order\n";
    cout << "✓ Need range operations (lower_bound, upper_bound)\n";
    cout << "✓ Need bidirectional iteration\n";
    cout << "✓ When worst-case performance must be guaranteed\n";
    cout << "✓ Memory is constrained\n";
    
    // ============================================================
    // 16. QUICK REFERENCE - Unordered Set Operations
    // ============================================================
    cout << "\n16. UNORDERED SET - QUICK REFERENCE:\n";
    cout << "╔══════════════╦════════════════════════════════╦═══════════════╗\n";
    cout << "║ Operation    ║ Description                    ║ Complexity    ║\n";
    cout << "╠══════════════╬════════════════════════════════╬═══════════════╣\n";
    cout << "║ insert(val)  ║ Add element (no duplicates)   ║ O(1) average  ║\n";
    cout << "║ erase(val)   ║ Remove element                ║ O(1) average  ║\n";
    cout << "║ find(val)    ║ Search for element            ║ O(1) average  ║\n";
    cout << "║ count(val)   ║ Check existence (0 or 1)      ║ O(1) average  ║\n";
    cout << "║ size()       ║ Number of elements            ║ O(1)          ║\n";
    cout << "║ empty()      ║ Check if empty                ║ O(1)          ║\n";
    cout << "║ clear()      ║ Remove all elements           ║ O(n)          ║\n";
    cout << "║ bucket_count()║ Number of hash buckets      ║ O(1)          ║\n";
    cout << "║ load_factor() ║ Average elements per bucket  ║ O(1)          ║\n";
    cout << "║ reserve(n)   ║ Reserve space for n elements  ║ O(n)          ║\n";
    cout << "║ rehash(n)    ║ Change number of buckets      ║ O(n)          ║\n";
    cout << "╚══════════════╩════════════════════════════════╩═══════════════╝\n";
    
    cout << "\n=== End of Unordered Set Operations Demo ===\n";
    
    return 0;
}