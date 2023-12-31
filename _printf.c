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
	int num;

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
		if (str == NULL)
			str = "(null)";
		print_string(fd, str, written_chars);
		break;
	case '%':
		print_percent(fd, written_chars);
		break;
	case 'd':
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


void handle_specifiers_2(int fd, char specifier,
		va_list args, int *written_chars)
{
	char *str;
	char invalid_specifier[3];
	void* ptr;

	invalid_specifier[0] = '%';
	invalid_specifier[1] = specifier;
	invalid_specifier[2] = '\0';

	switch (specifier)
	{
		case 'r':
			str = va_arg(args, char *);
			print_string_re(fd, str, written_chars);
			break;
		case 'p':
			ptr = va_arg(args, void*);
			print_pointer(fd, ptr, written_chars);
			break;
		default:
			_simple_write(fd, invalid_specifier, 2);
			*written_chars += 2;
		break;
	}
}

/**
 * print_pointer - pointer print
 * @fd: file descriptor
 * @ptr: pointer
 * @written_chars: return value\
 */

void print_pointer(int fd, void* ptr, int *written_chars)
{
	char buffer[20];
	sprintf(buffer, "%p", ptr);
	_simple_write(fd, buffer, strlen(buffer));
	*written_chars += strlen(buffer);
}

int _printf(const char *format, ...)
{
	/*check if format is NULL*/
	va_list args;
	int written_chars = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format != '\0')
	{
	if (*format == '%')
	{
		format++;
		/*Handle format specifiers*/
		if (*format == 'r' || *format == 'p')
			handle_specifiers_2(1, *format, args, &written_chars);
		else
			handle_specifiers(1, *format, args, &written_chars);
	} else
	{
		_simple_write(1, format, 1);
		written_chars++;
	}
	format++;
	}
	va_end(args);
	return (written_chars);
}

