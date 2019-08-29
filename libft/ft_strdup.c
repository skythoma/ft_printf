/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:00:58 by skythoma          #+#    #+#             */
/*   Updated: 2019/03/05 20:25:15 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*nstr;

	nstr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			nstr[i] = s1[i];
			i++;
		}
		nstr[i] = '\0';
		return (nstr);
	}
}
