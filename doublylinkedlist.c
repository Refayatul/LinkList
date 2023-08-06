#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
};

struct Node *head;

struct Node* getnewnode(int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
};

void InsertAtHead(int new_data)
{
	struct Node* new_node = getnewnode(new_data);
	if(head == NULL){
        head = new_node;
        return;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
}

void InsertAt(int data, int position) {
    struct Node* newNode = getnewnode(data);
    if (position == 1) {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
struct Node* previousNode = head;
    for (int i = 0; i < position - 2; i++) {
        previousNode = previousNode->next;
    }

    newNode->prev = previousNode;
    newNode->next = previousNode->next;
    struct Node* nextNode = newNode->next;
    nextNode->prev = newNode;
    previousNode->next = newNode;

}

void InsertAtEnd(int data){
    struct Node* new_node = getnewnode(data);
    struct Node *last = head;
    if (head == NULL)
	{
	head = new_node;
	return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return;
}

void deleteFirst(){
    struct Node* temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;

}

void deleteAt(int position){
    struct Node* temp = head;
    struct Node* temp1 = NULL;
    int i;
    if(position == 1){
        deleteFirst();
        return;
    }
    for (i = 0; i< position - 2; i++){
        temp = temp->next;
    }
    temp1= temp->next;
    if(temp1->next == NULL){
        temp->next = NULL;
        free(temp1);
        return;
    }

    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);

}


void printList(struct Node *node)
{
while (node != NULL)
{
	printf(" %d", node->data);
	node = node->next;
}
printf("\n");
}

int main(){
    InsertAtHead(5);
    InsertAtHead(4);
    InsertAt(10, 2);
    InsertAtEnd(21);
    printList(head);
    deleteFirst();
    printList(head);
    deleteAt(2);
    printList(head);
    return 0;
}

