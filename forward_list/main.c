#include "stdio.h"
#include <stdlib.h>
#include "test.h"


int main()
{
	forward_list stack = NULL;
	
	for (size_t i = 0; i < 1000000; i++)
	{
		push_front(&stack, i); 
	}
	
	/* reverse(&stack); */
	
	stack ? printf("Top element = %i\n", front(stack)) : 0;  
	
	/* display(stack); */ 
	/* erase(&stack);  */
	
	return 0;
}

