#include "main.h"

/**
 * get_bit - Gets the value number of a bit at a index.
 * @n: The bits.
 * @index: The index to get the value at - indices start at 0.
 * Return: If an error occurs - -1. otherwise - The value of bit at index.
 *
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
