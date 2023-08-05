#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


class Node{
public:
    int data;
    Node *next;
    Node(int value){
        this->data = value;
        next = NULL;
    }

};

void printLiskList(Node *head){
    while(head != NULL)
    {
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;
}

void removeLast(Node *&head){
    Node *current = head;
    while(current->next->next != NULL){
        current = current->next; 
    }
    current->next = NULL;
    //cout<<current->data;

}









int main()
{   
    
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next= new Node(6);
    printLiskList(head);
    removeLast(head);
    printLiskList(head);

   




    return 0;
}
