/**
 * List Operations Demo - C++ STL List
 * 
 * This program demonstrates common list operations with detailed explanations.
 * List is a doubly linked list that allows fast insertions and deletions at both ends.
 * 
 * Author: Anand Suthar
 * Date: 12-02-2026
 */

#include <iostream>
#include <list>
#include <string>
using namespace std;

// Helper function to display list elements
template<typename T>
void displayList(const list<T>& lst, const string& message) {
    cout << message << ": ";
    if (lst.empty()) {
        cout << "List is empty";
    } else {
        for (const T& val : lst) {
            cout << val << " ";
        }
    }
    cout << "\n";
}

// Helper function to display list details
template<typename T>
void displayListDetails(const list<T>& lst) {
    cout << "\n--- List Details ---\n";
    cout << "Size: " << lst.size() << "\n";
    cout << "Is empty? " << (lst.empty() ? "Yes" : "No") << "\n";
    if (!lst.empty()) {
        cout << "First element (front): " << lst.front() << "\n";
        cout << "Last element (back): " << lst.back() << "\n";
    }
    cout << "---------------------\n\n";
}

int main() {
    cout << "=== C++ STL List Operations Demo ===\n";
    cout << "List is a doubly linked list - optimized for insertions/deletions anywhere\n\n";
    
    // Create an empty list
    list<int> numbers;
    displayListDetails(numbers);
    
    // 1. push_back(val) - Adds element at the end
    cout << "1. push_back() - Adding elements at the end:\n";
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    displayList(numbers, "After push_back(30, 40, 50)");
    displayListDetails(numbers);
    
    // 2. push_front(val) - Adds element at the front (unique to list/deque)
    cout << "2. push_front() - Adding elements at the front:\n";
    numbers.push_front(20);
    numbers.push_front(10);
    displayList(numbers, "After push_front(20, 10)");
    displayListDetails(numbers);
    
    // 3. pop_back() - Removes the last element
    cout << "3. pop_back() - Removing last element:\n";
    numbers.pop_back();
    displayList(numbers, "After pop_back() (removed 50)");
    displayListDetails(numbers);
    
    // 4. pop_front() - Removes the first element (unique to list/deque)
    cout << "4. pop_front() - Removing first element:\n";
    numbers.pop_front();
    displayList(numbers, "After pop_front() (removed 10)");
    displayListDetails(numbers);
    
    // 5. insert(pos, val) - Inserts element at specific position
    cout << "5. insert() - Inserting elements at specific positions:\n";
    
    // Insert at beginning
    auto it = numbers.begin();
    numbers.insert(it, 5);
    displayList(numbers, "After insert at beginning (5)");
    
    // Insert at end (similar to push_back)
    numbers.insert(numbers.end(), 60);
    displayList(numbers, "After insert at end (60)");
    
    // Insert in the middle
    it = numbers.begin();
    advance(it, 2);  // Move iterator to position 2 (list doesn't support + operator)
    numbers.insert(it, 25);
    displayList(numbers, "After insert at position 2 (25)");
    
    // Insert multiple elements
    it = numbers.begin();
    advance(it, 1);
    numbers.insert(it, 3, 7);  // Insert 7 three times
    displayList(numbers, "After inserting 7 three times at position 1");
    displayListDetails(numbers);
    
    // 6. erase(pos) - Removes element at specific position
    cout << "6. erase() - Removing elements:\n";
    
    // Erase single element
    it = numbers.begin();
    advance(it, 2);
    numbers.erase(it);  // Remove element at index 2
    displayList(numbers, "After erasing element at position 2");
    
    // Erase range of elements
    auto start = numbers.begin();
    auto end = numbers.begin();
    advance(start, 1);
    advance(end, 4);
    numbers.erase(start, end);  // Remove range [position 1, position 4)
    displayList(numbers, "After erasing range (positions 1-3)");
    displayListDetails(numbers);
    
    // 7. remove(val) - Removes ALL elements matching value (unique to list)
    cout << "7. remove() - Removing all elements with specific value:\n";
    numbers.push_back(30);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(30);
    displayList(numbers, "Before remove(30) - added duplicates");
    
    numbers.remove(30);  // Removes ALL occurrences of 30
    displayList(numbers, "After remove(30)");
    displayListDetails(numbers);
    
    // 8. reverse() - Reverses the list
    cout << "8. reverse() - Reversing the list:\n";
    numbers.reverse();
    displayList(numbers, "After reverse()");
    displayListDetails(numbers);
    
    // 9. sort() - Sorts the list
    cout << "9. sort() - Sorting the list:\n";
    numbers.sort();  // Ascending order (default)
    displayList(numbers, "After sort() (ascending)");
    
    // Sort in descending order using greater<int>()
    // Note: greater<int>() is from <functional> but it's often included via <iostream>
    // If you want to be explicit, you can use a lambda or custom comparator
    numbers.sort([](int a, int b) { return a > b; });  // Lambda for descending order
    displayList(numbers, "After sort(descending lambda)");
    displayListDetails(numbers);
    
    // 10. Unique list operations
    cout << "\n10. Unique list operations:\n";
    
    // splice() - Transfer elements from one list to another
    list<int> list1 = {1, 2, 3, 4, 5};
    list<int> list2 = {10, 20, 30, 40, 50};
    
    displayList(list1, "list1 before splice");
    displayList(list2, "list2 before splice");
    
    auto it2 = list1.begin();
    advance(it2, 2);
    list1.splice(it2, list2);  // Move all elements from list2 to list1 at position 2
    
    displayList(list1, "list1 after splice (moved list2 into position 2)");
    displayList(list2, "list2 after splice (now empty)");
    
    // merge() - Merge two sorted lists
    list<int> sorted1 = {1, 3, 5, 7, 9};
    list<int> sorted2 = {2, 4, 6, 8, 10};
    
    cout << "\nmerge() - Merging two sorted lists:\n";
    displayList(sorted1, "sorted1");
    displayList(sorted2, "sorted2");
    
    sorted1.merge(sorted2);  // Both lists must be sorted
    displayList(sorted1, "After merge (sorted1 + sorted2)");
    displayList(sorted2, "sorted2 after merge (empty)");
    
    // unique() - Remove consecutive duplicates
    list<int> duplicates = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5};
    displayList(duplicates, "List with consecutive duplicates");
    duplicates.unique();  // Removes consecutive duplicates only
    displayList(duplicates, "After unique()");
    
    // 11. Size operations
    cout << "\n11. Size operations:\n";
    cout << "Current list size: " << numbers.size() << "\n";
    numbers.resize(5);  // Resize to 5 elements
    displayList(numbers, "After resize(5) - truncates/expands");
    numbers.resize(8, 99);  // Resize to 8, new elements initialized to 99
    displayList(numbers, "After resize(8, 99)");
    
    // 12. Access operations
    cout << "\n12. Access operations:\n";
    if (!numbers.empty()) {
        cout << "Front element: " << numbers.front() << "\n";
        cout << "Back element: " << numbers.back() << "\n";
    }
    
    // 13. Clearing the list
    cout << "\n13. clear() - Removing all elements:\n";
    numbers.clear();
    displayList(numbers, "After clear()");
    displayListDetails(numbers);
    
    // 14. emplace and emplace_back/front (C++11)
    cout << "\n14. emplace operations - Construct in-place:\n";
    list<pair<int, string>> employeeList;
    
    // emplace_back constructs the object directly in the list
    employeeList.emplace_back(101, "Alice");
    employeeList.emplace_front(102, "Bob");
    
    auto it3 = employeeList.begin();
    advance(it3, 1);
    employeeList.emplace(it3, 103, "Charlie");
    
    cout << "Employee list after emplace operations:\n";
    for (const auto& emp : employeeList) {
        cout << "ID: " << emp.first << ", Name: " << emp.second << "\n";
    }
    
    // 15. swap() - Swap two lists
    cout << "\n15. swap() - Exchanging contents of two lists:\n";
    list<int> listA = {100, 200, 300};
    list<int> listB = {400, 500, 600, 700};
    
    displayList(listA, "List A before swap");
    displayList(listB, "List B before swap");
    
    listA.swap(listB);
    
    displayList(listA, "List A after swap");
    displayList(listB, "List B after swap");
    
    // 16. assign() - Assign new contents
    cout << "\n16. assign() - Assigning new contents:\n";
    list<int> listC;
    listC.assign(5, 99);  // 5 elements with value 99
    displayList(listC, "After assign(5, 99)");
    
    listC.assign({1, 2, 3, 4, 5});  // Assign from initializer list
    displayList(listC, "After assign({1,2,3,4,5})");
    
    // 17. remove_if() - Remove elements based on condition (no algorithm header needed)
    cout << "\n17. remove_if() - Removing elements based on condition:\n";
    list<int> listD = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    displayList(listD, "Before remove_if");
    
    // Remove all even numbers using lambda
    listD.remove_if([](int n) { return n % 2 == 0; });
    displayList(listD, "After removing even numbers");
    
    // Remove all numbers greater than 5
    listD.remove_if([](int n) { return n > 5; });
    displayList(listD, "After removing numbers > 5");
    
    // 18. Comparing vector vs list performance characteristics
    cout << "\n18. List vs Vector - Key Differences:\n";
    cout << "- List: Fast insertions/deletions anywhere (O(1) with iterator)\n";
    cout << "- List: No random access (can't do list[5])\n";
    cout << "- List: Higher memory overhead (prev/next pointers)\n";
    cout << "- Vector: Fast random access (O(1))\n";
    cout << "- Vector: Fast insertions/deletions only at end\n";
    cout << "- Vector: Contiguous memory, cache-friendly\n";
    
    cout << "\n=== End of List Operations Demo ===\n";
    
    return 0;
}