/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h" 
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	    int borrow = 0, res = 0, minus = 0;
	    Dlist *temp1, *temp2;
	    temp1 = *tail1;
	    temp2 = *tail2;

	    // Check which operand is greater, If yes make temp1 greater
	    if (list_length(head1, tail1, head2, tail2) == 2)
	    {
		temp1 = *tail2;
		temp2 = *tail1;
		minus = 1;
	    }

	    // Subtract corresponding digits
	    while (temp1 != NULL && temp2 != NULL)
	    {
			if (temp1->data < temp2->data + (-borrow))
			{
			    res = temp1->data + 10 - temp2->data + borrow;
			    borrow = -1;
			}
			else
			{
			    res = temp1->data - temp2->data + borrow;
			    borrow = 0;
			}

			// Create a new result node
			Dlist *new = malloc(sizeof(Dlist));
			if (new == NULL)
			    return FAILURE;

			new->data = res;
			new->prev = NULL;
			new->next = NULL;

			// Append result to the result list
			if (*headR == NULL || *tailR == NULL)
			{
			    *headR = new;
			    *tailR = new;
			}
			else
			{
			    Dlist *temp = *headR;
			    *headR = new;
			    temp->prev = new;
			    new->next = temp;
			}

			temp1 = temp1->prev;
			temp2 = temp2->prev;
	    }

	    // Process remaining digits in temp1
	    while (temp1 != NULL)
	    {
			res = temp1->data + borrow;
			if (res < 0)
			{
			    res += 10;
			    borrow = -1;
			}
			else
			{
			    borrow = 0;
			}

			// Create a new result node
			Dlist *new = malloc(sizeof(Dlist));
			if (new == NULL)
			    return FAILURE;

			new->data = res;
			new->prev = NULL;
			new->next = NULL;

			if (*headR == NULL || *tailR == NULL)
			{
			    *headR = new;
			    *tailR = new;
			}
			else
			{
			    Dlist *temp = *headR;
			    *headR = new;
			    temp->prev = new;
			    new->next = temp;
			}
			temp1 = temp1->prev;
	    }

	    // Remove leading zeros from the result list
	    remove_zero(headR);

	    // Ensure proper linking of the result list
	    if (*headR != NULL)
			(*headR)->prev = NULL;

	    // Handle negative result
	    if (minus == 1)
	    {
	    		(*headR)->data *= -1;
	    }
	    return SUCCESS;
}

