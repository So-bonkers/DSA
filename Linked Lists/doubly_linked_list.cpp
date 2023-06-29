#include <bits/stdc++.h>
using namespace std;

class Node // A node of the doubly linked list
{
public:
    int data;
    Node *next;
    Node *prev;
};

// Function to delete a node in the Doubly Linked List
// head_ref --> pointer to head node pointer.
// del --> pointer to node to be deleted.
void deleteNode(Node **head_ref, Node *del)
{
    // base case
    if (*head_ref == NULL || del == NULL)
        return;

    // If node to be deleted is head node
    if (*head_ref == del)
        *head_ref = del->next;

    // Change next only if node to be deleted is NOT the last node
    if (del->next != NULL)
        del->next->prev = del->prev;

    // Change prev only if node to be deleted is NOT the last node
    if (del->next != NULL)
        del->prev->next = del->next;

    // Finally, free the memory occupied by del*
    free(del);
    return;
}

// Function to insert a node at the beginning of the Doubly Linked List
void push(Node **head_ref, int new_data)
{
    // Allocate node
    Node *new_node = new Node();

    // Put in the data
    new_node->data = new_data;

    // Prev is always NULL since we are adding at the beginning
    new_node->prev = NULL;

    // Link the old list of the new node
    new_node->next = (*head_ref);

    // Change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print nodes in a given Doubly Linked List
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

// Driver code
int main()
{
    // Start with empty list
    Node *head = NULL;

    // Let us create the Doubly Linked List
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 16);

    cout << "Original Linked List ";
    printList(head);

    // Delete nodes from the Doubly Linked List
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    deleteNode(&head, head->next);

    // Modified linked list will be NULL<-8->NULL
    cout<<"\nModified Linked List: ";
    printList(head);

    return 0;
}