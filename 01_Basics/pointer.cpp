#include <iostream>
using namespace std;

int main() {
    // ============================================
    // 1. BASIC POINTER DECLARATION & INITIALIZATION
    // ============================================
    cout << "=== 1. Basic Pointer Declaration ===" << endl;
    
    int a = 45;
    int *p = &a;  // p stores address of a
    
    cout << "Value of a: " << a << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Value of pointer p: " << p << endl;
    cout << "Value at address p (*p): " << *p << endl;
    cout << "Address of pointer p (&p): " << &p << endl;
    
    // ============================================
    // 2. POINTER TYPES & VOID POINTERS
    // ============================================
    cout << "\n=== 2. Pointer Types ===" << endl;
    
    float f = 3.14;
    char c = 'A';
    
    float *floatPtr = &f;
    char *charPtr = &c;
    
    cout << "Float value: " << *floatPtr << endl;
    cout << "Char value: " << *charPtr << endl;
    
    // Void pointer (generic pointer)
    void *voidPtr = &a;
    // voidPtr = &f; // Can point to any type
    
    // Must cast void pointer before dereferencing
    cout << "Value via void pointer: " << *(static_cast<int*>(voidPtr)) << endl;
    
    // ============================================
    // 3. NULL vs NULLPTR
    // ============================================
    cout << "\n=== 3. NULL vs nullptr ===" << endl;
    
    int *ptr1 = NULL;       // Old C style (actually 0)
    int *ptr2 = nullptr;    // Modern C++11 style
    int *ptr3 = 0;          // Also works but not recommended
    
    cout << "NULL pointer: " << ptr1 << endl;
    cout << "nullptr: " << ptr2 << endl;
    
    // Always check before dereferencing
    if (ptr1 == nullptr) {
        cout << "Pointer is null!" << endl;
    }
    
    // ============================================
    // 4. POINTER ARITHMETIC
    // ============================================
    cout << "\n=== 4. Pointer Arithmetic ===" << endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    int *arrPtr = arr;  // Points to first element
    
    cout << "arrPtr[0]: " << arrPtr[0] << " or *arrPtr: " << *arrPtr << endl;
    cout << "arrPtr[1]: " << arrPtr[1] << " or *(arrPtr+1): " << *(arrPtr + 1) << endl;
    
    // Increment/Decrement
    arrPtr++;  // Now points to arr[1]
    cout << "After arrPtr++: " << *arrPtr << endl;
    
    arrPtr--;  // Back to arr[0]
    cout << "After arrPtr--: " << *arrPtr << endl;
    
    // Pointer difference
    int *ptrA = &arr[0];
    int *ptrB = &arr[3];
    cout << "Difference (ptrB - ptrA): " << (ptrB - ptrA) << " elements" << endl;
    
    // ============================================
    // 5. POINTERS AND ARRAYS
    // ============================================
    cout << "\n=== 5. Pointers and Arrays ===" << endl;
    
    int nums[3] = {100, 200, 300};
    int *numsPtr = nums;
    
    cout << "Array access methods:" << endl;
    cout << "nums[0]: " << nums[0] << endl;
    cout << "*(nums): " << *(nums) << endl;
    cout << "*(numsPtr): " << *(numsPtr) << endl;
    cout << "numsPtr[0]: " << numsPtr[0] << endl;
    
    // Multi-dimensional arrays
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*matrixPtr)[3] = matrix;  // Pointer to array of 3 integers
    
    cout << "matrix[1][2]: " << matrix[1][2] << endl;
    cout << "*(*(matrixPtr + 1) + 2): " << *(*(matrixPtr + 1) + 2) << endl;
    
    // ============================================
    // 6. POINTER TO POINTER (DOUBLE POINTER)
    // ============================================
    cout << "\n=== 6. Pointer to Pointer ===" << endl;
    
    int value = 100;
    int *singlePtr = &value;
    int **doublePtr = &singlePtr;
    
    cout << "value: " << value << endl;
    cout << "*singlePtr: " << *singlePtr << endl;
    cout << "**doublePtr: " << **doublePtr << endl;
    cout << "Address of singlePtr: " << &singlePtr << endl;
    cout << "doublePtr: " << doublePtr << endl;
    
    // ============================================
    // 7. CONSTANT POINTERS
    // ============================================
    cout << "\n=== 7. Constant Pointers ===" << endl;
    
    int x = 5, y = 10;
    
    // Case 1: Pointer to constant data
    const int *ptrToConst = &x;
    // *ptrToConst = 20; // ERROR: Cannot modify data
    ptrToConst = &y;      // OK: Can change pointer
    
    // Case 2: Constant pointer to data
    int *const constPtr = &x;
    *constPtr = 20;       // OK: Can modify data
    // constPtr = &y;     // ERROR: Cannot change pointer
    
    // Case 3: Constant pointer to constant data
    const int *const constPtrToConst = &x;
    // *constPtrToConst = 30; // ERROR: Cannot modify data
    // constPtrToConst = &y;  // ERROR: Cannot change pointer
    
    cout << "After modifications: x = " << x << endl;
    
    // ============================================
    // 8. POINTERS AND FUNCTIONS
    // ============================================
    cout << "\n=== 8. Pointers and Functions ===" << endl;
    
    // Function prototypes
    void swapValues(int*, int*);
    void printArray(int*, int);
    int* returnPointer();
    
    int num1 = 5, num2 = 10;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapValues(&num1, &num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Passing arrays to functions
    int testArr[] = {1, 2, 3, 4, 5};
    printArray(testArr, 5);
    
    // Returning pointer from function
    int *returnedPtr = returnPointer();
    cout << "Value from returned pointer: " << *returnedPtr << endl;
    
    // ============================================
    // 9. DYNAMIC MEMORY ALLOCATION
    // ============================================
    cout << "\n=== 9. Dynamic Memory Allocation ===" << endl;
    
    // Single variable
    int *dynPtr = new int;
    *dynPtr = 999;
    cout << "Dynamically allocated int: " << *dynPtr << endl;
    delete dynPtr;  // Must delete to avoid memory leak
    
    // Array
    int *arrDyn = new int[5];
    for (int i = 0; i < 5; i++) {
        arrDyn[i] = (i + 1) * 100;
    }
    cout << "Dynamic array: ";
    for (int i = 0; i < 5; i++) {
        cout << arrDyn[i] << " ";
    }
    cout << endl;
    delete[] arrDyn;  // Use delete[] for arrays
    
    // ============================================
    // 10. COMMON PITFALLS AND ERRORS
    // ============================================
    cout << "\n=== 10. Common Pitfalls ===" << endl;
    
    // Pitfall 1: Uninitialized pointer
    int *badPtr;
    // *badPtr = 5; // DANGEROUS: Undefined behavior!
    
    // Pitfall 2: Dangling pointer
    int *danglingPtr = new int(42);
    delete danglingPtr;
    // *danglingPtr = 10; // ERROR: Accessing freed memory
    
    // Pitfall 3: Memory leak
    // int *leakPtr = new int[100];
    // Forgot to delete[] leakPtr;
    
    // Pitfall 4: Returning address of local variable
    // int* badFunction() {
    //     int local = 10;
    //     return &local; // ERROR: local dies after function ends
    // }
    
    cout << "Always initialize pointers!" << endl;
    
    // ============================================
    // 11. SMART POINTERS (C++11+)
    // ============================================
    cout << "\n=== 11. Smart Pointers ===" << endl;
    
    // Note: Need to #include <memory> for these
    // unique_ptr: Exclusive ownership
    // shared_ptr: Shared ownership with reference counting
    // weak_ptr: Non-owning reference to shared_ptr
    
    cout << "Use smart pointers to avoid memory leaks!" << endl;
    
    // ============================================
    // 12. POINTERS WITH STRUCTURES AND CLASSES
    // ============================================
    cout << "\n=== 12. Pointers with Structures ===" << endl;
    
    struct Person {
        string name;
        int age;
    };
    
    Person person1 = {"Alice", 25};
    Person *personPtr = &person1;
    
    cout << "Access struct members:" << endl;
    cout << "person1.name: " << person1.name << endl;
    cout << "personPtr->name: " << personPtr->name << endl;
    cout << "(*personPtr).age: " << (*personPtr).age << endl;
    
    // Dynamic allocation of struct
    Person *dynPerson = new Person{"Bob", 30};
    cout << "Dynamic person: " << dynPerson->name << ", " << dynPerson->age << endl;
    delete dynPerson;
    
    // ============================================
    // 13. POINTER TYPE CASTING
    // ============================================
    cout << "\n=== 14. Pointer Type Casting ===" << endl;
    
    // C-style cast (avoid in C++)
    float floatVal = 65.5;
    char *charCast = (char*)&floatVal;
    
    // C++ style casts (preferred)
    // static_cast: Compile-time type conversion
    // reinterpret_cast: Low-level reinterpretation
    // const_cast: Add/remove const qualifier
    // dynamic_cast: Safe downcasting in inheritance
    
    int intVal = 97;
    char *charPtr2 = reinterpret_cast<char*>(&intVal);
    cout << "Reinterpret cast: " << *charPtr2 << endl;
    
    // ============================================
    // SUMMARY: POINTER RULES
    // ============================================
    cout << "\n=== SUMMARY: Pointer Rules ===" << endl;
    cout << "1. Always initialize pointers" << endl;
    cout << "2. Check for nullptr before dereferencing" << endl;
    cout << "3. Match new/delete and new[]/delete[]" << endl;
    cout << "4. Don't return addresses of local variables" << endl;
    cout << "5. Use smart pointers when possible" << endl;
    cout << "6. Understand pointer arithmetic" << endl;
    cout << "7. Know const pointer variations" << endl;
    cout << "8. Be careful with type casting" << endl;
    
    return 0;
}

// ============================================
// FUNCTION DEFINITIONS
// ============================================

// Function to swap values using pointers
void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print array using pointer
void printArray(int *arr, int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// Function returning a pointer
int* returnPointer() {
    // Static variable lives for program duration
    static int value = 777;
    return &value;
}