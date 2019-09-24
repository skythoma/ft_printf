#include "ft_printf.h"

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