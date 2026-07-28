#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};

class SingLinkedList{
    private:
        Node* head;

    public:
        SingLinkedList(){
            head = nullptr;
        }

        void insertAtFirst(int data){
            Node* temp;
            temp = new Node(data);
            temp->next = head;
            head = temp;
        }

        void insertAtEnd(int data){
            Node* temp = new Node(data);

            if(head == nullptr){
                head = temp;
                return;
            }

            Node* temp1 = head;
            while(temp1->next != nullptr){
                temp1 = temp1->next;
            }

            temp1->next = temp;
        }

        void insertInBetween(int data, int target){
            Node* temp = head;

            while(temp != nullptr && temp->data != target){
                temp = temp->next;
            }

            if(temp != nullptr){
                Node* temp1 = new Node(data);
                temp1->next = temp->next;
                temp->next = temp1;
            }else{
                cout << "The Targated Value " << target << "Not found in list!" << endl;
            }
        }
        
        void deleteAtFirst(){
            if(head == nullptr){
                cout << "Nothing to delete";
                return;
            }

            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }

        void deleteAtEnd(){
            if(head == nullptr){
                cout << "Nothing to delete: ";
                return;
            }

            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }

            Node* temp1 = temp->next;
            temp->next = nullptr;
            temp1->next = nullptr;
            delete temp1;
        }

        void display(){
            Node* temp = head;

            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main(){

    SingLinkedList list;

    list.insertAtFirst(10);
    list.insertAtFirst(11);
    list.insertAtFirst(12);
    list.insertAtFirst(13);
    list.insertAtFirst(14);
    list.insertAtFirst(16);

    cout << "Linked List: ";
    list.display();

    list.insertAtEnd(20);
    cout << "After Inserting 20 at end: ";
    list.display();

    list.insertInBetween(15,10);
    cout << "After inserting 15 after 10: ";
    list.display();

    list.deleteAtFirst();
    cout << "After deleting frist Node: ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleting End Node: ";
    list.display();

    return 0;
}