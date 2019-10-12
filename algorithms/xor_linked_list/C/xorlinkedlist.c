
#include<stdio.h> 
#include<stdlib.h> 
#include<inttypes.h> 

struct Node 
{ 
    int data; 
    struct Node* npx; 
}; 
  
struct Node* XOR (struct Node *a, struct Node *b) 
{ 
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 
  

void insert(struct Node **head_ref, int data) 
{
    struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) ); 
    new_node->data = data; 
    new_node->npx = XOR(*head_ref, NULL); 

    if (*head_ref != NULL) 
    {
        struct Node* next = XOR((*head_ref)->npx, NULL); 
        (*head_ref)->npx = XOR(new_node, next); 
    } 
  
    *head_ref = new_node; 
} 
  
void printList (struct Node *head) 
{ 
    struct Node *curr = head; 
    struct Node *prev = NULL; 
    struct Node *next; 
  
    printf ("Linked List: "); 
  
    while (curr != NULL) 
    { 
        printf ("%d ", curr->data); 
        next = XOR (prev, curr->npx);
        prev = curr; 
        curr = next; 
    } 
} 

int main () 
{
    struct Node *head = NULL; 
    insert(&head, 10); 
    insert(&head, 20); 
    insert(&head, 30); 
    insert(&head, 40); 
    printList (head); 
  
    return (0); 
} 

