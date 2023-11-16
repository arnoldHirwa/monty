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
	char buffer[100];
	stack_t *stack = NULL;
	int ln = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.size = 0;
	info.top = NULL;
	info.format = STACK_FORMAT;
	info.fp = fopen(argv[1], "r");
	if (info.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for ( ; fgets(buffer, sizeof(buffer), info.fp) != NULL; ln++)
	{
		/* printf("%s", buffer); */
		handle_cmd(buffer, &stack, ln);
	}

	free_dlistint(stack);
	return (0);
}
