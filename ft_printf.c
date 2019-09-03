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

#include "ft_printf.h"


void    percent_s(va_list args, int *p)
{
    
}

int ft_printf(const char* format, ...)
{
    int     char_count;
    int     print_int;
    char    integer_str;
    char    *print_str;

    va_list  args;        /* basically a pointer to an argument in variadic-arg array */

    va_start(args, format); /* "args" points at the first variadic-arg */

    char_count = 0;
    while (*str_parse)
    {
        if (*format == '\0')
        {    
            ft_putchar('%');
            format++;
            char_count += 2;
        }
    }

    va_end(args);

    return (char_count);
}