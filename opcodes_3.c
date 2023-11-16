#include "monty.h"

/**
* mod - Find remainder of the division of the second
* by the top item in the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void mod(stack_t **stack, unsigned int line_number)
{
	int first;

	(void)line_number;
	(void)stack;

	if (info.size < 2)
	{
		fprintf(stderr, "L%d: can't modd, stack too short\n", line_number);
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
	info.top->next->n %= first;
	pop(stack, line_number);
}
