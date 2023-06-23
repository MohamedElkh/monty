#include "monty.h"

bovalue_t bovalue = {NULL, NULL, 0, NULL};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	ssize_t readline = 1;
	size_t val = 0;
	unsigned int count = 0;
	stack_t *stack = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bovalue.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (readline > 0)
	{
		cont = NULL;
		readline = getline(&cont, &val, file);
		bovalue.cont = cont;

		count++;
		if (readline > 0)
		{
			execute(cont, &stack, count, file);
		}

		free(cont);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
