/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:16:33 by skythoma          #+#    #+#             */
/*   Updated: 2019/08/20 12:16:44 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSIONS
# define FLAGS "+- #0"
# define PLUSFLAG '+'       
# define MINUSFLAG '-' /* left justiy */
# define SPACEFLAG ' '
# define HASHFLAG '#'
# define ZEROFLAG '0'
# define DIGITS "0123456789"
//# define PRECISION_DOT '.'

# define  TYPE       bin->type
# define  PRECISION_DOT  bin->precision_dot
# define  PRECISION      bin->precision
# define  STAR          bin->star
# define  WIDTH         bin->width
# define  ARGS          bin->args      


#include "libft/libft.h"
#include <stdarg.h> /* for variadic arguments */
#include <stdio.h>
#include <stdint.h>
#include <wchar.h> /* for wide characters + wide integer */
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct them_flags /* all me flegs */
{
    bool     p_flag; /* '+' flag */
    bool     min_flag; /* '-' flag */
    bool     spce_flag; /* ' ' flag */
    bool     hash_flg; /* '#' flag */
    bool     zero_flag; /* '0' flag */
    bool     precision;
    bool     star;  /* '*' */
    int      precision_dot;
    int      width;
    int      args;
    int      ret;
    int      len;
    char     type;
}   t_flags;


typedef struct  d_arg
{
    t_flags *flags;
    va_list args;


} t_arg;

int                 ft_printf(const char* format, ...);
char                *str_parse(char **str);
int                 variablelen(char *str);
int                 spec_char_len(char *str, char c);
void                print_hex(unsigned int n, int *p);
void                print_bighex(unsigned int n, int *p);
void	            ft_putstrf(char const *str, int *p);
void                ultoa_base(unsigned long num, int base, int *lenptr);
void                print_integer(int i, int *lenptr);
void                syntax(va_list args, char char_on_str, int *p);
void                all_flags(char *frmat, int *i, t_flags *lwii);
void                make_bin(t_flags *bin);
void                get_prec(char *format, int *i, t_flags *bin, va_list args);
void                get_width(char *format, int *i, t_flags *bin, va_list args);
void                type(char c, t_flags *bin);
void                make_bin(t_flags *bin);
void                get_flags(char *frmat, int *i, t_flags *bin, va_list arg);
void                syntax(va_list args, char char_on_str, int *p);
void                print(int start, int end, char *format);
void                print_format(char f);
void                print_str(char *s, int *p);
void                print_octal(unsigned int n, int *p);
void                print_integer(int i, int *lenptr);
void                ultoa_base(unsigned long num, int base, int *lenptr);
char                *ft_itoa_base(int value, int base);

#endif