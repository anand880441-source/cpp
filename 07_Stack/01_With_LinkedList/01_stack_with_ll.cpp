// #include<iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// Node* head = nullptr;
// Node* temp = nullptr;

// void push(int value){
//     Node* n = new Node();
//     n->data = value;
//     n->next = nullptr;

//     if(head == nullptr){
//         head = n;
//         temp = n;
//     }else{
//         // temp -> next = n;
//         // temp = temp -> next;
//         n -> next = temp;
//         head = n;
//         temp = head;
//     }
// };

// void pop(){
//     temp = head;
//     head = head -> next;
//     temp = nullptr;
//     delete temp;
// }

// void display(){
//     Node *temp = head;
//     while(temp!= nullptr){
//         cout<< temp -> data << " -> ";
//         temp = temp -> next;
//     }
//     cout << "nullptr" << endl;
// }

// int main() {


//     for(int i = 1; i<5; i++){
//         push(i * 10);
//     }

//     cout<<"Push: ";
//     display();

//     pop();


//     cout << "Pop: ";
//     display();

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {6,-7,0,-3,-2,-1,2,1};
    vector<int> sumArr;

    int sum = 0;
    int maxSum = 0;

    for(int i = 0; i< arr.size(); i++){
        for(int j = 1; j <arr.size(); j++){
            sum = arr[i] + arr[j];
        }
        sumArr.push_back(sum);
        sum = 0;
    }

    for(int i = 0; i<sumArr.size(); i++){
        if(arr[i] > maxSum){
            maxSum = arr[i];
        }
    }
    cout << maxSum;
    return 0;
}