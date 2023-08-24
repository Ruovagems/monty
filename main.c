#include "monty.h"

void free_all(stack_t **stack);
/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 * Return: Always 0 success
 */
int main(int argc, char *argv[])
{
	char *lineptr = NULL, *token = NULL;
	size_t n = 0;
	FILE *file;
	ssize_t nchars;
	int line_number = 1;
	instruct result;
	stack_t *stack = NULL;

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
	while ((nchars = getline(&lineptr, &n, file)) != -1)
	{
		token = strtok(lineptr, " \n");
		if (token == NULL)
		{
			line_number++;
			continue;
		}
		result = execute_opcodes(token);
		if (result == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_number, token);
			free(lineptr);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free(lineptr);
	fclose(file);
	free_all(&stack);
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
