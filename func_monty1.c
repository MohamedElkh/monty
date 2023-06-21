#include "monty.h"
/**
 * func_pop - function to prints the top
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/
void func_pop(stack_t **main, unsigned int count)
{
	stack_t *hx;

	if (*main == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	hx = *main;
	*main = hx->next;
	free(hx);
}

/**
 * func_swap - function to adds the top two elements of the stack.
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/
void func_swap(stack_t **main, unsigned int count)
{
	stack_t *hx;
	int le = 0;
	int aux;

	hx = *main;
	while (hx)
	{
		hx = hx->next;
		le++;
	}
	if (le < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}

	hx = *main;
	aux = hx->n;
	hx->n = hx->next->n;
	hx->next->n = aux;
}

/**
 * func_add - function to adds the top two elements of the stack.
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/
void func_add(stack_t **main, unsigned int count)
{
	stack_t *hx;
	int le = 0;
	int ax;

	hx = *main;
	while (hx)
	{
		hx = hx->next;
		le++;
	}
	if (le < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	hx = *main;
	ax = hx->n + hx->next->n;

	hx->next->n = ax;
	*main = hx->next;
	free(hx);
}

/**
  *func_nop - function print nothing
  *@main: the stack head
  *@count: the line_number
  *Return: no return
 */
void func_nop(stack_t **main, unsigned int count)
{
	(void) main;
	(void) count;
}
