/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:07:20 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/28 14:03:59 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *buf1, const char *buf2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	i = 0;
	b1 = (unsigned char *)buf1;
	b2 = (unsigned char *)buf2;
	if (!buf2)
		return (0);
	if (n == 0)
		return (ft_strlen(buf2));
	while (i < n - 1)
	{
		*(b1 + i) = *(b2 + i);
		if (*(b2 + i) == '\0')
			break ;
		i++;
	}
	*(b1 + i) = '\0';
	return (ft_strlen(buf2));
}
