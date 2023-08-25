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

/**
 * _div - divides the second top by the top
 * @stack: is the pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int total;

	stack_t *curr = *stack;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = curr->next->n / curr->n;
	curr->next->n = total;
	_pop(stack, line_number);
}

/**
 * _mul - multiplies the second top by the top
 * @stack: is the pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	int total;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = curr->n * curr->next->n;
	curr->next->n = total;
	_pop(stack, line_number);
}

/**
 * _mod - remainder of dividing the second top by the top
 * @stack: is the pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int total;

	stack_t *curr = *stack;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = curr->next->n % curr->n;
	curr->next->n = total;
	_pop(stack, line_number);
}
