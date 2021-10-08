/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:57:50 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/21 18:50:29 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned int	i;
	unsigned char	*b1;
	unsigned char	*b2;

	if (buf1 == buf2)
		return (buf1);
	b1 = (unsigned char *)buf1;
	b2 = (unsigned char *)buf2;
	if (buf1 > buf2)
	{
		i = n;
		while (0 < i--)
			*(b1 + i) = *(b2 + i);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(b1 + i) = *(b2 + i);
			i++;
		}
	}
	return (b1);
}
