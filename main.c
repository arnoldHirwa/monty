#include "monty.h"

/**
* main - Entry point of monty function
* @argc: Amount of arguments passed to the function
* @argv: Array of arguments
*
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	FILE *fp;
	char buffer[1024];
	stack_l *stack = NULL;
	int ln = 1;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for ( ; fgets(buffer, sizeof(buffer), fp) != NULL; ln++)
	{
		/* printf("%s", buffer); */
		handle_cmd(buffer, &stack, ln);
	}

	free_dlistint(stack);
	return (0);
}
