#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 *error_usage - prints usage message
 *Return: nothing
*/

void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 *file_error - prints error
 *@argv: argument
 *Return: nothing
*/

void file_error(char *argv)
{
	fprintf(stderr, "ERROR: can't open file%s\n", argv);
	exit(EXIT_FAILURE);
}

int operationStatus = 0;

/**
*main - Entry point
*@argc: number of argumnets
*@argv: value of arguments
*Return: 0
*/

int main(int argc, char **argv)
{
	FILE *file;
	size_t buffer_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (getline(&buffer, &buffer_len, file) != -1)
	{
		if (operationStatus)
			break;
		if (*buffer == '\n')
		{
			line_number++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_number++;
			continue;
		}
		global.arg = strtok(NULL, " \t\n");
		get_opcode(&stack, str, line_number);
		line_number++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(operationStatus);
}
