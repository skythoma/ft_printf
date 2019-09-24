/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 03:22:57 by skythoma          #+#    #+#             */
/*   Updated: 2019/08/29 03:22:59 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    all_flags(char *frmat, int *i, t_flags *lwii) /* location where its in */
{
    while (frmat[*i] != '\0' && (frmat[*i] == '+' || frmat[*i] == '-' || frmat[*i] == '0' || frmat[*i] == ' ' || frmat[*i] == '#'))
    {
        if (frmat[*i] == '+')
        {
            
        }
    }
}

void    make_bin(t_flags *bin) /* struct being initialized/getting it ready */
{
    bin->min_flag = false;
    bin->p_flag = false;
    bin->spce_flag = false;
    bin->hash_flg = false;
    bin->zero_flag = false;
    bin->precision = false;
    bin->star = false;
    bin->type = 0;
    bin->width = 0;
    bin->precision_dot = 0;
    bin->args = 0;
    bin->ret = 0;
    bin->len = 0;
}

void	get_width(char *format, int *i, t_flags *bin, va_list args)
{
	char	*ptr;

	ptr = format;
	while (format[*i] != '\0' && (format[*i] == '*' || (format[*i] > 47 && format[*i] < 58)))
	{
		if (format[*i] == '*')
		{
			WIDTH = va_arg(args, int);
			*i += 1;
		}
		else
		{
			ptr += *i;
			WIDTH = ft_atoi(ptr);
			while (format[*i] > 47 && format[*i] < 58)
				*i += 1;
		}
	}
}

void    get_prec(char *format, int *i, t_flags *bin, va_list args)
{
    char    *ptr;

    ptr = format;
    PRECISION_DOT = 0;
    if (format[*i] != '.')
        return ;
    *i += 1;
    PRECISION = true;
    while (format[*i] != '\0' && (format[*i] == '-' || format[*i] == '*' || (format[*i] > 47 && format < 58)))
    {
        if (format[*i] == '*')
        {
            STAR = true;
            PRECISION = va_arg(args, int);
            *i += 1;
        }
        else
        {
            ptr += *i;
            PRECISION = ft_atoi(ptr);
            while ((format[*i] != '\0' && format[*i] > 47 && format[*i] < 58) || format[*i] == '-')
                *i += 1;
        }
    }
}

void    type(char c, t_flags *bin)
{
    if (c == 'd' || c == 'D' || c == 's' || c == 'S' || c == 'p' ||  c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 'f' || c == 'F' || c == '%' )
        TYPE = c;
    else
    {
        TYPE = -1;
    }
}

void	form_args(char *format, int *i, t_flags *bin)
{
	while (format[*i] != '\0' && (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'z' ||
			format[*i] == 'j' || format[*i] == 'q'))
	{
		if (format[*i] == 'h' && ARGS == 1)
			ARGS = 2;
		else if (format[*i] == 'h' && ARGS != 6 && ARGS != 5)
			ARGS = 1;
		else if (format[*i] == 'l' && ARGS == 3)
			ARGS = 4;
		else if (format[*i] == 'l')
			ARGS = 3;
		else if (format[*i] == 'j')
			ARGS = 5;
		else if (format[*i] == 'z')
			ARGS = 6;
		*i += 1;
	}
}