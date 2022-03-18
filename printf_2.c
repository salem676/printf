/*
 * File: printf_2.c
 * Author salem676/katiacorona
 */
#include main.h
/**
 * figuresf - takes an integer as input and counts the digits.
 * @num: the number taken as input.
 * Description: this functions counts figures in number.
 * Return: returns the number of digits.
 */
int figuresf(int num)
{
	int count = 0;
	/*
	 * @count: -.
	 */
	while (num != 0)
	{
		num = (num / 10);
		count++;
	}
	return (count);
}
/**
 * printeger - takes an int as input and formats as negative or positive.
 * @num: the number taken as input.
 * Description: as above.
 * Return: the number of digits that will be printed out.
 */
int printeger(int num)
{
	int figures;
	long int num1 = num;
	/*
	 * @figures: figures of number.
	 */
	figures = figuresf(num1);
	if (num1 < 0)
	{
		_putchar('-');
		num1 = num1 * (-1);
		figures++;
	}
	if (num1 >= 10)
	{
		printeger(num1 / 10);
	}
	_putchar((num1 % 10) + '0');
	return (figures);
}
/**
 * print_i - takes a variadic argument as input and prints it as an integer.
 * @args: a variadic argument to be printed as an integer.
 * Description: this prints integer values.
 * Return: the number of characters printed.
 */
int print_i(va_list args)
{
	int counter = 0;
	int dummy = va_arg(args, int);
	/*
	 * @counter: -.
	 * @dummy: dummy variable for next argument.
	 */
	if (dummy == 0)
	{
		_putchar('0');
	return (1);
	}
	counter += printeger(dummy);
	return (counter);
}
