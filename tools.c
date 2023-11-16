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
	fclose(info.fp);
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

/**
 * num_len -  count how many charachter in number
 * @num: number
 * Return: the number lentgh
 */
size_t num_len(int num)
{
	int len = 0;

	if (!num)
		return (1);
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
 * verify_number -  verify is number for push opcode
 * is valid or not
 * @token: token string
 * Return: 1 on success, 0 otherwise
 */
int verify_number(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == num_len(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		return (1);

	return (0);
}
