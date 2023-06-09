#include <stdio.h>
#include <stdlib.h>
#include "test.h"

#define empty_list        "List is empty."
#define exit_msg          "Out of memory...Program terminated." 
#define exit_failure       0x1

static const unsigned char node_size = sizeof(node);


void push_front(node **head, int data)
{
    node *new_node = (node *) malloc(node_size);
    if(!new_node)
    {
        puts(exit_msg); 
        exit(exit_failure); 
    }
    new_node->data = data;
    new_node->next = *head; 
    *head = new_node;
}


void pop_front(node **head)
{
    if(!*head)
    {
	puts(empty_list); 
        return;
    }
    struct node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}


int front(node *head)
{
    return head->data;
}


void reverse(node **head)
{
    if(!*head)
    {
	puts(empty_list); 
        return;
    }
    node *prev = NULL; 
    node *next = NULL;
    while (*head) 
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;
}
    

int is_empty(node *head)
{
    if(!head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void display(node *head)
{
    for (node *it = head; it; it = it->next)
    {
	printf("%i ", it->data);
    }
    puts(""); 
}


void erase(node **head)
{
    if(!*head)
    {
	puts(empty_list); 
        return;
    }
    node *tmp = NULL;
    for (node *it = *head; it; )
    {
    	tmp = it;
        it = it->next; 
        free(tmp);
    }
    *head = NULL; 
}

