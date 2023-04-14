#include "main.h"

/**
  *err_argc - an argument with errors
  *@argc: number of arguments
  */

void err_argc(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
  *err_close - a close error of a file
  *@fds: the file descriptors
  */

void err_close(int fds)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fds);
	exit(100);
}

/**
  *err_write - a write error of a file
  *@str: the string to be written
  */

void err_write(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
	exit(99);
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: array of pointers to the arguments
 * Return: 0 (Success).
 */
int main(int argc, char **argv)
{
	int fds, fdscp;
	int wr, rd;
	char bufr[1024];

	err_argc(argc);
	fdscp = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fdscp == -1)
		err_write(argv[2]);
	fds = open(argv[1], O_RDONLY);
	if (fds == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fdscp);
		exit(98);
	}
	while ((rd = read(fds, bufr, 1024)) != 0)
	{
		if (rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close(fdscp);
			exit(98);
		}
		wr = write(fdscp, bufr, rd);
		if (wr == -1)
			err_write(argv[2]);
	}
	if (close(fds) == -1)
		err_close(fds);
	else
		close(fds);
	if (close(fdscp) == -1)
		err_close(fdscp);
	else
		close(fdscp);
	return (0);
}
