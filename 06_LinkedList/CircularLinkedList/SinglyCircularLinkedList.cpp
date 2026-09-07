#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFirst(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
            tail->next = head;
            return;
        } else {
            temp->next = head; 
            head = temp;       
            tail->next = head;  
        }
    }

    void insertAtEnd(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
            tail->next = head;
            return;
        } else {
            tail->next = temp;  
            tail = temp;        
            tail->next = head;  
        }
    }

    void insertInBetween(int data, int target){
        Node* temp = new Node(data);

        if(head == nullptr){
            cout << "No Node Present!";
            return;
        }

        Node* temp1 = head;
        bool found = false;

        do{
            if(temp1->data == target){
                found = true;
                break;
            }
            temp1 = temp1 -> next;
        }while(temp1 != head);

        if(!found){
            cout << "Target not found!";
            return;
        }

        temp -> next = temp1 -> next;
        temp1 -> next = temp;

        if(temp1 == tail){
            tail = temp1;
        }
    }

    void deleteFirstNode(){
        Node* temp = head;

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
        tail -> next = head;
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    
    list.insertAtFirst(10);
    list.insertAtFirst(20);
    cout << "Initial list: ";
    list.displayForward();
    
    list.insertAtEnd(40);
    cout << "After inserting 40 at end: ";
    list.displayForward();

    list.insertInBetween(30, 10);
    cout << "After inserting 30 after 10: ";
    list.displayForward();

    list.deleteFirstNode();
    cout << "After Deleting the first Node: ";
    list.displayForward();
    
    return 0;
}
