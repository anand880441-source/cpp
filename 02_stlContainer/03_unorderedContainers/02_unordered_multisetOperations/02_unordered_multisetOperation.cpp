/**
 * Unordered Multiset Operations Demo - C++ STL Unordered Multiset
 * 
 * An unordered_multiset is like unordered_set, but ALLOWS DUPLICATE VALUES.
 * Uses HASH TABLE internally → FAST O(1) average operations!
 * Think of it as: MULTISET but UNSORTED and FASTER!
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <unordered_set>  // for unordered_multiset
#include <string>
using namespace std;

int main() {
    cout << "=== C++ STL UNORDERED MULTISET Operations Demo ===\n";
    cout << "Unordered Multiset = DUPLICATES allowed, NO order, FAST (O(1) average)\n";
    cout << "Underlying data structure: HASH TABLE\n\n";
    
    // ============================================================
    // CREATE an unordered_multiset
    // ============================================================
    cout << "1. CREATING an unordered_multiset:\n";
    unordered_multiset<int> ums;
    cout << "Created empty unordered_multiset\n\n";
    
    // ============================================================
    // 1. insert() - Adding elements (DUPLICATES ALLOWED!)
    // ============================================================
    cout << "2. insert() - Adding elements:\n";
    
    ums.insert(30);
    ums.insert(10);
    ums.insert(50);
    ums.insert(20);
    ums.insert(40);
    
    cout << "After first inserts: 30, 10, 50, 20, 40\n";
    cout << "Contents: ";
    for (int x : ums) cout << x << " ";
    cout << "\n";
    
    // NOW INSERT DUPLICATES - THIS IS DIFFERENT FROM unordered_set!
    cout << "\nAdding DUPLICATES:\n";
    ums.insert(30);
    ums.insert(20);
    ums.insert(30);
    ums.insert(10);
    
    cout << "After inserting duplicates (30, 20, 30, 10):\n";
    cout << "Contents: ";
    for (int x : ums) cout << x << " ";
    cout << "\n";
    cout << "✓ Notice: DUPLICATES ARE KEPT!\n";
    cout << "✓ Notice: NO particular order!\n\n";
    
    // ============================================================
    // 2. count() - How many times a value appears
    // ============================================================
    cout << "3. count() - Counting occurrences:\n";
    cout << "Number of 30's: " << ums.count(30) << "\n";
    cout << "Number of 20's: " << ums.count(20) << "\n";
    cout << "Number of 10's: " << ums.count(10) << "\n";
    cout << "Number of 40's: " << ums.count(40) << "\n";
    cout << "Number of 50's: " << ums.count(50) << "\n";
    cout << "Number of 99's: " << ums.count(99) << " (not found)\n\n";
    
    // ============================================================
    // 3. find() - Find FIRST occurrence of a value
    // ============================================================
    cout << "4. find() - Finding first occurrence:\n";
    
    auto it = ums.find(30);
    if (it != ums.end()) {
        cout << "Found " << *it << " (first occurrence of 30)\n";
    }
    
    it = ums.find(99);
    if (it == ums.end()) {
        cout << "99 not found (returns end())\n";
    }
    cout << "\n";
    
    // ============================================================
    // 4. erase() - Removing elements (ALL occurrences!)
    // ============================================================
    cout << "5. erase() - Removing elements:\n";
    
    cout << "Before erase - Size: " << ums.size() << "\n";
    cout << "Contents: ";
    for (int x : ums) cout << x << " ";
    cout << "\n";
    
    // erase(value) - Removes ALL occurrences
    int removed = ums.erase(30);
    cout << "Removed " << removed << " occurrences of 30\n";
    
    cout << "After erase(30): ";
    for (int x : ums) cout << x << " ";
    cout << "\n";
    
    // erase(iterator) - Removes SINGLE element
    it = ums.find(20);
    if (it != ums.end()) {
        ums.erase(it);
        cout << "Removed ONE occurrence of 20 using iterator\n";
    }
    
    cout << "After removing one 20: ";
    for (int x : ums) cout << x << " ";
    cout << "\n";
    cout << "After erase - Size: " << ums.size() << "\n\n";
    
    // ============================================================
    // 5. size() and empty()
    // ============================================================
    cout << "6. size() and empty():\n";
    cout << "Current size: " << ums.size() << "\n";
    cout << "Is empty? " << (ums.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 6. clear() - Remove all elements
    // ============================================================
    cout << "7. clear() - Removing all elements:\n";
    ums.clear();
    cout << "After clear - Size: " << ums.size() << "\n";
    cout << "Is empty? " << (ums.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. DIFFERENT INITIALIZATION METHODS
    // ============================================================
    cout << "8. Different initialization methods:\n";
    
    // Method 1: Empty + insert
    unordered_multiset<int> ums1;
    ums1.insert(5);
    ums1.insert(2);
    ums1.insert(5);  // Duplicate - KEPT!
    ums1.insert(2);  // Duplicate - KEPT!
    cout << "ums1 (empty + insert): ";
    for (int x : ums1) cout << x << " ";
    cout << "  (duplicates KEPT!)\n";
    
    // Method 2: Initializer list
    unordered_multiset<int> ums2 = {5, 2, 8, 2, 1, 5, 9, 5, 2, 1};
    cout << "ums2 (initializer list): ";
    for (int x : ums2) cout << x << " ";
    cout << "  (ALL duplicates kept, UNSORTED!)\n";
    
    // Method 3: From another unordered_multiset
    unordered_multiset<int> ums3(ums2);
    cout << "ums3 (copy of ums2): ";
    for (int x : ums3) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 8. equal_range() - Get ALL occurrences of a value
    // ============================================================
    cout << "9. equal_range() - Get ALL occurrences:\n";
    
    unordered_multiset<int> range_demo = {1, 2, 3, 2, 4, 2, 5, 2, 6};
    cout << "Contents: ";
    for (int x : range_demo) cout << x << " ";
    cout << "\n";
    
    auto range = range_demo.equal_range(2);
    cout << "All occurrences of 2: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
    
    // ============================================================
    // 9. BUCKET INTERFACE - Understanding hash table
    // ============================================================
    cout << "10. BUCKET INTERFACE - How hash table works:\n";
    
    unordered_multiset<int> hash_demo = {10, 20, 30, 10, 20, 10};
    
    cout << "Hash table statistics:\n";
    cout << "  Number of buckets: " << hash_demo.bucket_count() << "\n";
    cout << "  Load factor: " << hash_demo.load_factor() << "\n";
    cout << "  Size: " << hash_demo.size() << "\n";
    
    // Show which bucket each element is in
    cout << "\nBucket distribution:\n";
    for (int x : hash_demo) {
        cout << "  Element " << x << " is in bucket " << hash_demo.bucket(x) << "\n";
    }
    cout << "\n";
    
    // ============================================================
    // 10. STRING KEYS - Very common use case
    // ============================================================
    cout << "11. STRING KEYS - Unordered multiset of strings:\n";
    
    unordered_multiset<string> fruits;
    fruits.insert("apple");
    fruits.insert("banana");
    fruits.insert("apple");  // Duplicate - KEPT!
    fruits.insert("orange");
    fruits.insert("apple");  // Duplicate - KEPT!
    fruits.insert("banana"); // Duplicate - KEPT!
    
    cout << "Fruits: ";
    for (const string& f : fruits) {
        cout << f << " ";
    }
    cout << "\n";
    cout << "Number of fruits: " << fruits.size() << "\n";
    cout << "Number of apples: " << fruits.count("apple") << "\n";
    cout << "Number of bananas: " << fruits.count("banana") << "\n";
    cout << "Number of grapes: " << fruits.count("grapes") << "\n\n";
    
    // ============================================================
    // 11. PRACTICAL EXAMPLE 1: Voting machine (multiple votes)
    // ============================================================
    cout << "12. PRACTICAL EXAMPLE - Voting Machine:\n";
    
    unordered_multiset<string> votes;
    
    // People vote for their favorite color
    votes.insert("Red");
    votes.insert("Blue");
    votes.insert("Red");
    votes.insert("Green");
    votes.insert("Red");
    votes.insert("Blue");
    votes.insert("Red");
    votes.insert("Yellow");
    votes.insert("Blue");
    
    cout << "All votes: ";
    for (const string& v : votes) cout << v << " ";
    cout << "\n";
    
    cout << "\nVote count:\n";
    cout << "  Red: " << votes.count("Red") << " votes\n";
    cout << "  Blue: " << votes.count("Blue") << " votes\n";
    cout << "  Green: " << votes.count("Green") << " votes\n";
    cout << "  Yellow: " << votes.count("Yellow") << " votes\n";
    
    // Find winner
    unordered_set<string> candidates = {"Red", "Blue", "Green", "Yellow"};
    string winner;
    int max_votes = 0;
    
    for (const string& c : candidates) {
        int c_votes = votes.count(c);
        if (c_votes > max_votes) {
            max_votes = c_votes;
            winner = c;
        }
    }
    
    cout << "\nWinner: " << winner << " with " << max_votes << " votes!\n\n";
    
    // ============================================================
    // 12. PRACTICAL EXAMPLE 2: Inventory with multiple identical items
    // ============================================================
    cout << "13. PRACTICAL EXAMPLE - Store Inventory:\n";
    
    unordered_multiset<string> inventory;
    
    // Receive shipments
    inventory.insert("Laptop");
    inventory.insert("Mouse");
    inventory.insert("Laptop");
    inventory.insert("Keyboard");
    inventory.insert("Mouse");
    inventory.insert("Laptop");
    inventory.insert("Mouse");
    inventory.insert("Monitor");
    
    cout << "Current inventory:\n";
    cout << "  Laptops: " << inventory.count("Laptop") << "\n";
    cout << "  Mice: " << inventory.count("Mouse") << "\n";
    cout << "  Keyboards: " << inventory.count("Keyboard") << "\n";
    cout << "  Monitors: " << inventory.count("Monitor") << "\n";
    
    // Sell items
    cout << "\nSelling 2 laptops and 1 mouse...\n";
    
    auto sell_it = inventory.find("Laptop");
    if (sell_it != inventory.end()) inventory.erase(sell_it);
    sell_it = inventory.find("Laptop");
    if (sell_it != inventory.end()) inventory.erase(sell_it);
    
    sell_it = inventory.find("Mouse");
    if (sell_it != inventory.end()) inventory.erase(sell_it);
    
    cout << "After sales:\n";
    cout << "  Laptops: " << inventory.count("Laptop") << "\n";
    cout << "  Mice: " << inventory.count("Mouse") << "\n";
    cout << "  Keyboards: " << inventory.count("Keyboard") << "\n";
    cout << "  Monitors: " << inventory.count("Monitor") << "\n\n";
    
    // ============================================================
    // 13. PRACTICAL EXAMPLE 3: Word frequency counter (with duplicates)
    // ============================================================
    cout << "14. PRACTICAL EXAMPLE - Word Frequency:\n";
    
    string sentence = "the cat in the hat ate the rat on the mat";
    unordered_multiset<string> word_count;
    string word = "";
    
    cout << "Sentence: " << sentence << "\n\n";
    
    // Split sentence into words and add to multiset
    for (char c : sentence) {
        if (c == ' ') {
            if (!word.empty()) {
                word_count.insert(word);
                word = "";
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) word_count.insert(word);
    
    // Count unique words using unordered_set
    unordered_set<string> unique_words(word_count.begin(), word_count.end());
    
    cout << "Word frequencies:\n";
    for (const string& w : unique_words) {
        cout << "  '" << w << "' appears " << word_count.count(w) << " times\n";
    }
    cout << "\n";
    
    // ============================================================
    // 14. PERFORMANCE COMPARISON
    // ============================================================
    cout << "15. PERFORMANCE COMPARISON:\n";
    cout << "╔════════════════════╦════════════════╦══════════════════╗\n";
    cout << "║ Operation          ║ multiset       ║ unordered_multiset║\n";
    cout << "╠════════════════════╬════════════════╬══════════════════╣\n";
    cout << "║ insert()           ║ O(log n)       ║ O(1) average     ║\n";
    cout << "║ find()             ║ O(log n)       ║ O(1) average     ║\n";
    cout << "║ count()            ║ O(log n)       ║ O(1) average     ║\n";
    cout << "║ erase(value)       ║ O(log n)       ║ O(1) average     ║\n";
    cout << "║ erase(iterator)    ║ O(1)           ║ O(1) average     ║\n";
    cout << "║ clear()            ║ O(n)           ║ O(n)             ║\n";
    cout << "╚════════════════════╩════════════════╩══════════════════╝\n";
    cout << "✓ unordered_multiset is FASTER for most operations!\n";
    cout << "✗ But elements are NOT sorted\n\n";
    
    // ============================================================
    // 15. COMPARISON TABLE - All 4 sets!
    // ============================================================
    cout << "16. THE 4 SETS - COMPARISON:\n";
    cout << "╔══════════════════════╦════════════╦════════════╦════════════╦════════════╗\n";
    cout << "║ Container            ║ Sorted?    ║ Duplicates?║ Speed      ║ Memory     ║\n";
    cout << "╠══════════════════════╬════════════╬════════════╬════════════╬════════════╣\n";
    cout << "║ set                  ║ YES        ║ NO         ║ O(log n)   ║ Low        ║\n";
    cout << "║ multiset             ║ YES        ║ YES        ║ O(log n)   ║ Low        ║\n";
    cout << "║ unordered_set        ║ NO         ║ NO         ║ O(1)*      ║ High       ║\n";
    cout << "║ unordered_multiset   ║ NO         ║ YES        ║ O(1)*      ║ High       ║\n";
    cout << "╚══════════════════════╩════════════╩════════════╩════════════╩════════════╝\n";
    cout << "*Average case, worst case O(n)\n\n";
    
    // ============================================================
    // 16. QUICK REFERENCE - Unordered Multiset Operations
    // ============================================================
    cout << "17. UNORDERED MULTISET - QUICK REFERENCE:\n";
    cout << "╔══════════════╦════════════════════════════════════╦═══════════════╗\n";
    cout << "║ Operation    ║ Description                        ║ Complexity    ║\n";
    cout << "╠══════════════╬════════════════════════════════════╬═══════════════╣\n";
    cout << "║ insert(val)  ║ Add element (duplicates ALLOWED!)  ║ O(1) average  ║\n";
    cout << "║ erase(val)   ║ Remove ALL occurrences of val      ║ O(1) average  ║\n";
    cout << "║ find(val)    ║ Find FIRST occurrence              ║ O(1) average  ║\n";
    cout << "║ count(val)   ║ Count occurrences of val           ║ O(1) average  ║\n";
    cout << "║ equal_range(val)║ Get ALL occurrences of val      ║ O(1) average  ║\n";
    cout << "║ size()       ║ Total number of elements           ║ O(1)          ║\n";
    cout << "║ empty()      ║ Check if empty                     ║ O(1)          ║\n";
    cout << "║ clear()      ║ Remove all elements                ║ O(n)          ║\n";
    cout << "║ bucket_count() ║ Number of hash buckets           ║ O(1)          ║\n";
    cout << "║ load_factor()  ║ Average elements per bucket      ║ O(1)          ║\n";
    cout << "║ reserve(n)   ║ Reserve space for n elements       ║ O(n)          ║\n";
    cout << "╚══════════════╩════════════════════════════════════╩═══════════════╝\n";
    
    cout << "\n=== End of Unordered Multiset Operations Demo ===\n";
    
    return 0;
}