#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularLinkedList {
private:
    Node *head;
    Node *tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFirst(int data) {
        Node *temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
            head->prev = tail;
            tail->next = head;
        } else {
            temp->next = head;
            temp->prev = tail;
            head->prev = temp;
            tail->next = temp;
            head = temp;
        }
    }

    void insertAtEnd(int data) {
        Node *temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        } else {
            tail->next = temp;
            temp->prev = tail;
            temp->next = head;
            head->prev = temp;
            tail = temp;
        }
    }

    void insertInBetween(int data, int target) {
        if (head == nullptr) {
            cout << "List is empty! Cannot insert." << endl;
            return;
        }

        Node *temp1 = head;
        bool found = false;

        do {
            if (temp1->data == target) {
                found = true;
                break;
            }
            temp1 = temp1->next;
        } while (temp1 != head);

        if (!found) {
            cout << "Target value " << target << " not found!" << endl;
            return;
        }

        Node *temp = new Node(data);
        
        temp->next = temp1->next;
        temp->prev = temp1;
        
        temp1->next->prev = temp;
        temp1->next = temp;

        if (temp1 == tail) {
            tail = temp;
        }
    }

    void deleteFirstNode(){
        if(head == nullptr){
            cout << "No Node Present!";
            return;
        }
        if(head -> next == head){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        head = head -> next;
        head -> prev = tail;
        tail -> next = head;
    }

    void deleteLastNode(){
        Node* temp = tail;

        if(head == nullptr){
            cout << "No Node Present to delete!";
            return;
        }
        if(head -> next == head){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        tail = tail -> prev;
        tail -> next = head;
        delete temp;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    
    list.insertAtFirst(10);
    list.insertAtFirst(20);
    list.insertAtFirst(30);
    cout << "Initial list: ";
    list.displayForward();

    list.insertAtEnd(40);
    cout << "After inserting 40 at end: ";
    list.displayForward();

    list.insertInBetween(25, 20);
    cout << "After inserting 25 after 20: ";
    list.displayForward();

    list.deleteFirstNode();
    cout << "After deleting first Node: ";
    list.displayForward();

    list.deleteLastNode();
    cout << "After deleting last Node: ";
    list.displayForward();

    return 0;
}
