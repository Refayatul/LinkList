#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        next = NULL;
    }
};

void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void removeLast(Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    cout << "After removing Last: ";
    printLinkedList(head);
}

void removeFirst(Node*& head) {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "After removing First: ";
    printLinkedList(head);
}


void removeGivenPosition(Node *head,int pos){
    Node *current = head;
    if(pos == 1){
        removeFirst(head);
        return;
    }
    for(int i = 0;i < pos - 2;i++){   
        head = head ->next;
    }
     if (head == NULL || head->next == NULL) {
         cout << "Invalid position!" << endl;
         return;
     }
      head->next = head->next->next;

      cout<<"After removing value from "<< pos <<" position : ";
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(7);

    cout << "Original Linked List: ";
    printLinkedList(head);

    
    removeGivenPosition(head, 3);
    printLinkedList(head);
    removeFirst(head);
    removeLast(head);

    return 0;
}
