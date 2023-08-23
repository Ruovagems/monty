#include "monty.h"
#include <stdio.h>
/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector 
 *
 * Return : Always 0 success
 */

int main(int argc, char *argv[])
{
	char *lineptr = NULL, *token = NULL;
	size_t n = 0;
	FILE *file;
	int close_file, line_number = 1;
	instruction_t result;

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


	while (getline(&lineptr, &n, file) != -1)
	{
		token = strtok(lineptr, " \n");
		if (token == NULL)
		{
			line_number++;
			continue;
		}

		/* call the necessary function */
		result = execute_opcodes(token);

		if (result == NULL)
		{
			printf("L%d: unknown instruction %s\n",line_number, token);
			exit(EXIT_FAILURE);
		}

	}

	free(lineptr);
	close_file = fclose(file);
	if (close_file == -1)
		exit(EXIT_FAILURE);



	return (0);
}
