#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * _puts - prints a string
 * @str: the string
 * Return: 0
*/
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}
/**
 * _putchar - prints a character
 * @c: ascii
 * Return: 0
*/
int _putchar(char c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
