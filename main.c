#include "monty.h"


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
	ssize_t nchars; 
	FILE *file;
	int close_file;

	if (argc != 2)
	{
		dprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file = NULL)
	{
		dprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while (nchars = getline(&lineptr, &n, file) =! -1)
	{
		token = strtok(lineptr, " \n");
		if (token == NULL)
			exit(EXIT_SUCCESS);

		/* call the necessary function */
	}

	free(lineptr);
	close_file = fclose(file);
	if (close_file == -1)
		exit(EXIT_FAILURE);



	return (0);
}
