#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFirst(int data)
    {
        Node *temp = new Node(data);

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertAtLast(int data){
        Node* temp = new Node(data);
        
        if(head == nullptr){
            head = temp;
            tail = temp;
            return;
        }

        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    

    void inserInBetween(int data, int target)
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        while (temp != nullptr && temp->data != target)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "\nTarget " << target << " not found!" << endl;
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        temp->next = newNode;
    }

    void deleteAtFirst(){
        Node* temp = head;

        if (head == nullptr){
            cout << "Nothing to delete!";
            return; 
        }

        head = head->next;
        head->prev = nullptr;
        delete temp; 
    }

    void deleteAtLast(){
        Node* temp = tail;

        if (head == nullptr){
            cout << "Nothing to delete!";
            return; 
        }

        tail = tail->prev;
        tail->next = nullptr;
        delete temp; 
    }

    void deleteInBetween(int target){
        Node* temp = head;

        if (head == nullptr){
            cout << "Nothing to delete!";
            return; 
        }

        while(temp!= nullptr && temp->data != target){
            temp = temp->next;
        }

        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev; 
        delete temp; 
    }

    void displayForward()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    

    void displayBackward()
    {
        if (head == nullptr)
        {
            cout << "No nodes are there" << endl;
            return;
        }
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtFirst(10);
    list.insertAtFirst(20);
    list.insertAtFirst(30);
    list.insertAtFirst(40);

    cout << "Initial List: ";
    list.displayForward();

    cout << "After Inserting 50 at last node: ";
    list.insertAtLast(50);
    list.displayForward();

    cout << "Insert In between: ";
    list.inserInBetween(55, 10);
    list.displayForward();

    cout << "After deleting first node: ";
    list.deleteAtFirst();
    list.displayForward();

    cout << "After deleting last node: ";
    list.deleteAtLast();
    list.displayForward();

    cout << "After deleting 20 node: ";
    list.deleteInBetween(20);
    list.displayForward();

    // cout << "Display Backward: ";
    // list.displayBackward();

    return 0;
}
