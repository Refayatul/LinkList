#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    int data;
};

Node *head = NULL;

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
    cout << endl;
}

Node *getNewNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int value)
{
    Node *newNode = getNewNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
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
    for (int i = 0; i < position - 2 && previousNode != NULL; i++)
    {
        previousNode = previousNode->next;
    }

    if (previousNode == NULL)
    {
        cout << "Invalid position." << endl;
        delete newNode;
        return;
    }

    newNode->prev = previousNode;
    newNode->next = previousNode->next;
    Node *nextNode = newNode->next;
    if (nextNode != NULL)
    {
        nextNode->prev = newNode;
    }
    previousNode->next = newNode;

    cout << "After inserting " << data << " at position " << position << ", the new list is: ";
    printList(head);
}

void InsertAtEnd(int data)
{
    Node *newNode = getNewNode(data);
    Node *last = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

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
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    if (position == 1)
    {
        deleteFirst();
        return;
    }
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *last = head;
    while (last->next != NULL)
        last = last->next;

    if (last->prev == NULL)
    {
        deleteFirst();
        return;
    }

    last->prev->next = NULL;
    delete last;
}

int main()
{
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtHead(5);
    InsertAtHead(6);

    cout << "Original Linked List: ";
    printList(head);

    InsertAt(9, 3);
    deleteFirst();

    cout << "Linked List after deleting the first node: ";
    printList(head);

    deleteAt(2);

    cout << "Linked List after deleting at position 2: ";
    printList(head);

    deleteAtEnd();

    cout << "Linked List after deleting the last node: ";
    printList(head);

    // Cleans memory
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
