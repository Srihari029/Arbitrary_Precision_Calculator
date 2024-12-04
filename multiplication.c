/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *str1, char *str2)
{
	int carry = 0,res = 0, op , count = 0, last = 0;
        Dlist *temp1,*temp2;
        temp1 = *tail1;
        temp2 = *tail2;
	Dlist *headR1 = NULL, *tailR1 = NULL,*headR2 = NULL, *tailR2 = NULL,*headR3 = NULL, *tailR3 = NULL;
	// Swap the greater number to temp1
	if(strlen(str1) < strlen(str2))
	{
		temp1 = *tail2;
        	temp2 = *tail1;
	}
	Dlist *start = temp1;
	while(temp2 != NULL)
	{
		while(temp1 != NULL)
		{
			res = (temp1->data * temp2->data) + carry;
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
			
			// Insert in result 1
			if(count == 0)
			{
				insert_first(&headR1,&tailR1,new);
			}
			// Insert at result 2
			else if(count == 1)
			{
				insert_first(&headR2,&tailR2,new);
			}
			temp1 = temp1->prev;
		}
		temp2 = temp2->prev;
		temp1 = start;
		
		// insert carry if leftover
		if(count == 0 && carry > 0)
		{			
			Dlist * new = malloc(sizeof(Dlist));
                	if(new == NULL)
                	        return FAILURE;
                	new->prev = NULL;
                	new->next = NULL;
                	new->data = carry;
                	insert_first(&headR1,&tailR1,new);
			carry = 0;
        	}
		if(count == 1 && carry > 0)
		{
                        Dlist * new = malloc(sizeof(Dlist));
                        if(new == NULL)
                                return FAILURE;
                        new->prev = NULL;
                        new->next = NULL;
                        new->data = carry;
                        insert_first(&headR2,&tailR2,new);
			carry = 0;
                }	
		count++;	
		// Add zeros at last after each element multiplication
		insert_zero(&headR2,&tailR2,last);
		last++;

		// If both result node are full call addition operation
		if(count == 2)
		{
			// add result 1 and result 2
			addition(&headR1, &tailR1, &headR2, &tailR2, &headR3, &tailR3);
			// store the result 3 in result 1
			headR1 = headR3;
			tailR1 = tailR3;
			//free result 3
			headR3 = NULL;
			tailR3 = NULL;
			// free result 2
			delete_list(&headR2,&tailR2);
			count --;
		}	
	}
	
	// Load the result to headR and tailR
	*headR = headR1;
	*tailR = tailR1;
	// Remove leading zeros
	remove_zero(headR);
	return SUCCESS;
}
