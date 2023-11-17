#include "monty.h"

/**
* handle_cmd - return a specific function based on the read line
* @buf: A buffer which contains command
* @stack: A structure of the stack
* @line: line number of the command
*
* Return: 0 on success, 1 on failure
*/
int handle_cmd(char *buf, stack_t **stack, int line)
{
	char *token, *sep = "\n\t\r ", *opc;
	int n;

	instruction_t findFx[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pchar", pchar},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"mod", mod},
		{"nop", nop}, {"div", _div}, {"sub", sub}, {"mul", mul},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {"stack", _stack},
		{"queue", queue},
		{NULL, NULL}
	};
	token = strtok(buf, sep);
	if (!token || (token && '#' == token[0]))
	{
		nop(stack, line);
		return (0);
	}
	for (n = 0; findFx[n].opcode; n++)
	{
		opc = findFx[n].opcode;
		if (strcmp(opc, token) == 0)
		{
			if (strcmp(token, "push") == 0)
				return (verify_number(token, stack, line));

			else
				findFx[n].f(stack, line);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
	return (1);
}
