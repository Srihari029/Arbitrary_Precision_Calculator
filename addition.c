/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

// Function to perform Addition operation
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int carry = 0,res = 0,op;
	Dlist *temp1,*temp2;
	temp1 = *tail1;
	temp2 = *tail2;
	
	// While both are not null
	while(temp1 != NULL && temp2 != NULL)
	{
		res = temp1->data + temp2->data + carry;
		if(res > 9)
		{	
			// Store the unit digit
			op = res % 10;
			// Carry the tens digit
			carry = res / 10;
		}
		else
			carry = 0;

		Dlist *new = malloc(sizeof(Dlist));
    		if(new == NULL)
    	        	return FAILURE;
		if(res > 9)
			new->data = op;
		else
   			new->data = res;

   		new->prev = NULL;
   		new->next = NULL;
		insert_first(headR,tailR,new);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}

	// When temp1 becomes null and temp2 is not null
	while(temp1 == NULL && temp2 != NULL)
	{
		res = temp2->data + carry;
		if(res > 9)
                {
                        // Store the unit digit
                        op = res % 10;
                        // Carry the tens digit
                        carry = res / 10;
                }
                else
                        carry = 0;
		
		Dlist *new = malloc(sizeof(Dlist));
    		if(new == NULL)
    	        	return FAILURE;
		if(res > 9)
   			new->data = op;
		else
			new->data = res;
   		new->prev = NULL;
   		new->next = NULL;
		insert_first(headR,tailR,new);
                temp2 = temp2->prev;
	}

	// When temp2 becomes null and temp1 is not null
	while(temp1 != NULL && temp2 == NULL)
        {
                res = temp1->data + carry;
                if(res > 9)
                {
                        // Store the unit digit
                        op = res % 10;
                        // Carry the tens digit
                        carry = res / 10;
                }
                else
                        carry = 0;
		
		Dlist *new = malloc(sizeof(Dlist));
    		if(new == NULL)
    	        	return FAILURE;
		if(res > 9)
   			new->data = op;
		else
			new->data = res;
   		new->prev = NULL;
   		new->next = NULL;
		insert_first(headR,tailR,new);
        	temp1 = temp1->prev;
        }

	// If carry remains add in new node
	if(carry == 1)
	{
		Dlist * new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;
		new->prev = NULL;
		new->next = NULL;
                new->data = carry;
		insert_first(headR,tailR,new);
	}	
	return SUCCESS;
}
