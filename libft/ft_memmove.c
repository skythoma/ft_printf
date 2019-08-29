/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:41:28 by skythoma          #+#    #+#             */
/*   Updated: 2019/03/01 00:04:46 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*cd;
	const unsigned char	*cs;
	size_t				i;

	cd = dst;
	cs = src;
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			cd[i] = cs[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (n--)
			cd[n] = cs[n];
	}
	return (dst);
}
