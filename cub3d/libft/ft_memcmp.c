/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:57:23 by hkikuchi          #+#    #+#             */
/*   Updated: 2020/11/26 16:26:49 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	unsigned int	i;

	b1 = (unsigned char *)buf1;
	b2 = (unsigned char *)buf2;
	i = 0;
	while (i < n)
	{
		if (*(b1 + i) != *(b2 + i))
			return (*(b1 + i) - *(b2 + i));
		i++;
	}
	return (0);
}
