/**
 * Unordered Map Operations Demo - C++ STL Unordered Map
 * 
 * An unordered_map is a key-value container with UNIQUE keys, NO order, FAST O(1) access.
 * Uses HASH TABLE internally → FASTEST lookups and insertions!
 * Think of it as: MAP but UNSORTED and FASTER!
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <unordered_map>  // for unordered_map
#include <string>
using namespace std;

int main() {
    cout << "=== C++ STL UNORDERED MAP Operations Demo ===\n";
    cout << "Unordered Map = UNIQUE keys, NO order, FAST (O(1) average)\n";
    cout << "Underlying data structure: HASH TABLE\n\n";
    
    // ============================================================
    // CREATE an unordered_map
    // ============================================================
    cout << "1. CREATING an unordered_map:\n";
    unordered_map<int, string> um;  // key: int, value: string
    cout << "Created empty unordered_map\n\n";
    
    // ============================================================
    // 1. insert({key, value}) - Adding key-value pairs
    // ============================================================
    cout << "2. insert() - Adding elements:\n";
    
    // Method 1: Using initializer list
    um.insert({1, "John"});
    um.insert({2, "Alice"});
    um.insert({3, "Bob"});
    
    cout << "After insert({1,\"John\"}, {2,\"Alice\"}, {3,\"Bob\"}):\n";
    for (auto& p : um) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "✓ Notice: NO particular order! (Order may vary each run)\n";
    
    // Try to insert duplicate key
    auto result = um.insert({2, "Charlie"});  // Key 2 already exists!
    cout << "\nInsert duplicate key 2: " 
         << (result.second ? "Success" : "FAILED (key already exists!)") << "\n";
    cout << "  Existing value for key 2: " << result.first->second << "\n\n";
    
    // ============================================================
    // 2. operator[key] - Access OR Insert (MOST COMMON!)
    // ============================================================
    cout << "3. operator[] - Access or Insert:\n";
    
    // If key EXISTS: returns value (reference)
    cout << "um[2] = " << um[2] << " (key exists)\n";
    
    // If key DOESN'T EXIST: CREATES new entry with default value!
    cout << "um[4] doesn't exist, so...\n";
    um[4] = "Diana";  // Creates {4, "Diana"}
    cout << "After um[4] = \"Diana\":\n";
    for (auto& p : um) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // Using [] to modify existing value
    um[2] = "Alicia";  // Updates key 2
    cout << "\nAfter um[2] = \"Alicia\":\n";
    cout << "  um[2] = " << um[2] << "\n";
    cout << "✓ [] operator can INSERT and UPDATE!\n\n";
    
    // ============================================================
    // 3. at(key) - Safe access with bounds checking
    // ============================================================
    cout << "4. at() - Safe access with bounds checking:\n";
    
    try {
        cout << "um.at(1) = " << um.at(1) << "\n";
        cout << "um.at(3) = " << um.at(3) << "\n";
        
        // This will throw exception if key doesn't exist!
        cout << "Trying um.at(99)...\n";
        cout << um.at(99) << "\n";  // THROWS EXCEPTION!
    }
    catch (const out_of_range& e) {
        cout << "  EXCEPTION: Key 99 not found!\n";
    }
    cout << "✓ at() is SAFE but SLOWER than []\n\n";
    
    // ============================================================
    // 4. find(key) - Search for a key (FAST!)
    // ============================================================
    cout << "5. find() - Searching for keys:\n";
    
    auto it = um.find(3);
    if (it != um.end()) {
        cout << "Found: Key " << it->first << " -> Value: " << it->second << "\n";
    }
    
    it = um.find(99);
    if (it == um.end()) {
        cout << "Key 99 not found (returns end())\n";
    }
    cout << "✓ Time complexity: O(1) average!\n\n";
    
    // ============================================================
    // 5. erase(key) - Remove element by key
    // ============================================================
    cout << "6. erase() - Removing elements:\n";
    
    cout << "Before erase - Size: " << um.size() << "\n";
    cout << "Contents: ";
    for (auto& p : um) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";
    
    // Erase by key
    int removed = um.erase(2);
    cout << "Erased key 2: " << removed << " element removed\n";
    
    // Erase by iterator
    it = um.find(4);
    if (it != um.end()) {
        um.erase(it);
        cout << "Erased key 4 using iterator\n";
    }
    
    cout << "After erase - Size: " << um.size() << "\n";
    cout << "Contents: ";
    for (auto& p : um) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n\n";
    
    // ============================================================
    // 6. size() and empty()
    // ============================================================
    cout << "7. size() and empty():\n";
    cout << "Current size: " << um.size() << "\n";
    cout << "Is empty? " << (um.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. clear() - Remove all elements
    // ============================================================
    cout << "8. clear() - Removing all elements:\n";
    um.clear();
    cout << "After clear - Size: " << um.size() << "\n";
    cout << "Is empty? " << (um.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 8. DIFFERENT INITIALIZATION METHODS
    // ============================================================
    cout << "9. Different initialization methods:\n";
    
    // Method 1: Empty + insert/[]
    unordered_map<int, string> um1;
    um1[1] = "One";
    um1[2] = "Two";
    um1[3] = "Three";
    cout << "um1 (empty + []): ";
    for (auto& p : um1) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";
    
    // Method 2: Initializer list (C++11)
    unordered_map<int, string> um2 = {
        {1, "Apple"},
        {2, "Banana"},
        {3, "Cherry"},
        {4, "Date"}
    };
    cout << "um2 (initializer list): ";
    for (auto& p : um2) cout << "{" << p.first << "," << p.second << "} ";
    cout << "  (UNSORTED!)\n";
    
    // Method 3: From another map
    unordered_map<int, string> um3(um2);
    cout << "um3 (copy of um2): ";
    for (auto& p : um3) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n\n";
    
    // ============================================================
    // 9. DIFFERENT KEY/VALUE TYPES
    // ============================================================
    cout << "10. Different key/value types:\n";
    
    // String keys, int values (phonebook)
    unordered_map<string, int> phonebook;
    phonebook["John"] = 123456;
    phonebook["Alice"] = 789012;
    phonebook["Bob"] = 345678;
    phonebook["Alice"] = 999999;  // Update
    
    cout << "Phonebook (name -> number):\n";
    for (auto& p : phonebook) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
    
    // String keys, double values (prices)
    unordered_map<string, double> prices;
    prices["Laptop"] = 999.99;
    prices["Mouse"] = 29.99;
    prices["Keyboard"] = 79.99;
    
    cout << "Prices (product -> price):\n";
    for (auto& p : prices) {
        cout << "  " << p.first << " -> $" << p.second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 10. count(key) - Check if key exists
    // ============================================================
    cout << "11. count() - Check if key exists:\n";
    
    if (phonebook.count("John") > 0) {
        cout << "John exists in phonebook\n";
    }
    
    if (phonebook.count("Zebra") == 0) {
        cout << "Zebra not found in phonebook\n";
    }
    cout << "✓ Returns 0 or 1 (unique keys)\n\n";
    
    // ============================================================
    // 11. BUCKET INTERFACE - Understanding hash table
    // ============================================================
    cout << "12. BUCKET INTERFACE - How hash table works:\n";
    
    unordered_map<int, string> hash_demo = {
        {10, "Ten"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"}
    };
    
    cout << "Hash table statistics:\n";
    cout << "  Number of buckets: " << hash_demo.bucket_count() << "\n";
    cout << "  Load factor: " << hash_demo.load_factor() << "\n";
    cout << "  Max load factor: " << hash_demo.max_load_factor() << "\n";
    cout << "  Size: " << hash_demo.size() << "\n";
    
    cout << "\nBucket distribution:\n";
    for (auto& p : hash_demo) {
        cout << "  Key " << p.first << " is in bucket " 
             << hash_demo.bucket(p.first) << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 12. rehash() and reserve() - Performance tuning
    // ============================================================
    cout << "13. rehash() and reserve() - Performance tuning:\n";
    
    unordered_map<int, string> perf;
    perf.reserve(100);  // Reserve space for 100 elements
    cout << "After reserve(100): Buckets = " << perf.bucket_count() << "\n";
    
    for (int i = 0; i < 50; i++) {
        perf[i] = "Value" + to_string(i);
    }
    cout << "After inserting 50 elements:\n";
    cout << "  Size: " << perf.size() << "\n";
    cout << "  Buckets: " << perf.bucket_count() << "\n";
    cout << "  Load factor: " << perf.load_factor() << "\n\n";
    
    // ============================================================
    // 13. PRACTICAL EXAMPLE 1: Student grades database
    // ============================================================
    cout << "14. PRACTICAL EXAMPLE - Student Grades:\n";
    
    unordered_map<string, char> grades;
    
    // Add grades
    grades["Alice"] = 'A';
    grades["Bob"] = 'B';
    grades["Charlie"] = 'A';
    grades["Diana"] = 'C';
    grades["Eve"] = 'B';
    
    cout << "Student Grades:\n";
    for (auto& p : grades) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }
    
    // Lookup a grade
    string student = "Charlie";
    if (grades.find(student) != grades.end()) {
        cout << "\n" << student << "'s grade: " << grades[student] << "\n";
    }
    
    // Update grade
    grades["Bob"] = 'A';  // Bob improved!
    cout << "Bob's new grade: " << grades["Bob"] << "\n";
    
    // Remove student
    grades.erase("Diana");
    cout << "After removing Diana, size: " << grades.size() << "\n\n";
    
    // ============================================================
    // 14. PRACTICAL EXAMPLE 2: Word frequency counter (FAST!)
    // ============================================================
    cout << "15. PRACTICAL EXAMPLE - Word Frequency Counter:\n";
    
    string text = "the quick brown fox jumps over the lazy dog the quick fox";
    unordered_map<string, int> freq;
    string word = "";
    
    cout << "Text: " << text << "\n\n";
    
    // Count word frequencies
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                freq[word]++;  // Beautiful! Inserts or increments
                word = "";
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) freq[word]++;
    
    cout << "Word frequencies:\n";
    for (auto& p : freq) {
        cout << "  '" << p.first << "' appears " << p.second << " times\n";
    }
    cout << "✓ Total unique words: " << freq.size() << "\n\n";
    
    // ============================================================
    // 15. PRACTICAL EXAMPLE 3: Cache/Lookup table
    // ============================================================
    cout << "16. PRACTICAL EXAMPLE - Product Cache:\n";
    
    unordered_map<int, pair<string, double>> product_cache;
    
    // Simulate loading from database
    product_cache[101] = {"Laptop", 999.99};
    product_cache[102] = {"Mouse", 29.99};
    product_cache[103] = {"Keyboard", 79.99};
    product_cache[104] = {"Monitor", 299.99};
    
    // Fast lookup by ID
    int search_id = 103;
    auto prod_it = product_cache.find(search_id);
    if (prod_it != product_cache.end()) {
        cout << "Product " << search_id << ":\n";
        cout << "  Name: " << prod_it->second.first << "\n";
        cout << "  Price: $" << prod_it->second.second << "\n";
    }
    
    // Check if product exists
    search_id = 999;
    if (product_cache.count(search_id) == 0) {
        cout << "\nProduct " << search_id << " not in cache\n";
    }
    cout << "\n";
    
    // ============================================================
    // 16. PRACTICAL EXAMPLE 4: Config settings
    // ============================================================
    cout << "17. PRACTICAL EXAMPLE - Configuration Settings:\n";
    
    unordered_map<string, string> config;
    
    // Load configuration
    config["theme"] = "dark";
    config["font_size"] = "12";
    config["language"] = "en";
    config["auto_save"] = "true";
    
    cout << "Current settings:\n";
    for (auto& p : config) {
        cout << "  " << p.first << " = " << p.second << "\n";
    }
    
    // Access settings
    cout << "\nTheme: " << config["theme"] << "\n";
    cout << "Font size: " << config["font_size"] << "\n";
    
    // Update setting
    config["theme"] = "light";
    cout << "Theme changed to: " << config["theme"] << "\n\n";
    
    // ============================================================
    // 17. MAP vs UNORDERED_MAP - COMPARISON
    // ============================================================
    cout << "18. MAP vs UNORDERED_MAP - Which to use?\n";
    cout << "\n╔════════════════╦════════════════════════╦══════════════════════════╗\n";
    cout << "║ Feature        ║ map                    ║ unordered_map            ║\n";
    cout << "╠════════════════╬════════════════════════╬══════════════════════════╣\n";
    cout << "║ Order          ║ SORTED (by key)        ║ NO ORDER                 ║\n";
    cout << "║ Duplicate keys ║ NO                     ║ NO                       ║\n";
    cout << "║ Implementation ║ Red-Black Tree         ║ Hash Table               ║\n";
    cout << "║ Insert         ║ O(log n)               ║ O(1) average, O(n) worst ║\n";
    cout << "║ Find           ║ O(log n)               ║ O(1) average, O(n) worst ║\n";
    cout << "║ Erase          ║ O(log n)               ║ O(1) average, O(n) worst ║\n";
    cout << "║ [] operator    ║ YES                    ║ YES                      ║\n";
    cout << "║ at()           ║ YES                    ║ YES                      ║\n";
    cout << "║ Memory         ║ Less                   ║ More (hash table)        ║\n";
    cout << "╚════════════════╩════════════════════════╩══════════════════════════╝\n";
    
    cout << "\n--- When to use UNORDERED_MAP ---\n";
    cout << "✓ Need FAST O(1) lookups/inserts\n";
    cout << "✓ Order doesn't matter\n";
    cout << "✓ Working with large data sets\n";
    cout << "✓ Implementing caches\n";
    cout << "✓ Dictionaries/Lookup tables\n";
    cout << "✓ Counting frequencies\n";
    cout << "✓ Phone books\n";
    cout << "✓ Configuration settings\n";
    
    cout << "\n--- When to use MAP ---\n";
    cout << "✓ Need elements in SORTED order\n";
    cout << "✓ Need range operations (lower_bound, upper_bound)\n";
    cout << "✓ Need to iterate in sorted order\n";
    cout << "✓ When worst-case performance must be guaranteed\n";
    cout << "✓ Memory is constrained\n";
    
    // ============================================================
    // 18. QUICK REFERENCE - Unordered Map Operations
    // ============================================================
    cout << "\n19. UNORDERED MAP - QUICK REFERENCE:\n";
    cout << "╔══════════════╦════════════════════════════════════╦═══════════════╗\n";
    cout << "║ Operation    ║ Description                        ║ Complexity    ║\n";
    cout << "╠══════════════╬════════════════════════════════════╬═══════════════╣\n";
    cout << "║ um[key] = val║ Insert or update (CREATES if new!)║ O(1) average  ║\n";
    cout << "║ um.at(key)   ║ Safe access (throws if not found) ║ O(1) average  ║\n";
    cout << "║ insert({k,v})║ Insert only if key doesn't exist  ║ O(1) average  ║\n";
    cout << "║ erase(key)   ║ Remove element by key              ║ O(1) average  ║\n";
    cout << "║ find(key)    ║ Find element by key                ║ O(1) average  ║\n";
    cout << "║ count(key)   ║ Check if key exists (0 or 1)       ║ O(1) average  ║\n";
    cout << "║ size()       ║ Number of key-value pairs          ║ O(1)          ║\n";
    cout << "║ empty()      ║ Check if map is empty              ║ O(1)          ║\n";
    cout << "║ clear()      ║ Remove all elements                ║ O(n)          ║\n";
    cout << "║ bucket_count()║ Number of hash buckets           ║ O(1)          ║\n";
    cout << "║ load_factor() ║ Average elements per bucket       ║ O(1)          ║\n";
    cout << "║ reserve(n)   ║ Reserve space for n elements       ║ O(n)          ║\n";
    cout << "╚══════════════╩════════════════════════════════════╩═══════════════╝\n";
    
    cout << "\n=== End of Unordered Map Operations Demo ===\n";
    
    return 0;
}