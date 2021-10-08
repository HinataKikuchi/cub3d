/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:08:51 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/04/07 20:06:15 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	c;

	i = 0;
	b = (unsigned char *)buf;
	c = (unsigned char)ch;
	while (i < n)
	{
		if (*(b + i) == c)
			return ((void *)(b + i));
		i++;
	}
	return (NULL);
}
