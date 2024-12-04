/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"

int main(int argc,char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL,*tailR = NULL;
	int Quo;
	char option, operator;
	char *num1,*num2;
	
	// Check number of arguments	
	if(argc != 4)
	{
		printf("INFO : Invalid number of arguments!\n");
		printf("Format : a./out  <Operand-1>  <Operator>  <Operand-2>\n");
		return -1;
	}
	// check if its an integer or not
	if((strchr(argv[1],'.') != NULL) || (strchr(argv[3],'.') != NULL))
	{
		printf("INFO : Float value found!. Enter only integer\n");
		return -1;
	}
	num1 = argv[1];
	num2 = argv[3];
	
	// Input 1 ---> digits into node 
	printf("Operand1 : ");	
	input(&head1,&tail1,num1);
	remove_zero(&head1);
	// Input 2 ---> digits into node 
	printf("Operand2 : ");	
	input(&head2,&tail2,num2);
	remove_zero(&head2);
	// operator
	operator = argv[2][0];
	
	switch (operator)
	{
		case '+':
			/* call the function to perform the addition operation */
			if(addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
				// Print Value 
				printf("Result : ");
				printnode(headR);
			}
			else
			{
				printf("INFO : Addition operation failed!\n");
			}
			break;
		case '-':	
			/* call the function to perform the subtraction operation */
			if(subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
				// Print Value 
                                printf("Result : ");
                                printnode(headR);
                        }
                        else
                        {
                                printf("INFO : Subtraction operation failed!\n");
                        }
			break;
		case '*':	
			/* call the function to perform the multiplication operation */
			if(multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR, num1, num2) == SUCCESS)
			{
                                // Print Value 
                                printf("Result : ");
                                printnode(headR);
                        }
                        else
                        {
                                printf("INFO : Multiplication operation failed!\n");
                        }
			break;

		case '/':	
			/* call the function to perform the division operation */
			if(division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
                       		// Print Value
                      		printf("Result : ");
				printnode(headR);
			}
			else	
				printf("INFO : Division operation failed!\n");

			break;

		default:
			printf("Invalid Input:-( Try again...\n");
	}
	return 0;
}
