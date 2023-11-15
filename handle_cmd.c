#include "monty.h"

/**
* handle_cmd - return a specific function based on the read line
* @buf: A buffer which contains command
* @stack: A structure of the stack
* @line: line number of the command
*
* Return: 0 on success, 1 on failure
*/
int handle_cmd(char *buf, stack_l **stack, int line)
{
	char *token;
	char *sep = "\n\t\r ";
	int n;
	char *opc;
	int line_nbr = 0;

	instruction_t findFx[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	token = strtok(buf, sep);

	for (n = 0; findFx[n].opcode; n++)
	{
		opc = findFx[n].opcode;
		if (strcmp(opc, token) == 0)
		{
			if (strcmp(token, "pall") == 0)
			{
				findFx[n].f(stack, line);
			} else
			{
				token = strtok(NULL, sep);
				if (_isdigit(token) && token)
				{
					line_nbr = atoi(token);
					findFx[n].f(stack, line_nbr);
				} else
				{
					dprintf(STDOUT_FILENO, "L%d: usage: push integer\n", line);
					exit(EXIT_FAILURE);
				}
			}
			return (0);
		}
	}
	dprintf(STDOUT_FILENO, "L%d: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
	return (1);
}
