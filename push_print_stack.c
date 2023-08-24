#include "monty.h"

/**
 * _push - is for pushing to the stack
 * @stack: is the pointer to the list
 * @line_number: the line where the opcode is in the file
 */

void _push(stack_t **stack, unsigned int line_number)
{

	int num_token;
	char *token;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \n");
	if (token != NULL && _isnumeric(token) == 1)
	{
		num_token = atoi(token);
	}

	else
	{
		printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
	}

	new_node->n = num_token;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;

}

/**
 * _pall - print the values in the list
 * @stack: is the pointer to the list
 * @line_number: the line where the opcode is in the file
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *curr = *stack;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}


/**
 * _isnumeric - checks whether a given string is numeric
 * @str: is the input string
 * Return: 1 if str is numeric else 0
 */

int _isnumeric(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}

		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

