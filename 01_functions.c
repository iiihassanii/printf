#include "main.h"

/**
* print_string - handle string print
* @fd: file descriptor
* @str: string we wanna print
* @written_chars: return value
* Return: written charctars
*/

void print_string(int fd, const char *str, int *written_chars)
{
	int len = 0;
	const char *c = str;

	while (*c != '\0')
	{
		len++;
		c++;
	}
	_simple_write(fd, str, len);
	*written_chars += len;
}

/**
* print_percent - handle string print
* @fd: file descriptor
* @written_chars: return value
* Return: written charctars
*/

void print_percent(int fd, int *written_chars)
{
	_simple_write(fd, "%", 1);
	*written_chars += 1;
}
/**
* print_number - handle string print
* @fd: file descriptor
* @num: number we wanna print
* @written_chars: return value
* Return: written charctars
*/

void print_number(int fd, int num, int *written_chars)
{
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int num_copy = num;
	int num_digits = 0;

	if (num < 0)
	{
		buffer[buffer_index++] = '-';
		num_digits++;
		num_copy = -num_copy;
	}
	do {
		buffer[buffer_index++] = '0' + (num_copy % 10);
		num_digits++;
		num_copy /= 10;
	} while (num_copy != 0);

	while (buffer_index > 0)
	{
		_simple_write(fd, &buffer[--buffer_index], 1);
		*written_chars += 1;
	}
}
