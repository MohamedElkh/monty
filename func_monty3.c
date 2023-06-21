#include "monty.h"

/**
 * func_pchar - function to prints the char at the top of the stack
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/
void func_pchar(stack_t **main, unsigned int count)
{
	stack_t *hx;

	hx = *main;

	if (!hx)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}
	if (hx->n > 127 || hx->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bovalue.file);

		free(bovalue.cont);
		free_stack(*main);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", hx->n);
}

/**
 * func_pstr - func prints the string starting at the top of the stack
 * @main: the stack head
 * @count: the line_number
 * Return: no return
*/
void func_pstr(stack_t **main, unsigned int count)
{
	stack_t *hx;
	(void)count;

	hx = *main;

	while (hx)
	{
		if (hx->n > 127 || hx->n <= 0)
		{
			break;
		}

		printf("%c", hx->n);
		hx = hx->next;
	}

	printf("\n");
}

/**
  *func_rotl- function to rotates the stack to the top
  *@main: the stack head
  *@count: the line_number
  *Return: no return
 */
void func_rotl(stack_t **main,  __attribute__((unused)) unsigned int count)
{
	stack_t *temp = *main;
	stack_t *aux;

	if (*main == NULL || (*main)->next == NULL)
	{
		return;
	}

	aux = (*main)->next;
	aux->prev = NULL;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *main;
	(*main)->next = NULL;
	(*main)->prev = temp;
	(*main) = aux;
}

/**
  *func_rotr- func rotates the stack to the bottom
  *@main: the stack head
  *@count: the line_number
  *Return: no return
 */
void func_rotr(stack_t **main, __attribute__((unused)) unsigned int count)
{
	stack_t *cpy;

	cpy = *main;

	if (*main == NULL || (*main)->next == NULL)
	{
		return;
	}

	while (cpy->next)
	{
		cpy = cpy->next;
	}

	cpy->next = *main;
	cpy->prev->next = NULL;
	cpy->prev = NULL;

	(*main)->prev = cpy;
	(*main) = cpy;
}
