#include "main.h"

/**
 * _simple_write - simil print
 * @fd: file descriptor
 * @str: string we wanna print
 * @len: lenght
 * Return: VOID
 */
void _simple_write(int fd, const char *str, int len)
{
	write(fd, str, len);
}

/**
 * handle_specifiers - handle specifier charctar
 * @fd: file descriptor
 * @specifier: specifier charctar
 * @args: location of the char
 * @written_chars: return value
 * Return: written charctars
 */


void handle_specifiers(int fd, char specifier,
		va_list args, int *written_chars)
{
	char buffer[BUFFER_SIZE];
	/* Buffer to store the formatted string */
	int buffer_index = 0;

	switch (specifier)
	{
	case 'c':
		char c = (char)va_arg(args, int);

		_simple_write(fd, &c, 1); /*print only 1 char */
		*written_chars += 1;
		break;
	case 's':
		char *str = va_arg(args, char *);

		print_string(fd, str, written_chars);
		break;
	case '%':
		print_percent(fd, written_chars);
		break;
	case 'd':
		int num = va_arg(args, int);

		print_number(fd, num, written_chars);
		break;
	case 'i':
		int num = va_arg(args, int);

		print_number(fd, num, written_chars);
		break;
	default:
		/* Invalid format specifier, ignore and continue */
		char invalid_specifier[3] = {'%', specifier, '\0'};

		_simple_write(fd, invalid_specifier, 2);
		*written_chars += 2;
		break;
	}
}

/**
 * _printf - similler printf function
 * @format: specifies the necessary operations
 * Return: written charctars
 */

int _printf(const char *format, ...)
{
	/*check if format is NULL*/
	if (format == NULL)
		return (-1);
	va_list args;

	va_start(args, format);
	int written_chars = 0;

	while (*format != '\0')
	{
	if (*format == '%')
	{
	format++;

	/* Handle format specifiers*/
	handle_specifiers(1, *format, args, &written_chars);
	}
	else
	{
	_simple_write(1, format, 1);
	written_chars++;
	}
	format++;
	}
	va_end(args);
	return (written_chars);
}
