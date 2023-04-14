#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: the number of letters printed, or 0 if it failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int op;
	int rd;
	int wr;
	char *bufr;

	if (!filename)
		return (0);

	op = open(filename, O_RDONLY);
	if (op < 0)
		return (0);

	bufr = malloc(sizeof(char) * letters);
	if (!bufr)
		return (0);

	rd = read(op, bufr, letters);
	if (rd < 0)
	{
		free(bufr);
		return (0);
	}
	bufr[rd] = '\0';

	close(op);

	wr = write(STDOUT_FILENO, bufr, rd);
	if (wr < 0)
	{
		free(bufr);
		return (0);
	}

	free(bufr);
	return (wr);
}
