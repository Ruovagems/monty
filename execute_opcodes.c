#include "monty.h"

/**
 * execute_opcodes - it executes the opcodes
 * @str: is the input opcode
 * Return: the correct function depending on input
 */

instruct execute_opcodes(char *str)
{
	int i;
	instruction_t opt[] = {
		{"push", _push},
		{NULL, NULL}
	};
	i = 0;

	while (opt[i].f != NULL && strcmp(opt[i].opcode, str) != 0)
		i++;
	return (opt[i].f);
	
	
}
