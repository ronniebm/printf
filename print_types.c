#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *print_c - print a character.
 *@args: arguments.
 *Return: a integer.
 */
int print_c(va_list args)
{
	char c;

	c = (va_arg(args, int));
	_putchar(c);
	return (1);
}


/**
 *print_s - print a string.
 *@args: arguments.
 *Return: a integer.
 */
int print_s(va_list args)
{
	char *s;
	unsigned int i;

	i = 0;
	s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";
	}
	for (i = 0; s[i]; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * print_di - function parameter to print a digit.
 * @args: parameter to print a digit.
 * Return: returns a string.
 */
int print_di(va_list args)
{
	int n = va_arg(args, int);
	int end = n % 10;
	int exp = 1;
	int i = 1;
	int num, dec;

	n = n / 10;
	num = n;

	if (end < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		end = -end;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dec = num / exp;
			_putchar(dec + '0');
			num = num - (dec * exp);
			exp = exp / 10;
			i++;
		}
	}

	_putchar(end + '0');

	return (i);
}
