#include "monty.h"

/**
* add - Adds the top two items in the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void add(stack_t **stack, unsigned int line_number)
{
	int first;

	(void)line_number;
	(void)stack;

	if (info.size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	first = info.top->n;
	info.top->next->n += first;
	pop(stack, line_number);
}

/**
* nop - do nothing
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
