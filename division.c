/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int count = 0, sts,val = 0;
	Dlist *temp,*temp1;
	sts = list_length(head1,tail1,head2,tail2);
	// If operand 2 is 0 
	if(*head2 == *tail2)
	{
		if((*head2)->data == 0)
		{
			printf("INFO : Divide by 0. Value will be infinite\n");
			return -1;
		}
		if((*head2)->data == 1)
		{
			*headR = *head1;
			*tailR = *tail1;
			return SUCCESS;
		}

	}

	// loops until numerator is less than denominator
	while(sts != 2)
	{
		if(val % 2 == 0)
		{	
			count++;
			subtraction(head1,tail1,head2,tail2,headR,tailR);
			temp = *headR;
			temp1 = *tailR;
		}
		else
		{
			count++;
			subtraction(headR,tailR,head2,tail2,head1,tail1);
			temp = *head1;
			temp1 = *tail1;
		}
		// check den and num after subtraction
		sts = list_length(&temp,&temp1,head2,tail2);
		if(sts == 2)
			break;
		else
		{
			if(val % 2 == 0)
				delete_list(head1,tail1);
			else
				delete_list(headR,tailR);
			val++;
		}
	}
	// Delete result node
	delete_list(headR,tailR);
	
	Dlist *new = malloc(sizeof(Dlist));
	if(new == NULL)
		return FAILURE;
	new->data = count;  // Add the quotient to list
	new->prev = NULL;
	new->next = NULL;
	
	// Insert result to node
	insert_first(headR,tailR,new);
	return SUCCESS;
}
