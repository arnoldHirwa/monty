#include "monty.h"

/**
* _stack - reverse the stack to the bottom
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void _stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *last;


	(void)line_number;
	(void)stack;
	if (info.size < 2)
		return;

	current = *stack;
	last = *stack;
	while (current->next)
		current = current->next;

	current->prev->next = NULL;
	last->prev = current;
	current->next = last;
	current->prev = NULL;

	*stack = current;
}


/**
* queue - reverse the stack to the bottom
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *last;


	(void)line_number;
	(void)stack;
	if (info.size < 2)
		return;

	current = *stack;
	last = *stack;
	while (current->next)
		current = current->next;

	current->prev->next = NULL;
	last->prev = current;
	current->next = last;
	current->prev = NULL;

	*stack = current;
}
