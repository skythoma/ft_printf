/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:44:40 by skythoma          #+#    #+#             */
/*   Updated: 2019/08/20 12:44:42 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *s, int *lenptr)
{
	int i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		i = 6;
	}
	else
	{
		while (s[i])
			i++;
		write(1, s, 1);
	}
	*lenptr += 1;
}

void	ft_printchar(int i, int *lenptr)
{
	char c;

	c = (char)i;
	write(1, &c, 1);
	*lenptr += 1;
}

void    ultoa_base(unsigned long num, int base, int *lenptr) /* converting an unsigned long to str (ASCII) */
{
    char    *tab;
    unsigned long nbr; /* temp variable (holder) */
    char    *str;
    int i; /* indicates/represents size */

    tab = "0123456789abcdef";
    nbr = num;
    i = 1;
    while (nbr /= base)
        i++;
    if (!(str = (char *)malloc(sizeof(*str) * (i + 1)))) /* giving the __ a size  */
        return ;
    str[i] = '\0';
    while (i--)
    {
        str[i] = tab[num % base];
        num /= base;
    }
    ft_printstr(str, lenptr);
    free(str);
}

void	print_integer(int i, int *lenptr)
{
	long l;

	l = i;
	if (l < 0)
	{
		l = -l;
		ft_printchar((int)'-', lenptr);
	}
	ultoa_base(l, 10, lenptr); /* prints a base 10 int */
}

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

int main()
{
    int a = 10;

    int *ptr = &a;

    ft_printf("my char test -> %c", 'h');
    printf("fake char test -> %c\n", 'h');
    write(1, "\n", 1);

    ft_printf("my ptr test -> %p\n", ptr);
    printf("fake ptr test -> %p\n", ptr);

    ft_printf("my string test -> %s", "hello there!");
    write(1, "\n", 1);
    printf("fake string test -> %s", "hello");

    ft_printf("my hexi test -> %x\n", 42);
    printf("fake hexi test -> %x\n", 42);

    ft_printf("my decimal test -> %d", 42);
	printf("fake decimal test -> %5d", 42);
    
    write(1, "\n", 1);
    ft_printf("my integer test -> %i", 123);
    write(1, "\n", 1);
    printf("fake integer test -> %5i", 123);

    return (0);
}