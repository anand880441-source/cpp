/**
 * Vector Operations Demo - C++ STL Vector
 * 
 * This program demonstrates common vector operations with detailed explanations.
 * Vector is a dynamic array that provides fast random access and efficient
 * insertion/deletion at the end.
 * 
 * Author: Anand Suthar
 * Date: 12-02-2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to display vector elements
void displayVector(const vector<int>& v, const string& message) {
    cout << message << ": ";
    if (v.empty()) {
        cout << "Vector is empty";
    } else {
        for (int val : v) {
            cout << val << " ";
        }
    }
    cout << "\n";
}

// Helper function to display vector details
void displayVectorDetails(const vector<int>& v) {
    cout << "\n--- Vector Details ---\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << "\n";
    if (!v.empty()) {
        cout << "First element (front): " << v.front() << "\n";
        cout << "Last element (back): " << v.back() << "\n";
    }
    cout << "----------------------\n\n";
}

int main() {
    cout << "=== C++ STL Vector Operations Demo ===\n\n";
    
    // Create an empty vector
    vector<int> numbers;
    displayVectorDetails(numbers);
    
    // 1. push_back(val) - Adds element at the end
    cout << "1. push_back() - Adding elements at the end:\n";
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    displayVector(numbers, "After push_back(10, 20, 30)");
    displayVectorDetails(numbers);
    
    // 2. pop_back() - Removes the last element
    cout << "2. pop_back() - Removing last element:\n";
    numbers.pop_back();
    displayVector(numbers, "After pop_back() (removed 30)");
    displayVectorDetails(numbers);
    
    // 3. insert(pos, val) - Inserts element at specific position
    cout << "3. insert() - Inserting elements at specific positions:\n";
    
    // Insert at beginning
    numbers.insert(numbers.begin(), 5);
    displayVector(numbers, "After insert at beginning (5)");
    
    // Insert at position (after first element)
    numbers.insert(numbers.begin() + 1, 7);
    displayVector(numbers, "After insert at position 1 (7)");
    
    // Insert multiple elements
    numbers.insert(numbers.end(), {40, 50});
    displayVector(numbers, "After inserting multiple elements at end (40, 50)");
    
    // Insert with count
    numbers.insert(numbers.begin() + 2, 3, 99); // Insert 99 three times
    displayVector(numbers, "After inserting 99 three times at position 2");
    displayVectorDetails(numbers);
    
    // 4. erase(pos) - Removes element at specific position
    cout << "4. erase() - Removing elements:\n";
    
    // Erase single element
    numbers.erase(numbers.begin() + 1); // Remove element at index 1
    displayVector(numbers, "After erasing element at index 1");
    
    // Erase range of elements
    numbers.erase(numbers.begin() + 2, numbers.begin() + 5); // Remove range
    displayVector(numbers, "After erasing range (index 2-4)");
    
    // Erase first element
    numbers.erase(numbers.begin());
    displayVector(numbers, "After erasing first element");
    displayVectorDetails(numbers);
    
    // 5. at(index) - Access element with bounds checking
    cout << "5. at() - Element access with bounds checking:\n";
    try {
        cout << "Element at index 0: " << numbers.at(0) << "\n";
        cout << "Element at index 1: " << numbers.at(1) << "\n";
        // This would throw an exception if index is out of bounds
        // cout << numbers.at(10) << "\n"; // Uncomment to see exception
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << "\n";
    }
    
    // Using front() and back()
    cout << "\nFront element: " << numbers.front() << "\n";
    cout << "Back element: " << numbers.back() << "\n\n";
    
    // 6. Accessing elements - various methods
    cout << "6. Different ways to access elements:\n";
    cout << "Using [] operator: numbers[0] = " << numbers[0] << "\n";
    cout << "Using .at(): numbers.at(0) = " << numbers.at(0) << "\n";
    cout << "Using front(): " << numbers.front() << "\n";
    cout << "Using back(): " << numbers.back() << "\n";
    
    // 7. Modifying elements
    cout << "\n7. Modifying elements:\n";
    numbers[0] = 100;  // Modify using [] operator
    numbers.at(1) = 200; // Modify using at()
    displayVector(numbers, "After modifying elements");
    
    // 8. Adding more elements to demonstrate size growth
    cout << "\n8. Vector dynamic growth:\n";
    cout << "Current capacity: " << numbers.capacity() << "\n";
    numbers.push_back(300);
    numbers.push_back(400);
    numbers.push_back(500);
    displayVector(numbers, "After adding more elements");
    cout << "New capacity: " << numbers.capacity() << "\n";
    cout << "Size: " << numbers.size() << "\n";
    
    // 9. clear() - Removes all elements
    cout << "\n9. clear() - Removing all elements:\n";
    numbers.clear();
    displayVector(numbers, "After clear()");
    displayVectorDetails(numbers);
    
    // 10. Checking empty() and other operations
    cout << "\n10. Working with empty vector:\n";
    if (numbers.empty()) {
        cout << "Vector is empty, adding some elements...\n";
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
    }
    displayVector(numbers, "Current vector");
    displayVectorDetails(numbers);
    
    // 11. Advanced operations - using algorithms with vectors
    cout << "\n11. Using STL algorithms with vectors:\n";
    
    // Sort in descending order
    sort(numbers.begin(), numbers.end(), greater<int>());
    displayVector(numbers, "After sorting in descending order");
    
    // Find element
    auto it = find(numbers.begin(), numbers.end(), 2);
    if (it != numbers.end()) {
        cout << "Found element 2 at index: " << (it - numbers.begin()) << "\n";
    }
    
    // Reverse vector
    reverse(numbers.begin(), numbers.end());
    displayVector(numbers, "After reversing");
    
    // 12. Demonstrating different vector initializations
    cout << "\n12. Different ways to initialize vectors:\n";
    
    // Method 1: Empty vector
    vector<int> v1;
    cout << "v1: Empty vector\n";
    
    // Method 2: With size and default value
    vector<int> v2(5, 10); // 5 elements, all 10
    displayVector(v2, "v2(5, 10)");
    
    // Method 3: With initializer list
    vector<int> v3 = {1, 2, 3, 4, 5};
    displayVector(v3, "v3 = {1,2,3,4,5}");
    
    // Method 4: Copy constructor
    vector<int> v4(v3);
    displayVector(v4, "v4(v3) - copy");
    
    // Method 5: From array
    int arr[] = {100, 200, 300};
    vector<int> v5(arr, arr + sizeof(arr)/sizeof(arr[0]));
    displayVector(v5, "v5 from array");
    
    cout << "\n=== End of Vector Operations Demo ===\n";
    
    return 0;
}