/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:33:18 by skythoma          #+#    #+#             */
/*   Updated: 2019/03/05 20:21:51 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*result;

	result = NULL;
	if (str1 == 0 || str2 == 0)
		return (NULL);
	result = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	if (result)
	{
		ft_strcpy(result, str1);
		ft_strcat(result, str2);
		return (result);
	}
	else
		return (NULL);
}
