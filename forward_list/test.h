#ifdef TEST_H
#error "multiple inclusion of 'test.h'"
#endif

#ifndef TEST_H
#define TEST_H

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
typedef struct node* forward_list;


/* Add data to the front of the %forward_list. */
extern void push_front(node **head, int data);

/* Remove first element. This is a typical %stack operation.  
 * It shrinks the %forward_list by one. */
extern void pop_front(node **head); 

/* Return the first element in the %forward_list. */
extern int front(node *head);

/* Reverse the %forward_list. */
extern void reverse(node **head);

/* Return true if the %forward_list is empty. */
extern int is_empty(node *head);

/* Display content of the %forward_list. */
extern void display(node *head);

/* Free the memory allocated for the %forward_list. */
extern void erase(node **head); 

#endif
