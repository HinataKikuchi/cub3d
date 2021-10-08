/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:35:57 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/05/06 13:36:39 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0' || !s1)
		return ((char *)(s1));
	i = 0;
	j = 0;
	while ((i + j < ft_strlen(s1)) && i + j < len)
	{
		j = 0;
		if (*(s1 + i) == *(s2 + j))
		{
			while (*(s2 + j) && (i + j < len) && (i + j < ft_strlen(s1)))
			{
				if (*(s1 + i + j) != *(s2 + j))
					break ;
				j++;
			}
		}
		if (*(s2 + j) == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
