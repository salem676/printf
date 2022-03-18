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
int printeger(int num1)
{
	int figures;
	long int num = num1; 
	/*
	 * @figures: figures of number.
	 */
	figures = figuresf(num);
	if (num < 0)
	{
		_putchar('-');
		num = num * (-1);
		figures++;
	}
	if (num >= 10)
	{
		printeger(num / 10);
	}
	_putchar((num % 10) + '0');
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
