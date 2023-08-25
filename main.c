#include "monty.h"

FILE *file = NULL;
void free_all(stack_t **stack);
/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 * Return: Always 0 success
 */
int main(int argc, char *argv[])
{
	char lineptr[SIZE];
	char *token = NULL;
	int line_number = 1;
	instruct result;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(lineptr, SIZE, file) != NULL)
	{
		token = strtok(lineptr, " \n\r\t");
		if (token == NULL || token[0] == '#')
		{
			line_number++;
			continue;
		}

		result = execute_opcodes(token);
		if (result == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_number, token);
			fclose(file);
			exit(EXIT_FAILURE);
		}

		result(&head, line_number);
		line_number++;
	}
	fclose(file);
	free_all(&head);
	return (0);
}


/**
 * free_all - frees the list
 * @stack: is the pointer to the list
 * Return: void
 */
void free_all(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *next = NULL;

	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

