/*
 * File: printf_0.c
 * Author: salem676/katiacorona
 */
#include "main.h"
/**
 * get_print_func - selects case printed.
 * @c: pointer to constant char.
 * Description: this functions selects the case printed.
 * Return: pointer to functions for print case .
 */
int (*get_print_func(const char *c))(va_list)
{
	print_t format[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_prc},
		{"i", print_i},
		{"d", print_i},
		/*
		*{"b", print_b},
		*{"r", print_r},
		*{"u", print_u},
		*{"o", print_o},
		*{"x", print_x},
		*{"X", print_X},
		*/
		{NULL, NULL}
	};
	unsigned int index = 0;
	/*
	 * @format: list that holds print cases.
	 * @index: functions as index for format.
	 */
	while (format[index].option)
	{
		if (*(format[index].option) == *c)
			return (format[index].f);
		index++;
	}
	return (NULL);
}
/* function that prints everything */
/**
 * _printf - prints type.
 * @format: format character pointer to char..
 * Description: prints determined format.
 * Return: integer with size of thing to print.
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int (*print_func)(va_list);
	int index = 0, counter = 0;
	/*
	 * @arguments: are the arguments for list.
	 * @print_func: pointer to function returns int.
	 * @index: counter; @counter: same.
	 */
	va_start(arguments, format);
	if (format == NULL)
		return (-1);
	while (format[index] != '\0')
	{
		while (format[index] != '%' && format[index] != '\0')
		{
			_putchar(format[index]);
			counter++;
			index++;
		}
		print_func = get_print_func(&format[index + 1]);
		if (format[index] == '%')
		{
			if (print_func != NULL)
				counter += print_func(arguments);
			else
			{
				if (format[index + 1] == '\0')
					return (-1);
				_putchar(format[index]);
				_putchar(format[index + 1]);
				counter += 2;
			}
			index += 2;
			continue;
		}
	}
	va_end(arguments);
	return (counter);
}
