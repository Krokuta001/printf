#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list print_args;
	char *next_str;
	int add_chars = 0, length = 0;

	va_start(print_args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = va_arg(print_args, int);

				write(1, &c, 1);
				add_chars++;
			}
			else if (*format == '%')
				write(1, format, (add_chars++, 1));
			else if (*format == 's')
			{
				next_str = va_arg(print_args, char *);
				length = strlen(next_str);
				write(1, next_str, (add_chars += length, length));
			}
		}
		else
		{
			write(1, format, 1);
			add_chars++;
			format++;
		}
		format++;
	}
		va_end(print_args);
		return (add_chars);
}
