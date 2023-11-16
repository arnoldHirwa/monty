#ifndef MONTY_H
#define MONTY_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

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
 * struct info_s - keep track of global variables
 * @fp: file descriptor of a file to be opened
 * @top: data at the top of stack
 * @size: amount of nodes in the stack
 * Description: use if to keep file descriptors and other
 * global variables.
*/
typedef struct info_s
{
	FILE *fp;
	stack_t *top;
	int size;
} info_t;
info_t info;
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
		void (*f)(stack_t **, unsigned int);
} instruction_t;


int handle_cmd(char *, stack_t **, int ln);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void free_dlistint(stack_t *head);
int _isdigit(char *);
void fs_close(int status, void *arg);
size_t num_len(int num);
int verify_number(char *, stack_t **, int);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

#endif /*ifndef MONTY_H*/
