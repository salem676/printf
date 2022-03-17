/*
 * File: printf_1.c
 * Author: salem676/katiacorona
 * Description: contains _putchar, prin_c
 * print_s and print_prc functions.
 */
#include "main.h"
/**
 * _putchar - selects case printed.
 * @c: char to print.
 * Description: implements putchar with write func.
 * Return: printing of value by write.
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
/**
 * print_c - prints char.
 * @args: next argument.
 * Description: prints next argument with _putchar.
 * Return: integer value with _putchar.
 */
int print_c(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
/**
 * print_s - prints string.
 * @args: next argument.
 * Description: prints next argument string.
 * Return: integer value with _putchar.
 */
int print_s(va_list args)
{
	int counter = 0;
	char *dummy = va_arg(args, char*);
	/*
	 * @counter: serves as itself.
	 * @dummy: ptr to char temp variable.
	 */
	while (dummy[counter] != '\0')
	{
		_putchar(dummy[counter]);
		counter++;
	}
	return (counter);
}
/**
 * print_prc - prints %.
 * @args: destined string.
 * Description: receives args and prints %.
 * Return: printing by _putchar.
 */
int print_prc(va_list args)
{
	return (_putchar('%'));
}
