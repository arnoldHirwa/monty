#include "monty.h"
/**
* push - push a number on the top of a stack
* @stack: A struct of the stack
* @line_number: The number to pushed
*
* Return: None
*/
void push(stack_l **stack, unsigned int line_number)
{
	stack_l *new;

	new = malloc(sizeof(stack_l));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - Prints the data stored in stack starting from the top
 * @stack: A struct of stack to be printed
 * @line_number: The number of lines read so far
 *
 * Return: None
*/

void pall(stack_l **stack, unsigned int line_number __attribute__((unused)))
{
	stack_l *current = *stack;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}
