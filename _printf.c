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
	char c, *str;
	char invalid_specifier[3];
	/* Buffer to store the formatted string */
	int num;
	/*hey */
	invalid_specifier[0] = '%';
	invalid_specifier[1] = specifier;
	invalid_specifier[2] = '\0';
	switch (specifier)
	{
	case 'c':
		c = (char)va_arg(args, int);
		_simple_write(fd, &c, 1); /*print only 1 char */
		*written_chars += 1;
		break;
	case 's':
		str = va_arg(args, char *);
		print_string(fd, str, written_chars);
		break;
	case '%':
		print_percent(fd, written_chars);
		break;
	case 'd':
		num = va_arg(args, int);

		print_number(fd, num, written_chars);
		break;
	case 'i':
		num = va_arg(args, int);
		print_number(fd, num, written_chars);
		break;
	default:
		_simple_write(fd, invalid_specifier, 2);
		*written_chars += 2;
		break;
	}
}
/**
 * handle_specifiers_2 - handle specifier charctar
 * @fd: file descriptor
 * @specifier: specifier charctar
 * @args: location of the char
 * @written_chars: return value
 * Return: written charctars
 */


void handle_specifiers_2(int fd, char specifier, va_list args, int *written_chars)
{
	char c, *str;
	char invalid_specifier[3];
	/* Buffer to store the formatted string */
	int num;
	/*hey */
	invalid_specifier[0] = '%';
	invalid_specifier[1] = specifier;
	invalid_specifier[2] = '\0';
    switch (specifier)
	{
	case 'r':
		str = va_arg(args, char *);
		print_string_re(fd, str, written_chars);
	break;
	default:
		char invalid_specifier[3] = {'%', specifier, '\0'};
		_simple_write(fd, invalid_specifier, 2);
		*written_chars += 2;
	break;
	}
}
