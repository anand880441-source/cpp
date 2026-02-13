/**
 * Unordered Multimap Operations Demo - C++ STL Unordered Multimap
 * 
 * An unordered_multimap is like unordered_map, but ALLOWS DUPLICATE KEYS.
 * Uses HASH TABLE internally → FAST O(1) average operations!
 * Think of it as: MULTIMAP but UNSORTED and FASTER!
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <unordered_map>  // for unordered_multimap
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    cout << "=== C++ STL UNORDERED MULTIMAP Operations Demo ===\n";
    cout << "Unordered Multimap = DUPLICATE KEYS allowed, NO order, FAST (O(1) average)\n";
    cout << "Underlying data structure: HASH TABLE\n\n";
    
    // ============================================================
    // CREATE an unordered_multimap
    // ============================================================
    cout << "1. CREATING an unordered_multimap:\n";
    unordered_multimap<int, string> umm;  // key: int, value: string
    cout << "Created empty unordered_multimap\n\n";
    
    // ============================================================
    // 1. insert({key, value}) - Adding key-value pairs (DUPLICATE KEYS ALLOWED!)
    // ============================================================
    cout << "2. insert() - Adding key-value pairs:\n";
    
    // Add some entries
    umm.insert({1, "John"});
    umm.insert({2, "Alice"});
    umm.insert({3, "Bob"});
    
    cout << "After first inserts:\n";
    for (auto& p : umm) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "✓ Notice: NO particular order! (Order may vary each run)\n";
    
    // NOW INSERT DUPLICATE KEYS - THIS IS DIFFERENT FROM unordered_map!
    cout << "\nAdding DUPLICATE KEYS:\n";
    umm.insert({1, "Jane"});     // Same key 1, different value
    umm.insert({2, "Bob"});      // Same key 2, different value
    umm.insert({1, "James"});    // Same key 1, different value
    umm.insert({3, "Barbara"});  // Same key 3, different value
    
    cout << "After inserting duplicate keys:\n";
    for (auto& p : umm) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "✓ Notice: DUPLICATE KEYS ARE KEPT!\n";
    cout << "✓ Unlike unordered_map which would reject duplicates\n\n";
    
    // ============================================================
    // 2. count(key) - How many values for a key?
    // ============================================================
    cout << "3. count() - Counting how many values for a key:\n";
    
    cout << "Key 1 appears " << umm.count(1) << " times\n";
    cout << "Key 2 appears " << umm.count(2) << " times\n";
    cout << "Key 3 appears " << umm.count(3) << " times\n";
    cout << "Key 99 appears " << umm.count(99) << " times (not found)\n\n";
    
    // ============================================================
    // 3. find(key) - Find FIRST occurrence of a key
    // ============================================================
    cout << "4. find() - Finding FIRST occurrence of a key:\n";
    
    auto it = umm.find(2);
    if (it != umm.end()) {
        cout << "Found key " << it->first << " -> " << it->second;
        cout << " (this is the FIRST value for key 2)\n";
    }
    
    it = umm.find(99);
    if (it == umm.end()) {
        cout << "Key 99 not found (returns end())\n";
    }
    cout << "✓ Time complexity: O(1) average!\n\n";
    
    // ============================================================
    // 4. erase(key) - Removes ALL occurrences of a key
    // ============================================================
    cout << "5. erase() - Removing elements:\n";
    
    cout << "Before erase - Size: " << umm.size() << "\n";
    cout << "Contents:\n";
    for (auto& p : umm) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // erase(key) - Removes ALL entries with that key
    int removed = umm.erase(1);
    cout << "\nRemoved " << removed << " entries with key 1\n";
    
    cout << "After erase(1):\n";
    for (auto& p : umm) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // erase(iterator) - Removes SINGLE element
    it = umm.find(2);
    if (it != umm.end()) {
        umm.erase(it);
        cout << "\nRemoved ONE entry with key 2 using iterator\n";
        cout << "After erasing one key 2:\n";
        for (auto& p : umm) {
            cout << "  " << p.first << " -> " << p.second << "\n";
        }
    }
    cout << "After erase - Size: " << umm.size() << "\n\n";
    
    // ============================================================
    // 5. size() and empty()
    // ============================================================
    cout << "6. size() and empty():\n";
    cout << "Current size: " << umm.size() << "\n";
    cout << "Is empty? " << (umm.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 6. clear() - Remove all elements
    // ============================================================
    cout << "7. clear() - Removing all elements:\n";
    umm.clear();
    cout << "After clear - Size: " << umm.size() << "\n";
    cout << "Is empty? " << (umm.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. DIFFERENT INITIALIZATION METHODS
    // ============================================================
    cout << "8. Different initialization methods:\n";
    
    // Method 1: Empty + insert
    unordered_multimap<int, string> umm1;
    umm1.insert({1, "One"});
    umm1.insert({2, "Two"});
    umm1.insert({1, "Uno"});     // Duplicate key - KEPT!
    umm1.insert({2, "Dos"});     // Duplicate key - KEPT!
    cout << "umm1 (empty + insert): ";
    for (auto& p : umm1) cout << "{" << p.first << "," << p.second << "} ";
    cout << "  (duplicate keys KEPT!)\n";
    
    // Method 2: Initializer list
    unordered_multimap<int, string> umm2 = {
        {1, "Apple"},
        {2, "Banana"},
        {1, "Apricot"},   // Duplicate key 1
        {3, "Cherry"},
        {2, "Blueberry"}, // Duplicate key 2
        {1, "Avocado"}    // Duplicate key 1
    };
    cout << "umm2 (initializer list with duplicates): ";
    for (auto& p : umm2) cout << "{" << p.first << "," << p.second << "} ";
    cout << "  (ALL duplicates kept, UNSORTED!)\n";
    
    // Method 3: From another unordered_multimap
    unordered_multimap<int, string> umm3(umm2);
    cout << "umm3 (copy of umm2): ";
    for (auto& p : umm3) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n\n";
    
    // ============================================================
    // 8. equal_range() - Get ALL values for a key
    // ============================================================
    cout << "9. equal_range() - Get ALL values for a key:\n";
    
    unordered_multimap<int, string> courses = {
        {1, "Math"},
        {2, "Physics"},
        {1, "Algebra"},
        {3, "Chemistry"},
        {1, "Calculus"},
        {2, "Mechanics"},
        {1, "Geometry"},
        {2, "Electronics"}
    };
    
    cout << "All courses:\n";
    for (auto& p : courses) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // Get ALL values for key 1
    cout << "\nAll courses for key 1:\n";
    auto range = courses.equal_range(1);
    int count = 1;
    for (auto it = range.first; it != range.second; ++it) {
        cout << "  " << count++ << ". " << it->second << "\n";
    }
    
    // Get ALL values for key 2
    cout << "\nAll courses for key 2:\n";
    range = courses.equal_range(2);
    count = 1;
    for (auto it = range.first; it != range.second; ++it) {
        cout << "  " << count++ << ". " << it->second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 9. IMPORTANT: NO [] operator and NO at() in unordered_multimap!
    // ============================================================
    cout << "10. IMPORTANT: unordered_multimap has NO [] or at()!\n";
    cout << "✓ unordered_multimap: NO umm[key] = value\n";
    cout << "✓ unordered_multimap: NO umm.at(key)\n";
    cout << "✗ This is NOT allowed in unordered_multimap!\n";
    cout << "  Reason: Which value would it return when keys can have multiple values?\n\n";
    
    // ============================================================
    // 10. BUCKET INTERFACE - Understanding hash table
    // ============================================================
    cout << "11. BUCKET INTERFACE - How hash table works:\n";
    
    unordered_multimap<int, string> hash_demo = {
        {10, "Ten"},
        {20, "Twenty"},
        {10, "Ten2"},    // Duplicate
        {30, "Thirty"},
        {20, "Twenty2"}, // Duplicate
        {10, "Ten3"}     // Duplicate
    };
    
    cout << "Hash table statistics:\n";
    cout << "  Number of buckets: " << hash_demo.bucket_count() << "\n";
    cout << "  Load factor: " << hash_demo.load_factor() << "\n";
    cout << "  Size: " << hash_demo.size() << "\n";
    
    cout << "\nBucket distribution:\n";
    for (auto& p : hash_demo) {
        cout << "  Key " << p.first << " -> " << p.second 
             << " is in bucket " << hash_demo.bucket(p.first) << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 11. STRING KEYS - Very common use case
    // ============================================================
    cout << "12. STRING KEYS - Unordered multimap with string keys:\n";
    
    unordered_multimap<string, string> dictionary;
    
    // One word can have multiple meanings
    dictionary.insert({"run", "to move quickly on foot"});
    dictionary.insert({"run", "to operate (e.g., run a program)"});
    dictionary.insert({"run", "a series of performances"});
    dictionary.insert({"bank", "financial institution"});
    dictionary.insert({"bank", "side of a river"});
    dictionary.insert({"bank", "to deposit money"});
    dictionary.insert({"run", "a quick trip"});
    
    cout << "Dictionary entries:\n";
    for (auto& p : dictionary) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }
    
    cout << "\nNumber of meanings for 'run': " << dictionary.count("run") << "\n";
    cout << "Number of meanings for 'bank': " << dictionary.count("bank") << "\n";
    
    // Find all meanings of 'run'
    cout << "\nAll meanings of 'run':\n";
    auto run_range = dictionary.equal_range("run");
    int meaning_num = 1;
    for (auto it = run_range.first; it != run_range.second; ++it) {
        cout << "  " << meaning_num++ << ". " << it->second << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 12. PRACTICAL EXAMPLE 1: Student courses registration
    // ============================================================
    cout << "13. PRACTICAL EXAMPLE - Student Course Registration:\n";
    
    unordered_multimap<string, string> registration;
    
    // One student can take multiple courses
    registration.insert({"Alice", "Math"});
    registration.insert({"Bob", "Physics"});
    registration.insert({"Alice", "Computer Science"});
    registration.insert({"Charlie", "Chemistry"});
    registration.insert({"Alice", "English"});
    registration.insert({"Bob", "Math"});
    registration.insert({"Alice", "History"});
    registration.insert({"Diana", "Biology"});
    
    cout << "All registrations:\n";
    for (auto& p : registration) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // Find all courses for Alice
    cout << "\nAlice's courses:\n";
    auto alice_courses = registration.equal_range("Alice");
    int course_num = 1;
    for (auto it = alice_courses.first; it != alice_courses.second; ++it) {
        cout << "  " << course_num++ << ". " << it->second << "\n";
    }
    
    // Count courses per student
    cout << "\nCourse counts:\n";
    cout << "  Alice: " << registration.count("Alice") << " courses\n";
    cout << "  Bob: " << registration.count("Bob") << " courses\n";
    cout << "  Charlie: " << registration.count("Charlie") << " courses\n";
    cout << "  Diana: " << registration.count("Diana") << " courses\n\n";
    
    // ============================================================
    // 13. PRACTICAL EXAMPLE 2: Product categories
    // ============================================================
    cout << "14. PRACTICAL EXAMPLE - Product Categories:\n";
    
    unordered_multimap<string, string> store;
    
    // One category can have multiple products
    store.insert({"Electronics", "Laptop"});
    store.insert({"Electronics", "Smartphone"});
    store.insert({"Electronics", "Tablet"});
    store.insert({"Clothing", "Shirt"});
    store.insert({"Clothing", "Jeans"});
    store.insert({"Books", "Novel"});
    store.insert({"Books", "Textbook"});
    store.insert({"Books", "Comics"});
    store.insert({"Electronics", "Headphones"});
    store.insert({"Clothing", "Jacket"});
    
    cout << "Products by category:\n";
    string current_cat = "";
    // Note: Since it's unordered, we need a different approach
    // Let's collect unique categories first
    unordered_set<string> categories;
    for (auto& p : store) {
        categories.insert(p.first);
    }
    
    for (const string& cat : categories) {
        cout << "\n  " << cat << ":\n";
        auto cat_range = store.equal_range(cat);
        for (auto it = cat_range.first; it != cat_range.second; ++it) {
            cout << "    - " << it->second << "\n";
        }
    }
    
    // Count products in Electronics
    cout << "\nElectronics has " << store.count("Electronics") << " products\n";
    
    // Remove a category
    store.erase("Books");
    cout << "After removing Books category, size: " << store.size() << "\n\n";
    
    // ============================================================
    // 14. PRACTICAL EXAMPLE 3: Tags system
    // ============================================================
    cout << "15. PRACTICAL EXAMPLE - Article Tags:\n";
    
    unordered_multimap<string, string> article_tags;
    
    // Articles can have multiple tags
    article_tags.insert({"Article1", "C++"});
    article_tags.insert({"Article1", "Programming"});
    article_tags.insert({"Article1", "STL"});
    article_tags.insert({"Article2", "Python"});
    article_tags.insert({"Article2", "Programming"});
    article_tags.insert({"Article3", "C++"});
    article_tags.insert({"Article3", "Algorithms"});
    article_tags.insert({"Article1", "Data Structures"});
    
    cout << "All article tags:\n";
    for (auto& p : article_tags) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    
    // Find all tags for Article1
    cout << "\nTags for Article1:\n";
    auto article1_tags = article_tags.equal_range("Article1");
    int tag_num = 1;
    for (auto it = article1_tags.first; it != article1_tags.second; ++it) {
        cout << "  " << tag_num++ << ". " << it->second << "\n";
    }
    
    // Count how many articles use C++
    cout << "\nArticles using C++: " << article_tags.count("C++") << "\n";
    cout << "Articles using Python: " << article_tags.count("Python") << "\n\n";
    
    // ============================================================
    // 15. UNORDERED_MAP vs UNORDERED_MULTIMAP - COMPARISON
    // ============================================================
    cout << "16. UNORDERED_MAP vs UNORDERED_MULTIMAP:\n";
    cout << "\n╔══════════════════════╦════════════════════════╦══════════════════════════╗\n";
    cout << "║ Feature              ║ unordered_map          ║ unordered_multimap       ║\n";
    cout << "╠══════════════════════╬════════════════════════╬══════════════════════════╣\n";
    cout << "║ Duplicate keys       ║ NO                     ║ YES                      ║\n";
    cout << "║ [] operator          ║ YES (m[k] = v)         ║ NO                       ║\n";
    cout << "║ at()                 ║ YES                    ║ NO                       ║\n";
    cout << "║ insert({k,v})        ║ One per key            ║ Multiple per key         ║\n";
    cout << "║ erase(key)           ║ Removes one entry      ║ Removes ALL entries      ║\n";
    cout << "║ count(key)           ║ Returns 0 or 1         ║ Returns 0,1,2,3...       ║\n";
    cout << "║ find(key)            ║ Unique entry           ║ First occurrence         ║\n";
    cout << "║ equal_range(key)     ║ Range of 1 element     ║ Range of ALL elements    ║\n";
    cout << "╚══════════════════════╩════════════════════════╩══════════════════════════╝\n";
    
    cout << "\n--- When to use UNORDERED_MULTIMAP ---\n";
    cout << "✓ One key needs MULTIPLE values\n";
    cout << "✓ Order doesn't matter\n";
    cout << "✓ Need FAST O(1) operations\n";
    cout << "✓ Student taking multiple courses\n";
    cout << "✓ Product categories\n";
    cout << "✓ Dictionary with multiple meanings\n";
    cout << "✓ Article/blog post tags\n";
    cout << "✓ Index/Cross-reference systems\n";
    
    cout << "\n--- When NOT to use UNORDERED_MULTIMAP ---\n";
    cout << "✗ If you need sorted keys (use multimap)\n";
    cout << "✗ If you need unique keys (use unordered_map)\n";
    cout << "✗ If you need [] operator (use unordered_map)\n";
    cout << "✗ If memory is limited (hash table overhead)\n";
    
    // ============================================================
    // 16. QUICK REFERENCE - Unordered Multimap Operations
    // ============================================================
    cout << "\n17. UNORDERED MULTIMAP - QUICK REFERENCE:\n";
    cout << "╔══════════════╦════════════════════════════════════╦═══════════════╗\n";
    cout << "║ Operation    ║ Description                        ║ Complexity    ║\n";
    cout << "╠══════════════╬════════════════════════════════════╬═══════════════╣\n";
    cout << "║ insert({k,v})║ Add key-value pair (duplicates OK)║ O(1) average  ║\n";
    cout << "║ erase(key)   ║ Remove ALL entries with this key  ║ O(1) average  ║\n";
    cout << "║ find(key)    ║ Find FIRST occurrence of key      ║ O(1) average  ║\n";
    cout << "║ count(key)   ║ How many values for this key      ║ O(1) average  ║\n";
    cout << "║ equal_range(k)║ Get ALL values for a key        ║ O(1) average  ║\n";
    cout << "║ size()       ║ Total number of key-value pairs   ║ O(1)          ║\n";
    cout << "║ empty()      ║ Check if map is empty             ║ O(1)          ║\n";
    cout << "║ clear()      ║ Remove all elements               ║ O(n)          ║\n";
    cout << "║ bucket_count()║ Number of hash buckets           ║ O(1)          ║\n";
    cout << "║ load_factor() ║ Average elements per bucket      ║ O(1)          ║\n";
    cout << "║ reserve(n)   ║ Reserve space for n elements      ║ O(n)          ║\n";
    cout << "╚══════════════╩════════════════════════════════════╩═══════════════╝\n";
    
    cout << "\n=== End of Unordered Multimap Operations Demo ===\n";
    
    return 0;
}