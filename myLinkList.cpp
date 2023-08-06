#include <iostream>
using namespace std;
struct Node
{
    Node *prev;
    Node *next;
    int data;
};

Node *head = NULL;

Node *getNewNode(int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void InsertAtHead(int value)
{
    Node *new_node = getNewNode(value);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void InsertAt(int data, int position)
{
    Node *newNode = getNewNode(data);
    if (position == 1)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *previousNode = head;
    for (int i = 0; i < position - 2; i++)
    {
        previousNode = previousNode->next;
    }

    newNode->prev = previousNode;
    newNode->next = previousNode->next;
    Node *nextNode = newNode->next;
    nextNode->prev = newNode;
    previousNode->next = newNode;
}

void InsertAtEnd(int data)
{
    Node *new_node = getNewNode(data);
    Node *last = head;
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

void deleteFirst()
{
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head != NULL)
    {
        head->prev = NULL;
    }
}

void deleteAt(int position)
{
    Node *temp = head;
    Node *temp1 = NULL;
    int i;
    if (position == 1)
    {
        deleteFirst();
        return;
    }
    for (i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    if (temp1->next == NULL)
    {
        temp->next = NULL;
        delete temp1;
        return;
    }

    temp->next = temp1->next;
    temp1->next->prev = temp;
    delete temp1;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
   cout << endl;
}

int main()
{
    InsertAtHead(5);
    InsertAtHead(4);
    cout<<"Original Link List :";
    InsertAt(10, 2);
    InsertAtEnd(21);

    printList(head);
    deleteFirst();
    printList(head);
    deleteAt(2);
    printList(head);

    // Clean up memory (deallocate nodes)
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
