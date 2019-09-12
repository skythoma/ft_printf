#include "ft_printf.h"

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

void    print_string(char *str, int *p)
{
   int x;
   
   x = -1;
   while (str[++x] != '\0')
   {
       ft_putchar(str[x]);
       *p = *p + 1;
   }
}

void	ft_putstr(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

/* void    unsign_count(unsigned long long int nb, int *size)
{
    while (nb != 0)
    {
        *size += 1;
        nb /= 10;
    }
}
*/

void    put_ulltoa(unsigned long long num, int *p)
{
    if (num >= 10)
    {
        put_ulltoa((num / 10), p);
        put_ulltoa((num % 10), p);
    }
    else
    {
        *p = *p+ 1;
        ft_putchar(num + '0');
    }
    
}

 void    ulltoa_base(unsigned long long num, int base) /* converting an unsigned long to str (ASCII) */
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
    //ft_printstr(str);
     ft_putstr(str);
     free(str);
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
    else if (char_on_str == 'p')
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

void    ft_putchar(char c)
{
    write(1, &c, 1);
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

#include <stdio.h>


void	ft_putnbr(int n)
{
	long num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + 48);
}


void	print_integer(int i, int *lenptr)
{
	 long l;

	 l = i;
	 if (l < 0)
	 {
	 	l = -l;
	 	//ft_printchar((int)'-', lenptr);
	 }
    ft_putnbr(i);
}

// void    ft_putnbr

void    ft_printstr(char *s, int *lenptr)
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

void    ft_printchar(int i, int *lenptr)
{
        char c;

        c = (char)i;
        write(1, &c, 1);
        *lenptr += 1;
}

int main()
{
    int a;
    int *b;
    a = 5;
    b = &a;

    ft_printf("my char test -> %c %c\n", 'a', 65);
    printf("fake char test -> %c %c\n", 'a', 65 );
    write(1, "\n", 1);

    printf("real: [before %x after]\n", 42);
    ft_printf("mine: [before %x after]\n", 42);
    write(1, "\n", 1);

    ft_printf("my reghex test -> %x\n", 392);
    printf("fake reghex test -> %x\n", 392);
    write(1, "\n", 1);

    ft_printf("my oct test -> %o\n", 392);
    printf("fake oct test -> %o\n", 392);
    write(1, "\n", 1);

    ft_printf("my big oct test -> %O\n", 392);
    printf("fake big oct test -> %O\n", 392);
    write(1, "\n", 1);

    ft_printf("my decimal test -> %d\n", 392);
    printf("fake decimal test -> %d\n", 392);
    write(1, "\n", 1);

    ft_printf("my big decimal test -> %D\n", 392);
    printf("fake big decimal test -> %D\n", 392);
    write(1, "\n", 1);

    printf("real: [%p]\n", b);
	ft_printf("mine: [%p]\n", b);
    write(1, "\n", 1);

    ft_printf("my int test -> %i\n", 392);
    printf("fake int test -> %i\n", 392);
    write(1, "\n", 1);

    ft_printf("my otherr int test -> %d\n", -2035065302);
    printf("fake oter int test -> %d\n", -2035065302);
    write(1, "\n", 1);

    ft_printf("my pct u test -> %u\n", 392);
    printf("fake pct u test -> %u\n", 392);
    write(1, "\n", 1);

    ft_printf("my str test -> %s\n", "what up");
    printf("fake str test -> %s\n", "what up");
    write(1, "\n", 1);

    ft_printf("my big X test %X\n", -123);
    printf("fake big X test %X\n", -123);
    write(1, "\n", 1);

    char *str3 = "abc";
	int ft2 = ft_printf("mine is [%s]\n", str3);
	int og2 = printf("real is [%s]\n", str3);
    write(1, "\n", 1);

    printf("real: [%s]\n", "Á±≥");
	ft_printf("mine: [%s]\n", "Á±≥");


    return (0);
}