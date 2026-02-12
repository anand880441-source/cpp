/**
 * Deque Operations Demo - C++ STL Deque (Double-Ended Queue)
 * 
 * This program demonstrates common deque operations with detailed explanations.
 * Deque is a double-ended queue that supports fast insertions and deletions at both ends.
 * Unlike vector, deque provides push_front/pop_front efficiently, and unlike list,
 * deque provides random access via at() and [] operator.
 * 
 * Author: Anand Suthar
 * Date: 12-02-2026
 */

#include <iostream>
#include <deque>
#include <string>
using namespace std;

// Helper function to display deque elements
template<typename T>
void displayDeque(const deque<T>& dq, const string& message) {
    cout << message << ": ";
    if (dq.empty()) {
        cout << "Deque is empty";
    } else {
        for (const T& val : dq) {
            cout << val << " ";
        }
    }
    cout << "\n";
}

// Helper function to display deque details
template<typename T>
void displayDequeDetails(const deque<T>& dq) {
    cout << "\n--- Deque Details ---\n";
    cout << "Size: " << dq.size() << "\n";
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << "\n";
    if (!dq.empty()) {
        cout << "First element (front): " << dq.front() << "\n";
        cout << "Last element (back): " << dq.back() << "\n";
    }
    cout << "----------------------\n\n";
}

int main() {
    cout << "=== C++ STL Deque Operations Demo ===\n";
    cout << "Deque is a double-ended queue - fast insertions/deletions at BOTH ends + random access\n\n";
    
    // Create an empty deque
    deque<int> numbers;
    displayDequeDetails(numbers);
    
    // 1. push_back(val) - Adds element at the end
    cout << "1. push_back() - Adding elements at the end:\n";
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    displayDeque(numbers, "After push_back(30, 40, 50)");
    displayDequeDetails(numbers);
    
    // 2. push_front(val) - Adds element at the front
    cout << "2. push_front() - Adding elements at the front:\n";
    numbers.push_front(20);
    numbers.push_front(10);
    displayDeque(numbers, "After push_front(20, 10)");
    displayDequeDetails(numbers);
    
    // 3. pop_back() - Removes the last element
    cout << "3. pop_back() - Removing last element:\n";
    numbers.pop_back();
    displayDeque(numbers, "After pop_back() (removed 50)");
    displayDequeDetails(numbers);
    
    // 4. pop_front() - Removes the first element
    cout << "4. pop_front() - Removing first element:\n";
    numbers.pop_front();
    displayDeque(numbers, "After pop_front() (removed 10)");
    displayDequeDetails(numbers);
    
    // 5. at(index) - Returns element with bounds checking
    cout << "5. at(index) - Element access with bounds checking:\n";
    try {
        cout << "Element at index 0: " << numbers.at(0) << "\n";
        cout << "Element at index 1: " << numbers.at(1) << "\n";
        cout << "Element at index 2: " << numbers.at(2) << "\n";
        
        // This would throw an exception
        // cout << "Element at index 10: " << numbers.at(10) << "\n";
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << "\n";
    }
    cout << "\n";
    
    // 6. front() - Returns first element
    cout << "6. front() - Accessing first element:\n";
    cout << "Front element: " << numbers.front() << "\n\n";
    
    // 7. back() - Returns last element
    cout << "7. back() - Accessing last element:\n";
    cout << "Back element: " << numbers.back() << "\n\n";
    
    // 8. size() - Returns number of elements
    cout << "8. size() - Getting deque size:\n";
    cout << "Current size: " << numbers.size() << "\n\n";
    
    // 9. [] operator - Random access without bounds checking
    cout << "9. [] operator - Random access (no bounds checking):\n";
    cout << "numbers[0] = " << numbers[0] << "\n";
    cout << "numbers[1] = " << numbers[1] << "\n";
    cout << "numbers[2] = " << numbers[2] << "\n\n";
    
    // 10. insert() - Insert at specific position
    cout << "10. insert() - Inserting at specific positions:\n";
    
    // Insert at beginning
    auto it = numbers.begin();
    numbers.insert(it, 5);
    displayDeque(numbers, "After insert at beginning (5)");
    
    // Insert at end
    numbers.insert(numbers.end(), 60);
    displayDeque(numbers, "After insert at end (60)");
    
    // Insert in middle (deque supports iterator arithmetic!)
    it = numbers.begin() + 2;  // Deque supports this! Unlike list
    numbers.insert(it, 25);
    displayDeque(numbers, "After insert at position 2 (25)");
    
    // Insert multiple elements
    it = numbers.begin() + 1;
    numbers.insert(it, 3, 7);  // Insert 7 three times
    displayDeque(numbers, "After inserting 7 three times at position 1");
    displayDequeDetails(numbers);
    
    // 11. erase() - Remove at specific position
    cout << "11. erase() - Removing elements:\n";
    
    // Erase single element
    it = numbers.begin() + 2;  // Direct arithmetic!
    numbers.erase(it);
    displayDeque(numbers, "After erasing element at position 2");
    
    // Erase range
    auto start = numbers.begin() + 1;
    auto end = numbers.begin() + 4;
    numbers.erase(start, end);
    displayDeque(numbers, "After erasing range (positions 1-3)");
    displayDequeDetails(numbers);
    
    // 12. assign() - Assign new contents
    cout << "12. assign() - Assigning new contents:\n";
    deque<int> newDeque;
    newDeque.assign(5, 99);  // 5 elements with value 99
    displayDeque(newDeque, "After assign(5, 99)");
    
    newDeque.assign({10, 20, 30, 40, 50});  // From initializer list
    displayDeque(newDeque, "After assign({10,20,30,40,50})");
    displayDequeDetails(newDeque);
    
    // 13. resize() - Change size
    cout << "13. resize() - Changing deque size:\n";
    newDeque.resize(3);  // Truncate to 3 elements
    displayDeque(newDeque, "After resize(3)");
    
    newDeque.resize(6, 100);  // Expand to 6, new elements = 100
    displayDeque(newDeque, "After resize(6, 100)");
    displayDequeDetails(newDeque);
    
    // 14. clear() - Remove all elements
    cout << "14. clear() - Removing all elements:\n";
    newDeque.clear();
    displayDeque(newDeque, "After clear()");
    displayDequeDetails(newDeque);
    
    // 15. emplace() - Construct in-place (C++11)
    cout << "15. emplace operations - Construct in-place:\n";
    deque<pair<int, string>> employeeDeque;
    
    // emplace_back and emplace_front
    employeeDeque.emplace_back(101, "Alice");
    employeeDeque.emplace_front(102, "Bob");
    
    // emplace at position
    auto itPos = employeeDeque.begin() + 1;
    employeeDeque.emplace(itPos, 103, "Charlie");
    
    cout << "Employee deque after emplace operations:\n";
    for (const auto& emp : employeeDeque) {
        cout << "ID: " << emp.first << ", Name: " << emp.second << "\n";
    }
    cout << "\n";
    
    // 16. swap() - Exchange contents
    cout << "16. swap() - Exchanging contents:\n";
    deque<int> dequeA = {1, 2, 3, 4, 5};
    deque<int> dequeB = {100, 200, 300};
    
    displayDeque(dequeA, "Deque A before swap");
    displayDeque(dequeB, "Deque B before swap");
    
    dequeA.swap(dequeB);
    
    displayDeque(dequeA, "Deque A after swap");
    displayDeque(dequeB, "Deque B after swap");
    cout << "\n";
    
    // 17. Deque vs Vector vs List - Key Differences
    cout << "17. Deque vs Vector vs List - Key Differences:\n";
    cout << "\n--- DEQUE advantages ---\n";
    cout << "✓ Fast insertions/deletions at BOTH ends (O(1))\n";
    cout << "✓ Random access via [] and at() (O(1))\n";
    cout << "✓ Iterator arithmetic supported (it + n)\n";
    cout << "✓ No reallocation cost like vector\n";
    cout << "✓ Memory is allocated in blocks, not contiguous like vector\n";
    
    cout << "\n--- DEQUE disadvantages ---\n";
    cout << "✗ Slower than vector for random access (slightly)\n";
    cout << "✗ More complex internal structure (block-based)\n";
    cout << "✗ Not cache-friendly as vector (non-contiguous)\n";
    cout << "✗ Insertions in middle are O(n), same as vector\n";
    
    cout << "\n--- When to use DEQUE ---\n";
    cout << "• When you need push_front() AND push_back()\n";
    cout << "• When you need random access AND double-ended operations\n";
    cout << "• Task queues (front removal, back insertion)\n";
    cout << "• Sliding window algorithms\n";
    cout << "• Palindromes checker\n";
    
    cout << "\n--- Performance Comparison ---\n";
    cout << "Operation        | Vector | Deque  | List  \n";
    cout << "-----------------|--------|--------|-------\n";
    cout << "push_back        | O(1)*  | O(1)   | O(1)  \n";
    cout << "push_front       | O(n)   | O(1)   | O(1)  \n";
    cout << "pop_back         | O(1)   | O(1)   | O(1)  \n";
    cout << "pop_front        | O(n)   | O(1)   | O(1)  \n";
    cout << "insert middle    | O(n)   | O(n)   | O(1)**\n";
    cout << "random access    | O(1)   | O(1)   | O(n)  \n";
    cout << "*  Vector: amortized O(1), may reallocate\n";
    cout << "** List: O(1) with iterator, but O(n) to find position\n\n";
    
    // 18. Practical example: Task scheduler
    cout << "18. Practical Example - Task Scheduler:\n";
    deque<string> taskQueue;
    
    // Add tasks to back
    taskQueue.push_back("Compile code");
    taskQueue.push_back("Run tests");
    taskQueue.push_back("Generate report");
    
    // Urgent task at front
    taskQueue.push_front("Fix critical bug");
    
    displayDeque(taskQueue, "Task queue");
    
    // Process tasks from front
    cout << "\nProcessing tasks:\n";
    while (!taskQueue.empty()) {
        cout << "Processing: " << taskQueue.front() << "\n";
        taskQueue.pop_front();
    }
    displayDeque(taskQueue, "All tasks completed");
    
    // 19. Sliding window example
    cout << "\n19. Practical Example - Sliding Window:\n";
    deque<int> window = {1, 2, 3, 4, 5};
    displayDeque(window, "Initial window");
    
    // Slide window to the right
    window.pop_front();     // Remove first
    window.push_back(6);    // Add new element
    displayDeque(window, "After sliding right (add 6, remove 1)");
    
    // Slide window to the left
    window.pop_back();      // Remove last
    window.push_front(0);   // Add at front
    displayDeque(window, "After sliding left (add 0, remove 5)");
    
    cout << "\n=== End of Deque Operations Demo ===\n";
    
    return 0;
}