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
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = NULL;

	if (*stack)
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		new->prev = *stack;
		(*stack)->next = new;
	} else
	{
		new->prev = NULL;
		*stack = new;
	}
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
	if (*stack)
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		for ( ; *stack; *stack = (*stack)->prev)
			printf("%d\n", (*stack)->n);
	}
}
