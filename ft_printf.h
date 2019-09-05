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
# define MINUSFLAG '-'
# define SPACEFLAG ' '
# define HASHFLAG '#'
# define ZEROFLAG '0'
# define DIGITS "0123456789"
# define PRECISION_DOT '.'
# define MODIFIERS "hljz"
# define H_MOD  

#include "libft/libft.h"
#include <stdarg.h> /* for variadic arguments */
#include <stdio.h>
#include <stdint.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

typedef struct them_flags /* all me flegs */
{
    int     p_flag; /* '+' flag */
    int     min_flag; /* '-' flag */
    int     spce_flag; /* ' ' flag */
    int     hash_flg; /* '#' flag */
    int     zero_flag; /* '0' flag */
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
#endif