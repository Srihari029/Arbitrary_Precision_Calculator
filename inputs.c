#include "apc.h"

// Covert string to value and store in list
int input(Dlist **head, Dlist **tail, char *num) 
{
   	 int i = 0;
   	 while (num[i] != '\0') 
	 {
   	     	Dlist *new = malloc(sizeof(Dlist));
   	     	if (new == NULL)
   	        	 return FAILURE;

        	new->data = num[i] - '0';  // Convert char to int
        	new->prev = NULL;
        	new->next = NULL;
	
        	if (*head == NULL) {
        	    *head = new;
        	    *tail = new;
	        } 	
		else 
		{
        	    (*tail)->next = new;
         	    new->prev = *tail;
            	    *tail = new;
        	}	
        	i++;
    	}
        
   	// Check and print the list without modifying *head
   	if (*head == NULL)
       	{
   	 	 printf("INFO : List is empty\n");
   	}
       	else 
	{
        	Dlist *temp = *head;
        	while (temp != NULL)
	       	{
        		printf("%d", temp->data);
            		temp = temp->next;
        	}
   	 }
    	 printf("\n");
    	 return SUCCESS;
}

// To insert data at first in a list
void insert_first(Dlist **headR,Dlist **tailR,Dlist *new)
{
	if(*headR == NULL || *tailR == NULL)
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
}

// Function to add zero at last (for multiplication operation) 
int insert_zero(Dlist **head,Dlist **tail,int n)
{
	int i = 0;
	while(i<n)
	{
		Dlist *new = malloc(sizeof(Dlist));
    		if(new == NULL)
    		        return FAILURE;
    		new->data = 0;
   		new->prev = NULL;
    		new->next = NULL;
    		if(*head == NULL)
   		{
   		        *head = new;
        		*tail = new;
    		}
		else
		{
    			(*tail)->next = new;
   			new->prev = *tail;
    			*tail = new;
		}
		i++;
	}
}

// Delete and free list
int delete_list(Dlist **head,Dlist **tail)
{
	if(*head == NULL || *tail == NULL)
        	return FAILURE;
 	Dlist *temp = *head;
	Dlist *temp1 = *head;
  	while(temp1 != NULL)
   	{
 	        temp1 = (temp1)->next;
       		free(temp);
        	temp = temp1;
    	}
	*head = NULL;
	*tail = NULL;
    	return SUCCESS;
}

// Check length and value of two operand and return which is greater 
int list_length(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
	int len1 = 0,len2 = 0;
	Dlist *temp1 = *head1,*temp2 = *head2;
	while(temp1 != NULL)
	{
		len1++;
		temp1 = temp1->next;
	}
	while(temp2 != NULL)
        {
                len2++;
                temp2 = temp2->next;
        }
	// By length
	if(len1 > len2)
		return 1;
	else if(len1 < len2)
		return 2;
	// By value
	else
	{
		temp1 = *head1;
	        temp2 = *head2;	
		while(temp1 != NULL && temp2 != NULL)
		{
			if(temp1->data > temp2->data)
				return 1;
			if(temp1->data < temp2->data)
				return 2;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}	
		return 1;
	}
}

// Function to remove leading zeros
void remove_zero(Dlist **headR)
{

        while(*headR != NULL)
        {
                Dlist * temp = *headR;
                if(temp->data == 0)
                {
                        (*headR)->prev = NULL;
                        *headR = temp->next;
                        free(temp);
                }
                else
                        break;
        }
        if(*headR == NULL)
        {
                Dlist *new = malloc(sizeof(Dlist));
                new->prev = NULL;
                new->next = NULL;
                new->data = 0;
                *headR = new;
        }
}

