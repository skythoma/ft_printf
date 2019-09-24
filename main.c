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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void    make_string(double nb, char *rest, int i)
{
    int     aft_dt;
    int     dt;

    dt = 0;
    aft_dt = 0;
    if (nb < 1)
    {
        rest[i++] = '.';
        dt = i;
        while (aft_dt < 6)
        {
            nb *= 10;
            if (((int)(nb + 0.000001)) != 10)
                rest[i++] = (int)(nb + 48 + 0.000001);
            nb -= (int)nb;
            aft_dt++;
        }
    }
    while (i - dt < 6)
        rest[i++] = '0';
    rest[i] = '\0';
}

char    *ft_itoa(int nbr)
{
    char    store[11];
    char    *ret;
    int     flag;
    int     len;
    int     i;
    int     j;

    flag = 0;
    i = 0;
    j = 0;
    if (nbr < 0) /* if negative */
    {
        flag = 1;
        nbr *= -1;
    }
    else if (!nbr)
        return (0);
    while (nbr > 0)
    {
        store[i] = nbr % 10 + '0';
        nbr /= 10;
        i++;
    }
    if (flag)
        store[i++] = '-';
    len = ft_strlen(store) + 1;
    if (!(ret = (char *)malloc(sizeof(char) * len)))
        return (NULL);
    i--;
    while (i >= 0)
    {
        ret[j] = store[i];
        j++;
        i++;
    }
    ret[j] = '\0';
    return (ret);
}

char    *ftoa(double n) /* float to ascii(string) */
{
    char        *flt;
    char        *first;
    long int    nb;
    int         i;

    i = -1;
    nb = (long int)n;
    first = ft_itoa(nb);
    flt = (char *)malloc(100);
    n -= (double)nb;
    if (n < 0)
        n *= -1;
    while (first[++i])
        flt[i] = first[i];
    make_string(n, flt, i);
    free(first);
    return (flt);
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
      //  print_float(va_arg(args, float), p);
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

int		main()
{
	char c = 'a';
	int x = -100;
	int a = 1007;
	int data = 29;
	char *str;
	str = "babs";
	printf("------CHAR-------\n\n");
	printf("real: [%c]\n", 42);
	ft_printf("mine: [%c]\n", 42);
	printf("real -2 width: [%-2c]\n", c);
	ft_printf("mine neg 2 width: [%-2c]\n", c);
	printf("real -c: [%-c]\n", c);
	ft_printf("my neg char, no width: [%-c]\n", c);
	printf("real 2 width: [%2c]\n", c);
	ft_printf("mine: [%2c]\n", c);
	printf("real: [%c]\n", c);
	ft_printf("my normal char: [%c]\n", c);
	printf("real: [%50c]\n", c);
	ft_printf("mine: [%50c]\n", c);
	int kk = printf("real: [%-50c]\n", c);
	int ww =ft_printf("mine: [%-50c]\n", c);
	printf("%d\n", kk);
	printf("%d\n", ww);
	int zero = printf("r: [%c]\n", 0);
	int z1 = ft_printf("m: [%c]\n", 0);
	printf("%d\n", zero);
	printf("%d\n", z1);
	int r = printf("r: [%.c]\n", 0);
	int m = ft_printf("m: [%.c]\n", 0);
	printf("r: %d\n", r);
	printf("m: %d\n", m);
	printf("r: [%2c]\n", c);
	ft_printf("m: [%2c]\n", c);
	printf("r: [%5c]\n", c);
	ft_printf("m: [%5c]\n", c);
	printf("r: [%.%]\n");
	ft_printf("m: [%.%]\n");
	printf("r: [%.3%]\n");
	ft_printf("m: [%.3%]\n");
	printf("r: [%.10%]\n");
	ft_printf("m: [%.10%]\n\n");
	printf("r: [%.3%]\n");
	ft_printf("m: [%.3%]\n");


	printf("-----INT----\n\n");
	printf("real: [% d]\n", 9999);
	ft_printf("mine: [% d]\n", 9999);
	printf("real: [%d]\n", -7);
	ft_printf("mine: [%d]\n", -7);
	printf("real: [%   d]\n", 7);
	ft_printf("mine: [%  d]\n", 7);
	printf("real: [%    d]\n", -7);
	ft_printf("mine: [%   d]\n", -7);
	printf("real: [%d]\n", a);
	ft_printf("mine: [%d]\n", a);
	printf("real: [%-10d]\n", x);
	ft_printf("mine: [%-10d]\n", x);
	printf("real: [%5d]\n", 0);
	ft_printf("mine: [%5d]\n", 0);
	printf("real: [%5d]\n", -42);
	ft_printf("mine: [%5d]\n", -42);
	printf("real: [%-5d]\n", -42);
	ft_printf("mine: [%-5d]\n", -42);
	printf("real: [%05d]\n", 0);
	ft_printf("mine: [%05d]\n", 0);
	printf("real: [%-5d]\n", 10);
	ft_printf("mine: [%-5d]\n", 10);
	printf("real: [%+5d]\n", 10);
	ft_printf("mine: [%+5d]\n", 10);
	ft_printf("mine: [%d]\n", 1);
	printf("real: [%d]\n", 1);
	ft_printf("mine: [%10d]\n", 10);
	printf("real: [%10d]\n", 10);
	ft_printf("mine: [%-10d]\n", 10);
	printf("real: [%-10d]\n", 10);
	ft_printf("mine: the [%d]\n", 1);
	printf("real: the [%d]\n", 1);
	ft_printf("mine: [%d is one]\n", 1);
	printf("real: [%d is one]\n", 1);
	ft_printf("mine: [%d is negative one]\n", -1);
	printf("real: [%d is negative one]\n", -1);
	printf("real: [%d]\n", 4242);
	ft_printf("mine: [%d]\n", 4242);
	printf("real: [%d]\n", -4242);
	ft_printf("mine: [%d]\n", -4242);
	printf("real: [%d]\n", 2147483647);
	ft_printf("mine: [%d]\n", 2147483647);
	printf("real: [%ld]\n", -2147483649);
	ft_printf("mine: [%ld]\n", -2147483649);
	printf("real: [%00d]\n", -42);
	ft_printf("mine: [%00d]\n", -42);
	printf("real: [%d]\n", 32768);
	ft_printf("mine: [%hd]\n", 32768);
	printf("real: [%d]\n", 0);
	ft_printf("mine: [%hd]\n", 0);
	printf("real: [%i%i]\n", 0, 42);
	ft_printf("mine: [%i%i]\n", 0, 42);
	printf("real: [%d]\n", -2035065302);
	ft_printf("mine: [%d]\n", -2035065302);
	printf("real: [%d]\n", 32767);
	ft_printf("mine: [%hd]\n", 32767);
	printf("real: [%d]\n", 1);
	ft_printf("mine: [%hd]\n", 1);
	int klk = printf("% d\n", 42);
	int lk = ft_printf("% d\n", 42);
	printf("r: %d\n", klk);
	printf("m: %d\n", lk);
	printf("-------EXTRAHEX------\n\n");
	int og = printf("r: %x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	int ft = ft_printf("m: %x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	printf("%d\n", og);
	printf("%d\n", ft);
	int ogk = printf("r: %x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	int ftk = ft_printf("m: %x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	printf("%d\n", ogk);
	printf("%d\n", ftk);
	printf("r: [%#x]\n", 0);
	ft_printf("m: [%#x]\n", 0);
	printf("r: [%-#x]\n", 0);
	ft_printf("m: [%-#x]\n", 0);
	printf("r: [%#X]\n", 0);
	ft_printf("m: [%#X]\n", 0);
	printf("r: [%-#X]\n", 0);
	ft_printf("m: [%-#X]\n", 0);
	// int f1t = ft_printf("mine is [%d]\n", -42);
	// int o1g = printf("real is [%d]\n", -42);
	// printf("mine: [%d]\n", f1t);
	// printf("real: [%d]\n\n", o1g);
	
	printf("-----INTS USING I-------\n\n");
	printf("real: [%i]\n", -2035065302);
	ft_printf("mine: [%i]\n", -2035065302);
	printf("real: [%i]\n", -203);
	ft_printf("mine: [%i]\n", -203);
	printf("real: [%i]\n", -23);
	ft_printf("mine: [%i]\n", -23);
	printf("real: [%020i]\n", 19999);
	ft_printf("mine: [%020i]\n", 19999);
	printf("real: [%+0i]\n", 10);
	ft_printf("mine: [%+0i]\n", 10);
	printf("real: [%-30i]\n", 7);
	ft_printf("mine: [%-30i]\n", 7);
	printf("real: [%0000i]\n", 23);
	ft_printf("mine: [%0000i]\n", 23);
	printf("real: [%000010i]\n", 23);
	ft_printf("mine: [%000010i]\n", 23);
	printf("real: [%10i]\n", -203);
	ft_printf("mine: [%10i]\n\n", -203);
	
	
	printf("-----STRINGS----\n\n");
	//int s1 = printf("{%d}\n", 0);
	//int s2 = ft_printf("{%s}\n", 0);
	//printf("r: %d\n", s1);
//	printf("m: %d\n", s1);
	printf("real: [%s]\n", "Á±≥");
	ft_printf("mine: [%s]\n", "Á±≥");
	ft_printf("mine: [%-70s]\n", str);
	printf("real: [%-70s]\n", str);
	ft_printf("mine: [%70s]\n", str);
	printf("real: [%70s]\n", str);
	ft_printf("my str twice: [%s, %s]\n", str, str);
	printf("real: [%-5s]\n", str);
	ft_printf("mine: [%-5s]\n", str);
	ft_printf("mine: [%5s]\n", str);
	printf("real: [%5s]\n", str);
	char *str3 = "abc";
	// int ft2 = ft_printf("mine is [%s]\n", str3);
	// int og2 = printf("real is [%s]\n", str3);
	// printf("mine: [%d]\n", ft2);
	// printf("real: [%d]\n", og2);
	// ft_printf("mine: [%s]\n", NULL);
	// printf("real: [%5s]\n\n", NULL);
	
	// printf("------MORE-STRINGS----\n\n");
	// printf("real: [%-5s]\n","");
	// ft_printf("mine: [%-5s]\n","");
	// printf("real: [%-5s]\n","a");
	// ft_printf("mine: [%-5s]\n","a");
	// printf("real: [%-5s]\n","ab");
	// ft_printf("mine: [%-5s]\n","ab");
	// printf("real: [%-5s]\n","abcd");
	// ft_printf("mine: [%-5s]\n","abcd");
	// printf("real: [%5s]\n","abcdefg");
	// ft_printf("mine: [%5s]\n","abcdefg");
	// printf("real: [ Z%s ]\n", "test");
	// ft_printf("mine: [ Z%s ]\n\n", "test");
	//printf("real: [%s]\n", NULL);
	//ft_printf("mine: [%s]\n\n", NULL);

	// printf("-----PRECISION-----\n\n");
	// char	*str2 = "abcdefghijk";
	// printf("real: [%.10s]\n", str2);
	// ft_printf("mine: [%.10s]\n", str2);
	// // printf("real: [%.*s]\n", 6, str2);
	// // ft_printf("mine: [%.*s]\n", 6, str2);
	// printf("real: [%.3s]\n", str2);
	// ft_printf("mine: [%.3s]\n", str2);
	// printf("real: [%15.5s]\n", str2);
	// ft_printf("mine: [%15.5s]\n", str2);
	// printf("real: [%-10.5s]\n", str2);
	// ft_printf("mine: [%-10.5s]\n", str2);
	// printf("real: [%.0d]\n", 2);
	// printf("real: [%.0f.]\n", 2.2);
	// printf("real: [%.1f]\n", 2.2);
	// printf("real: [%5.1f]\n", 2.2);
	// printf("real: [%.6f]\n", 2.2);
	// printf("real: [%5.0d]\n", a);
	// printf("real: [%.0d]\n", x);
	// printf("real: [%.1d]\n", x);
	// printf("real: [%.2d]\n", x);
	// printf("real: [%.5s]\n","abcdefg");
	// printf("real: [%5.5s]\n\n","abcdefg");

	printf("-----HEX-----\n\n");
	printf("real: [before %x after]\n", 42);
	ft_printf("mine: [before %x after]\n", 42);
	printf("real: [%-20x]\n", 42U);
	ft_printf("mine: [%-20x]\n", 42U);
	printf("real: [%#20x]\n", 42U);
	ft_printf("mine: [%#20x]\n", 42U);
	printf("real: [%2x]\n", 42U);
	ft_printf("mine: [%2x]\n", 42U);
	printf("real: [%2x]\n", 542);
	ft_printf("mine: [%2x]\n", 542);
	printf("real: [%5x]\n", 542);
	ft_printf("mine: [%5x]\n", 542);
	printf("real: [%#x]\n", 542);
	ft_printf("mine: [%#x]\n", 542);
	printf("real: [%08x]\n", data);
	ft_printf("mine: [%08x]\n", data);
	printf("real: [%5x]\n", -42);
	ft_printf("mine: [%5x]\n", -42);
	printf("real: [%x]\n", -123);
	ft_printf("mine: [%x]\n", -123);
	printf("real: [%#lx]\n", 9223372036854775807);
	ft_printf("mine: [%#lx]\n\n", 9223372036854775807);
	printf("r: [%lx]\n", 4294967296);
	ft_printf("m: [%lx]\n", 4294967296);
	printf("r: [%lX]\n", 4294967296);
	ft_printf("m: [%lX]\n", 4294967296);

	int lol = printf("%c\n", 42);
	int lol2 = ft_printf("%c\n", 42);
	printf("%d\n", lol);
	printf("%d\n", lol2);
	int lol3 = printf("%5c\n", 42);
	int lol4 = ft_printf("%5c\n", 42);
	printf("%d\n", lol3);
	printf("%d\n", lol4);
	printf("r: [%-05%]\n");
	ft_printf("m: [%-05%]\n");
	printf("r: [%05%]\n");
	ft_printf("m: [%05%]\n");
	//printf("r: [%010s is a string]\n", "this");
	ft_printf("m: [%010s is a string]\n", "this");
	//printf("r: [% u]\n", 4294967295);
	ft_printf("m: [% u]\n", 4294967295);
	int u = printf("r: [%lu]\n", 4294967295);
	int u1 = ft_printf("m: [%lu]\n", 4294967295);
	printf("r: [%d]\n", u);
	ft_printf("m: [%d]\n", u1);
	int x1 = ft_printf("m: [%#8x]\n", 42);
	int x2 = printf("r: [%#8x]\n", 42);
	printf("m: %d\n", x1);
	printf("r: %d\n", x2);
	//printf("r: [%o, %ho, %hho]\n", -42, -42, -42);
	ft_printf("m: [%o, %ho, %hho]\n", -42, -42, -42);
	int c1 = ft_printf("r: [%#x]\n", 0);
	int c2 = printf("m: [%#x]\n", 0);
	printf("%d\n", c1);
	printf("%d\n", c2);
	int l = printf("r: {%010d}\n", -42);
	int l2 = ft_printf("m: {%010d}\n", -42);
	printf("%d\n", l);
	printf("%d\n", l2);
	printf("r: [%.0%]\n");
	ft_printf("m: [%.0%]\n");
	printf("real: [%35ld]\n", 9223372036854775807);
	ft_printf("mine: [%35lld]\n", 9223372036854775807);
	
	printf("-----BIG-HEX----\n\n");
	printf("real: [before %X after]\n", 42);
	ft_printf("mine: [before %X after]\n", 42);
	printf("real: [%5X]\n", -42);
	ft_printf("mine: [%5X]\n", -42);
	printf("real: [%#X]\n", 542);
	ft_printf("mine: [%#X]\n", 542);
	printf("real: [%#20X]\n", 42U);
	ft_printf("mine: [%#20X]\n", 42U);
	printf("real: [%-30X]\n", -2);
	ft_printf("mine: [%-30X]\n", -2);
	printf("real: [%2X]\n", 42U);
	ft_printf("mine: [%2X]\n", 42U);
	printf("real: [%x%X%x%X]\n", -42, 42, -42, 42);
	ft_printf("mine: [%x%X%x%X]\n\n", -42, 42, -42, 42);

	printf("-----OCTAL-----\n\n");
	printf("real: [%o]\n", 42);
	ft_printf("mine: [%o]\n", 42);
	printf("real: [%#o]\n", -42);
	ft_printf("mine: [%#o]\n", -42);
	printf("real: [%5o]\n", 42);
	ft_printf("mine: [%5o]\n", 42);
	printf("real: [%10o]\n", 42);
	ft_printf("mine: [%10o]\n", 42);
	printf("real: [%15o]\n", 42);
	ft_printf("mine: [%15o]\n", 42);
	printf("real: [%-5o]\n", 42);
	ft_printf("mine: [%-5o]\n", 42);
	printf("real: [%-10o]\n", 42);
	ft_printf("mine: [%-10o]\n", 42);
	printf("real: [%-15o]\n", 42);
	ft_printf("mine: [%-15o]\n", 42);
	printf("real: [%#5o]\n", 222);
	ft_printf("mine: [%#5o]\n", 222);
	printf("real: [%#10o]\n", 42);
	ft_printf("mine: [%#10o]\n", 42);
	printf("real: [%#15o]\n", 42);
	ft_printf("mine: [%#15o]\n", 42);
	printf("real: [%o]\n", 10);
	ft_printf("mine: [%o]\n\n", 10);
	
	printf("-----OTHER-----\n\n");
	ft_printf("mine: [%-5%]\n");
	printf("real: [%-5%]\n");
	ft_printf("mine: [%5%]\n");
	printf("real: [%5%]\n");
	int fti = ft_printf("%%\n");
	int ogi = printf("%%\n");
	printf("mine: [%d]\n", fti);
	printf("real: [%d]\n", ogi);
	ft_printf("mine: [%  %]\n");
	printf("real: [%   %]\n\n");

	printf("-------UNSIGNED-----\n\n");
	int ft3 = ft_printf("mine: [%u]\n", -1);
	int og3 = printf("real: [%u]\n", -1);
	printf("my rtn: [%d]\n", ft3);
	printf("real rtn: [%d]\n", og3);
	printf("real: [%u]\n", 15);
	ft_printf("mine: [%u]\n", 15);
	printf("real: [%u]\n", 10);
	ft_printf("mine: [%u]\n", 10);
	printf("real: [%u]\n", 5);
	ft_printf("mine: [%u]\n", 5);
	printf("real: [%u]\n", -5);
	ft_printf("mine: [%u]\n", -5);
	printf("real: [%u]\n", -10);
	ft_printf("mine: [%u]\n", -10);
	printf("real: [%10u]\n", 10);
	ft_printf("mine: [%10u]\n", 10);
	printf("real: [%-10u]\n", 10);
	ft_printf("mine: [%-10u]\n", 10);
	printf("r: [%lu]\n", 4294967296);
	ft_printf("m: [%lu]\n", 4294967296);

	printf("----ASTRICT----\n\n");
	printf("real: [%*s]\n", 5, "abc");
	ft_printf("mine: [%*s]\n", 5, "abc");
	printf("real: [%*s]\n", 10, "abc");
	ft_printf("mine: [%*s]\n", 10, "abc");
	printf("real: [%*s]\n", 15, "abc");
	ft_printf("mine: [%*s]\n", 15, "abc");
	printf("real: [%*s]\n", -5, "abc");
	ft_printf("mine: [%*s]\n", -5, "abc");
	printf("real: [%*s]\n", -10, "abc");
	ft_printf("mine: [%*s]\n", -10, "abc");
	printf("real: [%*s]\n", -15, "abc");
	ft_printf("mine: [%*s]\n", -15, "abc");
	printf("real: [%-*s]\n", 6, "abc");
	ft_printf("mine: [%-*s]\n\n", 6, "abc");

	printf("------POINT-----\n\n");
	int k = 5;
	int *b = &k;
	int f = -15;
	int *e = &f;
	 int z = 2147483647;
	 int *y = &z;
	char *lll = "abc";
	//void *lol = &lll;
	int ft4 = ft_printf("mine: [%p]\n", y);
	int og4 = printf("real: [%p]\n", y);
	printf("my rtn: [%d]\n", ft4);
	printf("real rtn: [%d]\n", og4);
	printf("real: [%p]\n", b);
	ft_printf("mine: [%p]\n", b);
	printf("real: [%p]\n", e);
	ft_printf("mine: [%p]\n", e);
	printf("real: [%p]\n", y);
	ft_printf("mine: [%p]\n", y);
	printf("real: [%30p]\n", y);
	ft_printf("mine: [%30p]\n", y);
	printf("real: [%-30p]\n", y);
	ft_printf("mine: [%-30p]\n", y);
	printf("real: [%50p]\n", y);
	ft_printf("mine: [%50p]\n", y);
	printf("real: [%3p]\n", y);
	ft_printf("mine: [%3p]\n", y);
	printf("real: [%p]\n", &lll);
	ft_printf("mine: [%p]\n\n", &lll);

	printf("-----BINARY----\n\n");
	// printf("binary: 0=0, 1=1, 2=10, 3=11, 4=100, 7=111, 8=1000, 10=1010 etc.\n\n");
	// ft_printf("mine: [%b]\n", 0);
	// ft_printf("mine: [%b]\n", 1);
	// ft_printf("mine: [%b]\n", -1);
	// ft_printf("mine: [%b]\n", 2);
	// ft_printf("mine: [%b]\n", -2);
	// ft_printf("mine: [%b]\n", 3);
	// ft_printf("mine: [%b]\n", -3);
	// ft_printf("mine: [%b]\n", 4);
	// ft_printf("mine: [%b]\n", 7);
	// ft_printf("mine: [%b]\n", 8);
	// ft_printf("mine: [%b]\n", 10);
	// ft_printf("mine: [%b]\n", 16);
	// ft_printf("mine: [%b]\n", -20);
	// int nb1 = ft_printf("[%s]\n", NULL);
	// int nb2 = printf("[%s]\n", NULL);
	// int nb3 = ft_printf("[%c]\n", 0);
	// int nb4 = printf("[%c]\n", 0);
	// int nb5 = ft_printf("[%-35x]\n", 42);
	// int nb6 = printf("[%-35x]\n", 42);
	//printf("YOURS %d\n", nb1);
	//printf("OFFICIAL %d\n\n", nb2);
	
	printf("--------MORE------\n\n");
//	printf("r: {%-30s}\n", "我是一只猫。");
//	ft_printf("m: {%-30s}\n", "我是一只猫。");
	// int odd = printf("r: {%30s}\n", "我是一只猫。");
	// int oddd = ft_printf("m: {%30s}\n", "我是一只猫。");
	// printf("r: %d\n", odd);
	// printf("m: %d\n", oddd);
	char *str1 = "abcdefghijk";
	int wq = printf("r: %.5s\n", str1);
	int wqq = ft_printf("m: %.5s\n", str1);
	printf("r: %d\n", wq);
	printf("m: %d\n", wq);
	int sas = printf("r: %.4s\n", "42");
	int sass = ft_printf("m: %.4s\n", "42");
	printf("r: %d\n", sas);
	printf("m: %d\n", sass);
	int bwq = printf("r: %.4s\n", "42 is the answer");
	int bbwq = ft_printf("m: %.4s\n", "42 is the answer");
	printf("r: %d\n", bwq);
	printf("m: %d\n", bbwq);
	int sus = printf("%15.4s\n", "42");
	int suss = printf("%15.4s\n", "42");
	printf("r: %d\n", sus);
	printf("m: %d\n", suss);
	ft_printf("m: %lx\n", 4294967296);
	printf("r: %lx\n", 4294967296);
	ft_printf("m: %.20s\n", "42 is the answer");
	printf("r: %.20s\n", "42 is the answer");
	ft_printf("m: @moulitest: %#.x %#.0x\n", 0, 0);
	printf("r: @moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("m: %.xkk\n", 0);
	printf("r: %.xkk\n", 0);
	int mm = ft_printf("m: %#6o\n", 2500);
	int mk = printf("r: %#6o\n", 2500);
	ft_printf("m: %-#6o\n", 2500);
	printf("r: %-#6o\n", 2500);
	printf("m: %d\n", mm);
	printf("r: %d\n", mk);
	ft_printf("m: %6.3o\n", 2500);
	printf("r: %6.3o\n", 2500);
	printf("r: @moulitest: %5.d %5.0d\n", 0, 0);
	ft_printf("m: @moulitest: %5.d %5.0d\n", 0, 0);
	ft_printf("m: %lx\n", 4294967296);
	printf("r: %lx\n", 4294967296);
	ft_printf("m: %5.x\n", 10);
	ft_printf("m: %5.s\n", "abcdefg");
	ft_printf("m: @moulitest: %#.o %#.0o\n", 0, 0);
	printf("r: @moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("m: % +d\n", 42);
	//printf("r: % +d\n", 42);
	ft_printf("m: %++d\n", 42);
	printf("r: %++d\n", 42);
	ft_printf("m: @moulitest: %.d %.0d\n", 42, 43);
	printf("r: @moulitest: %.d %.0d\n", 42, 43);
	ft_printf("m: @moulitest: %.5u\n", 42);
	printf("r: @moulitest: %.5u\n", 42);
	ft_printf("m: %lu\n", 4294967296);
	printf("r: %lu\n", 4294967296);
	ft_printf("m: %lx\n", 4294967296);
	printf("r: %lx\n", 4294967296);
	ft_printf("m: %010x\n", 542);
	printf("r: %010x\n", 542);


	// ft_printf("m: %+lld\n", 4242424242424242424242);
	// printf("r: %+lld\n", 4242424242424242424242);
	// ft_printf("m: %+lld\n", 4242424242424242);
	// printf("r: %+lld\n", 4242424242424242);
	// printf("------------------------------\n");
	// printf("YOURS %d\n", nb3);
	// printf("OFFICIAL %d\n", nb4);
	// printf("------------------------------\n");
	// printf("YOURS %d\n", nb5);
	// printf("OFFICIAL %d\n", nb6);
	// printf("------------------------------\n");
	
	//broken moulitests
	
	// printf("{r: %10R}\n");
	// ft_printf("m: {%10R}\n");
	// int odd = printf("r: {%30s}\n", "我是一只猫。");
	// int oddd = ft_printf("m: {%30s}\n", "我是一只猫。");
	// ft_printf("m: %+lld\n", 4242424242424242424242);
	// printf("r: %+lld\n", 4242424242424242424242);
	// //ft_printf("m: %+lld\n", 4242424242424242);
	// printf("r: %+ld\n", 4242424242424242);
	return (0);
}

/* int main()
{
    int a;
    int *b;
    a = 5;
    b = &a;

    ft_printf("my char test -> %c %c\n", 'a', 65);
    printf("fake char test -> %c %c\n", 'a', 65);
    write(1, "\n", 1);

    ft_printf("my big char test -> %C %C\n", 'a', 65);
    printf("fake big char test -> %C %C\n", 'a', 65);
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
    
    ft_printf("my big str test -> %S\n", "what up");
    printf("fake big str test -> %S\n", "what up");
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
    write(1, "\n", 1);

    float flt;
    flt = 10.234;

    ft_printf("%", "hey");
    write(1, "\n", 1);
    ft_printf("my float test -> is %f \n", flt);
    printf("fake float test -> is %f \n", flt);

    return (0);
}
*/