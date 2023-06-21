#ifndef _MONTY_H
#define _MONTY_H

#define  _POSIX_C_SOURCE 200809L
#define  _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

/**
 * struct bovalue_s - contain cont, args, file, lifev
 * @cont: the content
 * @args: the value
 * @lifev: the flag to change.
 * @file: the pointer to monty 
 * Description: carries values through the program
 */

typedef struct bovalue_s
{
	char *cont;
	char *args;
	int lifev;
	FILE *file;
}  bovalue_t;

extern bovalue_t bovalue;

/* func_monty1 */
void func_pop(stack_t **main, unsigned int count);
void func_swap(stack_t **main, unsigned int count);
void func_add(stack_t **main, unsigned int count);
void func_nop(stack_t **main, unsigned int count);
/* func_monty2 */
void func_sub(stack_t **main, unsigned int count);
void func_div(stack_t **main, unsigned int count);
void func_mul(stack_t **main, unsigned int count);
void func_mod(stack_t **main, unsigned int count);
/* func_monty3 */
void func_pchar(stack_t **main, unsigned int count);
void func_pstr(stack_t **main, unsigned int count);
void func_rotl(stack_t **main, unsigned int count);
void func_rotr(stack_t **main, unsigned int count);
/* func_monty4 */
void func_queue(stack_t **main, unsigned int count);
void func_stack(stack_t **main, unsigned int count);
void addnode(stack_t **main, int n);
void addqueue(stack_t **main, int n);
/* func_help */
void func_push(stack_t **main, unsigned int count);
void func_pall(stack_t **main, unsigned int count);
void func_pint(stack_t **main, unsigned int count);
/* func_exe */
int execute(char *cont, stack_t **main, unsigned int count, FILE *file);
void free_stack(stack_t *main);
/* here only on monty.h  */
char *_realloc(char *ptr, unsigned int old_value, unsigned int new_value);
ssize_t getstdin(char **linep, int file);
char  *clean_line(char *cont);


#endif
