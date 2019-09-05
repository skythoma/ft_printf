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

void    syntax(va_list args, char char_on_str, int *p)
{
    if (char_on_str == 'c')
        ft_printchar(va_arg(args, int), p);
    else if (char_on_str == 's')
        ft_printstr(va_arg(args, char *), p);
    else if (char_on_str == 'd' || char_on_str == 'i')
        print_integer(va_arg(args, int), p);
    else if (char_on_str == 'u')
        ultoa_base(va_arg(args, unsigned int), 10, p);
    else if (char_on_str == 'p')
    {
        ft_printstr("0x", p);
        ultoa_base(va_arg(args, unsigned int), 10, p);
    }
    else if (char_on_str == 'o')
        ultoa_base(va_arg(args, unsigned int), 8, p);
    else if (char_on_str == 'x')
        ultoa_base(va_arg(args, unsigned int), 16, p);
    else if (char_on_str == '%')
        ft_printchar((int)'%', p);
}

int ft_printf(const char* format, ...)
{
    int     char_count;
    int     *len;
    int     i;
    va_list  args;        /* basically a pointer to an argument in variadic-arg array */

    i = 0;
    char_count = 0;
    len = &char_count;
    va_start(args, format); /* "args" points at the first variadic-arg */

    char_count = 0;
    while (format[i])
    {
        if (format[i] != '%')
            ft_printchar((int)format[i], len);
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