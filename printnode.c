#include "apc.h"

// Function to print nodes in list
void printnode(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("0");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);
		    /* Travering in forward direction */
		    head = head->next; 
	    }
    	}
	printf("\n");
}

