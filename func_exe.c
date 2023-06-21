#include "monty.h"

/**
 * free_stack - function to frees doubly linked list
 * @main: the head of the stack
 */

void free_stack(stack_t *main)
{
	stack_t *x;

	x = main;

	while (main)
	{
		x = main->next;
		free(main);
		main = x;
	}
}

/**
 * execute - executes the opcode
 * @cont: the line of content
 * @main: the pointer to be checked
 * @count: the number to be checked
 * @file: the pointer to be checked
 * Return: no return
 */

int execute(char *cont, stack_t **main, unsigned int count, FILE *file)
{
	instruction_t opstf[] = {
		{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
		{"pop", func_pop}, {"swap", func_swap}, {"add", func_add},
		{"nop", func_nop}, {"sub", func_sub}, {"div", func_div},
		{"mul", func_mul}, {"mod", func_mod}, {"pchar", func_pchar},
		{"pstr", func_pstr}, {"rotl", func_rotl}, {"rotr", func_rotr},
		{"stack", func_stack}, {"queue", func_queue},
		{NULL, NULL}
	};

	unsigned int x = 0;
	char *opx;

	opx = strtok(cont, " \n\t");

	if (opx && opx[0] == '#')
	{
		return (0);
	}
	bovalue.args = strtok(NULL, " \n\t");
	while (opstf[x].opcode && opx)
	{
		if (strcmp(opx, opstf[x].opcode) == 0)
		{
			opstf[x].f(main, count);

			return (0);
		}
		x++;
	}
	if (opx && opstf[x].opcode == NULL)
	{

		fprintf(stderr, "L%d: unknown instruction %s\n", count, opx);
		fclose(file);
		free(cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	return (1);
}
