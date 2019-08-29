/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:04:03 by skythoma          #+#    #+#             */
/*   Updated: 2019/08/23 13:04:06 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     spec_char_len(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}

int     variablelen(char *str)
{
    int i;

    i = 1;
    while (ft_strchr(FLAGS, str[i]) || ft_strchr(DIGITS, str[i]) || str[i] == PRECISION_DOT || ft_strchr(MODIFIERS, str[i]))
    {
        i++;
    }
    if (str[i] != '\0')
        i += 1;
    return (i);
}

char    *str_parse(char **str)
{
    int     len_str;
    char    *str_chunk;

    len_str = 0;
    if (**str == '\0')
        return (0);
    else if (**str == '%')
    {
        len_str = variablelen(*str);
    }
    else
    {
        len_str = spec_char_len(*str, '%');
    }
    if ((str_chunk = ft_strsub(*str, 0, len_str)))
	{
		*str += len_str;
		return (str_chunk);
	}
	return (0);
}