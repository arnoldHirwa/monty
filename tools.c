#include "monty.h"

/**
* free_dlistint - free the linked list of stack
* @head: A node of the list to be released
*
* Return: None
*/
void free_dlistint(stack_l *head)
{
	stack_l *current = head;

	if (head)
	{
		while (head->prev != NULL)
			head = head->prev;
	}

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
* _isdigit - Check if a character is a digit
* @y: The number to be checked
*
* Return: 1 for a character that will be a digit or 0 for any else
*/
int _isdigit(char *y)
{
	int n;

	if (y == NULL)
		return (0);

	for (n = 0; y[n] != '\0'; n++)
	{
		if ((int)y[n] >= 48 && (int)y[n] <= 57)
			continue;
		else
			return (0);
	}

	return (1);
}
