#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>



/**
*swap_nodes - swap the top two elements of a stack
*@stack: pointer to struct
*@line_number : integer
*Return: void
*/

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *stackNode = NULL;

	int tmp = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	stackNode = *stack;
	tmp = stackNode->n;
	stackNode->n = tmp;

	stackNode->n = stackNode->next->n;
	stackNode->next->n = tmp;
}

/**
*_nop - is a no operation function
*@stack: pointer to struct
*@line_number: integer
*Return: nothing
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}


/**
*print_char - print the ascii value
*@stack: pointer to the struct
*@line_number: integer
*Return: void
*/

void print_char(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 *is_digit - it checks if the string is digit
 *@string: string
 *Return: 1 or 0 on failure
*/
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
