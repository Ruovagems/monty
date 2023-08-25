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
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	i = 0;

	while (opt[i].f != NULL && strcmp(opt[i].opcode, str) != 0)
	{
		i++;
	}

	return (opt[i].f);
}

/**
 * _pop - removes the topmost element
 * @stack: is a pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = (*stack)->next;

	free(*stack);
	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr->prev = NULL;
	*stack = curr;

}

/**
 * _swap - swaps the two topmost elements
 * @stack: is a pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int num;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = curr->n;
	curr->n = curr->next->n;
	curr->next->n = num;
}

/**
 * _add - adds the two topmost elements
 * @stack: is a pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	int total;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = curr->n + curr->next->n;
	curr->next->n = total;
	_pop(stack, line_number);

}

/**
 * _nop - nop doesn’t do anything
 * @stack: is a pointer to the list
 * @line_number: is where the opcode is in the file
 * Return: void
 */

void _nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	;
}
