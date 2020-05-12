#include <unistd.h>

/**
* _putchar - function that acts as putchar
* @x: Character to print
*
* Return: 1 on success, -1 on failure.
*/

int _putchar(char x)
{
	return (write(1, &x, 1));
}
