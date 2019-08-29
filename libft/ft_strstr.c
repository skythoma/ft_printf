/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:59:51 by skythoma          #+#    #+#             */
/*   Updated: 2019/03/05 20:16:05 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		mark;

	i = 0;
	if (s2[i] == '\0')
		return (char *)(s1);
	while (s1[i])
	{
		j = 0;
		mark = -1;
		if (s1[i] == s2[j])
			mark = i;
		while (s1[i] == s2[j] && s2[j] != '\0')
		{
			if (s2[j + 1] == '\0')
				return (char *)&s1[mark];
			i++;
			j++;
		}
		if (mark != -1)
			i = mark;
		i++;
	}
	return (NULL);
}
