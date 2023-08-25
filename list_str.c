#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: is the pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	int chr;

	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	chr = curr->n;
	if (chr >= 65 || chr <= 90 || chr >= 97 || chr <= 122)
	{
		printf("%c\n", chr);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - prints the string starting at the top of the stack
 * followed by a new line
 * @stack: is the pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */
void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	int chr;

	while (curr != NULL)
	{
		chr = curr->n;
		if ((chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122))
		{
			putchar(chr);
		}
		else
		{
			break;
		}
		curr = curr->next;
	}
	printf("\n");
}
