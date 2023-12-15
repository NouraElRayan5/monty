#include "monty.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * queue_n - add a node to queue
 * @stack: stack head
 * @n: number of the nodes
 * Return: Null
*/
stack_t *queue_n(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}


/**
 * isnumber - check if str is number
 * @str: string being passed
 * Return: return 1 if str is number, 0 otherwise
*/
int isnumber(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);
	return (1);
}

/**
 * print_stack - prints the stack
 * @stack: pointer to head of stack
 * Return: number
*/

size_t print_stack(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}
