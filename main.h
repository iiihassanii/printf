#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/*functions*/
void _simple_write(int fd, const char *str, int len);
void print_string(int fd, const char *str, int *written_chars);
void print_percent(int fd, int *written_chars);
void print_number(int fd, int num, int *written_chars);
void handle_specifiers(int fd, char specifier,
		va_list args, int *written_chars);
int _printf(const char *format, ...);
#endif
