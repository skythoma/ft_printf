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