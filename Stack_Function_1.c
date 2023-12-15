#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 *_push - push integer to a stack
 *@stack: linked lists
 *@line_number: number of line opcode
 *Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *n = global.arg;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}

	if (global.data_struct == 1)
	{
		if (!add_n(stack, atoi(global.arg)))
		{
			return;
			operationStatus = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_n(stack, atoi(global.arg)))
		{
			return;
			operationStatus = EXIT_FAILURE;
		}
	}
}


/**
 *_pall - print all function
 *@stack: pointer to list
 *@line_number: integer
 *Return: void
 */

void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 *_pint - print integer
 *@stack: pointer to lists
 *@line_number: Integer
 *Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
*_pop - remove the top element from a stack
*@stack: pointer to a struct represent the stack node
*@line_number: integer
*Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}

	node = (*stack)->next;
	free(*stack);
	*stack = node;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/**
 *free_stack - free a stack
 *@stack: pointer to head of the linked list
 *Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
