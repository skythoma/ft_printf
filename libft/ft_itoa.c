/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:55:59 by skythoma          #+#    #+#             */
/*   Updated: 2019/05/02 14:22:26 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int i)
{
	int	c;

	c = 0;
	if (i < 0)
		c++;
	while (i)
	{
		c++;
		i /= 10;
	}
	return (c);
}

static char		*absolu(size_t v_absolu, size_t i, char *nb)
{
	while (v_absolu)
	{
		nb[i--] = '0' + (v_absolu % 10);
		v_absolu /= 10;
	}
	return (nb);
}

char			*ft_itoa(int n)
{
	char	*nb;
	size_t	nbc;
	size_t	sign;
	size_t	v_absolu;
	size_t	i;

	nbc = ft_size(n);
	i = nbc - 1;
	nb = (char *)malloc(sizeof(char) * (nbc) + 1);
	if (nb == NULL)
		return (NULL);
	sign = ((n < 0) ? 1 : 0);
	v_absolu = (unsigned)((n < 0) ? -n : n);
	if (!v_absolu || v_absolu == 0)
	{
		nb[0] = '0';
		nb[1] = '\0';
		return (nb);
	}
	if (sign == 1)
		nb[0] = '-';
	nb = absolu(v_absolu, i, nb);
	nb[nbc] = '\0';
	return (nb);
}
