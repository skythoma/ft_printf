/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:40:49 by skythoma          #+#    #+#             */
/*   Updated: 2019/08/21 10:40:51 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void    get_flags(char *frmat, int *i, t_flags *bin, va_list arg)
{
    *i += 1;
    while (frmat[*i] != '\0' && (frmat[*i] == '-' || frmat[*i] == '+' || frmat[*i] == ' ' || frmat[*i] == '#' || frmat[*i] == '0' || frmat[*i] == '*' || frmat[*i] == 'h' || frmat[*i] == 'l' || frmat[*i] == 'j' || frmat[*i] == 'z' || frmat[*i] >= '0' && frmat[*i] <= '9'))
    {
        all_flags(frmat, i, bin);
        get_width(frmat, i, bin, arg);
        get_prec(frmat, i, bin, arg);
        form_args(frmat, bin, i);
    }
    type(frmat[*i], bin);
}

void    syntax(va_list args, char char_on_str, int *p)
{
    if (char_on_str == 'c')
        ft_printchar(va_arg(args, int), p);
    else if (char_on_str == 'X')
        print_bighex(va_arg(args, unsigned int), p);
    else if (char_on_str == 's')
        print_string(va_arg(args, char *), p);
    else if (char_on_str == 'S')
        print_string(va_arg(args, char *), p);
    else if (char_on_str == 'd' || char_on_str == 'i' || char_on_str == 'D')
        print_integer(va_arg(args, int), p);
    else if (char_on_str == 'u' || char_on_str == 'U')
        put_ulltoa(va_arg(args, unsigned long long), p);
    else if (char_on_str == 'p' || char_on_str == 'P')
    {
        ft_putstr("0x");
        ulltoa_base(va_arg(args, unsigned long long), 16);
    }
    else if (char_on_str == 'o')
        print_octal(va_arg(args, unsigned int), p);
    else if (char_on_str == 'O')
        print_octal(va_arg(args, unsigned int), p);
    else if (char_on_str == 'x')
        print_hex(va_arg(args, unsigned int), p);
    else if (char_on_str == '%')
        ft_printchar((int)'%', p);
    //else if (char_on_str == 'f')
      //  print_float(va_arg(args, double), p);
}

int ft_printf(const char* format, ...)
{
    int     char_count;
    int     start;
    int     i;
    int     len;
    int     *lenp;

    va_list  args;        /* basically a pointer to an argument in variadic-arg array */

    i = 0;
    start = 0;
    char_count = 0;
    len = 0;
    lenp = &len;

    va_start(args, format); /* "args" points at the first variadic-arg */

    while (format[i])
    {
        if (format[i] != '%')
            print(start, i, format);
        else
        {
            i++;
            syntax(args, format[i], len);
        }
        i++;
    }
    va_end(args);
    return (char_count);
}