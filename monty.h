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
} stack_l;
/**
 * struct info_s - keep track of global variables
 * @fp: file descriptor of a file to be opened
 *
 * Description: use if to keep file descriptors and other
 * global variables.
*/
typedef struct info_s
{
	FILE *fp;
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
		void (*f)(stack_l **stack, unsigned int line_number);
} instruction_t;


int handle_cmd(char *, stack_l **, int ln);
void push(stack_l **, unsigned int);
void pall(stack_l **, unsigned int);
void free_dlistint(stack_l *head);
int _isdigit(char *);
void fs_close(int status, void *arg);
size_t num_len(int num);
int verify_number(char *token);

#endif /*ifndef MONTY_H*/
