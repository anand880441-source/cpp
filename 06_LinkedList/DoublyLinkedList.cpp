// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;
//     Node(int val)
//     {
//         data = val;
//         prev = nullptr;
//         next = nullptr;
//     }
// };

// class DoublyLinkedList
// {
// private:
//     Node *head;
//     Node *tail;

// public:
//     DoublyLinkedList()
//     {
//         head = nullptr;
//         tail = nullptr;
//     }

//     void insertAtFirst(int data)
//     {
//         Node *temp = new Node(data);

//         if (head == nullptr)
//         {
//             head = temp;
//             tail = temp;
//             return;
//         }

//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }

//     void insertAtLast(int data)
//     {
//         Node *temp = new Node(data);

//         if (head == nullptr)
//         {
//             head = temp;
//             tail = temp;
//             return;
//         }

//         temp->prev = tail;
//         tail->next = temp;
//         tail = temp;
//     }

//     void inserInBetween(int data, int target)
//     {
//         // case 1
//         if (head == nullptr)
//         {
//             cout << "No Node exist!";
//             return;
//         }
//         // case 2
//         if (head->next == nullptr)
//         {
//             if (head->data != target)
//             {
//                 cout << "No target found!";
//                 return;
//             }
//             Node *temp = new Node(data);
//             temp->prev = head;
//             head->next = temp;
//             tail = temp;
//         }
//         // case 3
//         Node *temp1 = head;
//         while (temp1 != nullptr && temp1->data != target)
//         {
//             temp1 = temp1->next;
//         }

//         if (temp1 == nullptr)
//         {
//             cout << "No target found!" << endl;
//             return;
//         }
//         Node *temp = new Node(data);
//         temp->next = temp1->next;
//         temp->prev = temp1;
//         temp1->next = temp;

//         if (temp->next != nullptr)
//         {
//             temp->next->prev = temp;
//         }
//         if (temp->next == nullptr)
//         {
//             tail = temp;
//         }
//     }

//     void deleteAtFirst()
//     {
//         if (head == nullptr)
//         {
//             cout << "Nothing to delete";
//             return;
//         }
//         else if (head == tail)
//         {
//             delete head;
//             head = nullptr;
//             tail = nullptr;
//         }
//         else
//         {
//             head = head->next;
//             delete head->prev;
//             head->prev = nullptr;
//         }
//     }

//     void deleteAtLast()
//     {
//         if (head == nullptr)
//         {
//             cout << "Nothing to delete";
//             return;
//         }
//         else if (head == tail)
//         {
//             delete tail;
//             head = nullptr;
//             tail = nullptr;
//         }
//         else
//         {
//             tail = tail->prev;
//             delete tail->next;
//             tail->next = nullptr;
//         }
//     }

//     void deleteInBetween(int target)
//     {
//         if (head == nullptr)
//         {
//             cout << "Nothing to delete!";
//             return;
//         }

//         Node *temp = head;
//         while (temp != nullptr && temp->data != target)
//         {
//             temp = temp->next;
//         }

//         if (temp == nullptr)
//         {
//             cout << "No target found!";
//             return;
//         }

//         if (temp == head)
//         {
//             deleteAtFirst();
//             return;
//         }

//         if (temp == tail)
//         {
//             deleteAtLast();
//             return;
//         }

//         temp->prev->next = temp->next;
//         temp->next->prev = temp->prev;
//         delete temp;
//     }

//     void displayForward()
//     {
//         Node *temp = head;
//         while (temp != nullptr)
//         {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }

//     void displayBackward()
//     {
//         if (head == nullptr)
//         {
//             cout << "No nodes are there" << endl;
//             return;
//         }
//         Node *temp = tail;
//         while (temp != nullptr)
//         {
//             cout << temp->data << " -> ";
//             temp = temp->prev;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main()
// {
//     DoublyLinkedList list;
//     list.insertAtFirst(10);
//     list.insertAtFirst(20);
//     list.insertAtFirst(30);
//     list.insertAtFirst(40);

//     cout << "Initial List: ";
//     list.displayForward();

//     cout << "After Inserting 50 at last node: ";
//     list.insertAtLast(50);
//     list.displayForward();

//     cout << "Insert In between: ";
//     list.inserInBetween(55, 20);
//     list.displayForward();

//     cout << "After deleting first node: ";
//     list.deleteAtFirst();
//     list.displayForward();

//     cout << "After deleting last node: ";
//     list.deleteAtLast();
//     list.displayForward();

//     cout << "After deleting 20 node: ";
//     list.deleteInBetween(20);
//     list.displayForward();

//     // cout << "Display Backward: ";
//     // list.displayBackward();

//     return 0;
// }



#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
};

void insertAtFirst(Node *&head, int data) {
    Node *newNode = new Node();
    newNode->val = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode; 
    }
    head = newNode;
}

void insertAtLast(Node* &head, int data){
    Node *newNode = new Node();
    newNode->val = data;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        newNode->prev = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){ 
        temp = temp -> next;
    }
    
    temp -> next = newNode;
    newNode -> prev = temp;
}

void display(Node *&head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> val << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* n0 = new Node();
    n0 -> val = 10;
    n0 -> prev = nullptr;
    n0 -> next = nullptr;

    cout << "Insert At First: ";
    insertAtFirst(n0, 20);
    display(n0);

    cout << "Insert At Last: ";
    insertAtLast(n0, 30);
    display(n0);

    return 0;
}
