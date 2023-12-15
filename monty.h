#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define INSTRUCTIONS { \
						{"push", _push},\
						{"pall", _pall},\
						{"pint", _pint},\
						{"pop", _pop},\
						{"swap", swap_nodes},\
						{"nop", _nop},\
						{"div", div_nodes},\
						{"mul", mull_nodes},\
						{"add", add_nodes},\
						{"sub", sub_nodes},\
						{"mod", mod_nodes},\
						{"pchar", print_char},\
						{"pstr", p_str},\
						{"rotl", _rotl},\
						{"rotr", _rotr},\
						{NULL, NULL} \
					}

/**
 * struct help- argument for current opcode
 * @data_struct: struct
 * @arg: arguments
 * Description: global structure
 */
typedef struct help
{
	int data_struct;
	char *arg;
} help;
help global;

extern int operationStatus;


void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void p_str(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int count);
void _rotr(stack_t **stack, unsigned int count);
void sub_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void mull_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void get_opcode(stack_t **stack, char *str, unsigned int line_number);
size_t print_stack(const stack_t *stack);
stack_t *add_n(stack_t **stack, const int n);
stack_t *queue_n(stack_t **stack, const int n);
int _isnumber(char *str);
int is_digit(char *string);

#endif
