#include <stdio.h>
#include <stdlib.h>
#include "test.h"

static const unsigned char node_size = sizeof(node);


void push_front(node **head, int data)
{
    node *new_node = (node *) malloc(node_size);
    if(!new_node)
    {
        puts("Out of memory...Program terminated.");
        return; 
    }
    new_node->data = data;
    new_node->next = *head; 
    *head = new_node;
}


void pop_front(node **head)
{
    if(!*head)
    {
	puts("List is empty."); 
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
    node *prev = NULL, *next = NULL;
    while (*head) {
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
    for (struct node *it = head; it; it = it->next)
    {
	printf("%i ", it->data);
    }
    puts(""); 
}


void erase(node **head)
{
    if(!*head)
    {
	puts("List is empty."); 
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

