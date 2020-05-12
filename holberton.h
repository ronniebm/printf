#ifndef _PRINTFFUNC_
#define _PRINTFFUNC_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct call - structure used in printf function.
 * @character: parameter used for pointer char.
 * @ptrfunc: parameter used for function type.
 */
typedef struct call
{
	char *character;
	int (*ptrfunc)(va_list args);
} caller;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_di(va_list args);
int _putchar(char x);
int auxiliar(const char *format, va_list args, caller *functions);

#endif
