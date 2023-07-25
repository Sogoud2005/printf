#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAM_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
/**
 * struct parameters - parameters struct
 * @unsign: flag if unsign.
 * @plus_flag: on if plus flag
 * @space_flag: on if hashtag_flag
 * @hashtag_flag: on if flag specified
 * @zero_flag: on if _flag
 * @minus_flag: on if minus_flag
 *
 * @width: field width
 * @precision: field precision
 *
 *
 * @h_modifier: on if h_mod.
 * @l_modifier: on if l_mod.
 *
*/
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} param_t;
/**
 * struct specifiers - specifiers struct
 * @specifier: the specifier
 * @f: pointer to function
*/
typedef struct specifiers
{
	char *specifier;
	void (*f)(va_list, param_t *);
} specifiers_t;


/* _puts.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list ap, param_t *params);
int print_int(va_list ap, param_t *params);
int print_string(va_list ap, param_t *params);
int print_percent(va_list ap, param_t *params);
int print_S(va_list ap, param_t *params);

/* number.c */
char *convert(unsigned long int num, int base, int flag, param_t *params);
int print_unsigned(va_list ap, param_t *params);
int print_address(va_list ap, param_t *params);

/* specifier.c */
int (*get_specifier(char *s))(va_list, param_t *);
int get_print_func(char *s, va_list ap, param_t *params);
int get_flag(char *s, param_t *params);
int get_modifier(char *s, param_t *params);
int *get_width(char *s, param_t *params, va_list ap);

/* convert_number.c */
int print_HEX(va_list ap, param_t *params);
int print_hex(va_list ap, param_t *params);
int print_octal(va_list ap, param_t *params);
int print_binary(va_list ap, param_t *params);

/* simple_print.c */
int print_from_to(char *start, char *end, char *except);
int print_rev(va_list ap, param_t *params);
int rot13(va_list ap, param_t *params);

/* print_numbers.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, param_t *params);
int print_number_right_shift(char *str, param_t *params);
int print_number_left_shift(char *str, param_t *params);

/* params.c */
void init_params(param_t *params, va_list ap);

/* string_fields.c */
int *get_precision(char *p, param_t *params);

/* _printf.c */
int _printf(const char *format, ...);

#endif
