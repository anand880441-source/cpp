/**
 * Multiset Operations Demo - C++ STL Multiset
 * 
 * A multiset is SIMILAR to set, but ALLOWS DUPLICATE values.
 * Elements are still stored in SORTED order.
 * 
 * Author: Anand Suthar
 * Date: 13-02-2026
 */

#include <iostream>
#include <set>        // for multiset
using namespace std;

int main() {
    cout << "=== C++ STL MULTISET Operations Demo ===\n";
    cout << "Multiset = Set that ALLOWS DUPLICATES\n";
    cout << "Elements are automatically SORTED\n\n";
    
    // ============================================================
    // CREATE a multiset
    // ============================================================
    cout << "1. CREATING a multiset:\n";
    multiset<int> ms;
    cout << "Created empty multiset of integers\n\n";
    
    // ============================================================
    // 1. insert() - Adding elements (DUPLICATES ALLOWED!)
    // ============================================================
    cout << "2. insert() - Adding elements:\n";
    
    ms.insert(30);
    ms.insert(10);
    ms.insert(50);
    ms.insert(20);
    ms.insert(40);
    
    cout << "After inserting: 30, 10, 50, 20, 40\n";
    
    // NOW INSERT DUPLICATES - THIS IS THE DIFFERENCE FROM SET!
    ms.insert(30);
    ms.insert(20);
    ms.insert(30);
    
    cout << "After inserting DUPLICATES: 30, 20, 30\n";
    
    // Display all elements
    cout << "Multiset now has: ";
    for (int x : ms) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "✓ Notice: SORTED order AND DUPLICATES are kept!\n";
    cout << "✓ Unlike set which would remove duplicates\n\n";
    
    // ============================================================
    // 2. count() - How many times a value appears
    // ============================================================
    cout << "3. count() - Counting occurrences:\n";
    
    int val = 30;
    cout << "Number of times " << val << " appears: " << ms.count(val) << "\n";
    
    val = 20;
    cout << "Number of times " << val << " appears: " << ms.count(val) << "\n";
    
    val = 10;
    cout << "Number of times " << val << " appears: " << ms.count(val) << "\n";
    
    val = 99;
    cout << "Number of times " << val << " appears: " << ms.count(val) << " (not found)\n\n";
    
    // ============================================================
    // 3. find() - Find FIRST occurrence of a value
    // ============================================================
    cout << "4. find() - Finding first occurrence:\n";
    
    auto it = ms.find(30);
    if (it != ms.end()) {
        cout << "Found " << *it << " at position: " << distance(ms.begin(), it) << "\n";
        cout << "(find() returns the FIRST occurrence)\n";
    }
    
    it = ms.find(99);
    if (it == ms.end()) {
        cout << "99 not found (returns end())\n\n";
    }
    
    // ============================================================
    // 4. erase() - Removing elements (ALL occurrences!)
    // ============================================================
    cout << "5. erase() - Removing elements:\n";
    
    cout << "Current multiset: ";
    for (int x : ms) cout << x << " ";
    cout << "\n";
    
    // erase(value) - Removes ALL occurrences of that value
    int removed = ms.erase(30);
    cout << "Removed " << removed << " occurrences of 30\n";
    
    cout << "After erase(30): ";
    for (int x : ms) cout << x << " ";
    cout << "\n";
    
    // erase(iterator) - Removes SINGLE element at position
    it = ms.find(20);
    if (it != ms.end()) {
        ms.erase(it);
        cout << "Removed one 20 using iterator\n";
    }
    
    cout << "After removing one 20: ";
    for (int x : ms) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 5. size() and empty()
    // ============================================================
    cout << "6. size() and empty():\n";
    cout << "Current size: " << ms.size() << "\n";
    cout << "Is empty? " << (ms.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 6. clear() - Remove all elements
    // ============================================================
    cout << "7. clear() - Removing all elements:\n";
    ms.clear();
    cout << "After clear() - Size: " << ms.size() << "\n";
    cout << "Is empty? " << (ms.empty() ? "Yes" : "No") << "\n\n";
    
    // ============================================================
    // 7. DIFFERENT WAYS TO CREATE MULTISET
    // ============================================================
    cout << "8. Different initialization methods:\n";
    
    // Method 1: Empty multiset
    multiset<int> ms1;
    ms1.insert(5);
    ms1.insert(2);
    ms1.insert(5);  // Duplicate
    cout << "ms1 (empty + inserts): ";
    for (int x : ms1) cout << x << " ";
    cout << "\n";
    
    // Method 2: Initializer list (C++11)
    multiset<int> ms2 = {5, 2, 8, 2, 1, 5, 9, 5};
    cout << "ms2 (initializer list {5,2,8,2,1,5,9,5}): ";
    for (int x : ms2) cout << x << " ";
    cout << "  (all duplicates kept!)\n";
    
    // Method 3: From another multiset
    multiset<int> ms3(ms2);
    cout << "ms3 (copy of ms2): ";
    for (int x : ms3) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 8. lower_bound() and upper_bound() with duplicates
    // ============================================================
    cout << "9. lower_bound() and upper_bound():\n";
    
    multiset<int> bounds = {10, 20, 20, 20, 30, 40, 40, 50};
    cout << "Multiset: ";
    for (int x : bounds) cout << x << " ";
    cout << "\n";
    
    // lower_bound - FIRST position where value can be inserted
    auto lb = bounds.lower_bound(20);
    // upper_bound - LAST position where value can be inserted
    auto ub = bounds.upper_bound(20);
    
    cout << "lower_bound(20): points to " << *lb << " at index " << distance(bounds.begin(), lb) << "\n";
    cout << "upper_bound(20): points to " << *ub << " at index " << distance(bounds.begin(), ub) << "\n";
    
    // equal_range - get BOTH bounds at once
    auto range = bounds.equal_range(20);
    cout << "equal_range(20): from " << *range.first << " to " << *range.second;
    cout << " (covers all 20's)\n\n";
    
    // ============================================================
    // 9. COMPARISON: set vs multiset
    // ============================================================
    cout << "10. SET vs MULTISET - IMPORTANT DIFFERENCES:\n";
    
    set<int> regularSet = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    multiset<int> multiSet = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    
    cout << "Same input for both: {3,1,4,1,5,9,2,6,5,3}\n";
    cout << "SET (no duplicates):      ";
    for (int x : regularSet) cout << x << " ";
    cout << "\n";
    cout << "MULTISET (with duplicates): ";
    for (int x : multiSet) cout << x << " ";
    cout << "\n";
    cout << "✓ MULTISET keeps ALL duplicates!\n";
    cout << "✓ Both are SORTED automatically!\n\n";
    
    // ============================================================
    // 10. PRACTICAL EXAMPLE 1: Voting counter
    // ============================================================
    cout << "11. PRACTICAL EXAMPLE - Vote Counter:\n";
    
    multiset<string> votes;
    
    // People vote for their favorite color
    votes.insert("Red");
    votes.insert("Blue");
    votes.insert("Red");
    votes.insert("Green");
    votes.insert("Red");
    votes.insert("Blue");
    votes.insert("Red");
    
    cout << "All votes: ";
    for (string v : votes) cout << v << " ";
    cout << "\n";
    
    cout << "Red votes: " << votes.count("Red") << "\n";
    cout << "Blue votes: " << votes.count("Blue") << "\n";
    cout << "Green votes: " << votes.count("Green") << "\n";
    cout << "Yellow votes: " << votes.count("Yellow") << " (no votes)\n\n";
    
    // ============================================================
    // 11. PRACTICAL EXAMPLE 2: Student grades tracker
    // ============================================================
    cout << "12. PRACTICAL EXAMPLE - Grade Tracker:\n";
    
    multiset<int> grades;
    
    // Add some grades (multiple students can have same grade)
    grades.insert(85);
    grades.insert(92);
    grades.insert(78);
    grades.insert(85);  // Another student with same grade
    grades.insert(90);
    grades.insert(85);  // Third student with 85
    grades.insert(95);
    
    cout << "All grades: ";
    for (int g : grades) cout << g << " ";
    cout << "\n";
    
    cout << "Class size: " << grades.size() << " students\n";
    cout << "Students with 85: " << grades.count(85) << "\n";
    cout << "Students with 95: " << grades.count(95) << "\n";
    
    // Find highest grade
    cout << "Highest grade: " << *grades.rbegin() << "\n";
    // Find lowest grade
    cout << "Lowest grade: " << *grades.begin() << "\n\n";
    
    // ============================================================
    // 12. ITERATOR TRAVERSAL
    // ============================================================
    cout << "13. Iterator traversal:\n";
    
    multiset<int> traversal = {5, 1, 5, 2, 5, 3, 5, 4};
    cout << "Multiset: ";
    for (int x : traversal) cout << x << " ";
    cout << "\n";
    
    cout << "Forward (begin to end): ";
    for (auto it = traversal.begin(); it != traversal.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Reverse (rbegin to rend): ";
    for (auto it = traversal.rbegin(); it != traversal.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
    
    // ============================================================
    // 13. MULTISET WITH CUSTOM COMPARATOR
    // ============================================================
    cout << "14. Multiset with custom comparator (descending):\n";
    
    multiset<int, greater<int>> descending = {1, 3, 5, 3, 1, 7, 5, 9};
    cout << "Descending order multiset: ";
    for (int x : descending) cout << x << " ";
    cout << "\n\n";
    
    // ============================================================
    // 14. QUICK REFERENCE - Multiset Operations
    // ============================================================
    cout << "15. MULTISET OPERATIONS - QUICK REFERENCE:\n";
    cout << "╔══════════════╦══════════════════════════════╦══════════════╗\n";
    cout << "║ Operation    ║ Description                  ║ Complexity   ║\n";
    cout << "╠══════════════╬══════════════════════════════╬══════════════╣\n";
    cout << "║ insert(val)  ║ Add element (duplicates OK) ║ O(log n)     ║\n";
    cout << "║ erase(val)   ║ Remove ALL occurrences      ║ O(log n)     ║\n";
    cout << "║ count(val)   ║ How many times value appears║ O(log n)     ║\n";
    cout << "║ find(val)    ║ Find FIRST occurrence       ║ O(log n)     ║\n";
    cout << "║ size()       ║ Total elements              ║ O(1)         ║\n";
    cout << "║ empty()      ║ Check if empty              ║ O(1)         ║\n";
    cout << "║ clear()      ║ Remove all elements         ║ O(n)         ║\n";
    cout << "╚══════════════╩══════════════════════════════╩══════════════╝\n";
    
    cout << "\n=== End of Multiset Operations Demo ===\n";
    
    return 0;
}