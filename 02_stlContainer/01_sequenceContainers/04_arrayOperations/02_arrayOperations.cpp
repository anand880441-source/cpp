/**
 * Array Operations Demo - C++ STL Array (C++11)
 * 
 * This program demonstrates common array operations with detailed explanations.
 * STL array is a fixed-size container that combines C++11 features with C-style array performance.
 * Unlike C-style arrays, STL arrays know their own size and work with STL algorithms.
 * 
 * Author: Anand Suthar
 * Date: 12-02-2026
 */

#include <iostream>
#include <array>
#include <string>
using namespace std;

// Helper function to display array elements
template<typename T, size_t N>
void displayArray(const array<T, N>& arr, const string& message) {
    cout << message << ": [";
    if (arr.empty()) {
        cout << "Array is empty";
    } else {
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
    }
    cout << "]\n";
}

// Helper function to display array details
template<typename T, size_t N>
void displayArrayDetails(const array<T, N>& arr) {
    cout << "\n--- Array Details ---\n";
    cout << "Size: " << arr.size() << "\n";
    cout << "Max size: " << arr.max_size() << "\n";  // Same as size() for array
    cout << "Is empty? " << (arr.empty() ? "Yes" : "No") << "\n";
    if (!arr.empty()) {
        cout << "First element (front): " << arr.front() << "\n";
        cout << "Last element (back): " << arr.back() << "\n";
    }
    cout << "----------------------\n\n";
}

int main() {
    cout << "=== C++ STL Array Operations Demo ===\n";
    cout << "STL array is a fixed-size container (size known at compile time)\n";
    cout << "Combines the performance of C-style arrays with STL container benefits\n\n";

    // 1. Different ways to initialize arrays
    cout << "1. Array Initialization Methods:\n";
    
    // Method 1: Default initialization (garbage values)
    array<int, 5> arr1;
    displayArray(arr1, "arr1 (default initialization - garbage values)");
    
    // Method 2: Value initialization (zero-initialized)
    array<int, 5> arr2{};
    displayArray(arr2, "arr2 (value initialization - all zeros)");
    
    // Method 3: Initializer list
    array<int, 5> arr3 = {1, 2, 3, 4, 5};
    displayArray(arr3, "arr3 (initializer list: {1,2,3,4,5})");
    
    // Method 4: Partial initialization (remaining zero-initialized)
    array<int, 5> arr4 = {10, 20};
    displayArray(arr4, "arr4 (partial: {10,20} - rest zero)");
    
    // Method 5: Uniform initialization (C++11)
    array<int, 5> arr5{100, 200, 300, 400, 500};
    displayArray(arr5, "arr5 (uniform initialization)");
    
    // Method 6: Copy constructor
    array<int, 5> arr6(arr3);
    displayArray(arr6, "arr6 (copy constructor from arr3)");
    cout << "\n";

    // 2. size() - Returns number of elements (compile-time constant)
    cout << "2. size() - Getting array size:\n";
    array<double, 8> prices;
    cout << "Size of prices array: " << prices.size() << "\n";
    cout << "Size of arr3: " << arr3.size() << "\n";
    
    // size() is constexpr - can be used at compile time
    constexpr size_t arraySize = arr3.size();
    cout << "Compile-time size: " << arraySize << "\n\n";

    // 3. at(index) - Element access with bounds checking
    cout << "3. at(index) - Element access with bounds checking:\n";
    array<string, 4> names = {"Alice", "Bob", "Charlie", "Diana"};
    displayArray(names, "Names array");
    
    try {
        cout << "Element at index 0: " << names.at(0) << "\n";
        cout << "Element at index 2: " << names.at(2) << "\n";
        cout << "Element at index 3: " << names.at(3) << "\n";
        
        // This will throw an exception
        // cout << "Element at index 10: " << names.at(10) << "\n";
    } catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << "\n";
    }
    cout << "\n";

    // 4. front() - Returns first element
    cout << "4. front() - Accessing first element:\n";
    cout << "First name: " << names.front() << "\n";
    
    // front() can be used to modify
    names.front() = "Alicia";
    cout << "After modification: " << names.front() << "\n\n";

    // 5. back() - Returns last element
    cout << "5. back() - Accessing last element:\n";
    cout << "Last name: " << names.back() << "\n";
    
    // back() can be used to modify
    names.back() = "Diana Ross";
    cout << "After modification: " << names.back() << "\n\n";

    // 6. fill(value) - Fill entire array with value
    cout << "6. fill() - Filling array with a value:\n";
    array<int, 8> scores;
    
    scores.fill(100);
    displayArray(scores, "scores after fill(100)");
    
    scores.fill(0);
    displayArray(scores, "scores after fill(0)");
    
    // Fill with different values
    array<char, 5> letters;
    letters.fill('A');
    displayArray(letters, "letters after fill('A')");
    cout << "\n";

    // 7. empty() - Check if array is empty
    cout << "7. empty() - Checking if array is empty:\n";
    array<int, 0> emptyArray;  // Zero-sized array (C++11)
    array<int, 5> nonEmptyArray = {1, 2, 3};
    
    cout << "Zero-sized array is empty? " << (emptyArray.empty() ? "Yes" : "No") << "\n";
    cout << "Non-empty array is empty? " << (nonEmptyArray.empty() ? "Yes" : "No") << "\n\n";

    // 8. [] operator - Unchecked access
    cout << "8. [] operator - Unchecked random access:\n";
    array<int, 5> data = {10, 20, 30, 40, 50};
    displayArray(data, "Data array");
    
    cout << "data[0] = " << data[0] << "\n";
    cout << "data[2] = " << data[2] << "\n";
    cout << "data[4] = " << data[4] << "\n";
    
    // Modifying using [] operator
    data[1] = 25;
    data[3] = 45;
    displayArray(data, "After modification using []");
    cout << "\n";

    // 9. Iterators - begin(), end(), rbegin(), rend()
    cout << "9. Iterator Operations:\n";
    array<int, 6> iterDemo = {1, 2, 3, 4, 5, 6};
    
    cout << "Forward iteration: ";
    for (auto it = iterDemo.begin(); it != iterDemo.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Reverse iteration: ";
    for (auto it = iterDemo.rbegin(); it != iterDemo.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Range-based for loop: ";
    for (const auto& val : iterDemo) {
        cout << val << " ";
    }
    cout << "\n\n";

    // 10. data() - Get pointer to underlying C array
    cout << "10. data() - Accessing underlying C array:\n";
    array<int, 5> cArrayDemo = {11, 22, 33, 44, 55};
    
    int* rawPtr = cArrayDemo.data();
    cout << "Raw pointer value: " << *rawPtr << "\n";
    cout << "Using pointer arithmetic: " << *(rawPtr + 2) << "\n";
    
    // Modify via raw pointer
    rawPtr[3] = 99;
    displayArray(cArrayDemo, "After modification via raw pointer");
    cout << "\n";

    // 11. swap() - Exchange contents
    cout << "11. swap() - Exchanging array contents:\n";
    array<int, 5> array1 = {1, 2, 3, 4, 5};
    array<int, 5> array2 = {10, 20, 30, 40, 50};
    
    displayArray(array1, "Array1 before swap");
    displayArray(array2, "Array2 before swap");
    
    array1.swap(array2);
    
    displayArray(array1, "Array1 after swap");
    displayArray(array2, "Array2 after swap");
    cout << "\n";

    // 12. get<N>() - Tuple interface (C++11)
    cout << "12. get<N>() - Tuple-style access:\n";
    array<string, 3> colors = {"Red", "Green", "Blue"};
    
    cout << "get<0>: " << get<0>(colors) << "\n";
    cout << "get<1>: " << get<1>(colors) << "\n";
    cout << "get<2>: " << get<2>(colors) << "\n";
    
    // Compile-time bounds checking
    // get<5>(colors);  // Compile error!
    cout << "\n";

    // 13. Comparison operators
    cout << "13. Comparison Operators:\n";
    array<int, 4> comp1 = {1, 2, 3, 4};
    array<int, 4> comp2 = {1, 2, 3, 4};
    array<int, 4> comp3 = {1, 2, 3, 5};
    
    cout << "comp1 == comp2: " << (comp1 == comp2 ? "true" : "false") << "\n";
    cout << "comp1 != comp3: " << (comp1 != comp3 ? "true" : "false") << "\n";
    cout << "comp1 < comp3: " << (comp1 < comp3 ? "true" : "false") << "\n";
    cout << "comp1 <= comp2: " << (comp1 <= comp2 ? "true" : "false") << "\n\n";

    // 14. Practical Example 1: Fixed-size buffer
    cout << "14. Practical Example - Circular Buffer:\n";
    array<int, 5> buffer;
    buffer.fill(0);
    int writeIndex = 0;
    
    // Simulate writing to buffer
    for (int i = 1; i <= 8; i++) {
        buffer[writeIndex] = i;
        writeIndex = (writeIndex + 1) % buffer.size();
        cout << "After writing " << i << ": ";
        displayArray(buffer, "");
    }
    cout << "\n";

    // 15. Practical Example 2: Month days lookup
    cout << "15. Practical Example - Month Days Lookup:\n";
    array<int, 12> monthDays = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    
    array<string, 12> monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    cout << "Month days lookup:\n";
    for (size_t i = 0; i < monthDays.size(); ++i) {
        cout << monthNames[i] << ": " << monthDays[i] << " days\n";
    }
    cout << "\n";

    // 16. Practical Example 3: Grade statistics
    cout << "16. Practical Example - Grade Statistics:\n";
    array<double, 5> grades = {85.5, 92.0, 78.5, 88.0, 95.5};
    
    double sum = 0;
    double maxGrade = grades[0];
    double minGrade = grades[0];
    
    for (double grade : grades) {
        sum += grade;
        if (grade > maxGrade) maxGrade = grade;
        if (grade < minGrade) minGrade = grade;
    }
    
    cout << "Grades: ";
    displayArray(grades, "");
    cout << "Average: " << sum / grades.size() << "\n";
    cout << "Highest: " << maxGrade << "\n";
    cout << "Lowest: " << minGrade << "\n\n";

    // 17. Array vs C-style array comparison
    cout << "17. STL Array vs C-Style Array:\n";
    cout << "\n--- Advantages of STL array ---\n";
    cout << "✓ Knows its own size (size() method)\n";
    cout << "✓ STL algorithm compatible\n";
    cout << "✓ Bounds checking with at()\n";
    cout << "✓ Copyable via assignment\n";
    cout << "✓ No pointer decay\n";
    cout << "✓ Comparison operators\n";
    cout << "✓ Member functions (fill, swap, etc.)\n";
    
    cout << "\n--- Advantages of C-style array ---\n";
    cout << "✓ Slightly faster (no overhead)\n";
    cout << "✓ C compatibility\n";
    cout << "✓ Slightly smaller binary\n";
    cout << "✓ Can be initialized with string literals\n";
    
    cout << "\n--- Memory Layout ---\n";
    cout << "Both STL array and C-style array store elements contiguously\n";
    cout << "STL array has zero runtime overhead (same size as C array)\n";
    cout << "sizeof(STL array) == sizeof(C array) * N\n\n";

    // 18. Compile-time features
    cout << "18. Compile-time Features:\n";
    
    // constexpr array
    constexpr array<int, 3> constArr = {10, 20, 30};
    
    // Can be used in template parameters
    constexpr size_t arrSize = constArr.size();
    cout << "Compile-time size: " << arrSize << "\n";
    
    // get<N> works at compile time
    constexpr int firstElement = get<0>(constArr);
    cout << "Compile-time first element: " << firstElement << "\n\n";

    // 19. Multidimensional array
    cout << "19. Multidimensional Array:\n";
    array<array<int, 3>, 3> matrix = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};
    
    cout << "2D Array (3x3):\n";
    for (const auto& row : matrix) {
        cout << "  ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    // 20. Important Notes
    cout << "20. Important Notes and Limitations:\n";
    cout << "• Size must be known at compile time\n";
    cout << "• Cannot be resized (fixed-size)\n";
    cout << "• Zero-sized arrays are allowed but have no elements\n";
    cout << "• No push_back() or pop_back()\n";
    cout << "• No insert() or erase()\n";
    cout << "• Perfect for fixed-size data: RGB colors, coordinates, lookup tables\n";
    
    cout << "\n=== End of Array Operations Demo ===\n";
    
    return 0;
}