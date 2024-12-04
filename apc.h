#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;


/* Include the prototypes here */

/* Addition */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
/* Subtraction */
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
/* Multiplication */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *str1, char *str2);
/* Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
/* Validate inputs */
int input(Dlist **head, Dlist **tail, char * num);
/* Print node */
void printnode(Dlist *headR);
/* Remove leading zeros */
void remove_zero(Dlist **headR);
/* Delete and free nodes */
int delete_list(Dlist **head,Dlist **tail);
/* Insert zero at last */
int insert_zero(Dlist **headR2,Dlist **tailR2,int i);
/* Insert at first */
void insert_first(Dlist **headR,Dlist **tailR,Dlist *new);
/* Validate operand lenghts */
int list_length(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

#endif
