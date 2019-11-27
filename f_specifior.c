#include "ft_printf.h"

void	count(long long int n, unsigned int *size) /* kind of like an advnced strlen */
{
	while (n != 0) /* if the number is anything */
	{
		*size += 1;
		n /= 10;
	}
}

void	fill_table(int if_neg, long long int n, char *tab, int size)
{
	tab += size;
	*tab-- = '\0'; /* "have to go backwards to go forward" */

	if (n == LL_MIN)
	{
		*tab-- = '8';
		n /= 10;
		size--;
	}
	if (n > LL_MAX)
	{
		n = LL_MIN + (n - LL_MIN) - 1;
		if_neg = 1;
	}
	else
		n = (if_neg == 1 ? n - n - n : n);
	while (size-- > 0)
	{
		if ((if_neg == 1) && (size == 0))
			*tab = '-';
		else
			*tab-- = n % 10 + 48;
		n /= 10;
	}
}

char	*ft_itoaplus(long long int n)
{
	unsigned int	size;
	char			*tab;
	int				if_neg;

	if_neg = (n < 0 ? 1 : 0);
	size = (n < 0 ? 1 : 0);
	count(n, &size);
	size = (n == 0 ? 1 : size);
	if (!(tab = (char *)malloc(size + 1)))
		return ((char *)'\0');
	fill_table(if_neg, n, tab, size);
	return (tab);
}

void    make_string(double nb, char *rest, int i) /* making a fat string for decimal number */
{
    int     aft_dt; /* everything after (numbers, etc) */
    int     dt; /* the decimal itself */

    dt = 0;
    aft_dt = 0;
    if (nb < 1) /* if the number or whatever is lesss than 1 */
    {
        rest[i++] = '.'; /* whatever on the str is = to a '.' */
        dt = i;
        while (aft_dt < 6) 
        {
            nb *= 10; /* the number itself multiply by '10'*/
            if (((int)(nb + 0.000001)) != 10) /* 8 bytes / 8 spaces */
                rest[i++] = (int)(nb + 48 + 0.000001); /* 48 is '0' (ascii) */
            nb -= (int)nb;
            aft_dt++;
        }
    }
    while (i - dt < 6)
        rest[i++] = '0';
    rest[i] = '\0';
}

char    *ftoa(double n) /* float to ascii(string) */
{
    char        *flt; /* the actual number from the fucking str : it "gets" it, it knows what isit*/
    char        *first; /* temp */
    long int    nb; /* the number */
    int         i; /*  len? */

    i = -1;
    nb = (long int)n; /* converting n to long int */
    first = ft_itoaplus(nb);
    flt = (char *)malloc(100); /* gives the string it's space for whatever number it "gets" */
    n -= (double)nb;
    if (n < 0) /* if the number is lss than '0' */
        n *= -1; /* make that bitch negative */
    while (first[++i])
        flt[i] = first[i];
    make_string(n, flt, i);
    free(first);
    return (flt);
}

void    putachar(char c)
{
    write(1, &c, 1);
}

void    put(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        putachar(str[i]);
        i++;
    }
}

int main()
{   
    double n;

    n = 1773.827465920;

    put(ftoa(n));

    write(1, "\n", 1);

    return(0);

}