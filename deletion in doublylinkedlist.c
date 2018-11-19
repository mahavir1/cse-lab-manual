//Q.13) C program to perform deletion of a node in doubly linked list.

#include <stdio.h> 
#include <stdlib.h> 
  
/* a node of the doubly linked list */
struct Node 
{ 
  int data; 
  struct Node *next; 
  struct Node *prev; 
}; 
  
void deleteNode(struct Node **head_ref, struct Node *del) 
{ 
  /* base case */
  if(*head_ref == NULL || del == NULL) 
    return; 
  
  /* If node to be deleted is head node */
  if(*head_ref == del) 
    *head_ref = del->next; 
  
  /* Change next only if node to be deleted is NOT the last node */
  if(del->next != NULL) 
    del->next->prev = del->prev; 
  
  /* Change prev only if node to be deleted is NOT the first node */
  if(del->prev != NULL) 
    del->prev->next = del->next;      
  
  free(del); 
  return; 
}      
  
void push(struct Node** head_ref, int new_data) 
{ 
  /* allocate node */
  struct Node* new_node = 
       (struct Node*) malloc(sizeof(struct Node)); 
  
  /* put in the data  */
  new_node->data  = new_data; 
  
  /* since we are adding at the begining, 
    prev is always NULL */
  new_node->prev = NULL; 
  
  /* link the old list off the new node */
  new_node->next = (*head_ref);     
  
  /* change prev of head node to new node */
  if((*head_ref) !=  NULL) 
   (*head_ref)->prev = new_node ;     
  
  /* move the head to point to the new node */
   (*head_ref)    = new_node; 
} 
  
void printList(struct Node *node) 
{ 
  while(node!=NULL) 
  { 
   printf("%d ", node->data); 
   node = node->next; 
  } 
} 
int main() 
{ 

  struct Node* head = NULL; 
  push(&head, 2); 
  push(&head, 4); 
  push(&head, 8); 
  push(&head, 10); 
  
  printf("\n Original Linked list "); 
  printList(head); 
  
  deleteNode(&head, head);  /*delete first node*/
  deleteNode(&head, head->next);  /*delete middle node*/
  deleteNode(&head, head->next);  /*delete last node*/
  
  printf("\n Modified Linked list "); 
  printList(head);            
  
  getchar(); 
} 

