// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     // Constructor to easily create a new node
//     Node(int val) {
//         data = val;
//         next = nullptr;
//     }
// };

// class SingLinkedList {
// private:
//     Node *head;

// public:
//     SingLinkedList() {
//         head = nullptr;
//     }

//     // 1. Inserts a new node at the very beginning
//     void insertAtFirst(int data) {
//         Node* newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     // 2. Inserts a new node at the very end
//     void insertAtLast(int data) {
//         Node* temp = new Node(data);
//         if (head == nullptr) {
//             head = temp;
//             return;
//         }
//         Node* temp1 = head;
//         while (temp1->next != nullptr) {
//             temp1 = temp1->next;
//         }
//         temp1->next = temp;
//     }

//     // 3. Inserts a new node directly AFTER the targetedValue
//     void insertInBetween(int data, int targetedValue) {
//         Node *temp = head;
//         while (temp != nullptr && temp->data != targetedValue) {
//             temp = temp->next;
//         }
//         if (temp != nullptr) {
//             Node* newNode = new Node(data);
//             newNode->next = temp->next;
//             temp->next = newNode;
//         } else {
//             cout << "Targeted value " << targetedValue << " not found in the list!" << endl;
//         }
//     }

//     // Removed unused 'data' argument, added missing returns
//     void deleteAtFirst() {
//         // Case 1: Empty list
//         if (head == nullptr) {
//             cout << "Nothing to delete" << endl;
//             return;
//         }

//         // Case 2 & 3 combined cleanly
//         Node *temp = head;
//         head = head->next;
//         temp = nullptr;
//         delete temp;
//     }

//     // Added critical returns to prevent falling into downstream pointer exceptions
//     void deleteAtLast() {
//         // Case 1: Empty list
//         if (head == nullptr) {
//             cout << "Nothing to delete" << endl;
//             return;
//         }

//         // Case 2: One node
//         if (head->next == nullptr) {
//             delete head;
//             head = nullptr;
//             return; // Stops execution here
//         }

//         // Case 3: 2 or more nodes
//         Node *temp = head;
//         while (temp->next->next != nullptr) {
//             temp = temp->next;
//         }
//         Node* temp1 = temp->next;
//         temp->next = nullptr;
//         delete temp1;
//     }

//     // Corrected pointer evaluation order and boolean operator logic
//     void deleteInBetween(int target) {
//         if (head == nullptr) {
//             cout << "No Node exist" << endl;
//             return;
//         }

//         // If target is the head node
//         if (head->data == target) {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }

//         Node* temp = head;
//         while (temp->next != nullptr && temp->next->data != target) {
//             temp = temp->next;
//         }

//         if (temp->next == nullptr) {
//             cout << "No targeted Value node Exist" << endl;
//             return;
//         }

//         Node* temp1 = temp->next;
//         temp->next = temp1->next;
//         delete temp1;
//     }

//     // 4. Traverses and prints the entire list
//     void display() {
//         Node* temp = head;
//         while (temp != nullptr) {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main() {
//     SingLinkedList list;

//     // Initial Setup
//     list.insertAtFirst(10);
//     list.insertAtLast(30);
//     list.insertAtFirst(5);
//     list.insertAtFirst(25);

//     cout << "Initial list: ";
//     list.display();
//     // Output: 25 -> 5 -> 10 -> 30 -> NULL

//     // Insert 20 after 10
//     list.insertInBetween(20, 10);
//     cout << "After inserting 20 after 10: ";
//     list.display();
//     // Output: 25 -> 5 -> 10 -> 20 -> 30 -> NULL

//     list.deleteAtFirst();
//     cout << "After Deleting 25 (At-First): ";
//     list.display();
//     // Output: 5 -> 10 -> 20 -> 30 -> NULL

//     // Delete Last element (30)
//     list.deleteAtLast();
//     cout << "After Deleting 30 (At-End):   ";
//     list.display();
//     // Output: 5 -> 10 -> 20 -> NULL

//     // Delete Middle Element (10)
//     list.deleteInBetween(10);
//     cout << "After Deleting 10 (In-Between): ";
//     list.display();
//     // Output: 5 -> 20 -> NULL

//     return 0;
// }

// Struct

#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void insertAtFirst(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->val = data;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertAtLast(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->val = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteAtFirst(Node *&head)
{
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "Nothing to delete!!" << endl;
    }

    head = head->next;
    delete temp;
}

void deleteAtLast(Node *&head)
{
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "Nothing to delete!" << endl;
    }

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *temp1 = temp->next;

    temp->next = nullptr;
    delete temp1;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *n1 = new Node();
    n1->val = 10;

    Node *n2 = new Node();
    n2->val = 20;
    n1->next = n2;
    n2->next = nullptr;

    cout << "Insert At First: ";
    insertAtFirst(n1, 30);
    display(n1);

    cout << "\nInsert At Last: ";
    insertAtLast(n1, 40);
    display(n1);

    cout << "\nDelete At First: ";
    deleteAtFirst(n1);
    display(n1);

    cout << "\nDelete At Last: ";
    deleteAtLast(n1);
    display(n1);

    return 0;
}
