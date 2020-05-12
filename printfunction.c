#include "holberton.h"
/**
 * _printf - print all types.
 * @format: pointer to a string.
 * Return: an integer.
 */
int _printf(const char *format, ...)
{
	va_list list;
	int k;

	caller functions[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_di},
		{"i", print_di},
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);
		k = auxiliar(format, list, functions);
	va_end(list);
	return (k);
}

/**
 * auxiliar - it returns a string to _printf function.
 * @format: the string passed.
 * @args: arguments passed.
 * @functions: a pointer to a struct.
 * Return: an integer.
 */
int auxiliar(const char *format, va_list args, caller *functions)
{
	int i = 0, j = 0, k = 0;

	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && (format[i + 1] == ' ' || format[i + 1] != '%'))
		{
			if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
					i++;
			}
			while (j < 4)
			{
				if (format[i + 1] == functions[j].character[0])
				{
					k += functions[j].ptrfunc(args);
					i++;
					break;
				} j++;
			}
			if (j == 4)
				k += _putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			k += _putchar('%');
			i++;
		}
		else
		{
			k += _putchar(format[i]);
		}
		j = 0, i++;
	}
	return (k);
}
