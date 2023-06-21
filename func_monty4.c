#include "monty.h"

/**
 * addqueue - func to add node to the tail stack
 * @main: the head of the stack
 * @n: the new_value
 * Return: no return
 */

void addqueue(stack_t **main, int n)
{
	stack_t *newnode;
	stack_t *ax;

	ax = *main;

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		printf("Error\n");
	}

	newnode->n = n;
	newnode->next = NULL;

	if (ax)
	{
		while (ax->next)
		{
			ax = ax->next;
		}
	}

	if (!ax)
	{
		*main = newnode;

		newnode->prev = NULL;
	}
	else
	{
		ax->next = newnode;
		newnode->prev = ax;
	}
}

/**
 * func_queue - funct to funct to prints the top
 * @main: the stack head
 * @count: the line_number
 * Return: no return
 */

void func_queue(stack_t **main, unsigned int count)
{
	(void)main;
	(void)count;
	bovalue.lifev = 1;
}

/**
 * func_stack - func to prints the top
 * @main: the stack head
 * @count: the line_number
 * Return: no return
 */

void func_stack(stack_t **main, unsigned int count)
{
	(void)main;
	(void)count;
	bovalue.lifev = 0;
}

/**
 * addnode - func to add node to the head stack
 * @main: the head of the stack
 * @n: the new_value
 * Return: no return
 */
void addnode(stack_t **main, int n)
{

	stack_t *newnode;
	stack_t *aux;

	aux = *main;

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (aux)
	{
		aux->prev = newnode;
	}

	newnode->n = n;
	newnode->next = *main;

	newnode->prev = NULL;
	*main = newnode;
}
