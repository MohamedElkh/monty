#include "monty.h"
/**
 * func_push - function to add node to the stack
 * @main: the stack head
 * @count: theline_number
 * Return: no return
 */

void func_push(stack_t **main, unsigned int count)
{
	int num, x = 0;
	int flg = 0;

	if (bovalue.args)
	{
		if (bovalue.args[0] == '-')
		{
			x++;
		}
		for (; bovalue.args[x] != '\0'; x++)
		{
			if (bovalue.args[x] > 57 || bovalue.args[x] < 48)
			{
				flg = 1;
			}
		}
		if (flg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bovalue.file);

			free(bovalue.cont);
			free_stack(*main);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bovalue.file);
		free(bovalue.cont);

		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	num = atoi(bovalue.args);
	if (bovalue.lifev == 0)
		addnode(main, num);
	else
		addqueue(main, num);
}

/**
 * func_pall - function to prints the stack
 * @main: the stack head
 * @count: will not used
 * Return: no return
 */

void func_pall(stack_t **main, unsigned int count)
{
	stack_t *hx;
	(void)count;

	hx = *main;

	if (hx == NULL)
	{
		return;
	}
	while (hx)
	{
		printf("%d\n", hx->n);
		hx = hx->next;
	}
}

/**
 * func_pint - function prints the top
 * @main: stack head
 * @count: line_number
 * Return: no return
 */

void func_pint(stack_t **main, unsigned int count)
{
	if (*main == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bovalue.file);
		free(bovalue.cont);

		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*main)->n);
}
