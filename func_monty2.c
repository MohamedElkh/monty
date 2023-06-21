#include "monty.h"

/**
  *func_sub- function to sustration
  *@main: the stack head
  *@count: the line_number
  *Return: no return
 */
void func_sub(stack_t **main, unsigned int count)
{
	stack_t *aux;
	int su;
	int node;

	aux = *main;

	for (node = 0; aux != NULL; node++)
	{
		aux = aux->next;
	}
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	aux = *main;
	su = aux->next->n - aux->n;
	aux->next->n = su;

	*main = aux->next;
	free(aux);
}

/**
 * func_div - function divides the top two elements of the stack.
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/

void func_div(stack_t **main, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}

	hx = *main;

	if (hx->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	aux = hx->next->n / hx->n;
	hx->next->n = aux;
	*main = hx->next;
	free(hx);
}

/**
 * func_mul - func to multiplies the top two elements of the stack.
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/

void func_mul(stack_t **main, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}

	hx = *main;
	aux = hx->next->n * hx->n;
	hx->next->n = aux;

	*main = hx->next;
	free(hx);
}

/**
 * func_mod - func to computes the rest of the division
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/

void func_mod(stack_t **main, unsigned int count)
{
	stack_t *hx;
	int len = 0;
	int aux;

	hx = *main;
	while (hx)
	{
		hx = hx->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}

	hx = *main;

	if (hx->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	aux = hx->next->n % hx->n;
	hx->next->n = aux;
	*main = hx->next;
	free(hx);
}
