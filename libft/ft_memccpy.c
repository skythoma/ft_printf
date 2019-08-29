/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:21:07 by skythoma          #+#    #+#             */
/*   Updated: 2019/02/28 00:42:06 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*cs;
	unsigned char	*cd;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	cs = src;
	cd = dst;
	while (i < n)
	{
		cd[i] = cs[i];
		if (cd[i] == cc)
			return (&cd[i + 1]);
		i++;
	}
	return (NULL);
}
