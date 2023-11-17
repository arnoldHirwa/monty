#include "monty.h"
/**
* push - push a number on the top of a stack
* @stack: A struct of the stack
* @line_number: The number to pushed
*
* Return: None
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	(void)stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		info.top = *stack;
	} else if (info.format == STACK_FORMAT)
	{
		new->next = info.top;
		info.top->prev = new;
		*stack = new;
		info.top = new;
	} else
	{
		current = info.top;
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
	info.size++;
}

/**
* pall - Prints the data stored in stack starting from the top
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
* pint - Prints the data stored on the top of the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	if (info.size == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", info.top->n);
}


/**
* pop - Remove the top item
* @head: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}


	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(current);
	info.size--;
	info.top = *head;
}

/**
* swap - Swap the top two items in the stack
* @stack: A struct of stack to be printed
* @line_number: The number of lines read so far
*
* Return: None
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	(void)line_number;
	(void)stack;

	if (info.size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = info.top->n;
	info.top->n = info.top->next->n;
	info.top->next->n = tmp;
}
