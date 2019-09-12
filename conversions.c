#include "ft_printf.h"

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

char    *ft_itoa_base(int value, int base)
{
    static  char rep[] = "0123456789abcdef";
    static  char buf[50];
    char    *ptr;
    int     num;

    ptr = &buf[49];
    *ptr = '\0';
    num = value;
    if (value < 0 && base == 10)
        value *= -1;
    if (value == 0)
        *--ptr = rep[value % base];
    while (value != 0)
    {
        *--ptr = rep[value % base];
        value /= base;
    }
    if (num < 0 && base == 10)
        *--ptr = '-';
    return (ptr);
}

char    *ftoa(double n) /* float to ascii(string) */
{
    char    *flt;
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