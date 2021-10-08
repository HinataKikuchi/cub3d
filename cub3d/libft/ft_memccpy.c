/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:55:02 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/04/07 20:04:53 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *buf1, const void *buf2, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*b1;
	unsigned char	*b2;

	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	i = 0;
	b1 = (unsigned char *)buf1;
	b2 = (unsigned char *)buf2;
	while (i < n)
	{
		*(b1 + i) = *(b2 + i);
		if (*(b1 + i) == (unsigned char)c)
			return ((void *)b1 + i + 1);
		i++;
	}
	return (NULL);
}
