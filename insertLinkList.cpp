#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = NULL;
    }
};

void printLinkList(Node *head){
    while(head != NULL){
        cout<<head->value<<" ";
        head = head->next;

    }
    cout<<"\n";

}

void insertAtFirst(Node *&head){
    Node *newNode = new Node(2);
    newNode->next = head;
    head = newNode;
    cout<<"After inseting at first :";
}
void insertAtLast(Node *&head){
    Node *current = head;
    Node *newNode = new Node(8);
    if(head == NULL){
        head = newNode;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    cout<<"After inseting at  Last :";
}

void insertatGivenPosition(Node *&head,int pos,int value){
    Node *current = head;
    Node *newNode = new Node(value);
    for(int i = 0;i<pos-2;i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    cout<<"After inserting at     "<<pos <<": ";

}




int main() {
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next= new Node(5);
    head->next->next->next = new Node(7);
    printLinkList(head);
    insertAtFirst(head);
    printLinkList(head);
    insertAtLast(head);
    printLinkList(head);
    insertatGivenPosition(head,3,10);
    printLinkList(head);





    return 0;
}
