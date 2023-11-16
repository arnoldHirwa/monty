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


/**
* sub - Subtracts the top two items in the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void sub(stack_t **stack, unsigned int line_number)
{
	int first;

	(void)line_number;
	(void)stack;

	if (info.size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	first = info.top->n;
	info.top->next->n -= first;
	pop(stack, line_number);
}

/**
* _div - divides the top two items in the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void _div(stack_t **stack, unsigned int line_number)
{
	int first;

	(void)line_number;
	(void)stack;

	if (info.size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	first = info.top->n;
	if (first == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	info.top->next->n /= first;
	pop(stack, line_number);
}


/**
* mul - multiplies the top two items in the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void mul(stack_t **stack, unsigned int line_number)
{
	int first;

	(void)line_number;
	(void)stack;

	if (info.size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	first = info.top->n;
	info.top->next->n *= first;
	pop(stack, line_number);
}
