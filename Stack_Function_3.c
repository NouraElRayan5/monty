#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
*p_str - print a string from a stack
*@stack: pointer
*@line_number: integer
*Return: void
*/

void p_str(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		putchar((char) tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}


/**
*_rotl - this function perform a rotate left operation on the linked list
*@stack: pointer to a stack
*@count: count of lines
*Return: void
*/

void _rotl(stack_t **stack, unsigned int count)
{
	stack_t *Left;
	stack_t *Right;

	(void) count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	Left = Right = *stack;

	while (Right->next)
		Right = Right->next;
	Right->next = Left;
	Left->prev = Right;
	*stack = Left->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
*_rotr - this function perfoorm a rotate right operation on the list
*@stack: pointer to stack
*@count: count of lines
*Return: void
*/

void _rotr(stack_t **stack, unsigned int count)
{
	stack_t *lastNode;
	stack_t *prev;

	(void) count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	lastNode = *stack;

	while (lastNode->next)
		lastNode = lastNode->next;

	prev = lastNode->prev;
	lastNode->next = *stack;
	lastNode->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = lastNode;
	*stack = lastNode;
	}


/**
 *add_n - adds nodes to start of stack
 *@stack: stack head
 *@n: number of nodes
 *Return: Null
*/

stack_t *add_n(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "ERROR: malloc failed\n");
		free(new);
		return (NULL);
	}

	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 *get_opcode - function to run builtins
 *@stack: stack
 *@str: string
 *@line_number: integer
*/

void get_opcode(stack_t **stack, char *str, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	operationStatus = EXIT_FAILURE;
}
