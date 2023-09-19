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
 * print_string_re - handle string print
 * @fd: file descriptor
 * @str: string we wanna print
 * @written_chars: return value
 * Return: written charctars
 */

void print_string_re(int fd, const char *str, int *written_chars)
{
	char buffer[BUFFER_SIZE];
	unsigned int buffer_index = 0;
	const char *c = str;

	while (*c != '\0')
	{
		buffer[buffer_index++] = *c;
		c++;
	}
	while (buffer_index > 0)
	{
		_simple_write(fd, &buffer[--buffer_index], 1);
		*written_chars += 1;
	}
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
 * *print_int - dwdwd
 * @n: wadadwadd
 * Return: str
 */
char *print_int(int n)
{
	static char buffer[BUFFER_SIZE];

	sprintf(buffer, "%d", n);
	return (buffer);
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
	char *str = print_int(num);
	char *c = str;
	int len = 0;

	while (*c != '\0')
	{
		len++;
		c++;
	}
	_simple_write(fd, str, len);
	*written_chars += len;
}
