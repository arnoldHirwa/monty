#include "monty.h"

/**
* _stack - sets the format to LIFO
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	info.format = STACK_FORMAT;
}

/**
* queue - sets the format to FIFO
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	info.format = QUEUE_FORMAT;
}
