#include "monty.h"

/**
 * _sub - subtracts the top from the second top
 * @stack: is the pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	int total;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = curr->next->n - curr->n;
	curr->next->n = total;
	_pop(stack, line_number);
}
