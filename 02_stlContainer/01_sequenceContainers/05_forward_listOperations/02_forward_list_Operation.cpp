/**
 * Forward_list Operations Demo - C++ STL Forward List (C++11)
 * 
 * This program demonstrates common forward_list operations with detailed explanations.
 * Forward_list is a singly linked list that supports fast insertions/deletions
 * but ONLY forward traversal. It's more memory-efficient than list (doubly linked).
 * 
 * Author: Anand Suthar
 * Date: 12-02-2026
 */

#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

// Helper function to display forward_list elements
template<typename T>
void displayForwardList(const forward_list<T>& flst, const string& message) {
    cout << message << ": ";
    if (flst.empty()) {
        cout << "Forward list is empty";
    } else {
        for (const T& val : flst) {
            cout << val << " ";
        }
    }
    cout << "\n";
}

// Helper function to display forward_list details
template<typename T>
void displayForwardListDetails(const forward_list<T>& flst) {
    cout << "\n--- Forward List Details ---\n";
    cout << "Is empty? " << (flst.empty() ? "Yes" : "No") << "\n";
    if (!flst.empty()) {
        cout << "First element (front): " << flst.front() << "\n";
        
        // Calculate size manually - forward_list has no size() member!
        int count = 0;
        for (auto it = flst.begin(); it != flst.end(); ++it) {
            ++count;
        }
        cout << "Size (calculated): " << count << "\n";
    }
    cout << "----------------------------\n\n";
}

// Helper function to calculate size of forward_list
template<typename T>
int getSize(const forward_list<T>& flst) {
    int count = 0;
    for (auto it = flst.begin(); it != flst.end(); ++it) {
        ++count;
    }
    return count;
}

int main() {
    cout << "=== C++ STL Forward List Operations Demo ===\n";
    cout << "Forward list is a SINGLY linked list - forward traversal only\n";
    cout << "More memory efficient than list (no prev pointers), but limited functionality\n\n";
    
    // Create an empty forward_list
    forward_list<int> numbers;
    displayForwardListDetails(numbers);
    
    // 1. push_front(val) - Adds element at the front (ONLY way to add!)
    cout << "1. push_front() - Adding elements at the front:\n";
    numbers.push_front(30);
    numbers.push_front(20);
    numbers.push_front(10);
    displayForwardList(numbers, "After push_front(30, 20, 10)");
    displayForwardListDetails(numbers);
    
    // Note: There's NO push_back() in forward_list!
    cout << "Note: forward_list has NO push_back() - only push_front()\n\n";
    
    // 2. pop_front() - Removes the first element
    cout << "2. pop_front() - Removing first element:\n";
    numbers.pop_front();
    displayForwardList(numbers, "After pop_front() (removed 10)");
    displayForwardListDetails(numbers);
    
    // 3. insert_after(pos, val) - Inserts element AFTER given position
    cout << "3. insert_after() - Inserting after specific positions:\n";
    
    // Insert after beginning
    auto it = numbers.begin();
    numbers.insert_after(it, 15);
    displayForwardList(numbers, "After insert_after(begin, 15)");
    
    // Insert after first element
    it = numbers.begin();
    advance(it, 1);  // Move to position 1
    numbers.insert_after(it, 25);
    displayForwardList(numbers, "After insert_after(position 1, 25)");
    
    // Insert multiple elements after position
    it = numbers.begin();
    numbers.insert_after(it, 3, 5);  // Insert 3 copies of 5 after first position
    displayForwardList(numbers, "After insert_after(begin, 3, 5)");
    
    // Insert using initializer list
    it = numbers.begin();
    advance(it, 2);
    numbers.insert_after(it, {100, 200, 300});
    displayForwardList(numbers, "After insert_after(position 2, {100,200,300})");
    displayForwardListDetails(numbers);
    
    // 4. erase_after(pos) - Removes element AFTER given position
    cout << "4. erase_after() - Removing after specific positions:\n";
    
    // Erase after beginning
    it = numbers.begin();
    numbers.erase_after(it);
    displayForwardList(numbers, "After erase_after(begin)");
    
    // Erase after specific position
    it = numbers.begin();
    advance(it, 2);
    numbers.erase_after(it);
    displayForwardList(numbers, "After erase_after(position 2)");
    
    // Erase range of elements
    it = numbers.begin();
    auto end_it = numbers.begin();
    advance(it, 1);
    advance(end_it, 4);
    numbers.erase_after(it, end_it);
    displayForwardList(numbers, "After erase_after(range from position 1 to 4)");
    displayForwardListDetails(numbers);
    
    // 5. remove(val) - Removes ALL elements matching value
    cout << "5. remove() - Removing all elements with specific value:\n";
    forward_list<int> removeDemo = {10, 20, 30, 20, 40, 20, 50, 20};
    displayForwardList(removeDemo, "Before remove(20)");
    
    removeDemo.remove(20);  // Removes ALL occurrences of 20
    displayForwardList(removeDemo, "After remove(20)");
    displayForwardListDetails(removeDemo);
    
    // 6. front() - Access first element
    cout << "6. front() - Accessing first element:\n";
    cout << "Front element: " << numbers.front() << "\n";
    
    // Modify front element
    numbers.front() = 99;
    displayForwardList(numbers, "After modifying front to 99");
    cout << "\n";
    
    // 7. empty() - Check if forward_list is empty
    cout << "7. empty() - Checking if forward_list is empty:\n";
    cout << "Is forward_list empty? " << (numbers.empty() ? "Yes" : "No") << "\n\n";
    
    // 8. clear() - Remove all elements
    cout << "8. clear() - Removing all elements:\n";
    numbers.clear();
    displayForwardList(numbers, "After clear()");
    displayForwardListDetails(numbers);
    
    // 9. before_begin() - Special iterator before first element
    cout << "9. before_begin() - Iterator before first element:\n";
    forward_list<int> flist = {10, 20, 30, 40, 50};
    displayForwardList(flist, "Initial list");
    
    // Insert at beginning using before_begin()
    auto before_first = flist.before_begin();
    flist.insert_after(before_first, 5);
    displayForwardList(flist, "After insert_after(before_begin(), 5)");
    
    // Insert at beginning with multiple values
    flist.insert_after(flist.before_begin(), {1, 2, 3});
    displayForwardList(flist, "After insert_after(before_begin(), {1,2,3})");
    displayForwardListDetails(flist);
    
    // 10. remove_if() - Remove elements based on condition
    cout << "10. remove_if() - Removing elements based on condition:\n";
    forward_list<int> conditionList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    displayForwardList(conditionList, "Before remove_if");
    
    // Remove all even numbers
    conditionList.remove_if([](int n) { return n % 2 == 0; });
    displayForwardList(conditionList, "After removing even numbers");
    
    // Remove all numbers greater than 5
    conditionList.remove_if([](int n) { return n > 5; });
    displayForwardList(conditionList, "After removing numbers > 5");
    displayForwardListDetails(conditionList);
    
    // 11. reverse() - Reverse the forward_list
    cout << "11. reverse() - Reversing the list:\n";
    forward_list<int> revList = {1, 2, 3, 4, 5};
    displayForwardList(revList, "Before reverse");
    
    revList.reverse();
    displayForwardList(revList, "After reverse");
    displayForwardListDetails(revList);
    
    // 12. sort() - Sort the forward_list
    cout << "12. sort() - Sorting the list:\n";
    forward_list<int> unsortedList = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    displayForwardList(unsortedList, "Before sort");
    
    unsortedList.sort();  // Ascending order
    displayForwardList(unsortedList, "After sort() (ascending)");
    
    // Sort in descending order using lambda
    unsortedList.sort([](int a, int b) { return a > b; });
    displayForwardList(unsortedList, "After sort(descending)");
    displayForwardListDetails(unsortedList);
    
    // 13. unique() - Remove consecutive duplicates
    cout << "13. unique() - Removing consecutive duplicates:\n";
    forward_list<int> dupList = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6};
    displayForwardList(dupList, "Before unique");
    
    dupList.unique();  // Removes consecutive duplicates only
    displayForwardList(dupList, "After unique()");
    
    // unique with predicate
    forward_list<int> similarList = {10, 11, 20, 21, 30, 31, 40, 41};
    displayForwardList(similarList, "Before unique with predicate");
    
    // Remove elements where difference is 1
    similarList.unique([](int a, int b) { return b - a == 1; });
    displayForwardList(similarList, "After unique(close numbers)");
    cout << "\n";
    
    // 14. splice_after() - Transfer elements from another forward_list
    cout << "14. splice_after() - Transferring elements:\n";
    forward_list<int> list1 = {1, 2, 3, 4, 5};
    forward_list<int> list2 = {10, 20, 30, 40, 50};
    
    displayForwardList(list1, "List1 before splice");
    displayForwardList(list2, "List2 before splice");
    
    // Move all elements from list2 after first element of list1
    auto pos = list1.begin();
    list1.splice_after(pos, list2);
    
    displayForwardList(list1, "List1 after splice (moved list2 after position 0)");
    displayForwardList(list2, "List2 after splice (now empty)");
    
    // Splice single element
    forward_list<int> list3 = {100, 200, 300, 400, 500};
    forward_list<int> list4 = {1000, 2000, 3000};
    
    displayForwardList(list3, "List3 before splice");
    displayForwardList(list4, "List4 before splice");
    
    auto from_pos = list4.begin();
    auto to_pos = list3.begin();
    advance(to_pos, 2);
    list3.splice_after(to_pos, list4, from_pos);
    
    displayForwardList(list3, "List3 after splicing single element");
    displayForwardList(list4, "List4 after splice");
    cout << "\n";
    
    // 15. merge() - Merge two sorted forward_lists
    cout << "15. merge() - Merging sorted lists:\n";
    forward_list<int> sorted1 = {1, 3, 5, 7, 9};
    forward_list<int> sorted2 = {2, 4, 6, 8, 10};
    
    displayForwardList(sorted1, "Sorted1");
    displayForwardList(sorted2, "Sorted2");
    
    sorted1.merge(sorted2);  // Both lists must be sorted
    
    displayForwardList(sorted1, "After merge");
    displayForwardList(sorted2, "Sorted2 after merge (empty)");
    displayForwardListDetails(sorted1);
    
    // 16. assign() - Assign new contents
    cout << "16. assign() - Assigning new contents:\n";
    forward_list<int> assignList;
    
    assignList.assign(5, 99);  // 5 elements with value 99
    displayForwardList(assignList, "After assign(5, 99)");
    
    assignList.assign({10, 20, 30, 40, 50});  // From initializer list
    displayForwardList(assignList, "After assign({10,20,30,40,50})");
    
    // Assign from another list
    forward_list<int> sourceList = {100, 200, 300};
    assignList.assign(sourceList.begin(), sourceList.end());
    displayForwardList(assignList, "After assign from iterators");
    displayForwardListDetails(assignList);
    
    // 17. resize() - Change size
    cout << "17. resize() - Changing size:\n";
    forward_list<int> resizeList = {1, 2, 3, 4, 5};
    displayForwardList(resizeList, "Before resize");
    
    resizeList.resize(3);  // Truncate to 3 elements
    displayForwardList(resizeList, "After resize(3)");
    
    resizeList.resize(6, 99);  // Expand to 6, new elements = 99
    displayForwardList(resizeList, "After resize(6, 99)");
    displayForwardListDetails(resizeList);
    
    // 18. emplace_front() and emplace_after() (C++11)
    cout << "18. emplace operations - Construct in-place:\n";
    forward_list<pair<int, string>> empList;
    
    // emplace_front constructs at beginning
    empList.emplace_front(101, "Alice");
    empList.emplace_front(102, "Bob");
    
    // emplace_after constructs after position
    auto emp_pos = empList.begin();
    empList.emplace_after(emp_pos, 103, "Charlie");
    
    cout << "Employee list after emplace operations:\n";
    for (const auto& emp : empList) {
        cout << "ID: " << emp.first << ", Name: " << emp.second << "\n";
    }
    cout << "\n";
    
    // 19. Practical Example 1: Stack using forward_list
    cout << "19. Practical Example - Stack implementation:\n";
    forward_list<string> stack;
    
    // Push elements
    stack.push_front("First");
    stack.push_front("Second");
    stack.push_front("Third");
    displayForwardList(stack, "Stack after pushes");
    
    // Pop elements
    while (!stack.empty()) {
        cout << "Popped: " << stack.front() << "\n";
        stack.pop_front();
    }
    displayForwardList(stack, "Stack after all pops");
    
    // 20. Practical Example 2: Hash table chaining
    cout << "\n20. Practical Example - Hash table bucket:\n";
    const int BUCKET_SIZE = 10;
    forward_list<int> hashBucket[BUCKET_SIZE];
    
    // Insert elements
    int values[] = {15, 25, 35, 45, 55, 65, 75, 85, 95};
    for (int val : values) {
        int bucket = val % BUCKET_SIZE;
        hashBucket[bucket].push_front(val);
    }
    
    // Display buckets
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        if (!hashBucket[i].empty()) {
            cout << "Bucket " << i << ": ";
            for (int val : hashBucket[i]) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
    cout << "\n";
    
    // 21. Important Notes and Limitations
    cout << "21. Forward List - Key Characteristics:\n";
    cout << "\n--- Advantages ---\n";
    cout << "✓ Memory efficient (no prev pointer, ~40% less memory than list)\n";
    cout << "✓ Fast insertions/deletions at front O(1)\n";
    cout << "✓ No iterator invalidation on insert/erase\n";
    cout << "✓ Ideal for hash table buckets\n";
    cout << "✓ Perfect for adjacency lists in graphs\n";
    
    cout << "\n--- Disadvantages ---\n";
    cout << "✗ No size() member - must calculate manually O(n)\n";
    cout << "✗ No push_back() or pop_back()\n";
    cout << "✗ No reverse iteration (no rbegin/rend)\n";
    cout << "✗ Cannot access previous element\n";
    cout << "✗ insert/erase only AFTER position (not at position)\n";
    cout << "✗ No back() member function\n";
    
    cout << "\n--- When to use Forward List ---\n";
    cout << "• When memory is at premium\n";
    cout << "• When you only need forward traversal\n";
    cout << "• When insertions/deletions are at front\n";
    cout << "• Hash table collision chains\n";
    cout << "• Graph adjacency lists\n";
    cout << "• Implementing simple stacks\n";
    
    cout << "\n--- Performance Comparison ---\n";
    cout << "Operation         | forward_list | list    | vector \n";
    cout << "------------------|--------------|---------|--------\n";
    cout << "push_front        | O(1)         | O(1)    | O(n)   \n";
    cout << "push_back         | NO           | O(1)    | O(1)*  \n";
    cout << "insert/erase at pos| O(1)**      | O(1)**  | O(n)   \n";
    cout << "random access     | NO           | NO      | O(1)   \n";
    cout << "memory per element| 1 pointer    | 2 ptrs  | 0 ptrs \n";
    cout << "*  Amortized O(1)\n";
    cout << "** With iterator, O(n) to find position\n\n";
    
    // 22. Size calculation demonstration
    cout << "22. Size calculation - Manual vs Algorithm:\n";
    forward_list<int> sizeDemo = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    displayForwardList(sizeDemo, "List with multiple elements");
    cout << "Size (manual count): " << getSize(sizeDemo) << "\n";
    cout << "Distance algorithm alternative:\n";
    cout << "Size (using distance): " << distance(sizeDemo.begin(), sizeDemo.end()) << "\n\n";
    
    cout << "=== End of Forward List Operations Demo ===\n";
    
    return 0;
}