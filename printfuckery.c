#include "ft_printf.h"

void    print_bighex(unsigned int n, int *p) /* 'H' */
{
    if (n > 15)
	{
		print_bighex((n / 16), p);
		print_bighex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
	else
	{
		*p = *p + 1;
		n == 10 ? ft_putchar('A') : 0;
		n == 11 ? ft_putchar('B') : 0;
		n == 12 ? ft_putchar('C') : 0;
		n == 13 ? ft_putchar('D') : 0;
		n == 14 ? ft_putchar('E') : 0;
		n == 15 ? ft_putchar('F') : 0;
	}
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
	ultoa_base(l, 10, lenptr); 
}

void	print_octal(unsigned int n, int *p)
{
	if (n > 7)
	{
		print_octal((n / 8), p);
		print_octal((n % 8), p);
	}
	else
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
}

void	ft_putstrf(char const *str, int *p)
{
	int	x;

	x = -1;
	while (str[++x] != '\0')
	{
		ft_putchar(str[x]);
		*p = *p + 1;
	}

}

void    print_hex(unsigned int n, int *p)
{
    if (n > 15)
	{
		print_hex((n / 16), p);
		print_hex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
	else
	{
		*p = *p + 1;
		n == 10 ? ft_putchar('a') : 0;
		n == 11 ? ft_putchar('b') : 0;
		n == 12 ? ft_putchar('c') : 0;
		n == 13 ? ft_putchar('d') : 0;
		n == 14 ? ft_putchar('e') : 0;
		n == 15 ? ft_putchar('f') : 0;
	}
}

void    print_str(char *s, int *p)
{
    char    *string;
	va_list	args;

    string = va_arg(args, char*);
    if (string != NULL)
        ft_printstr(string, p);
    else
    {
		*p = *p + 6;
		write(1, "(null)", 1);
    }    
}
