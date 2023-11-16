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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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


/**
* pchar - prints char represented by the ascii at the top
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	int first;

	(void)line_number;
	(void)stack;

	if (info.size == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	first = info.top->n;
	if (first <= 127 && first >= 0)
	{
		printf("%c\n", (char)first);
	} else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
* pstr - prints string represented by the ascii
* of the stack starting from the top
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	int first;
	stack_t *current;

	(void)line_number;
	(void)stack;

	if (info.size == 0)
	{
		putchar('\n');
	} else
	{
		current = info.top;
		for (; current != NULL; current = current->next)
		{
			first = current->n;
			if (first <= 127 && first > 0)
			{
				printf("%c", (char)first);
			} else
			{
				break;
			}
		}
		putchar('\n');
	}
}


/**
* rotl - reverse the stack to the top
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *sec;


	(void)line_number;
	(void)stack;
	if (info.size < 2)
		return;

	current = *stack;
	sec = current->next;
	sec->prev = NULL;
	while (current->next)
		current = current->next;

	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current;

	while ((*stack)->prev)
		*stack = (*stack)->prev;
}


/**
* rotr - reverse the stack to the bottom
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void rotr(stack_t **stack, unsigned int line_number)
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
