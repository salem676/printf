#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/* struct definition */
typedef struct print
{
    char *option;
    int (*f)(va_list);
} print_t;
/* Prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list);
int (*get_print_func(const char *c))(va_list);
int print_s(va_list args);
int print_prc(va_list args);
int figuresf(int num);
int printeger(int num);
int print_i(va_list args);


#endif /* MAIN_H */
