#include <stdio.h>
#include <stdarg.h>

void print_char(va_list arg);
int print_string(va_list arg);

/**
 * _printf-printf replica
 * @format: format specifier
 * Return: count of printed objects
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char(args);
					count++;
					break;
				case 's':
					count = print_string(args);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * print_char - Prints a char.
 * @arg: A list of arguments pointing to
 *       the character to be printed.
 * Return: n/a
 */
void print_char(va_list arg)
{
	char letter;

	letter = va_arg(arg, int);
	putchar(letter);
}

/**
 * print_string - Prints a string.
 * @arg: A list of arguments pointing to
 *       the string to be printed.
 * Return: count of objs
 */
int print_string(va_list arg)
{
	char *str, *n = "(nil)";
	int count = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		while (*n != '\0')
		{
			putchar(*n);
			n++;
		}
	}
	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}

	return (count);
}
