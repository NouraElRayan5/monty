#include "monty.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
*sub_nodes - sub top of stack
*@stack: pointer to lists
*@line_number: number of lines
*Return: void
*/

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}

	sub = ((*stack)->next->n) - ((*stack)->n);
	_pop(stack, line_number);

	(*stack)->n = sub;
}

/**
 * mull_nodes - mull top of stack
 * @stack: pointer to lists
 * @line_number: number of lines
 * Return: void
*/
void mull_nodes(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mull, stack too short\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}

	aux = ((*stack)->next->n) * ((*stack)->n);
	_pop(stack, line_number);
	(*stack)->n = aux;
	}


/**
 * div_nodes - div top of stack
 * @stack: pointer to lists
 * @line_number: number of lines opcode
 * Return: void
*/
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	div = ((*stack)->next->n) / ((*stack)->n);
	_pop(stack, line_number);
	(*stack)->n = div;
	}


/**
 * mod_nodes - mod top of stack
 * @stack: pointer to lists
 * @line_number: number of lines opcode
 * Return: void
*/
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}

	mod = ((*stack)->next->n) % ((*stack)->n);
	_pop(stack, line_number);
	(*stack)->n = mod;
	}


/**
 * add_nodes - add two elements
 * @stack: pointer to lists
 * @line_number: number of lines opcode
 * Return: void
*/
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		operationStatus = EXIT_FAILURE;
		return;
	}

	sum = ((*stack)->next->n) + ((*stack)->n);
	_pop(stack, line_number);
	(*stack)->n = sum;
	}
